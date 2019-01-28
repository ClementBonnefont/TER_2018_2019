#include "IHM/mainwindow.h"
#include "MAE/threadmae.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Interfaces graphiques
    MainWindow w;
    ProtoInterface wSimu;

    //Machine à état
    MachineAEtat *mae = new MachineAEtat();
    ThreadMae thread(&w, &wSimu, mae);

    //SPI
    SPI spi;
    //TOR tor;

    w.show();
    wSimu.show();
    thread.start();
    qDebug("Attention a bien decommenter dans SPI la clock pour l'automate et lancer en ligne de commande et sudo");
    return a.exec();
}
