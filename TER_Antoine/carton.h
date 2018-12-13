#ifndef CARTON_H
#define CARTON_H

#include <QImage>
#include <QList>
#include <iostream>
#include <QDebug>

using namespace std;

class Carton
{
private:
    string chemin;
    string nom;
    string date;
    int nbLigne;
    int nbColonne;
    QList<QList<int>> matrice;

public:
    Carton(string chemin = "", string nom = "", string date = "", int nbL = 240, int nbC = 20);
    virtual ~Carton();
    QList<int> getLigne(int);
    void charger();
    void editCarton(int, string, string, string);
    void affichageCarton();
    void saveCarton(string);
    bool finCarton(int);
};

#endif // CARTON_H
