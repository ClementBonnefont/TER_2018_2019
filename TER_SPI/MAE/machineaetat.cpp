#include "machineaetat.h"

MachineAEtat::MachineAEtat()
{
    this->etatPresent = ATTENTE;
    this->memoEtat = ATTENTE;
}

bool MachineAEtat::finTempo() {
    QTime timeTemp = QTime::currentTime();
    return (time.secsTo(timeTemp) > 3);
}

void MachineAEtat::pilotageEA() {
    for(int i = 0; i < 24; i++) {
        if(vectLigne[i] == 0) {
            InterfaceSimu::valEA[i] = false;
        }
        else {
            InterfaceSimu::valEA[i] = true;
        }
    }
    SPI::digitalWriteSPI(listToHexa(this->vectLigne)); // On envoie sur le bus spi les lignes a
                                                       //commuter pour suivre le carton
}

void MachineAEtat::resetEA() {
    for(int i = 0; i < 24; i++) {
        InterfaceSimu::valEA[i] = false;
    }
    SPI::digitalWriteSPI(0);
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
        hexaReturn += l[i] << (i);
    }
    return hexaReturn;
}

void MachineAEtat::activer() {
    //BLOC F
    if(etatPresent == ATTENTE) {
        if(InterfaceDonnees::URGENCE) {
            InterfaceDonnees::URGENCE = false;
            memoEtat = etatPresent;
            etatSuivant = ETAT_URGENCE;
        }
        else if(InterfaceDonnees::DEBUT) {
            InterfaceDonnees::DEBUT = false;
            vectLigne = InterfaceDonnees::CARTON_EN_COURS->getLigneNoirBlanc(InterfaceDonnees::LIGNES_EN_COURS);
            time = QTime::currentTime();
            etatSuivant = PILOTAGE_ELECTROAIMANT;
        }
        else
            etatSuivant = etatPresent;
    }
    else if(etatPresent == PILOTAGE_ELECTROAIMANT) {
        if(InterfaceDonnees::URGENCE) {
            InterfaceDonnees::URGENCE = false;
            memoEtat = ETAT_PAUSE;
            etatSuivant = ETAT_URGENCE;
        }
        else if(InterfaceDonnees::FIN) {
            InterfaceDonnees::FIN = false;
            etatSuivant = ATTENTE;
        }
        else if(InterfaceDonnees::PAUSE /*|| finTempo()*/)
            etatSuivant = ETAT_PAUSE;
        else if(TOR::digitalReadValTor() /*InterfaceSimu::valTOR*/ /*&& !finTempo()*/)
            etatSuivant = PROCHAINE_LIGNE;
        else
            etatSuivant = etatPresent;
    }
    else if(etatPresent == ETAT_PAUSE) {
        if(InterfaceDonnees::URGENCE) {
            InterfaceDonnees::URGENCE = false;
            memoEtat = etatPresent;
            etatSuivant = ETAT_URGENCE;
        }
        else if(InterfaceDonnees::FIN) {
            InterfaceDonnees::FIN = false;
            etatSuivant = ATTENTE;
        }
        else if(InterfaceDonnees::REPRISE) {
            InterfaceDonnees::REPRISE = false;
            time = QTime::currentTime();
            etatSuivant = PILOTAGE_ELECTROAIMANT;
        }
        else
            etatSuivant = etatPresent;
    }
    else if(etatPresent == PROCHAINE_LIGNE) {
        if(InterfaceDonnees::URGENCE) {
            InterfaceDonnees::URGENCE = false;
             memoEtat = ETAT_PAUSE;
            etatSuivant = ETAT_URGENCE;
        }
        else if(InterfaceDonnees::FIN) {
            InterfaceDonnees::FIN = false;
            etatSuivant = ATTENTE;
        }
        else if(InterfaceDonnees::PAUSE)
            etatSuivant = ETAT_PAUSE;
        else if(!TOR::digitalReadValTor() /*!InterfaceSimu::valTOR*/) {
            calculProchaineLigne();
            vectLigne = InterfaceDonnees::CARTON_EN_COURS->getLigneNoirBlanc(InterfaceDonnees::LIGNES_EN_COURS);
            time = QTime::currentTime();
            etatSuivant = PILOTAGE_ELECTROAIMANT;
        }
        else
            etatSuivant = etatPresent;
    }
    else if(etatPresent == ETAT_URGENCE) {
        if(InterfaceDonnees::FIN) {
            InterfaceDonnees::FIN = false;
            etatSuivant = ATTENTE;
        }
        else if(InterfaceDonnees::REDEMARRAGE) {
            InterfaceDonnees::REDEMARRAGE = false;
            etatSuivant = memoEtat;
        }
        else
            etatSuivant = etatPresent;
    }

    //BLOC M
    etatPresent = etatSuivant;

    //BLOC G
    if(etatPresent == ATTENTE)
        InterfaceDonnees::LIGNES_EN_COURS = 0;

    if(etatPresent == ETAT_PAUSE)
        InterfaceDonnees::PAUSE = true;
    else
        InterfaceDonnees::PAUSE = false;

    if(etatPresent == PILOTAGE_ELECTROAIMANT)
        pilotageEA();
    else
        resetEA();
}

int MachineAEtat::getEtatPresent() {
    return this->etatPresent;
}
