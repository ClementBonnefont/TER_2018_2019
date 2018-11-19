#ifndef CARTON_H
#define CARTON_H

#include <QImage>
#include <QList>

class Carton
{
private:
    int nbLigne;
    int nbColonne;
    QList<QList<int>> matMotif;

public:
    Carton();
    QList<int> getLigne(int);
    bool finCarton(int);
};

#endif // CARTON_H
