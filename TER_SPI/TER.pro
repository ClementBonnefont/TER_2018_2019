QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TER
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

HEADERS += \
    Controller/ControllerCarton.h \
    IHM/choixsens.h \
    IHM/mainwindow.h \
    MAE/machineaetat.h \
    MAE/threadmae.h \
    Model/carton.h \
    Model/couleur.h \
    Model/interfacedonnees.h \
    Model/memoire.h \
    IHM_MAE/interfacesimu.h \
    IHM_MAE/programme.h \
    IHM_MAE/protointerface.h \
    spi.h

SOURCES += \
    Controller/ControllerCarton.cpp \
    IHM/choixsens.cpp \
    IHM/mainwindow.cpp \
    MAE/machineaetat.cpp \
    MAE/threadmae.cpp \
    Model/carton.cpp \
    Model/couleur.cpp \
    Model/interfacedonnees.cpp \
    Model/memoire.cpp \
    main.cpp \
    IHM_MAE/interfacesimu.cpp \
    IHM_MAE/programme.cpp \
    IHM_MAE/protointerface.cpp \
    spi.cpp

FORMS += \
    IHM/mainwindow.ui \
    IHM_MAE/protointerface.ui

unix:!macx: LIBS += -L$$PWD/../../../../usr/lib/ -lwiringPi

DEPENDPATH += $$PWD/../../../../usr/include
