#ifndef THREADMAE_H
#define THREADMAE_H

#include <QThread>
#include "machineaetat.h"
#include "IHM/mainwindow.h"

class ThreadMae : public QThread
{

    private :
        MachineAEtat *mae;
        ProtoInterface* proto;
        MainWindow* ihm;

    public:
        ThreadMae(MainWindow* w, ProtoInterface* proto, MachineAEtat* mae);
        void run();
};

#endif // THREADMAE_H
