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
    c.charger();
    c.afficheMatriceNoirBlanc();
    c.affichageCarton();
    c.saveCarton();
    c.saveCartonAs("C:\\Users\\clement\\Desktop\\TER\\carton6x8bis","carton6x8bis");
}

