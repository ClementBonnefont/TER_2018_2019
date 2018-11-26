SOURCES += \
    main.cpp \
    machineaetat.cpp \
    carton.cpp \
    interfacedonnees.cpp \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/programme.cpp \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.cpp \
    threadmae.cpp

QT+=widgets

HEADERS += \
    machineaetat.h \
    carton.h \
    interfacedonnees.h \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/programme.h \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.h \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/teste.h \
    threadmae.h

SUBDIRS += \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/ProtoInterfaceCmd.pro

FORMS += \
    ../../ProtoInterfaceCmd/ProtoInterfaceCmd/protointerface.ui
