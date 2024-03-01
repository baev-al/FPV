#include "workerthread.h"

void WorkerThread::run()
{
    while(1)
    {
        if(threadSetterMode == SetterMode::MPU_Data)
        {
            if(requestIsNeeded)
            {
                requestIsNeeded = false;
                emit requestAccGyroData();
                //threadTimer.start(100);
                QTimer::singleShot(100, this, &WorkerThread::changeRequestStatus);
            }
        }
    }
}

WorkerThread::WorkerThread()
{
    threadTimer.setSingleShot(true);
    requestIsNeeded = true;

    connect(&threadTimer, &QTimer::timeout, this, &WorkerThread::changeRequestStatus);
}

void WorkerThread::setMode(SetterMode sm)
{
    threadSetterMode = sm;
}

void WorkerThread::changeRequestStatus()
{
    requestIsNeeded = true;
}
