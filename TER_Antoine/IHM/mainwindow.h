#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QList>
#include <QGraphicsView>
#include "Controller/ControllerCarton.h"
#include "Model/interfacedonnees.h"
#include <QFileDialog>
#include <QFileInfo>
#include "choixsens.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void chargementCarton();
    void start_appli();
    void stop_appli();
    void pause_rep();
    void repaintBouton();
    void repaintLigne();


private:
    ControllerCarton controlCarton;

    QWidget* m_widgetprincipal;
    QVBoxLayout* mv_main;

    QHBoxLayout* mh_main;

    QGraphicsView* view;
    QGraphicsScene * scene;
    QRect *rectangle;

    QHBoxLayout* mh_chargerCarton;
    QHBoxLayout* mh_start;
    QHBoxLayout* mh_stop;
    QHBoxLayout* mh_pause_reprise;

    QPushButton* chargerCarton;
    QPushButton* start;
    QPushButton* stop;
    QPushButton* pause_reprise;

signals :
    void refreshBouton();
    void refreshLigne();


};

#endif // MAINWINDOW_H
