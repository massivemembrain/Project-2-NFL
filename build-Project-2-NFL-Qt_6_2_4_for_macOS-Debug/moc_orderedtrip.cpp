/****************************************************************************
** Meta object code from reading C++ file 'orderedtrip.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Project-2-NFL/orderedtrip.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orderedtrip.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OrderedTrip_t {
    const uint offsetsAndSize[16];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_OrderedTrip_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_OrderedTrip_t qt_meta_stringdata_OrderedTrip = {
    {
QT_MOC_LITERAL(0, 11), // "OrderedTrip"
QT_MOC_LITERAL(12, 34), // "on_pushButton_selectOrigin_cl..."
QT_MOC_LITERAL(47, 0), // ""
QT_MOC_LITERAL(48, 20), // "on_tableView_clicked"
QT_MOC_LITERAL(69, 11), // "QModelIndex"
QT_MOC_LITERAL(81, 5), // "index"
QT_MOC_LITERAL(87, 26), // "on_pushButton_done_clicked"
QT_MOC_LITERAL(114, 38) // "on_pushButton_startAnotherTri..."

    },
    "OrderedTrip\0on_pushButton_selectOrigin_clicked\0"
    "\0on_tableView_clicked\0QModelIndex\0"
    "index\0on_pushButton_done_clicked\0"
    "on_pushButton_startAnotherTrip_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrderedTrip[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    1,   39,    2, 0x08,    2 /* Private */,
       6,    0,   42,    2, 0x08,    4 /* Private */,
       7,    0,   43,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OrderedTrip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OrderedTrip *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_selectOrigin_clicked(); break;
        case 1: _t->on_tableView_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->on_pushButton_done_clicked(); break;
        case 3: _t->on_pushButton_startAnotherTrip_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject OrderedTrip::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_OrderedTrip.offsetsAndSize,
    qt_meta_data_OrderedTrip,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_OrderedTrip_t
, QtPrivate::TypeAndForceComplete<OrderedTrip, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *OrderedTrip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrderedTrip::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OrderedTrip.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int OrderedTrip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
