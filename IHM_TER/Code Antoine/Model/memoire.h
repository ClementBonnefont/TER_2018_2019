#ifndef MEMOIRE_H
#define MEMOIRE_H
#include <iostream>
#include "carton.h"
#include <QThread>
#include <QDir>
using namespace std;


//ce model enregistre la ligne en cours, le carton en cours
class Memoire : QThread
{
private:
    string repertoireDeSauvegarde;
    Carton cartonEnCours;
    int ligneEnCours;
public:
    Memoire(Carton, int ligne = 0, string = "");
    void startMemorisation();
    void stopMemorisation();
    void setCartonEnCours(Carton);
    void setLigneEnCours(int);
    void run() override;
};

#endif // MEMOIRE_H
