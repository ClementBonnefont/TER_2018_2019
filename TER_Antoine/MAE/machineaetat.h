#ifndef MACHINEAETAT_H
#define MACHINEAETAT_H

#include <QTime>
#include "Model/interfacedonnees.h"
#include "IHM/mainwindow.h"

//Simulation
#include "IHM_MAE/protointerface.h"

//SPI
#include "spi.h"

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
    MainWindow* ihm;

public:
    MachineAEtat(MainWindow* ihm);
    bool finTempo();
    void pilotageEA();
    void resetEA();
    void activer();
    int getEtatPresent();
    void calculProchaineLigne();
    unsigned long listToHexa(QList<int> l);
};

#endif // MACHINEAETAT_H
