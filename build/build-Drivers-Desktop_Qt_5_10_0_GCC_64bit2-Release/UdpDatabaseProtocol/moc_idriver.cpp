/****************************************************************************
** Meta object code from reading C++ file 'idriver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Interface/Drivers/idriver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'idriver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_iDriver_t {
    QByteArrayData data[23];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iDriver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iDriver_t qt_meta_stringdata_iDriver = {
    {
QT_MOC_LITERAL(0, 0, 7), // "iDriver"
QT_MOC_LITERAL(1, 8, 12), // "stateChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "msgEventString"
QT_MOC_LITERAL(4, 37, 3), // "msg"
QT_MOC_LITERAL(5, 41, 10), // "driverInfo"
QT_MOC_LITERAL(6, 52, 10), // "DriverInfo"
QT_MOC_LITERAL(7, 63, 5), // "start"
QT_MOC_LITERAL(8, 69, 4), // "stop"
QT_MOC_LITERAL(9, 74, 7), // "restart"
QT_MOC_LITERAL(10, 82, 5), // "state"
QT_MOC_LITERAL(11, 88, 16), // "isAddressCorrect"
QT_MOC_LITERAL(12, 105, 4), // "addr"
QT_MOC_LITERAL(13, 110, 19), // "availableRWStrategy"
QT_MOC_LITERAL(14, 130, 10), // "QList<int>"
QT_MOC_LITERAL(15, 141, 18), // "addressErrorString"
QT_MOC_LITERAL(16, 160, 22), // "setRelatedTagAddresses"
QT_MOC_LITERAL(17, 183, 18), // "QList<TagAddress*>"
QT_MOC_LITERAL(18, 202, 19), // "relatedTagAddresses"
QT_MOC_LITERAL(19, 222, 6), // "showUI"
QT_MOC_LITERAL(20, 229, 4), // "show"
QT_MOC_LITERAL(21, 234, 8), // "QWidget*"
QT_MOC_LITERAL(22, 243, 6) // "parent"

    },
    "iDriver\0stateChanged\0\0msgEventString\0"
    "msg\0driverInfo\0DriverInfo\0start\0stop\0"
    "restart\0state\0isAddressCorrect\0addr\0"
    "availableRWStrategy\0QList<int>\0"
    "addressErrorString\0setRelatedTagAddresses\0"
    "QList<TagAddress*>\0relatedTagAddresses\0"
    "showUI\0show\0QWidget*\0parent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iDriver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       1,  122, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       3,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   95,    2, 0x0a /* Public */,
       7,    0,   96,    2, 0x0a /* Public */,
       8,    0,   97,    2, 0x0a /* Public */,
       9,    0,   98,    2, 0x0a /* Public */,
      10,    0,   99,    2, 0x0a /* Public */,
      11,    1,  100,    2, 0x0a /* Public */,
      13,    0,  103,    2, 0x0a /* Public */,
      13,    1,  104,    2, 0x0a /* Public */,
      15,    1,  107,    2, 0x0a /* Public */,
      16,    1,  110,    2, 0x0a /* Public */,
      19,    2,  113,    2, 0x0a /* Public */,
      19,    1,  118,    2, 0x2a /* Public | MethodCloned */,
      19,    0,  121,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    0x80000000 | 6,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Bool, QMetaType::QString,   12,
    0x80000000 | 14,
    0x80000000 | 14, QMetaType::QString,   12,
    QMetaType::QString, QMetaType::QString,   12,
    QMetaType::Int, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 21,   20,   22,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void iDriver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        iDriver *_t = static_cast<iDriver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->msgEventString((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { DriverInfo _r = _t->driverInfo();
            if (_a[0]) *reinterpret_cast< DriverInfo*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->start();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->stop();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->restart();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->state();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->isAddressCorrect((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { QList<int> _r = _t->availableRWStrategy();
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 9: { QList<int> _r = _t->availableRWStrategy((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->addressErrorString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->setRelatedTagAddresses((*reinterpret_cast< const QList<TagAddress*>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->showUI((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 13: _t->showUI((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->showUI(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (iDriver::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iDriver::stateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (iDriver::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iDriver::msgEventString)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        iDriver *_t = static_cast<iDriver *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->state(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject iDriver::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_iDriver.data,
      qt_meta_data_iDriver,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *iDriver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iDriver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_iDriver.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "iLoadSave"))
        return static_cast< iLoadSave*>(this);
    return QObject::qt_metacast(_clname);
}

int iDriver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
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
void iDriver::stateChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void iDriver::msgEventString(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
