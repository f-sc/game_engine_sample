/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_main_window_t {
    QByteArrayData data[14];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_main_window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_main_window_t qt_meta_stringdata_main_window = {
    {
QT_MOC_LITERAL(0, 0, 11), // "main_window"
QT_MOC_LITERAL(1, 12, 20), // "on_b_loadlvl_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "on_b_add_clicked"
QT_MOC_LITERAL(4, 51, 19), // "on_b_remove_clicked"
QT_MOC_LITERAL(5, 71, 18), // "on_w_items_clicked"
QT_MOC_LITERAL(6, 90, 5), // "index"
QT_MOC_LITERAL(7, 96, 20), // "on_b_saveLvl_clicked"
QT_MOC_LITERAL(8, 117, 23), // "on_toolButton_3_clicked"
QT_MOC_LITERAL(9, 141, 24), // "on_main_window_destroyed"
QT_MOC_LITERAL(10, 166, 24), // "on_w_items_itemActivated"
QT_MOC_LITERAL(11, 191, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(12, 208, 4), // "item"
QT_MOC_LITERAL(13, 213, 6) // "column"

    },
    "main_window\0on_b_loadlvl_clicked\0\0"
    "on_b_add_clicked\0on_b_remove_clicked\0"
    "on_w_items_clicked\0index\0on_b_saveLvl_clicked\0"
    "on_toolButton_3_clicked\0"
    "on_main_window_destroyed\0"
    "on_w_items_itemActivated\0QTreeWidgetItem*\0"
    "item\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_main_window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    2,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,   13,

       0        // eod
};

void main_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        main_window *_t = static_cast<main_window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_b_loadlvl_clicked(); break;
        case 1: _t->on_b_add_clicked(); break;
        case 2: _t->on_b_remove_clicked(); break;
        case 3: _t->on_w_items_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_b_saveLvl_clicked(); break;
        case 5: _t->on_toolButton_3_clicked(); break;
        case 6: _t->on_main_window_destroyed(); break;
        case 7: _t->on_w_items_itemActivated((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject main_window::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_main_window.data,
      qt_meta_data_main_window,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *main_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *main_window::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_main_window.stringdata0))
        return static_cast<void*>(const_cast< main_window*>(this));
    return QWidget::qt_metacast(_clname);
}

int main_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
