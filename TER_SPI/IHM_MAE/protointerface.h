#ifndef PROTOINTERFACE_H
#define PROTOINTERFACE_H

#include <QMainWindow>
#include "programme.h"

namespace Ui {
class ProtoInterface;
}

class ProtoInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProtoInterface(QWidget *parent = nullptr);
    ~ProtoInterface();
    void setLabelEtatPresent(int);
    void setLabelLigne(int);
    void setCadre(int);
    void unSetCadre(int);

private slots:
    void on_bDebut_clicked();
    void on_bFin_clicked();
    void on_bPause_clicked();
    void on_bReprise_clicked();
    void on_bUrgence_clicked();
    void repaintCadres();
    void on_bTOR_stateChanged(int arg1);

    void on_cSensNormal_stateChanged(int arg1);

    void on_bRetourSysteme_clicked();

signals :
    void refreshCadres();

private:
    Ui::ProtoInterface *ui;
    Programme p;
};

#endif // PROTOINTERFACE_H
