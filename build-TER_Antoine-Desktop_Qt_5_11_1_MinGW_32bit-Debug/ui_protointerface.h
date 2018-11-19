/********************************************************************************
** Form generated from reading UI file 'protointerface.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTOINTERFACE_H
#define UI_PROTOINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProtoInterface
{
public:
    QWidget *centralWidget;
    QFrame *fenetreConteneur;
    QWidget *gridLayoutWidget;
    QGridLayout *grilleCmdeAimants1;
    QCheckBox *cmdE_4;
    QCheckBox *cmdE_23;
    QCheckBox *cmdE_9;
    QCheckBox *cmdE_10;
    QCheckBox *cmdE_8;
    QCheckBox *cmdE_7;
    QCheckBox *cmdE_6;
    QCheckBox *cmdE_5;
    QCheckBox *cmdE_11;
    QCheckBox *cmdE_12;
    QCheckBox *cmdE_3;
    QCheckBox *cmdE_2;
    QCheckBox *cmdE_24;
    QCheckBox *cmdE_1;
    QCheckBox *cmdE_22;
    QCheckBox *cmdE_21;
    QCheckBox *cmdE_20;
    QCheckBox *cmdE_19;
    QCheckBox *cmdE_18;
    QCheckBox *cmdE_17;
    QCheckBox *cmdE_16;
    QCheckBox *cmdE_15;
    QCheckBox *cmdE_14;
    QCheckBox *cmdE_13;
    QWidget *gridLayoutWidget_3;
    QGridLayout *grilleDelais;
    QSlider *horizontalSlider;
    QLCDNumber *lcdTpsRestant;
    QLabel *lTempsRestant;
    QLabel *lChoixduree;
    QWidget *gridLayoutWidget_4;
    QGridLayout *grilleActions;
    QPushButton *bUnSetAll;
    QPushButton *bLancerSequence;
    QPushButton *bArretTension;
    QPushButton *bSetAll;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *grilleTitre;
    QSpacerItem *horizontalSpacer;
    QLabel *lTitre;
    QSpacerItem *horizontalSpacer_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *grilleVisu;
    QLabel *lVisuVal1_8;
    QLabel *lVisuText1_8;
    QLabel *lVisu9_16;
    QLabel *lVisuText9_16;
    QLabel *lVisuVal17_24;
    QLabel *lVisuText17_24;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProtoInterface)
    {
        if (ProtoInterface->objectName().isEmpty())
            ProtoInterface->setObjectName(QStringLiteral("ProtoInterface"));
        ProtoInterface->resize(747, 561);
        centralWidget = new QWidget(ProtoInterface);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        fenetreConteneur = new QFrame(centralWidget);
        fenetreConteneur->setObjectName(QStringLiteral("fenetreConteneur"));
        fenetreConteneur->setGeometry(QRect(0, 10, 751, 491));
        fenetreConteneur->setFrameShape(QFrame::StyledPanel);
        fenetreConteneur->setFrameShadow(QFrame::Raised);
        gridLayoutWidget = new QWidget(fenetreConteneur);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 45, 241, 434));
        grilleCmdeAimants1 = new QGridLayout(gridLayoutWidget);
        grilleCmdeAimants1->setSpacing(6);
        grilleCmdeAimants1->setContentsMargins(11, 11, 11, 11);
        grilleCmdeAimants1->setObjectName(QStringLiteral("grilleCmdeAimants1"));
        grilleCmdeAimants1->setContentsMargins(0, 0, 0, 0);
        cmdE_4 = new QCheckBox(gridLayoutWidget);
        cmdE_4->setObjectName(QStringLiteral("cmdE_4"));
        cmdE_4->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_4, 3, 0, 1, 1);

        cmdE_23 = new QCheckBox(gridLayoutWidget);
        cmdE_23->setObjectName(QStringLiteral("cmdE_23"));
        cmdE_23->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_23, 10, 1, 1, 1);

        cmdE_9 = new QCheckBox(gridLayoutWidget);
        cmdE_9->setObjectName(QStringLiteral("cmdE_9"));
        cmdE_9->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_9, 8, 0, 1, 1);

        cmdE_10 = new QCheckBox(gridLayoutWidget);
        cmdE_10->setObjectName(QStringLiteral("cmdE_10"));
        cmdE_10->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_10, 9, 0, 1, 1);

        cmdE_8 = new QCheckBox(gridLayoutWidget);
        cmdE_8->setObjectName(QStringLiteral("cmdE_8"));
        cmdE_8->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_8, 7, 0, 1, 1);

        cmdE_7 = new QCheckBox(gridLayoutWidget);
        cmdE_7->setObjectName(QStringLiteral("cmdE_7"));
        cmdE_7->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_7, 6, 0, 1, 1);

        cmdE_6 = new QCheckBox(gridLayoutWidget);
        cmdE_6->setObjectName(QStringLiteral("cmdE_6"));
        cmdE_6->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_6, 5, 0, 1, 1);

        cmdE_5 = new QCheckBox(gridLayoutWidget);
        cmdE_5->setObjectName(QStringLiteral("cmdE_5"));
        cmdE_5->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_5, 4, 0, 1, 1);

        cmdE_11 = new QCheckBox(gridLayoutWidget);
        cmdE_11->setObjectName(QStringLiteral("cmdE_11"));
        cmdE_11->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_11, 10, 0, 1, 1);

        cmdE_12 = new QCheckBox(gridLayoutWidget);
        cmdE_12->setObjectName(QStringLiteral("cmdE_12"));
        cmdE_12->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_12, 11, 0, 1, 1);

        cmdE_3 = new QCheckBox(gridLayoutWidget);
        cmdE_3->setObjectName(QStringLiteral("cmdE_3"));
        cmdE_3->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_3, 2, 0, 1, 1);

        cmdE_2 = new QCheckBox(gridLayoutWidget);
        cmdE_2->setObjectName(QStringLiteral("cmdE_2"));
        cmdE_2->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_2, 1, 0, 1, 1);

        cmdE_24 = new QCheckBox(gridLayoutWidget);
        cmdE_24->setObjectName(QStringLiteral("cmdE_24"));
        cmdE_24->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_24, 11, 1, 1, 1);

        cmdE_1 = new QCheckBox(gridLayoutWidget);
        cmdE_1->setObjectName(QStringLiteral("cmdE_1"));
        cmdE_1->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_1, 0, 0, 1, 1);

        cmdE_22 = new QCheckBox(gridLayoutWidget);
        cmdE_22->setObjectName(QStringLiteral("cmdE_22"));
        cmdE_22->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_22, 9, 1, 1, 1);

        cmdE_21 = new QCheckBox(gridLayoutWidget);
        cmdE_21->setObjectName(QStringLiteral("cmdE_21"));
        cmdE_21->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_21, 8, 1, 1, 1);

        cmdE_20 = new QCheckBox(gridLayoutWidget);
        cmdE_20->setObjectName(QStringLiteral("cmdE_20"));
        cmdE_20->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_20, 7, 1, 1, 1);

        cmdE_19 = new QCheckBox(gridLayoutWidget);
        cmdE_19->setObjectName(QStringLiteral("cmdE_19"));
        cmdE_19->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_19, 6, 1, 1, 1);

        cmdE_18 = new QCheckBox(gridLayoutWidget);
        cmdE_18->setObjectName(QStringLiteral("cmdE_18"));
        cmdE_18->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_18, 5, 1, 1, 1);

        cmdE_17 = new QCheckBox(gridLayoutWidget);
        cmdE_17->setObjectName(QStringLiteral("cmdE_17"));
        cmdE_17->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_17, 4, 1, 1, 1);

        cmdE_16 = new QCheckBox(gridLayoutWidget);
        cmdE_16->setObjectName(QStringLiteral("cmdE_16"));
        cmdE_16->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_16, 3, 1, 1, 1);

        cmdE_15 = new QCheckBox(gridLayoutWidget);
        cmdE_15->setObjectName(QStringLiteral("cmdE_15"));
        cmdE_15->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_15, 2, 1, 1, 1);

        cmdE_14 = new QCheckBox(gridLayoutWidget);
        cmdE_14->setObjectName(QStringLiteral("cmdE_14"));
        cmdE_14->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_14, 1, 1, 1, 1);

        cmdE_13 = new QCheckBox(gridLayoutWidget);
        cmdE_13->setObjectName(QStringLiteral("cmdE_13"));
        cmdE_13->setCheckable(true);

        grilleCmdeAimants1->addWidget(cmdE_13, 0, 1, 1, 1);

        gridLayoutWidget_3 = new QWidget(fenetreConteneur);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(280, 50, 135, 241));
        grilleDelais = new QGridLayout(gridLayoutWidget_3);
        grilleDelais->setSpacing(6);
        grilleDelais->setContentsMargins(11, 11, 11, 11);
        grilleDelais->setObjectName(QStringLiteral("grilleDelais"));
        grilleDelais->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(gridLayoutWidget_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setEnabled(true);
        horizontalSlider->setContextMenuPolicy(Qt::NoContextMenu);
        horizontalSlider->setMaximum(3);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);

        grilleDelais->addWidget(horizontalSlider, 8, 2, 1, 1);

        lcdTpsRestant = new QLCDNumber(gridLayoutWidget_3);
        lcdTpsRestant->setObjectName(QStringLiteral("lcdTpsRestant"));
        lcdTpsRestant->setSmallDecimalPoint(true);
        lcdTpsRestant->setMode(QLCDNumber::Dec);
        lcdTpsRestant->setProperty("intValue", QVariant(0));

        grilleDelais->addWidget(lcdTpsRestant, 3, 2, 1, 1);

        lTempsRestant = new QLabel(gridLayoutWidget_3);
        lTempsRestant->setObjectName(QStringLiteral("lTempsRestant"));

        grilleDelais->addWidget(lTempsRestant, 2, 2, 1, 1);

        lChoixduree = new QLabel(gridLayoutWidget_3);
        lChoixduree->setObjectName(QStringLiteral("lChoixduree"));

        grilleDelais->addWidget(lChoixduree, 7, 2, 1, 1);

        gridLayoutWidget_4 = new QWidget(fenetreConteneur);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(280, 300, 451, 181));
        grilleActions = new QGridLayout(gridLayoutWidget_4);
        grilleActions->setSpacing(6);
        grilleActions->setContentsMargins(11, 11, 11, 11);
        grilleActions->setObjectName(QStringLiteral("grilleActions"));
        grilleActions->setContentsMargins(0, 0, 0, 0);
        bUnSetAll = new QPushButton(gridLayoutWidget_4);
        bUnSetAll->setObjectName(QStringLiteral("bUnSetAll"));

        grilleActions->addWidget(bUnSetAll, 1, 1, 1, 1);

        bLancerSequence = new QPushButton(gridLayoutWidget_4);
        bLancerSequence->setObjectName(QStringLiteral("bLancerSequence"));

        grilleActions->addWidget(bLancerSequence, 0, 0, 1, 1);

        bArretTension = new QPushButton(gridLayoutWidget_4);
        bArretTension->setObjectName(QStringLiteral("bArretTension"));

        grilleActions->addWidget(bArretTension, 0, 1, 1, 1);

        bSetAll = new QPushButton(gridLayoutWidget_4);
        bSetAll->setObjectName(QStringLiteral("bSetAll"));

        grilleActions->addWidget(bSetAll, 1, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(fenetreConteneur);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 721, 41));
        grilleTitre = new QHBoxLayout(horizontalLayoutWidget);
        grilleTitre->setSpacing(6);
        grilleTitre->setContentsMargins(11, 11, 11, 11);
        grilleTitre->setObjectName(QStringLiteral("grilleTitre"));
        grilleTitre->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        grilleTitre->addItem(horizontalSpacer);

        lTitre = new QLabel(horizontalLayoutWidget);
        lTitre->setObjectName(QStringLiteral("lTitre"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lTitre->setFont(font);

        grilleTitre->addWidget(lTitre);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        grilleTitre->addItem(horizontalSpacer_2);

        gridLayoutWidget_2 = new QWidget(fenetreConteneur);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(420, 50, 311, 241));
        grilleVisu = new QGridLayout(gridLayoutWidget_2);
        grilleVisu->setSpacing(6);
        grilleVisu->setContentsMargins(11, 11, 11, 11);
        grilleVisu->setObjectName(QStringLiteral("grilleVisu"));
        grilleVisu->setContentsMargins(0, 0, 0, 0);
        lVisuVal1_8 = new QLabel(gridLayoutWidget_2);
        lVisuVal1_8->setObjectName(QStringLiteral("lVisuVal1_8"));

        grilleVisu->addWidget(lVisuVal1_8, 0, 0, 1, 1);

        lVisuText1_8 = new QLabel(gridLayoutWidget_2);
        lVisuText1_8->setObjectName(QStringLiteral("lVisuText1_8"));

        grilleVisu->addWidget(lVisuText1_8, 1, 0, 1, 1);

        lVisu9_16 = new QLabel(gridLayoutWidget_2);
        lVisu9_16->setObjectName(QStringLiteral("lVisu9_16"));

        grilleVisu->addWidget(lVisu9_16, 0, 1, 1, 1);

        lVisuText9_16 = new QLabel(gridLayoutWidget_2);
        lVisuText9_16->setObjectName(QStringLiteral("lVisuText9_16"));

        grilleVisu->addWidget(lVisuText9_16, 1, 1, 1, 1);

        lVisuVal17_24 = new QLabel(gridLayoutWidget_2);
        lVisuVal17_24->setObjectName(QStringLiteral("lVisuVal17_24"));

        grilleVisu->addWidget(lVisuVal17_24, 0, 2, 1, 1);

        lVisuText17_24 = new QLabel(gridLayoutWidget_2);
        lVisuText17_24->setObjectName(QStringLiteral("lVisuText17_24"));

        grilleVisu->addWidget(lVisuText17_24, 1, 2, 1, 1);

        ProtoInterface->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProtoInterface);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 747, 26));
        ProtoInterface->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProtoInterface);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProtoInterface->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProtoInterface);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProtoInterface->setStatusBar(statusBar);
        QWidget::setTabOrder(cmdE_1, cmdE_2);
        QWidget::setTabOrder(cmdE_2, cmdE_3);
        QWidget::setTabOrder(cmdE_3, cmdE_4);
        QWidget::setTabOrder(cmdE_4, cmdE_5);
        QWidget::setTabOrder(cmdE_5, cmdE_6);
        QWidget::setTabOrder(cmdE_6, cmdE_7);
        QWidget::setTabOrder(cmdE_7, cmdE_8);
        QWidget::setTabOrder(cmdE_8, cmdE_9);
        QWidget::setTabOrder(cmdE_9, cmdE_10);
        QWidget::setTabOrder(cmdE_10, cmdE_11);
        QWidget::setTabOrder(cmdE_11, cmdE_12);
        QWidget::setTabOrder(cmdE_12, cmdE_13);
        QWidget::setTabOrder(cmdE_13, cmdE_14);
        QWidget::setTabOrder(cmdE_14, cmdE_15);
        QWidget::setTabOrder(cmdE_15, cmdE_16);
        QWidget::setTabOrder(cmdE_16, cmdE_17);
        QWidget::setTabOrder(cmdE_17, cmdE_18);
        QWidget::setTabOrder(cmdE_18, cmdE_19);
        QWidget::setTabOrder(cmdE_19, cmdE_20);
        QWidget::setTabOrder(cmdE_20, cmdE_21);
        QWidget::setTabOrder(cmdE_21, cmdE_22);
        QWidget::setTabOrder(cmdE_22, cmdE_23);
        QWidget::setTabOrder(cmdE_23, cmdE_24);
        QWidget::setTabOrder(cmdE_24, horizontalSlider);
        QWidget::setTabOrder(horizontalSlider, bSetAll);
        QWidget::setTabOrder(bSetAll, bUnSetAll);
        QWidget::setTabOrder(bUnSetAll, bLancerSequence);
        QWidget::setTabOrder(bLancerSequence, bArretTension);

        retranslateUi(ProtoInterface);

        QMetaObject::connectSlotsByName(ProtoInterface);
    } // setupUi

    void retranslateUi(QMainWindow *ProtoInterface)
    {
        ProtoInterface->setWindowTitle(QApplication::translate("ProtoInterface", "MainWindow", nullptr));
        cmdE_4->setText(QApplication::translate("ProtoInterface", "Cadre 4", nullptr));
        cmdE_23->setText(QApplication::translate("ProtoInterface", "Cadre 23", nullptr));
        cmdE_9->setText(QApplication::translate("ProtoInterface", "Cadre 9", nullptr));
        cmdE_10->setText(QApplication::translate("ProtoInterface", "Cadre 10", nullptr));
        cmdE_8->setText(QApplication::translate("ProtoInterface", "Cadre 8", nullptr));
        cmdE_7->setText(QApplication::translate("ProtoInterface", "Cadre 7", nullptr));
        cmdE_6->setText(QApplication::translate("ProtoInterface", "Cadre 6", nullptr));
        cmdE_5->setText(QApplication::translate("ProtoInterface", "Cadre 5", nullptr));
        cmdE_11->setText(QApplication::translate("ProtoInterface", "Cadre 11", nullptr));
        cmdE_12->setText(QApplication::translate("ProtoInterface", "Cadre 12", nullptr));
        cmdE_3->setText(QApplication::translate("ProtoInterface", "Cadre 3", nullptr));
        cmdE_2->setText(QApplication::translate("ProtoInterface", "Cadre 2", nullptr));
        cmdE_24->setText(QApplication::translate("ProtoInterface", "Cadre 24", nullptr));
        cmdE_1->setText(QApplication::translate("ProtoInterface", "Cadre 1", nullptr));
        cmdE_22->setText(QApplication::translate("ProtoInterface", "Cadre 22", nullptr));
        cmdE_21->setText(QApplication::translate("ProtoInterface", "Cadre 21", nullptr));
        cmdE_20->setText(QApplication::translate("ProtoInterface", "Cadre 20", nullptr));
        cmdE_19->setText(QApplication::translate("ProtoInterface", "Cadre 19", nullptr));
        cmdE_18->setText(QApplication::translate("ProtoInterface", "Cadre 18", nullptr));
        cmdE_17->setText(QApplication::translate("ProtoInterface", "Cadre 17", nullptr));
        cmdE_16->setText(QApplication::translate("ProtoInterface", "Cadre 16", nullptr));
        cmdE_15->setText(QApplication::translate("ProtoInterface", "Cadre 15", nullptr));
        cmdE_14->setText(QApplication::translate("ProtoInterface", "Cadre 14", nullptr));
        cmdE_13->setText(QApplication::translate("ProtoInterface", "Cadre 13", nullptr));
        lTempsRestant->setText(QApplication::translate("ProtoInterface", "Temps restant levage :", nullptr));
        lChoixduree->setText(QApplication::translate("ProtoInterface", "Choix dur\303\251e levage", nullptr));
        bUnSetAll->setText(QApplication::translate("ProtoInterface", "UnSetAll", nullptr));
        bLancerSequence->setText(QApplication::translate("ProtoInterface", "Lancer la S\303\251quence", nullptr));
        bArretTension->setText(QApplication::translate("ProtoInterface", "Arret Tension", nullptr));
        bSetAll->setText(QApplication::translate("ProtoInterface", "SetAll", nullptr));
        lTitre->setText(QApplication::translate("ProtoInterface", "Programme de test de la commande des \303\251lectro-aimants", nullptr));
        lVisuVal1_8->setText(QApplication::translate("ProtoInterface", "TextLabel", nullptr));
        lVisuText1_8->setText(QApplication::translate("ProtoInterface", "TextLabel", nullptr));
        lVisu9_16->setText(QApplication::translate("ProtoInterface", "TextLabel", nullptr));
        lVisuText9_16->setText(QApplication::translate("ProtoInterface", "TextLabel", nullptr));
        lVisuVal17_24->setText(QApplication::translate("ProtoInterface", "TextLabel", nullptr));
        lVisuText17_24->setText(QApplication::translate("ProtoInterface", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProtoInterface: public Ui_ProtoInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTOINTERFACE_H
