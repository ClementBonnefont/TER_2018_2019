#include "machineaetat.h"

MachineAEtat::MachineAEtat(MainWindow* w, ProtoInterface* wSimu)
{
    this->etatPresent = ATTENTE;
    this->ihm = w;
    this->ihmSimu = wSimu;
    this->ihmSimu->setLabelEtatPresent(this->etatPresent); //Simulation
    this->ihmSimu->setLabelLigne(InterfaceDonnees::LIGNES_EN_COURS+1); //Simulation
}

bool MachineAEtat::finTempo() {
    QTime timeTemp = QTime::currentTime();
    return (this->time.secsTo(timeTemp) > 3);
}

void MachineAEtat::lancerTempo() {
    this->time = QTime::currentTime();
}

void MachineAEtat::pilotageEA() {
    Communication::digitalWriteSPI(listToHexa(this->vectLigne));
}

void MachineAEtat::resetEA() {
    Communication::digitalWriteSPI(0);
}

void MachineAEtat::calculProchaineLigne() {
    if(InterfaceDonnees::SENS_NORMAL) {
        InterfaceDonnees::LIGNES_EN_COURS++;
        if(InterfaceDonnees::LIGNES_EN_COURS >= InterfaceDonnees::CARTON_EN_COURS->getNbLigne())
            InterfaceDonnees::LIGNES_EN_COURS = 0;
    }
    else {
        InterfaceDonnees::LIGNES_EN_COURS--;
        if(InterfaceDonnees::LIGNES_EN_COURS < 0)
                InterfaceDonnees::LIGNES_EN_COURS = InterfaceDonnees::CARTON_EN_COURS->getNbLigne() - 1;
    }
}

unsigned long MachineAEtat::listToHexa(QList<int> l) {
    unsigned long hexaReturn = 0x00;
    for(int  i = 0; i < 24; i++) {
        hexaReturn += l[i] << i;
    }
    return hexaReturn;
}

void MachineAEtat::activer() {
    //BLOC F
    if(this->etatPresent == ATTENTE) {
        if(InterfaceDonnees::URGENCE) {
            InterfaceDonnees::URGENCE = false;
            this->etatSuivant = ETAT_URGENCE;
        }
        else if(InterfaceDonnees::DEBUT) {
            InterfaceDonnees::DEBUT = false;
            this->vectLigne = InterfaceDonnees::CARTON_EN_COURS->getLigneNoirBlanc(InterfaceDonnees::LIGNES_EN_COURS);
            lancerTempo();
            this->etatSuivant = PILOTAGE_ELECTROAIMANT;
        }
        else
            this->etatSuivant = this->etatPresent;
    }
    else if(this->etatPresent == PILOTAGE_ELECTROAIMANT) {
        if(InterfaceDonnees::URGENCE) {
            InterfaceDonnees::URGENCE = false;
            this->etatSuivant = ETAT_URGENCE;
        }
        else if(InterfaceDonnees::FIN) {
            InterfaceDonnees::FIN = false;
            InterfaceDonnees::LIGNES_EN_COURS = 0;
            this->ihm->emit refreshLigne();
            this->etatSuivant = ATTENTE;
        }
        else if(InterfaceDonnees::PAUSE || finTempo()) {
            InterfaceDonnees::PAUSE = true;
            this->ihm->emit refreshBouton();
            this->etatSuivant = ETAT_PAUSE;
        }
        else if(/*InterfaceSimu::valTOR*/ Communication::digitalReadValTor() && !finTempo()) {
            this->etatSuivant = PROCHAINE_LIGNE;
        }
        else
            this->etatSuivant = this->etatPresent;
    }
    else if(this->etatPresent == ETAT_PAUSE) {
        if(InterfaceDonnees::URGENCE) {
            InterfaceDonnees::URGENCE = false;
            InterfaceDonnees::PAUSE = false;
            this->ihm->emit refreshBouton();
            this->etatSuivant = ETAT_URGENCE;
        }
        else if(InterfaceDonnees::FIN) {
            InterfaceDonnees::FIN = false;
            InterfaceDonnees::PAUSE = false;
            this->ihm->emit refreshBouton();
            InterfaceDonnees::LIGNES_EN_COURS = 0;
            this->ihm->emit refreshLigne();
            this->etatSuivant = ATTENTE;
        }
        else if(InterfaceDonnees::REPRISE) {
            InterfaceDonnees::REPRISE = false;
            InterfaceDonnees::PAUSE = false;
            this->ihm->emit refreshBouton();
            lancerTempo();
            this->etatSuivant = PILOTAGE_ELECTROAIMANT;
        }
        else
            this->etatSuivant = this->etatPresent;
    }
    else if(this->etatPresent == PROCHAINE_LIGNE) {
        if(InterfaceDonnees::URGENCE) {
            InterfaceDonnees::URGENCE = false;
            this->etatSuivant = ETAT_URGENCE;
        }
        else if(InterfaceDonnees::FIN) {
            InterfaceDonnees::FIN = false;
            InterfaceDonnees::LIGNES_EN_COURS = 0;
            this->ihm->emit refreshLigne();
            this->etatSuivant = ATTENTE;
        }
        else if(InterfaceDonnees::PAUSE) {
            this->ihm->emit refreshBouton();
            this->etatSuivant = ETAT_PAUSE;
        }
        else if(!/*InterfaceSimu::valTOR*/Communication::digitalReadValTor()) {
            calculProchaineLigne();
            this->ihm->emit refreshLigne();
            this->vectLigne = InterfaceDonnees::CARTON_EN_COURS->getLigneNoirBlanc(InterfaceDonnees::LIGNES_EN_COURS);
            lancerTempo();
            this->etatSuivant = PILOTAGE_ELECTROAIMANT;
        }
        else
            this->etatSuivant = this->etatPresent;
    }
    else if(etatPresent == ETAT_URGENCE) {
        if(InterfaceDonnees::CARTON_EN_COURS->getChemin() == "" || InterfaceDonnees::FIN) {
            InterfaceDonnees::FIN = false;
            InterfaceDonnees::LIGNES_EN_COURS = 0;
            this->ihm->emit refreshLigne();
            this->etatSuivant = ATTENTE;
        }
        else if(InterfaceDonnees::REDEMARRAGE) {
            InterfaceDonnees::REDEMARRAGE = false;
            InterfaceDonnees::PAUSE = true;
            this->ihm->emit refreshBouton();
            etatSuivant = ETAT_PAUSE;
        }
        else
            this->etatSuivant = this->etatPresent;
    }

    //Simulation
    if(this->etatPresent != this->etatSuivant) {
        if(this->etatSuivant == PILOTAGE_ELECTROAIMANT) {
            for(int i = 0; i < 24; i++) {
                if(this->vectLigne[i] == 0) {
                    InterfaceSimu::valEA[i] = false;
                }
                else {
                    InterfaceSimu::valEA[i] = true;
                }
            }
            this->ihmSimu->emit refreshCadres();
        }
        else if(this->etatPresent == PILOTAGE_ELECTROAIMANT) {
            for(int i = 0; i < 24; i++) {
                InterfaceSimu::valEA[i] = false;
            }
            this->ihmSimu->emit refreshCadres();
        }
        this->ihmSimu->setLabelEtatPresent(this->etatSuivant);
        this->ihmSimu->setLabelLigne(InterfaceDonnees::LIGNES_EN_COURS+1);
    }

    //BLOC M
    this->etatPresent = this->etatSuivant;

    //BLOC G
    if(this->etatPresent == PILOTAGE_ELECTROAIMANT)
        pilotageEA();
    else
        resetEA();
}
