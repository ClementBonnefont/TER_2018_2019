#ifndef MACHINEAETAT_H
#define MACHINEAETAT_H

#include <QTime>
#include "interfacedonnees.h"

//Simulation
#include "../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.h"

#define ATTENTE 0
#define PILOTAGE_ELECTROAIMANT 1
#define ETAT_PAUSE 2
#define PROCHAINE_LIGNE 3
#define ETAT_URGENCE 4

class MachineAEtat
{
private :
    int etatPresent;
    int etatSuivant;
    int memoEtat;
    QList<int> vectLigne;
    QTime time;

public:
    MachineAEtat();
    bool finTempo();
    void pilotageEA();
    void resetEA();
    void activer();
    int getEtatPresent();
    void calculProchaineLigne();
};

#endif // MACHINEAETAT_H
