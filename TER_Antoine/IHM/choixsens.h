#ifndef CHOIXSENS_H
#define CHOIXSENS_H

#include <iostream>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include "Model/interfacedonnees.h"

class choixSens : public QMainWindow
{
    Q_OBJECT
public:
    choixSens();

private slots:
    void normal();
    void inverse();

private:
    QWidget* m_widget;
    QHBoxLayout* mh_choix;

    QHBoxLayout* mh_normal;
    QHBoxLayout* mh_inverse;

    QPushButton* b_normal;
    QPushButton* b_inverse;
};

#endif // CHOIXSENS_H
