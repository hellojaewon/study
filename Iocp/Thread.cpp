#include "Thread.h"
#pragma  hdrstop

/****************************************************************************
*
*   CThread 
*
***/

CThread::CThread (
    FThreadFunc     threadProc,
    void *          argument,
    const wchar_t * name
) : m_handle(NULL),
    m_threadId(0)
{
    m_handle = (HANDLE)_beginthreadex(
        NULL,                       // security attribute
        0,                          // initial stack size
        CThread::ThreadBaseProc,    // start addres
        this,                       // argument
        CREATE_SUSPENDED,           // inital flag
        &m_threadId                 // thread id
    );
    if (!m_handle) {
        fprintf(stderr ,"_beginthreadex failed\n");
        exit(1);
    }
}

CThread::~CThread() {

}

void CThread::Start () {

}

void CThread::Suspend (bool isAlertable) {

}

void CThread::Stop () {

}

unsigned __stdcall CThread::ThreadBaseProc (void * argument) {
    CThread * thread = (CThread *)argument;

    unsigned result = thread->m_threadProc(thread->m_argument);

    return result;
}
