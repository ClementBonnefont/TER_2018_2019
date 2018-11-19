#include "machineaetat.h"

MachineAEtat::MachineAEtat()
{
    etatPresent = 0;
    memoEtat = ATTENTE;
    tor = false; //Simulation
    vectLigne = new int[24];
    //vectLigne = InterfaceDonnees::CARTON_EN_COURS.getLigne(InterfaceDonnees::LIGNES_EN_COURS);
}

void MachineAEtat::lancerTimer(int time) {
    this->timer.start(time);
}

int MachineAEtat::getTimeTimer() {
    return this->timer.remainingTime();
}

bool MachineAEtat::finTempo() {
    return (this->getTimeTimer() == 0);
}

void MachineAEtat::pilotageEA() {

}

void MachineAEtat::activer() {
    //BLOC F
    if(etatPresent == ATTENTE) {
        if(InterfaceDonnees::URGENCE) {
            memoEtat = etatPresent;
            etatSuivant = ETAT_URGENCE;
        }
        else if(InterfaceDonnees::DEBUT)
            etatSuivant = PILOTAGE_ELECTROAIMANT;
        else
            etatSuivant = etatPresent;
    }
    else if(etatPresent == PILOTAGE_ELECTROAIMANT) {
        if(InterfaceDonnees::URGENCE) {
            memoEtat = etatPresent;
            etatSuivant = ETAT_URGENCE;
        }
        else if(tor && (finTempo() == false))
            etatSuivant = PROCHAINE_LIGNE;
        else if(InterfaceDonnees::PAUSE || finTempo())
            etatSuivant = TEMPS_ECOULE;
        else
            etatSuivant = etatPresent;
    }
    else if(etatPresent == TEMPS_ECOULE) {
        if(InterfaceDonnees::URGENCE) {
            memoEtat = etatPresent;
            etatSuivant = ETAT_URGENCE;
        }
        else if(InterfaceDonnees::REPRISE)
            etatSuivant = PILOTAGE_ELECTROAIMANT;
        else
            etatSuivant = etatPresent;
    }
    else if(etatPresent == PROCHAINE_LIGNE) {
        if(InterfaceDonnees::URGENCE) {
            memoEtat = etatPresent;
            etatSuivant = ETAT_URGENCE;
        }
        else if(1)//InterfaceDonnees::CARTON_EN_COURS.finCarton(InterfaceDonnees::LIGNES_EN_COURS))
            etatSuivant = FIN_TISSAGE;
        else
            etatSuivant = PILOTAGE_ELECTROAIMANT;
    }
    else if(etatPresent == FIN_TISSAGE) {
        if(InterfaceDonnees::URGENCE) {
            memoEtat = etatPresent;
            etatSuivant = ETAT_URGENCE;
        }
        else
            etatSuivant = ATTENTE;
    }
    else if(etatPresent == ETAT_URGENCE) {
        if(InterfaceDonnees::REPRISE)
            etatSuivant = memoEtat;
        else
            etatSuivant = etatPresent;
    }

    //BLOC M
    etatPresent = etatSuivant;

    //BLOC G
    if(etatPresent == PILOTAGE_ELECTROAIMANT) {
        pilotageEA();
    }
    else if(etatPresent == PROCHAINE_LIGNE) {
        InterfaceDonnees::LIGNES_EN_COURS++;
        //vectLigne = InterfaceDonnees::CARTON_EN_COURS.getLigne(InterfaceDonnees::LIGNES_EN_COURS);
    }
    else if(etatPresent == FIN_TISSAGE) {
        InterfaceDonnees::FIN = true;
    }
    else if(etatPresent == TEMPS_ECOULE) {
        InterfaceDonnees::PAUSE = true;
    }
}

int MachineAEtat::getEtatPresent() {
    return this->etatPresent;
}
