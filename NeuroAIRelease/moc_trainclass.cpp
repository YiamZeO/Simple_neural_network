/****************************************************************************
** Meta object code from reading C++ file 'trainclass.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../NeuroAI/trainclass.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trainclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_TrainClass_t {
    uint offsetsAndSizes[14];
    char stringdata0[11];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[18];
    char stringdata5[16];
    char stringdata6[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TrainClass_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_TrainClass_t qt_meta_stringdata_TrainClass = {
    {
        QT_MOC_LITERAL(0, 10),  // "TrainClass"
        QT_MOC_LITERAL(11, 16),  // "pushCreateButton"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 17),  // "pushChooseButton1"
        QT_MOC_LITERAL(47, 17),  // "pushChooseButton2"
        QT_MOC_LITERAL(65, 15),  // "pushStartButton"
        QT_MOC_LITERAL(81, 6)   // "upTime"
    },
    "TrainClass",
    "pushCreateButton",
    "",
    "pushChooseButton1",
    "pushChooseButton2",
    "pushStartButton",
    "upTime"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_TrainClass[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TrainClass::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_TrainClass.offsetsAndSizes,
    qt_meta_data_TrainClass,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_TrainClass_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TrainClass, std::true_type>,
        // method 'pushCreateButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pushChooseButton1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pushChooseButton2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pushStartButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'upTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TrainClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrainClass *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pushCreateButton(); break;
        case 1: _t->pushChooseButton1(); break;
        case 2: _t->pushChooseButton2(); break;
        case 3: _t->pushStartButton(); break;
        case 4: _t->upTime(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *TrainClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrainClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrainClass.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TrainClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
