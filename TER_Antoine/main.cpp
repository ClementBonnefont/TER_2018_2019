#include <QApplication>
#include "../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.h"
#include <iostream>
#include <QDebug>
#include "machineaetat.h"
#include "threadmae.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Carton carton;
    InterfaceDonnees::CARTON_EN_COURS = carton;
    ProtoInterface w;
    ThreadMae *thread;
    thread = new ThreadMae;

    carton.charger();
    //w.show();
    //thread->start();
    InterfaceDonnees::CARTON_EN_COURS.affichageCarton();

    return app.exec();
}
