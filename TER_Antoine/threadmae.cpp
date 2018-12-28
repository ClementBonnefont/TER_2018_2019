#include "threadmae.h"

ThreadMae::ThreadMae(ProtoInterface* proto, MachineAEtat* mae) {
    this->mae = mae;
    this->proto = proto;
}

void ThreadMae::run() {
    int i = 0;
    while(isRunning()) {
        mae->activer();
        if(i == 200) {
            proto->emit refreshCadres();
            proto->setLabelEtatPresent(mae->getEtatPresent());
            proto->setLabelLigne(InterfaceDonnees::LIGNES_EN_COURS+1);
            i = 0;
        }
        i++;
    }
}
