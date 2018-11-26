#ifndef CARTON_H
#define CARTON_H

#include <QImage>
#include <QList>
#include <iostream>
#include "couleur.h"
#include <QDebug>

using namespace std;

class Carton
{
private:
    string chemin;
    string nom;
    string date;
    int nbLigne;
    const int nbColonne = 24;
    QList<QList<Couleur>> matrice;

public:
    Carton(string chemin = "", string nom = "", string date = "", int nbL = 0);
    Carton(Carton&);
    QList<Couleur> getLigne(int);
    void charger();
    void editCarton(int, int, Couleur);
    void affichageCarton();
    void saveCarton();
    void saveCartonAs(string, string);
    bool finCarton(int);
    QList<int> getLigneNoirBlanc(int);
    QList<QList<int>> getMatriceNoirBlanc();
    void afficheMatriceNoirBlanc();
    Carton operator=(Carton);
    QList<QList<Couleur>> getMatrice();

};

#endif // CARTON_H
