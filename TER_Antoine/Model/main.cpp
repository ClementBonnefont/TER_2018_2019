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
    //c.afficheMatriceNoirBlanc();
    //c.affichageCarton();
    //InterfaceDonnees::CARTON_EN_COURS;
    InterfaceDonnees::CARTON_EN_COURS.charger("C:\\Users\\clement\\Desktop\\TER\\carton6x8");
    InterfaceDonnees::LIGNES_EN_COURS = 4;
    InterfaceDonnees::MEMO_ETAT_PRESENT = 2;
    InterfaceDonnees::CARTON_EN_COURS.affichageCarton();

    Memoire::SAVE_MEMOIRE();
    Memoire::CHARGE_MEMOIRE();
    InterfaceDonnees::CARTON_EN_COURS.affichageCarton();
}
