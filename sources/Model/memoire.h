#ifndef MEMOIRE_H
#define MEMOIRE_H
#include <iostream>
#include "carton.h"
#include <QThread>
#include <QDir>
using namespace std;



//ce model enregistre la ligne en cours, le carton en cours
class Memoire
{

public:
    static bool CHARGE_MEMOIRE();
    static bool SAVE_MEMOIRE();

    static string REPERTOIRE_DE_SAUVEGARDE;

};

#endif // MEMOIRE_H
