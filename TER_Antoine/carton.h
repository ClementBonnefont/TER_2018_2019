#ifndef CARTON_H
#define CARTON_H

#include <QImage>
#include <QList>
#include <iostream>

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
    Carton(string chemin = "", string nom = "", string date = "", int nbL = 0, int nbC = 0);
    virtual ~Carton();
    QList<int> getLigne(int);
    void charger();
    void editCarton(int, string, string, string);
    void affichageCarton();
    void saveCarton(string);
    bool finCarton(int);
};

#endif // CARTON_H
