#include "IHM/mainwindow.h"
#include "MAE/threadmae.h"
#include <QApplication>

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

    w.show();
    wSimu.show();
    thread.start();

    return a.exec();
}
