/****************************************************************************
** Meta object code from reading C++ file 'tripcreateWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Project-2-NFL/tripcreateWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tripcreateWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TripCreateWidget_t {
    const uint offsetsAndSize[14];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TripCreateWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TripCreateWidget_t qt_meta_stringdata_TripCreateWidget = {
    {
QT_MOC_LITERAL(0, 16), // "TripCreateWidget"
QT_MOC_LITERAL(17, 26), // "on_proceedButtons_accepted"
QT_MOC_LITERAL(44, 0), // ""
QT_MOC_LITERAL(45, 26), // "on_proceedButtons_rejected"
QT_MOC_LITERAL(72, 28), // "on_pushButton_select_clicked"
QT_MOC_LITERAL(101, 26), // "on_pushButton_done_clicked"
QT_MOC_LITERAL(128, 28) // "on_pushButton_delete_clicked"

    },
    "TripCreateWidget\0on_proceedButtons_accepted\0"
    "\0on_proceedButtons_rejected\0"
    "on_pushButton_select_clicked\0"
    "on_pushButton_done_clicked\0"
    "on_pushButton_delete_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TripCreateWidget[] = {

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

void TripCreateWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TripCreateWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_proceedButtons_accepted(); break;
        case 1: _t->on_proceedButtons_rejected(); break;
        case 2: _t->on_pushButton_select_clicked(); break;
        case 3: _t->on_pushButton_done_clicked(); break;
        case 4: _t->on_pushButton_delete_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TripCreateWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_TripCreateWidget.offsetsAndSize,
    qt_meta_data_TripCreateWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TripCreateWidget_t
, QtPrivate::TypeAndForceComplete<TripCreateWidget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TripCreateWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TripCreateWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TripCreateWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TripCreateWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
