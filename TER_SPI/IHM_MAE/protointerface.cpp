#include "protointerface.h"
#include "ui_protointerface.h"
#include "programme.h"
#include <iostream>
#include <QString>
using namespace std;

ProtoInterface::ProtoInterface(QWidget *parent) : QMainWindow(parent), ui(new Ui::ProtoInterface)
{
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(refreshCadres()), this, SLOT(repaintCadres()));
    this->ui->cSensNormal->setChecked(true);
}

ProtoInterface::~ProtoInterface()
{
    delete ui;
}

void ProtoInterface::on_bDebut_clicked()
{
    p.debutTissage();
}

void ProtoInterface::on_bFin_clicked()
{
    p.finTissage();
}

void ProtoInterface::on_bPause_clicked()
{
    p.pauseTissage();
}

void ProtoInterface::on_bReprise_clicked()
{
    p.repriseTissage();
}

void ProtoInterface::on_bUrgence_clicked()
{
    p.urgenceTissage();
}

void ProtoInterface::setLabelEtatPresent(int etatPresent) {
    switch (etatPresent) {
        case 0 :    this->ui->lVisuEtatMAE->setText("Attente");
                    break;
        case 1 :    this->ui->lVisuEtatMAE->setText("Pilotage électro-aimant");
                    break;
        case 2 :    this->ui->lVisuEtatMAE->setText("Pause");
                    break;
        case 3 :    this->ui->lVisuEtatMAE->setText("Prochaine Ligne");
                    break;
        case 4 :    this->ui->lVisuEtatMAE->setText("Urgence");
                    break;
    default: break;
    }
}

void ProtoInterface::setLabelLigne(int l) {
    this->ui->lNbLignes->setText(QString::number(l));
}

void ProtoInterface::setCadre(int i) {
    switch (i+1) {
        case 1 :    this->ui->cmdE_1->setChecked(true);
                    break;
        case 2 :    this->ui->cmdE_2->setChecked(true);
                    break;
        case 3 :    this->ui->cmdE_3->setChecked(true);
                    break;
        case 4 :    this->ui->cmdE_4->setChecked(true);
                    break;
        case 5 :    this->ui->cmdE_5->setChecked(true);
                    break;
        case 6 :    this->ui->cmdE_6->setChecked(true);
                    break;
        case 7 :    this->ui->cmdE_7->setChecked(true);
                    break;
        case 8 :    this->ui->cmdE_8->setChecked(true);
                    break;
        case 9 :    this->ui->cmdE_9->setChecked(true);
                    break;
        case 10 :    this->ui->cmdE_10->setChecked(true);
                    break;
        case 11 :    this->ui->cmdE_11->setChecked(true);
                    break;
        case 12 :    this->ui->cmdE_12->setChecked(true);
                    break;
        case 13 :    this->ui->cmdE_13->setChecked(true);
                    break;
        case 14 :    this->ui->cmdE_14->setChecked(true);
                    break;
        case 15 :    this->ui->cmdE_15->setChecked(true);
                    break;
        case 16 :    this->ui->cmdE_16->setChecked(true);
                    break;
        case 17 :    this->ui->cmdE_17->setChecked(true);
                    break;
        case 18 :    this->ui->cmdE_18->setChecked(true);
                    break;
        case 19 :    this->ui->cmdE_19->setChecked(true);
                    break;
        case 20 :    this->ui->cmdE_20->setChecked(true);
                    break;
        case 21 :    this->ui->cmdE_21->setChecked(true);
                    break;
        case 22 :    this->ui->cmdE_22->setChecked(true);
                    break;
        case 23 :    this->ui->cmdE_23->setChecked(true);
                    break;
        case 24 :    this->ui->cmdE_24->setChecked(true);
                    break;
        default :   break;
    }
}

void ProtoInterface::unSetCadre(int i) {
    switch (i+1) {
        case 1 :    this->ui->cmdE_1->setChecked(false);
                    break;
        case 2 :    this->ui->cmdE_2->setChecked(false);
                    break;
        case 3 :    this->ui->cmdE_3->setChecked(false);
                    break;
        case 4 :    this->ui->cmdE_4->setChecked(false);
                    break;
        case 5 :    this->ui->cmdE_5->setChecked(false);
                    break;
        case 6 :    this->ui->cmdE_6->setChecked(false);
                    break;
        case 7 :    this->ui->cmdE_7->setChecked(false);
                    break;
        case 8 :    this->ui->cmdE_8->setChecked(false);
                    break;
        case 9 :    this->ui->cmdE_9->setChecked(false);
                    break;
        case 10 :    this->ui->cmdE_10->setChecked(false);
                    break;
        case 11 :    this->ui->cmdE_11->setChecked(false);
                    break;
        case 12 :    this->ui->cmdE_12->setChecked(false);
                    break;
        case 13 :    this->ui->cmdE_13->setChecked(false);
                    break;
        case 14 :    this->ui->cmdE_14->setChecked(false);
                    break;
        case 15 :    this->ui->cmdE_15->setChecked(false);
                    break;
        case 16 :    this->ui->cmdE_16->setChecked(false);
                    break;
        case 17 :    this->ui->cmdE_17->setChecked(false);
                    break;
        case 18 :    this->ui->cmdE_18->setChecked(false);
                    break;
        case 19 :    this->ui->cmdE_19->setChecked(false);
                    break;
        case 20 :    this->ui->cmdE_20->setChecked(false);
                    break;
        case 21 :    this->ui->cmdE_21->setChecked(false);
                    break;
        case 22 :    this->ui->cmdE_22->setChecked(false);
                    break;
        case 23 :    this->ui->cmdE_23->setChecked(false);
                    break;
        case 24 :    this->ui->cmdE_24->setChecked(false);
                    break;
        default :   break;
    }
}

void ProtoInterface::repaintCadres() {
    for(int i = 0; i < NB_CADRE; i++) {
        if(InterfaceSimu::valEA[i] == true)
            setCadre(i);
        else
            unSetCadre(i);
    }
}

void ProtoInterface::on_bTOR_stateChanged(int arg1)
{
    if(arg1 == 2)
        p.setTor(true);
    else if(arg1 == 0)
        p.setTor(false);
}

void ProtoInterface::on_cSensNormal_stateChanged(int arg1)
{
    if(arg1 == 2)
        p.setSens(true);
    else if(arg1 == 0)
        p.setSens(false);
}

void ProtoInterface::on_bRetourSysteme_clicked()
{
    p.retourTissage();
}
