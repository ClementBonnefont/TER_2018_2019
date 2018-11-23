#ifndef CARTON_H
#define CARTON_H

#include <QImage>
#include <QList>
#include <iostream>
#include "couleur.h"

using namespace std;

class Carton
{
private:
    string chemin;
    string nom;
    string date;
    int nbLigne;
    int nbColonne;
    QList<QList<Couleur>> matrice;

public:
    Carton(string chemin = "", string nom = "", string date = "", int nbL = 0, int nbC = 0);
    QList<Couleur> getLigne(int);
    void charger();
    void editCarton(int, int, Couleur);
    void affichageCarton();
    void saveCarton();
    void saveCartonAs(string, string);
    bool finCarton(int);
    QList<int> getLigneNoirBlanc(int);
};

#endif // CARTON_H
