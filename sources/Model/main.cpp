#include "carton.h"
#include "memoire.h"
#include "interfacedonnees.h"
#include <QApplication>
#include <QTextStream>
#include <iostream>

using namespace std;
int main (int argc, char* argv[]) {

    //QApplication a(argc, argv);
    //return a.exec();
    Carton c("C:\\Users\\clement\\Desktop\\TER\\carton6x8","carton6x8","26/11/2018");
    c.charger("C:\\Users\\clement\\Desktop\\TER\\carton6x8");
    c.afficheMatriceNoirBlanc();
    c.affichageCarton();
    InterfaceDonnees::CARTON_EN_COURS = c;
    InterfaceDonnees::LIGNES_EN_COURS = 4;
    InterfaceDonnees::MEMO_ETAT_PRESENT = 2;
    Memoire::SAVE_MEMOIRE();
}
