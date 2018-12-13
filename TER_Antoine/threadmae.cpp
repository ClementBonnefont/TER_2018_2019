#include "threadmae.h"
#include <QDebug>

ThreadMae::ThreadMae(ProtoInterface* proto, MachineAEtat* mae) {
    this->mae = mae;
    this->proto = proto;
}

void ThreadMae::run() {
    int i = 0;
    while(isRunning()) {
        mae->activer();
        if(i == 1000) {
            proto->emit refreshCadres();
            i = 0;
        }
        i++;
        proto->setLabel(mae->getEtatPresent());
    }
}
