/****************************************************************************
** Meta object code from reading C++ file 'protointerface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TER_Antoine/IHM_MAE/protointerface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protointerface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProtoInterface_t {
    QByteArrayData data[13];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProtoInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProtoInterface_t qt_meta_stringdata_ProtoInterface = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ProtoInterface"
QT_MOC_LITERAL(1, 15, 13), // "refreshCadres"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "on_bDebut_clicked"
QT_MOC_LITERAL(4, 48, 15), // "on_bFin_clicked"
QT_MOC_LITERAL(5, 64, 17), // "on_bPause_clicked"
QT_MOC_LITERAL(6, 82, 19), // "on_bReprise_clicked"
QT_MOC_LITERAL(7, 102, 19), // "on_bUrgence_clicked"
QT_MOC_LITERAL(8, 122, 13), // "repaintCadres"
QT_MOC_LITERAL(9, 136, 20), // "on_bTOR_stateChanged"
QT_MOC_LITERAL(10, 157, 4), // "arg1"
QT_MOC_LITERAL(11, 162, 27), // "on_cSensNormal_stateChanged"
QT_MOC_LITERAL(12, 190, 25) // "on_bRetourSysteme_clicked"

    },
    "ProtoInterface\0refreshCadres\0\0"
    "on_bDebut_clicked\0on_bFin_clicked\0"
    "on_bPause_clicked\0on_bReprise_clicked\0"
    "on_bUrgence_clicked\0repaintCadres\0"
    "on_bTOR_stateChanged\0arg1\0"
    "on_cSensNormal_stateChanged\0"
    "on_bRetourSysteme_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProtoInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    1,   71,    2, 0x08 /* Private */,
      11,    1,   74,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

       0        // eod
};

void ProtoInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProtoInterface *_t = static_cast<ProtoInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refreshCadres(); break;
        case 1: _t->on_bDebut_clicked(); break;
        case 2: _t->on_bFin_clicked(); break;
        case 3: _t->on_bPause_clicked(); break;
        case 4: _t->on_bReprise_clicked(); break;
        case 5: _t->on_bUrgence_clicked(); break;
        case 6: _t->repaintCadres(); break;
        case 7: _t->on_bTOR_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_cSensNormal_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_bRetourSysteme_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProtoInterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProtoInterface::refreshCadres)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ProtoInterface::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ProtoInterface.data,
      qt_meta_data_ProtoInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProtoInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProtoInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProtoInterface.stringdata0))
        return static_cast<void*>(const_cast< ProtoInterface*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ProtoInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ProtoInterface::refreshCadres()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
