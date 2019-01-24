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
    int nbColonneConnue;
    QList<QList<Couleur>> matrice;

public:
    Carton(string chemin = "", string nom = "", string date = "", int nbL = 0, int nbColonneConnue = 0);
    Carton(Carton&);
    QList<Couleur> getLigne(int ligne);
    void charger(string chemin);
    void editCarton(int ligne, int colonne, Couleur couleur);
    void affichageCarton();
    void saveCarton();
    void saveCartonAs(string chemin, string nom ="");
    bool finCarton(int ligne);
    QList<int> getLigneNoirBlanc(int ligne);
    QList<QList<int>> getMatriceNoirBlanc();
    void afficheMatriceNoirBlanc();
    Carton operator=(Carton);
    QList<QList<Couleur>> getMatrice();
    string getChemin();
    friend QTextStream& operator <<(QTextStream& out, Carton &c);
    int getNbColonneConnue();
    int getNbLigne();
};

#endif // CARTON_H
