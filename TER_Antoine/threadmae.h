#ifndef THREADMAE_H
#define THREADMAE_H

#include <QThread>
#include "machineaetat.h"

class ThreadMae : public QThread
{

    private :
        MachineAEtat mae;

    public:
        ThreadMae(QObject * parent = NULL);
        void run();
};

#endif // THREADMAE_H
