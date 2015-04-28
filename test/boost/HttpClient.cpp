/****************************************************************************
*
*   HttpClient.cpp
*   
*
*   Written by Jaewon Choi (08/17/2014)
*   Owned by Jaewon Choi
*
***/

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;


/****************************************************************************
*
*   CHttpClient
*
***/

class CHttpClient {
public:
    CHttpClient (
        boost::asio::io_service & ioService,
        const string &            server,
        const string &            path
    );

private:
    void DoResolve (
        const boost::system::error_code &        err,
        boost::asio::ip::tcp::resolver::iterator iter
    );
    void DoConnect (
        const boost::system::error_code &        err,
        boost::asio::ip::tcp::resolver::iterator iter
    );
    void DoWriteRequest (const boost::system::error_code & err);
    void DoReadStatusLine (const boost::system::error_code & err);
    void DoReadHeaders (const boost::system::error_code & err);
    void DoReadContent (const boost::system::error_code & err);

private:
    boost::asio::ip::tcp::resolver m_resolver;
    boost::asio::ip::tcp::socket   m_socket;
    boost::asio::streambuf         m_request;
    boost::asio::streambuf         m_response;
};

//===========================================================================
CHttpClient::CHttpClient (
    boost::asio::io_service & ioService,
    const string &            server,
    const string &            path
) : m_resolver(ioService)
  , m_socket(ioService)
{
    ostream requestStream(&m_request);
    requestStream<<"GET "<<path<<" HTTP/1.0\r\n";
    requestStream<<"Host: "<<server<<"\r\n";
    requestStream<<"Accept: */*\r\n";
    requestStream<<"Connection: close\r\n\r\n";

    boost::asio::ip::tcp::resolver::query query(server, "http");
    auto handler = boost::bind(
        &CHttpClient::DoResolve,
        this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::iterator
    );
    m_resolver.async_resolve(query, handler);
}

//===========================================================================
void CHttpClient::DoResolve (
    const boost::system::error_code &        err,
    boost::asio::ip::tcp::resolver::iterator iter
) {
    if (err) {
        printf("%s\n", __FUNCTION__);
        cout<<"Error: "<<err.message()<<endl;
        return;
    }

    boost::asio::ip::tcp::endpoint endPoint = *iter;
    auto handler = boost::bind(
        &CHttpClient::DoConnect,
        this,
        boost::asio::placeholders::error,
        ++iter
    );
    m_socket.async_connect(endPoint, handler);
}

//===========================================================================
void CHttpClient::DoConnect (
    const boost::system::error_code &        err,
    boost::asio::ip::tcp::resolver::iterator iter
) {
    if (err) {
        if (iter != boost::asio::ip::tcp::resolver::iterator()) {
            m_socket.close();
            boost::asio::ip::tcp::endpoint endPoint = *iter;
            auto handler = boost::bind(
                &CHttpClient::DoConnect,
                this,
                boost::asio::placeholders::error,
                ++iter
            );
            m_socket.async_connect(endPoint, handler);
        } else {
            printf("%s\n", __FUNCTION__);
            cout<<"Error: "<<err.message()<<endl;
        }
        return;
    }

    auto handler = boost::bind(
        &CHttpClient::DoWriteRequest,
        this,
        boost::asio::placeholders::error
    );
    boost::asio::async_write(m_socket, m_request, handler);
}

//===========================================================================
void CHttpClient::DoWriteRequest (const boost::system::error_code & err) {
    if (err) {
        printf("%s\n", __FUNCTION__);
        cout<<"Error: "<<err.message()<<endl;
        return;
    }

    auto handler = boost::bind(
        &CHttpClient::DoReadStatusLine,
        this,
        boost::asio::placeholders::error
    );
    boost::asio::async_read_until(m_socket, m_response, "\r\n", handler);
}

//===========================================================================
void CHttpClient::DoReadStatusLine (const boost::system::error_code & err) {
    if (err) {
        printf("%s\n", __FUNCTION__);
        cout<<"Error: "<<err.message()<<endl;
        return;
    }

    istream responseStream(&m_response);
    string httpVersion;
    responseStream>>httpVersion;
    unsigned statusCode;
    responseStream>>statusCode;
    string statusMessage;
    getline(responseStream, statusMessage);
    if (!responseStream || httpVersion.substr(0, 5) != "HTTP/") {
        cout<<"Invalid response"<<endl;
        return;
    }

    if (statusCode != 200) {
        cout<<"Response returned with status code ";
        cout<<statusCode<<endl;
        return;
    }

    auto handler = boost::bind(
        &CHttpClient::DoReadHeaders,
        this,
        boost::asio::placeholders::error
    );
    boost::asio::async_read_until(
        m_socket,
        m_response,
        "\r\n\r\n",
        handler
    );
}

//===========================================================================
void CHttpClient::DoReadHeaders (const boost::system::error_code & err) {
    if (err) {
        printf("%s\n", __FUNCTION__);
        cout<<"Error: "<<err.message()<<endl;
        return;
    }

    istream responseStream(&m_response);
    string header;
    while (getline(responseStream, header) && header != "\r")
        cout<<header<<endl;
    cout<<endl;

    if (m_response.size() > 0)
        cout<<&m_response;

    auto handler = boost::bind(
        &CHttpClient::DoReadContent,
        this,
        boost::asio::placeholders::error
    );
    boost::asio::async_read(
        m_socket,
        m_response,
        boost::asio::transfer_at_least(1),
        handler
    );
}

//===========================================================================
void CHttpClient::DoReadContent (const boost::system::error_code & err) {
    if (err) {
        if (err != boost::asio::error::eof){
            printf("%s\n", __FUNCTION__);
            cout<<"Error: "<<err.message()<<endl;
        }
        return;
    }

    cout<<&m_response;

    auto handler = boost::bind(
        &CHttpClient::DoReadContent,
        this,
        boost::asio::placeholders::error
    );
    boost::asio::async_read(
        m_socket,
        m_response,
        boost::asio::transfer_at_least(1),
        handler
    );
}

//===========================================================================
int main (int argc, char * argv[]) {
    try {
        if (argc != 3) {
            cout<<"Usage:: async client <server> <path>"<<endl;
            cout<<"Example:"<<endl;
            cout<<"    async_client www.boost.org /LICENSE_1_0.txt"<<endl;
            return 1;
        }

        boost::asio::io_service ioService;
        CHttpClient httpClient(ioService, argv[1], argv[2]);
        ioService.run();

        printf("completed\n");
    } catch (exception & e) {
        cout<<"Exception: "<<e.what()<<endl;
    }

    return 0;
}
