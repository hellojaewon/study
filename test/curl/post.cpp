
// URIs
// login (https) : https://www.letskorail.com/korail/com/loginAction.do
// list stations : http://www.letskorail.com/ebizprd/EbizPrdTicketPr11100/searchTnCode.do?hidOpener=txtGoStart
// search ticket : http://www.letskorail.com/ebizprd/EbizPrdTicketPr21111_i1.do
// reservation   :
#include <cstdio>
#include <cstring>
#include <curl/curl.h>

struct TicketPostBody {
    const char * name;
    const char * value;
};

static char LOGIN_URL[]         = "https://www.letskorail.com/korail/com/loginAction.do";
static char LIST_STATIONS_URL[] = "http://www.letskorail.com/ebizprd/EbizPrdTicketPr11100/searchTnCode.do?hidOpener=txtGoStart";
static char TICKET_SEARCH_URL[] = "http://www.letskorail.com/ebizprd/EbizPrdTicketPr21111_i1.do";

TicketPostBody loginBodies[] = {
    { "UserPwd",          ""                                    },
    { "UserId",           ""                                    },
    { "txtTotCnt",        ""                                    },
    { "txtIvntDt",        ""                                    },
    { "txtHaeRang",       ""                                    },
    { "txtDv",            "1"                                   },
    { "txtBookCnt",       ""                                    },
    { "selValues",        ""                                    },
    { "selInputFlg",      "2"                                   },
    { "ret_url",          ""                                    },
    { "RelayState",       "/ebizsso/sso/sp/service_front.jsp"   },
    { "radIngrDvCd",      "2"                                   },
    { "providerName",     "Ebiz Sso"                            },
    { "loginForm",        "http://www.letskorail.com:80/ebizsso/sso/ip/login_form.jsp"  },
    { "IPType",           "Ebiz Sso Identity Provider"          },
    { "hidMemberFlg",     "1"                                   },
    { "hidEmailAdr",      ""                                    },
    { "forwardingURI",    "/ebizsso/sso/sp/service_proc.jsp"    },
    { "acsURI",           "http://www.letskorail.com:80/ebizsso/sso/acs"    },
};

TicketPostBody searchBodies[] = {
    { "txtGoStartCode",       ""                    },
    { "txtGoEndCode",         ""                    },
    { "radJobId",             "1"                   },
    { "selGoTrain",           "05"                  },
    { "txtSeatAttCd_4",       "15"                  },
    { "txtSeatAttCd_3",       "00"                  },
    { "txtSeatAttCd_2",       "00"                  },
    { "txtPsgFlg_2",          "0"                   },
    { "txtPsgFlg_3",          "0"                   },
    { "txtPsgFlg_4",          "0"                   },
    { "txtPsgFlg_5",          "0"                   },
    { "chkCpn",               "N"                   },
    { "selGoSeat1",           "15"                  },
    { "selGoSeat2",           ""                    },
    { "txtPsgCnt1",           "1"                   },
    { "txtPsgCnt2",           "0"                   },
    { "txtGoPage",            "1"                   },
    { "txtGoAbrdDt",          "20150221"            },
    { "selGoRoom",            ""                    },
    { "useSeatFlg",           ""                    },
    { "useServiceFlg",        ""                    },
    { "checkStnNm",           "Y"                   },
    { "txtMenuId",            "11"                  },
    { "SeandYo",              "N"                   },
    { "txtGoStartCode2",      ""                    },
    { "txtGoEndCode2",        ""                    },
    { "hidEasyTalk",          ""                    },
    { "txtGoStart",           "%EC%84%9C%EC%9A%B8"  },
    { "txtGoEnd",             "%EB%B6%80%EC%82%B0"  },
    { "start",                "2015.2.21"           },
    { "selGoHour",            "06"                  },
    { "txtGoHour",            "065500"              },
    { "selGoYear",            "2015"                },
    { "selGoMonth",           "02"                  },
    { "selGoDay",             "21"                  },
    { "txtGoYoil",            "%ED%99%94"           },
    { "txtPsgFlg_1",          "1"                   },
 };

void Login ();
void ListStations ();
void TicketSearch ();

int main(int argc, char ** argv) {
   int menu;
    printf("1. Login\n");
    printf("2. List Stations\n");
    printf("3. Ticket Search\n");
    scanf("%d", &menu);
    switch (menu) {
        case 1:
            Login();
            break;
        case 2:
            ListStations();
            break;
        case 3:
            TicketSearch();
            break;
    }

    return 0;
}

void Login () {
    CURL * curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (!curl) {
        printf("curl_eash_init() failed\n");
        return;
    }

    curl_easy_setopt(curl, CURLOPT_URL, LOGIN_URL);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

    char postData[1024+1] = {0,};
    for (unsigned i = 0; i < sizeof(loginBodies)/sizeof(loginBodies[0]); i++) {
        char tmp[256];
        char * name = curl_easy_escape(curl, loginBodies[i].name, 0);
        char * value = curl_easy_escape(curl, loginBodies[i].value, 0);
        sprintf(tmp, "%s=%s&", name, value);
        strcat(postData, tmp);
        curl_free(name);
        curl_free(value);
    }
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        printf(
            "curl_easy_perform failed(%s)\n",
            curl_easy_strerror(res)
        );
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

void ListStations () {
    CURL * curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (!curl) {
        printf("curl_easy_init() failed\n");
        return;
    }

    curl_easy_setopt(curl, CURLOPT_URL, LIST_STATIONS_URL);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        printf(
            "curl_easy_perform failed(%s)\n",
            curl_easy_strerror(res)
        );
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

void TicketSearch () {
    CURL * curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (!curl) {
        printf("curl_easy_init() failed\n");
        return;
    }

    curl_easy_setopt(curl, CURLOPT_URL, TICKET_SEARCH_URL);
    char postData[1024+1] = {0,};
    for (unsigned i = 0; i < sizeof(searchBodies)/sizeof(searchBodies[0]); i++) {
        char tmp[256];
        sprintf(tmp, "%s=%s&", searchBodies[i].name, searchBodies[i].value);
        strcat(postData, tmp);
    }
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        printf(
            "curl_easy_perform failed(%s)\n",
            curl_easy_strerror(res)
        );
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
}
