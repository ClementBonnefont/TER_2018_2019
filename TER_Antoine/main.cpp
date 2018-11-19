#include <QApplication>
//#include <iostream>
#include <QDebug>
#include "machineaetat.h"

//using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Carton carton;
    InterfaceDonnees interface;
    InterfaceDonnees::CARTON_EN_COURS = carton;
    MachineAEtat mae;

    mae.activer();
    while(InterfaceDonnees::FIN == false) {
        qDebug() << mae.getEtatPresent();
    }
    return app.exec();
}
