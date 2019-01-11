#ifndef COULEUR_H
#define COULEUR_H
#include <iostream>

using namespace std;

class Couleur
{
private:
    int r;
    int g;
    int b;

public:
    Couleur(int r = 0, int g = 0, int b = 0);
    void setBlancNoir();
    bool isNoir();
    bool isBlanc();
    void setR(int);
    void setB(int);
    void setG(int);
    int getR();
    int getB();
    int getG();
    void editCouleur(int, int, int);
    void affichageCouleur();
    friend ostream& operator<<(ostream&,Couleur&);
};

#endif // COULEUR_H
