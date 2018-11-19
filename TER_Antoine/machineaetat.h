#ifndef MACHINEAETAT_H
#define MACHINEAETAT_H

#include <QTimer>
#include "interfacedonnees.h"

#define ATTENTE 0
#define PILOTAGE_ELECTROAIMANT 1
#define TEMPS_ECOULE 2
#define PROCHAINE_LIGNE 3
#define FIN_TISSAGE 4
#define ETAT_URGENCE 5

class MachineAEtat
{
private :
    int etatPresent;
    int etatSuivant;
    QTimer timer;
    bool tor;
    int memoEtat;
    int* vectLigne;

public:
    MachineAEtat();
    void lancerTimer(int);
    int getTimeTimer();
    bool finTempo();
    void pilotageEA();
    void activer();
    int getEtatPresent();
};

#endif // MACHINEAETAT_H
