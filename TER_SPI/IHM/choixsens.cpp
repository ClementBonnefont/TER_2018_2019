#include "choixsens.h"

choixSens::choixSens()
{
    setWindowTitle("Choix sens lecture carton");
    //setFixedSize(170, 50);

    m_widget = new QWidget(this);
    mh_choix = new QHBoxLayout(this);

    m_widget->setLayout(mh_choix);

    mh_normal = new QHBoxLayout(m_widget);
    mh_inverse = new QHBoxLayout(m_widget);

    mh_choix->addLayout(mh_normal);
    mh_choix->addLayout(mh_inverse);

    QSize s_inverse = QSize(100,100);
    QSize s_normal = QSize(100,100);

    b_normal = new QPushButton(m_widget);
    b_normal->setText("Sens normal");
    b_normal->setFixedSize(s_normal);
    b_normal->setGeometry(0,0,300,100);
    connect(b_normal, SIGNAL(clicked()), this, SLOT(normal()));

    b_inverse = new QPushButton(m_widget);
    b_inverse->setFixedSize(s_inverse);
    b_inverse->setText("Sens inversé");
    connect(b_inverse, SIGNAL(clicked()), this, SLOT(inverse()));

    mh_normal->addWidget(b_normal);
    mh_inverse->addWidget(b_inverse);

    setCentralWidget(m_widget);

}

void choixSens::normal(){
    InterfaceDonnees::SENS_NORMAL = true;
    this->close();
    InterfaceDonnees::DEBUT = true;
}

void choixSens::inverse(){
    InterfaceDonnees::SENS_NORMAL = false;
    this->close();
    InterfaceDonnees::DEBUT = true;
}
