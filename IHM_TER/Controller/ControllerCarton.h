#ifndef CONTROLLERCARTON_H
#define CONTROLLERCARTON_H

#include <QImage>
#include <QList>
#include <iostream>
#include "../Model/carton.h"

using namespace std;

class ControllerCarton
{
private:
   Carton carton;
public:
    ControllerCarton(string chemin = "", string nom = "", string date = "", int nbL = 0);
    ControllerCarton(ControllerCarton&);
    QList<Couleur> getLigne(int ligne);
    void charger(string chemin);
    void editCarton(int ligne, int colonne, Couleur couleur);
    void saveCarton();
    void saveCartonAs(string chemin, string nom);
    bool finCarton(int ligne);
    QList<int> getLigneNoirBlanc(int ligne);
    QList<QList<int>> getMatriceNoirBlanc();
    QList<QList<Couleur>> getMatrice();
    Carton getCarton();
    int getNbColonneConnue();
    int getNbLigne();

};

#endif // CONTROLLERCARTON_H
