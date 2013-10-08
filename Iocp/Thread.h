#ifdef THREAD_H 
#error "Header included more than once"
#endif
#define THREAD_H

#include <cstdio>
#include <Windows.h>
#include <process.h>
#include <cassert>


/****************************************************************************
*
*   IThread 
*
***/

class IThread {
public:
    virtual void Start () = 0;
    virtual void Suspend (bool isAlerable) = 0;
    virtual void Stop () = 0;
};

/****************************************************************************
*
*   CThread 
*
***/

typedef unsigned (* FThreadFunc) (
    void * argument
);

enum EThreadState {
    THREAD_STATE_RUNNING,
    THREAD_STATE_WAIT,
    THREAD_STATE_STOPPED,
    THREAD_STATE_ABORTED,

    THREAD_STATES,
};

class CThread : public IThread {
public:
    CThread (
        FThreadFunc    threadProc,
        void *         argument,
        const wchar_t * name
    );
    ~CThread ();

    // IThread interface
    void Start ();
    void Suspend (bool isAlertable);
    void Stop ();

private:
    static unsigned __stdcall ThreadBaseProc (void * argument);

    FThreadFunc m_threadProc;
    void *      m_argument;
    wchar_t     m_name[256];
    HANDLE      m_handle;
    unsigned    m_threadId;
};
