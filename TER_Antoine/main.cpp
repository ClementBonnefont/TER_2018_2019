#include <QApplication>
#include "../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.h"
#include <QDebug>
#include "machineaetat.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Carton carton;
    InterfaceDonnees interface;
    InterfaceDonnees::CARTON_EN_COURS = carton;
    ProtoInterface w;
    MachineAEtat mae;
    w.show();
    mae.activer();

    return app.exec();
}
