#ifndef INTERFACEDONNEES_H
#define INTERFACEDONNEES_H

#include "Model/carton.h"

class InterfaceDonnees
{
public:
    static int LIGNES_EN_COURS;
    static Carton* CARTON_EN_COURS;
    static bool DEBUT;
    static bool FIN;
    static bool PAUSE;
    static bool REPRISE;
    static bool URGENCE;
    static int MEMO_ETAT_PRESENT;
    static bool SENS_NORMAL;
    static bool REDEMARRAGE;
};

#endif // INTERFACEDONNEES_H
