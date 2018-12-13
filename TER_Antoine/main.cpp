#include <QApplication>
#include "../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.h"
#include <iostream>
#include <QDebug>
#include "threadmae.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    InterfaceDonnees::CARTON_EN_COURS.charger();
    ProtoInterface w;
    MachineAEtat *mae = new MachineAEtat;
    ThreadMae thread(&w, mae);

    w.show();
    thread.start();

    return app.exec();
}
