#include "IHM/mainwindow.h"
#include "MAE/threadmae.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Interfaces graphiques
    MainWindow w;
    ProtoInterface wSimu;

    //Machine à états
    MachineAEtat *mae = new MachineAEtat(&w, &wSimu);
    ThreadMae thread(mae);

    //Communication
    Communication com;

    w.show();
//    wSimu.show();
    thread.start();

    return a.exec();
}
