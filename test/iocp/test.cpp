#include "Thread.h"

#define MAX_THREADS 4

static unsigned s_threadPoolSize;
static HANDLE   s_ioPort;
static HANDLE   s_threads[MAX_THREADS];

const unsigned MAX_BUF = 1024;
char s_buf[MAX_BUF];

enum EOpType {
    OP_COMPUTE,

    OP_FILE_READ,
    OP_FILE_WRITE,

    OP_SOCKET_CONNECT,
    OP_SOCKET_READ,
    OP_SOCKET_WRITE,

    OP_TERMINATE,

    OP_TYPES,
};

struct IocpOp : public OVERLAPPED {
public:
    IocpOp (EOpType type = OP_TYPES);

    EOpType type;
};

IocpOp::IocpOp (EOpType type)
 : type(type)
{
    // Offset, OffsetHigh, hEvent should be initialized
    Offset     = 0;
    OffsetHigh = 0;
    hEvent     = NULL;
}

void DoCompute (IocpOp * op) {
    printf("%s called\n", __FILE__);
}

void DoFileRead (IocpOp * op) {
    printf("%s called\n", __FILE__);
    unsigned readBytes = op->InternalHigh;
    printf("readBytes : %u\n", readBytes);
    printf("-----------------------\n");
    for (unsigned i = 0; i < 100; i++)
        printf("%c", s_buf[i]);
    printf("\n");
    printf("-----------------------\n");
}

unsigned CALLBACK ThreadFunction (LPVOID param) {
    unsigned threadId = (unsigned)param;
    bool isRunning = true;
    while (isRunning) {
        DWORD count;
        IocpOp * op;
        HANDLE completionKey = NULL;
        unsigned result = GetQueuedCompletionStatus(
            s_ioPort,
            &count,
            (PULONG_PTR)&completionKey,
            (LPOVERLAPPED *)&op,
            INFINITE
        );
        printf("thread id : %u\n", threadId);
        Sleep(100);
        if (result == FALSE) {
            printf("GetQueuedCompletionStatus failed!\n");
            printf("error code : %d\n", GetLastError());
            break;
        }
        switch (op->type) {
            case OP_COMPUTE:
                DoCompute(op);
                break;
            case OP_FILE_READ:
                DoFileRead(op);
                break;
            case OP_FILE_WRITE:
            case OP_SOCKET_CONNECT:
            case OP_SOCKET_READ:
            case OP_SOCKET_WRITE:
                printf("not implemented operation type\n");
                break;
            case OP_TERMINATE:
                printf("terminated called!\n");
                isRunning = false;
                break;
            default:
                assert(0);
        }
    }
    return 0;
}

int main () {
    // create io completion port handle
    s_ioPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, 0);
    if (s_ioPort == NULL) {
        printf("CreateIoCompletionPort failed\n");
        exit(1);
    }

    s_threadPoolSize = MAX_THREADS;

    // create thread
    for (unsigned i = 0; i < s_threadPoolSize; i++) {
        unsigned threadId;
        s_threads[i] = (HANDLE)_beginthreadex(
            NULL,
            0,
            ThreadFunction,
            LPVOID(i), // argument
            CREATE_SUSPENDED,
            &threadId
        );
    }

    // start thread
    for (unsigned i = 0; i < s_threadPoolSize; i++)
        ResumeThread(s_threads[i]);

    HANDLE hFile = CreateFile(
        "text.txt",
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_OVERLAPPED | FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    if (hFile == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "CreateFile() failed\n");
        exit(1);
    }

    // associates file handle with iocp
    if (!CreateIoCompletionPort(hFile, s_ioPort, NULL, NULL)) {
        fprintf(stderr, "associating file handle with iocp failed!\n");
        exit(1);
    }

    IocpOp * op = new IocpOp(OP_FILE_READ);
    // otherwise, ReadFile fails
    unsigned result = ReadFile(
        hFile,
        s_buf,
        MAX_BUF-1,
        NULL,
        op
    );
    if (result == FALSE) {
        unsigned err = GetLastError();
        if (err == ERROR_IO_PENDING) {
            printf("overlapped io started\n");
        } else {
            printf("error code : %u\n", err);
            exit(1);
        }
    }

    for (unsigned i = 0; i < 10; i++) {
        Sleep(100);
        IocpOp computeOp(OP_COMPUTE);
        PostQueuedCompletionStatus(
            s_ioPort,
            0,
            0,
            &computeOp
        );
    }

    printf("main thread done!\n");
    printf("wait for all thread to finish the work from completion port\n");

    for (unsigned i = 0; i < s_threadPoolSize; i++) {
        IocpOp terminateOp(OP_TERMINATE);
        PostQueuedCompletionStatus(
            s_ioPort,
            0,
            0,
            &terminateOp
        );
    }

    // wait for all thread to be terminated
    for (unsigned i = 0; i < s_threadPoolSize; i++)
        WaitForSingleObject(s_threads[i], INFINITE);
    
    CloseHandle(s_ioPort);
    for (unsigned i = 0; i < s_threadPoolSize; i++)
        CloseHandle(s_threads[i]);

    // where is the best moment to close this file handle
    CloseHandle(hFile);

    return 0;
}
