#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    setWindowTitle("Machine à tisser");
    setFixedSize(1280,650);
    //setFixedSize(650,1280);
    //Déclaration des zones de la fenêtre
    m_widgetprincipal = new QWidget(this);
    mv_main = new QVBoxLayout(this);

    m_widgetprincipal->setLayout(mv_main);

    mh_main = new QHBoxLayout(this);

    //GRILLE
    view = new QGraphicsView();
    scene = new QGraphicsScene();


    for(int i=0; i<24;i++){
        for(int j=0;j<52;j++){
            QPen pen(Qt::black, 1, Qt::SolidLine);
            QColor color(0,255,255);
            QBrush brush(color);
            rectangle = new QRect((i*24), (j*24), 24, 24);
            scene->addRect(*rectangle,pen,brush);
        }
    }


    view->setScene(scene);

    //Fin GRILLE
    mv_main->addWidget(view);
    mv_main->addLayout(mh_main);

    mh_chargerCarton = new QHBoxLayout(m_widgetprincipal);
    mh_start = new QHBoxLayout(m_widgetprincipal);
    mh_stop = new QHBoxLayout(m_widgetprincipal);
    mh_pause_reprise = new QHBoxLayout(m_widgetprincipal);

    mh_main->addLayout(mh_chargerCarton);
    mh_main->addLayout(mh_start);
    mh_main->addLayout(mh_stop);
    mh_main->addLayout(mh_pause_reprise);

    //Déclaration des boutons
    chargerCarton = new QPushButton(m_widgetprincipal);
    chargerCarton->setText("Charger Carton");
    connect(chargerCarton, SIGNAL(clicked()), this, SLOT(chargementCarton()));

    start = new QPushButton(m_widgetprincipal);
    start->setEnabled(false);
    start->setText("START");
    start->setStyleSheet("background-color: green");
    connect(start, SIGNAL(clicked()),this, SLOT(start_appli()));

    stop = new QPushButton(m_widgetprincipal);
    stop->setText("STOP");
    stop->setEnabled(false);
    stop->setStyleSheet("background-color: red");
    connect(stop, SIGNAL(clicked()),this, SLOT(stop_appli()));

    pause_reprise = new QPushButton(m_widgetprincipal);
    pause_reprise->setText("Pause");
    connect(pause_reprise, SIGNAL(clicked()),this, SLOT(pause_rep()));



    //Ajout des boutons dans le layout du bas
    mh_chargerCarton->addWidget(chargerCarton);
    mh_start->addWidget(start);
    mh_stop->addWidget(stop);
    mh_pause_reprise->addWidget(pause_reprise);

    setCentralWidget(m_widgetprincipal);

    QObject::connect(this, SIGNAL(refreshBouton()), this, SLOT(repaintBouton()));
    QObject::connect(this, SIGNAL(refreshLigne()), this, SLOT(repaintLigne()));

}

MainWindow::~MainWindow()
{

}

//Méthode pour charger un carton et l'afficher dans la fenêtre
void MainWindow::chargementCarton(){

    QString str;
    str = QFileDialog::getOpenFileName(this, "Charger Carton", "");

    if(str.isEmpty())
    {
        return;
    }
    QFileInfo file(str);
    QString qChemin = file.filePath();
    string chemin = qChemin.toStdString();
    cout << chemin << endl;

        controlCarton.charger(chemin);
        if(controlCarton.getNbLigne()<=2){
            ligneEnPlus = 0;
        }else{
            if(controlCarton.getNbLigne()<=5 || controlCarton.getNbColonneConnue() <8){
                ligneEnPlus = 2;
            }else{
                if(controlCarton.getNbLigne()<12 || controlCarton.getNbColonneConnue() <10){
                    ligneEnPlus = 3;
                }else{
                    if(controlCarton.getNbLigne()<20 || controlCarton.getNbColonneConnue() <16){
                        ligneEnPlus = 5;
                    }else{
                        if(controlCarton.getNbLigne()<50){
                            ligneEnPlus = 8;
                        }else{
                            ligneEnPlus = 12;
                        }

                    }
                }
            }
        }

        repaintLigne();
        start->setEnabled(true);
        InterfaceDonnees::CARTON_EN_COURS->charger(chemin);
}

//Méthode lié au bouton "START" pour lancer l'exécution de la machine
void MainWindow::start_appli(){
    choixSens* choix = new choixSens;
    choix->show();
    stop->setEnabled(true);
    start->setEnabled(false);
}

//Méthode pour stopper la machine à état
void MainWindow::stop_appli(){
    InterfaceDonnees::FIN = true;
    start->setEnabled(true);
    stop->setEnabled(false);
}

//Méthode pour prendre en compte la mise en pause de la machine à état
void MainWindow::pause_rep(){
    if(InterfaceDonnees::PAUSE)
        InterfaceDonnees::REPRISE = true;
    else
        InterfaceDonnees::PAUSE = true;
}

void MainWindow::repaintBouton() {
    if(InterfaceDonnees::PAUSE)
        pause_reprise->setText("Reprise");
    else
        pause_reprise->setText("Pause");
}

void MainWindow::repaintLigne(){
    delete scene;
    scene = new QGraphicsScene();
    view->setScene(scene);
    tailleRec = 550/(controlCarton.getNbColonneConnue());
    int k = 0, r, g, b;
    QGraphicsTextItem *numeroLigne;
    for(int i=(InterfaceDonnees::LIGNES_EN_COURS-ligneEnPlus); k<controlCarton.getNbLigne()+ligneEnPlus;i++){
        if (i < 0){
            i = i+ controlCarton.getNbLigne();
        }
        if (i == controlCarton.getNbLigne())
            i = 0;
        for(int j=0;j<controlCarton.getNbColonneConnue();j++){
            QPen pen(Qt::black, 1, Qt::SolidLine);
            r = controlCarton.getMatrice()[i][j].getR();
            g = controlCarton.getMatrice()[i][j].getG();
            b = controlCarton.getMatrice()[i][j].getB();
            QColor color(r,g,b);
            QBrush brush(color);
            delete rectangle;
            rectangle = new QRect(tailleRec+(j*tailleRec), tailleRec+(k*tailleRec), tailleRec, tailleRec);
            scene->addRect(*rectangle,pen,brush);

        }
        numeroLigne = scene->addText(QString::number(i),QFont("Comic Sans MS",10));
        numeroLigne->setPos(0,tailleRec+(k*tailleRec));
        k++;
    }
    QGraphicsTextItem *numeroColonne;
    for(int j=0;j<controlCarton.getNbColonneConnue();j++){
        numeroColonne = scene->addText(QString::number(j),QFont("Comic Sans MS",10));
        numeroColonne->setPos(tailleRec+tailleRec*j,0);

    }
    rectangleLigne = new QRect(0,tailleRec+ligneEnPlus*tailleRec,tailleRec*(controlCarton.getNbColonneConnue()+1) ,tailleRec);
    QPen penTest(Qt::red,1,Qt::SolidLine);
    scene->addRect(*rectangleLigne,penTest);
}
