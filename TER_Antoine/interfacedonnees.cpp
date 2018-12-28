#include "interfacedonnees.h"

int InterfaceDonnees::LIGNES_EN_COURS = 0;
Carton* InterfaceDonnees::CARTON_EN_COURS = new Carton;
bool InterfaceDonnees::DEBUT = false;
bool InterfaceDonnees::FIN = false;
bool InterfaceDonnees::PAUSE = false;
bool InterfaceDonnees::REPRISE = false;
bool InterfaceDonnees::URGENCE = false;
int InterfaceDonnees::MEMO_ETAT_PRESENT = 0;
bool InterfaceDonnees::SENS_NORMAL = true;
bool InterfaceDonnees::REDEMARRAGE = false;
