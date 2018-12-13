SOURCES += \
    main.cpp \
    machineaetat.cpp \
    carton.cpp \
    interfacedonnees.cpp \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/programme.cpp \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.cpp \
    threadmae.cpp \
    interfacesimu.cpp

QT += widgets

HEADERS += \
    machineaetat.h \
    carton.h \
    interfacedonnees.h \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/programme.h \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.h \
    threadmae.h \
    interfacesimu.h

SUBDIRS += \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/ProtoInterfaceCmd.pro

FORMS += \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.ui
