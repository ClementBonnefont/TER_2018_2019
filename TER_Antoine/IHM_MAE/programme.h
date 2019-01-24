#ifndef PROGRAMME_H
#define PROGRAMME_H
#include <stdio.h>

#include "Model/interfacedonnees.h"
#include "interfacesimu.h"

#define NB_CADRE 24

class Programme
{
public:
    Programme();
    void debutTissage();
    void finTissage();
    void pauseTissage();
    void repriseTissage();
    void urgenceTissage();
    void retourTissage();
    void setTor(bool);
    void setCadre(int);
    void setSens(bool);
};

#endif // PROGRAMME_H
