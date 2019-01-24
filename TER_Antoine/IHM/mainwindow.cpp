#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    setWindowTitle("Machine à tisser");
    setFixedSize(1280,650);
    //Déclaration des zones de la fenêtre
    m_widgetprincipal = new QWidget(this);
    mv_main = new QVBoxLayout(this);

    m_widgetprincipal->setLayout(mv_main);

    mh_main = new QHBoxLayout(this);

    //Placement grille
    //QPushButton* grille = new QPushButton(m_widgetprincipal);
    //grille->setText("GRILLE");

    //GRILLE
    view = new QGraphicsView();
    scene = new QGraphicsScene();


/*
    int list[24][10];

    for(int i=0;i<24;i++){
        for(int j=0;j<10;j++){
             list[i][j] = 0;
        }
    }
*/
    for(int i=0; i<24;i++){
        for(int j=0;j<10;j++){
            QPen pen(Qt::black, 1, Qt::SolidLine);
            QColor color(0,255,255);
            QBrush brush(color);
            rectangle = new QRect(0+(i*10), 0+(j*10), 10, 10);
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
    start->setText("START");
    start->setStyleSheet("background-color: green");
    connect(start, SIGNAL(clicked()),this, SLOT(start_appli()));

    stop = new QPushButton(m_widgetprincipal);
    stop->setText("STOP");
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
    //cout << qChemin.toStdString() << endl;
    //char ch = '/';
    //boost::replace_all(chemin, "/", "\\");
    //for(unsigned int i =0 ; i<chemin.size();i++){
    //    if(chemin[i] == ch){
     //       chemin[i] = '\\';
       // }
    //}

    cout << chemin << endl;

    ControllerCarton controlCarton(chemin);
    controlCarton.charger(chemin);
    scene->clear();

    for(int i=0; i<controlCarton.getNbLigne();i++){
        for(int j=0;j<controlCarton.getNbColonneConnue();j++){
            QPen pen(Qt::black, 1, Qt::SolidLine);
            int r = controlCarton.getMatrice()[i][j].getR();
            int g = controlCarton.getMatrice()[i][j].getG();
            int b = controlCarton.getMatrice()[i][j].getB();
            QColor color(r,g,b);
            QBrush brush(color);
            rectangle = new QRect(0+(i*10), 0+(j*10), 10, 10);
            scene->addRect(*rectangle,pen,brush);
        }
    }

    InterfaceDonnees::CARTON_EN_COURS->charger(chemin);

}

//Méthode lié au bouton "START" pour lancer l'exécution de la machine
void MainWindow::start_appli(){
    choixSens* choix = new choixSens;
    choix->show();
}

//Méthode pour stopper la machine à état
void MainWindow::stop_appli(){
    InterfaceDonnees::FIN = true;
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

}
