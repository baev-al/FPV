#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QTimer>
#include "structs.h"

class WorkerThread : public QThread
{
    Q_OBJECT
    void run() override;
    SetterMode threadSetterMode;
    QTimer threadTimer;
    bool requestIsNeeded;
public:
    WorkerThread();
public slots:
    void setMode(SetterMode sm);
    void changeRequestStatus();
signals:
    void requestAccGyroData();
};

#endif // WORKERTHREAD_H
