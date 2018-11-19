#include <QApplication>
#include "../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.h"
#include <iostream>
#include "machineaetat.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Carton carton;
    InterfaceDonnees::CARTON_EN_COURS = carton;
    ProtoInterface w;
    MachineAEtat mae;

    w.show();
    mae.activer();
    w.setLabel(mae.getEtatPresent());
    return app.exec();
}
