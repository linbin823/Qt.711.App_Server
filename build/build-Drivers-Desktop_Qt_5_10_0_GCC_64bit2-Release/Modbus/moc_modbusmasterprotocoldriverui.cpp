/****************************************************************************
** Meta object code from reading C++ file 'modbusmasterprotocoldriverui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Drivers/Modbus/modbusmasterprotocoldriverui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbusmasterprotocoldriverui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModbusMasterProtocolDriverUI_t {
    QByteArrayData data[7];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModbusMasterProtocolDriverUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModbusMasterProtocolDriverUI_t qt_meta_stringdata_ModbusMasterProtocolDriverUI = {
    {
QT_MOC_LITERAL(0, 0, 28), // "ModbusMasterProtocolDriverUI"
QT_MOC_LITERAL(1, 29, 12), // "_updateState"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 5), // "state"
QT_MOC_LITERAL(4, 49, 18), // "on_pbStart_clicked"
QT_MOC_LITERAL(5, 68, 17), // "on_pbStop_clicked"
QT_MOC_LITERAL(6, 86, 18) // "on_pbClose_clicked"

    },
    "ModbusMasterProtocolDriverUI\0_updateState\0"
    "\0state\0on_pbStart_clicked\0on_pbStop_clicked\0"
    "on_pbClose_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModbusMasterProtocolDriverUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ModbusMasterProtocolDriverUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModbusMasterProtocolDriverUI *_t = static_cast<ModbusMasterProtocolDriverUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->_updateState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pbStart_clicked(); break;
        case 2: _t->on_pbStop_clicked(); break;
        case 3: _t->on_pbClose_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ModbusMasterProtocolDriverUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ModbusMasterProtocolDriverUI.data,
      qt_meta_data_ModbusMasterProtocolDriverUI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ModbusMasterProtocolDriverUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusMasterProtocolDriverUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModbusMasterProtocolDriverUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ModbusMasterProtocolDriverUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
