/****************************************************************************
** Meta object code from reading C++ file 'project_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "project_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'project_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_project_manager_t {
    QByteArrayData data[10];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_project_manager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_project_manager_t qt_meta_stringdata_project_manager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "project_manager"
QT_MOC_LITERAL(1, 16, 18), // "showProjectManager"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "addProjectWindow"
QT_MOC_LITERAL(4, 53, 10), // "addProject"
QT_MOC_LITERAL(5, 64, 9), // "checkPath"
QT_MOC_LITERAL(6, 74, 17), // "loadChosenProject"
QT_MOC_LITERAL(7, 92, 14), // "saveNewProject"
QT_MOC_LITERAL(8, 107, 13), // "loadBindedMap"
QT_MOC_LITERAL(9, 121, 13) // "saveBindedMap"

    },
    "project_manager\0showProjectManager\0\0"
    "addProjectWindow\0addProject\0checkPath\0"
    "loadChosenProject\0saveNewProject\0"
    "loadBindedMap\0saveBindedMap"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_project_manager[] = {

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
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void project_manager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        project_manager *_t = static_cast<project_manager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showProjectManager(); break;
        case 1: _t->addProjectWindow(); break;
        case 2: _t->addProject(); break;
        case 3: _t->checkPath(); break;
        case 4: _t->loadChosenProject(); break;
        case 5: _t->saveNewProject(); break;
        case 6: _t->loadBindedMap(); break;
        case 7: _t->saveBindedMap(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject project_manager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_project_manager.data,
      qt_meta_data_project_manager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *project_manager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *project_manager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_project_manager.stringdata0))
        return static_cast<void*>(const_cast< project_manager*>(this));
    return QObject::qt_metacast(_clname);
}

int project_manager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_ProjectsList_t {
    QByteArrayData data[3];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProjectsList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProjectsList_t qt_meta_stringdata_ProjectsList = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ProjectsList"
QT_MOC_LITERAL(1, 13, 20), // "deleteCurrentElement"
QT_MOC_LITERAL(2, 34, 0) // ""

    },
    "ProjectsList\0deleteCurrentElement\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProjectsList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ProjectsList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProjectsList *_t = static_cast<ProjectsList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteCurrentElement(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ProjectsList::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_ProjectsList.data,
      qt_meta_data_ProjectsList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProjectsList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProjectsList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProjectsList.stringdata0))
        return static_cast<void*>(const_cast< ProjectsList*>(this));
    return QListWidget::qt_metacast(_clname);
}

int ProjectsList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
