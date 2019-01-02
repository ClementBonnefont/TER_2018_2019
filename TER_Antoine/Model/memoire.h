#ifndef MEMOIRE_H
#define MEMOIRE_H
#include <iostream>
#include "carton.h"
#include "interfacedonnees.h"
using namespace std;


class Memoire
{

public:
    static bool CHARGE_MEMOIRE();
    static bool SAVE_MEMOIRE();

    static string REPERTOIRE_DE_SAUVEGARDE;

};

#endif // MEMOIRE_H
