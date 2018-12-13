#ifndef THREADMAE_H
#define THREADMAE_H

#include <QThread>
#include "machineaetat.h"

class ThreadMae : public QThread
{

    private :
        MachineAEtat *mae;
        ProtoInterface* proto;

    public:
        ThreadMae(ProtoInterface* proto, MachineAEtat * mae = nullptr);
        void run();
};

#endif // THREADMAE_H
