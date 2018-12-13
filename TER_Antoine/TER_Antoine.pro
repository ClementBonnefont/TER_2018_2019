SOURCES += \
    main.cpp \
    machineaetat.cpp \
    interfacedonnees.cpp \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/programme.cpp \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.cpp \
    threadmae.cpp \
    interfacesimu.cpp \
    Model/carton.cpp \
    Model/couleur.cpp \
    Model/memoire.cpp \
    Controller/ControllerCarton.cpp

QT += widgets

HEADERS += \
    machineaetat.h \
    interfacedonnees.h \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/programme.h \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.h \
    threadmae.h \
    interfacesimu.h \
    Model/carton.h \
    Model/couleur.h \
    Model/memoire.h \
    Controller/ControllerCarton.h

SUBDIRS += \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/ProtoInterfaceCmd.pro

FORMS += \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.ui
