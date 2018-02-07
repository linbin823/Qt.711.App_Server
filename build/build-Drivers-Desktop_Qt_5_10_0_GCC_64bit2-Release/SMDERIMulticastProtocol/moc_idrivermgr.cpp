/****************************************************************************
** Meta object code from reading C++ file 'idrivermgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Interface/Drivers/idrivermgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'idrivermgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_iDriverMgr_t {
    QByteArrayData data[28];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iDriverMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iDriverMgr_t qt_meta_stringdata_iDriverMgr = {
    {
QT_MOC_LITERAL(0, 0, 10), // "iDriverMgr"
QT_MOC_LITERAL(1, 11, 17), // "driverListChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "startAll"
QT_MOC_LITERAL(4, 39, 7), // "stopAll"
QT_MOC_LITERAL(5, 47, 10), // "driverList"
QT_MOC_LITERAL(6, 58, 15), // "QList<QObject*>"
QT_MOC_LITERAL(7, 74, 10), // "allDrivers"
QT_MOC_LITERAL(8, 85, 15), // "QList<iDriver*>"
QT_MOC_LITERAL(9, 101, 11), // "driverNames"
QT_MOC_LITERAL(10, 113, 22), // "driverNameRelateToType"
QT_MOC_LITERAL(11, 136, 10), // "driverType"
QT_MOC_LITERAL(12, 147, 13), // "setDriverName"
QT_MOC_LITERAL(13, 161, 3), // "pos"
QT_MOC_LITERAL(14, 165, 10), // "driverName"
QT_MOC_LITERAL(15, 176, 6), // "driver"
QT_MOC_LITERAL(16, 183, 8), // "contains"
QT_MOC_LITERAL(17, 192, 14), // "setRelatedTags"
QT_MOC_LITERAL(18, 207, 16), // "QList<iTagInfo*>"
QT_MOC_LITERAL(19, 224, 11), // "relatedTags"
QT_MOC_LITERAL(20, 236, 6), // "showUI"
QT_MOC_LITERAL(21, 243, 4), // "show"
QT_MOC_LITERAL(22, 248, 8), // "QWidget*"
QT_MOC_LITERAL(23, 257, 6), // "parent"
QT_MOC_LITERAL(24, 264, 12), // "insertDriver"
QT_MOC_LITERAL(25, 277, 10), // "DriverInfo"
QT_MOC_LITERAL(26, 288, 4), // "info"
QT_MOC_LITERAL(27, 293, 12) // "removeDriver"

    },
    "iDriverMgr\0driverListChanged\0\0startAll\0"
    "stopAll\0driverList\0QList<QObject*>\0"
    "allDrivers\0QList<iDriver*>\0driverNames\0"
    "driverNameRelateToType\0driverType\0"
    "setDriverName\0pos\0driverName\0driver\0"
    "contains\0setRelatedTags\0QList<iTagInfo*>\0"
    "relatedTags\0showUI\0show\0QWidget*\0"
    "parent\0insertDriver\0DriverInfo\0info\0"
    "removeDriver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iDriverMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       1,  154, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  105,    2, 0x0a /* Public */,
       4,    0,  106,    2, 0x0a /* Public */,
       5,    0,  107,    2, 0x0a /* Public */,
       7,    0,  108,    2, 0x0a /* Public */,
       9,    0,  109,    2, 0x0a /* Public */,
      10,    1,  110,    2, 0x0a /* Public */,
      12,    2,  113,    2, 0x0a /* Public */,
      15,    1,  118,    2, 0x0a /* Public */,
      16,    1,  121,    2, 0x0a /* Public */,
      17,    1,  124,    2, 0x0a /* Public */,
      20,    2,  127,    2, 0x0a /* Public */,
      20,    1,  132,    2, 0x2a /* Public | MethodCloned */,
      20,    0,  135,    2, 0x2a /* Public | MethodCloned */,
      24,    3,  136,    2, 0x0a /* Public */,
      24,    2,  143,    2, 0x2a /* Public | MethodCloned */,
      27,    1,  148,    2, 0x0a /* Public */,
      27,    1,  151,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 6,
    0x80000000 | 8,
    QMetaType::QStringList,
    QMetaType::QStringList, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   13,   14,
    QMetaType::QObjectStar, QMetaType::QString,   14,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Int, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 22,   21,   23,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 25, QMetaType::QString,   13,   26,   14,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 25,   13,   26,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Bool, QMetaType::Int,   13,

 // properties: name, type, flags
       5, 0x80000000 | 6, 0x00495009,

 // properties: notify_signal_id
       0,

       0        // eod
};

void iDriverMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        iDriverMgr *_t = static_cast<iDriverMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->driverListChanged(); break;
        case 1: _t->startAll(); break;
        case 2: _t->stopAll(); break;
        case 3: { QList<QObject*> _r = _t->driverList();
            if (_a[0]) *reinterpret_cast< QList<QObject*>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QList<iDriver*> _r = _t->allDrivers();
            if (_a[0]) *reinterpret_cast< QList<iDriver*>*>(_a[0]) = std::move(_r); }  break;
        case 5: { QStringList _r = _t->driverNames();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 6: { QStringList _r = _t->driverNameRelateToType((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setDriverName((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: { QObject* _r = _t->driver((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->contains((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->setRelatedTags((*reinterpret_cast< const QList<iTagInfo*>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->showUI((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 12: _t->showUI((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->showUI(); break;
        case 14: { bool _r = _t->insertDriver((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const DriverInfo(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->insertDriver((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const DriverInfo(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->removeDriver((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->removeDriver((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<iTagInfo*> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (iDriverMgr::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iDriverMgr::driverListChanged)) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        iDriverMgr *_t = static_cast<iDriverMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QObject*>*>(_v) = _t->driverList(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject iDriverMgr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_iDriverMgr.data,
      qt_meta_data_iDriverMgr,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *iDriverMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iDriverMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_iDriverMgr.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "iLoadSave"))
        return static_cast< iLoadSave*>(this);
    return QObject::qt_metacast(_clname);
}

int iDriverMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void iDriverMgr::driverListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
