#include "threadmae.h"

ThreadMae::ThreadMae(MainWindow* w, ProtoInterface* proto, MachineAEtat* mae) {
    this->ihm = w;
    this->mae = mae;
    this->proto = proto;
}

void ThreadMae::run() {
    int i = 0;
    while(isRunning()) {
        mae->activer();
        if(i >= 200) {
            ihm->emit refreshBouton();
            proto->emit refreshCadres();
            proto->setLabelEtatPresent(mae->getEtatPresent());
            proto->setLabelLigne(InterfaceDonnees::LIGNES_EN_COURS+1);
            i = 0;
        }
        i++;
    }
}
