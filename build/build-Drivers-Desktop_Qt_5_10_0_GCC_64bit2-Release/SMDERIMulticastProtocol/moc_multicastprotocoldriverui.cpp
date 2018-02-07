/****************************************************************************
** Meta object code from reading C++ file 'multicastprotocoldriverui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Drivers/SMDERIMulticastProtocol/multicastprotocoldriverui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multicastprotocoldriverui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MulticastProtocolDriverUI_t {
    QByteArrayData data[10];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MulticastProtocolDriverUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MulticastProtocolDriverUI_t qt_meta_stringdata_MulticastProtocolDriverUI = {
    {
QT_MOC_LITERAL(0, 0, 25), // "MulticastProtocolDriverUI"
QT_MOC_LITERAL(1, 26, 5), // "start"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 18), // "on_pbStart_clicked"
QT_MOC_LITERAL(4, 52, 17), // "on_pbStop_clicked"
QT_MOC_LITERAL(5, 70, 11), // "updateState"
QT_MOC_LITERAL(6, 82, 5), // "state"
QT_MOC_LITERAL(7, 88, 19), // "updateReceivedDataN"
QT_MOC_LITERAL(8, 108, 19), // "updateAcceptedDataN"
QT_MOC_LITERAL(9, 128, 18) // "on_pbClose_clicked"

    },
    "MulticastProtocolDriverUI\0start\0\0"
    "on_pbStart_clicked\0on_pbStop_clicked\0"
    "updateState\0state\0updateReceivedDataN\0"
    "updateAcceptedDataN\0on_pbClose_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MulticastProtocolDriverUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    1,   52,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MulticastProtocolDriverUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MulticastProtocolDriverUI *_t = static_cast<MulticastProtocolDriverUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->start(); break;
        case 1: _t->on_pbStart_clicked(); break;
        case 2: _t->on_pbStop_clicked(); break;
        case 3: _t->updateState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updateReceivedDataN(); break;
        case 5: _t->updateAcceptedDataN(); break;
        case 6: _t->on_pbClose_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MulticastProtocolDriverUI::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MulticastProtocolDriverUI::start)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MulticastProtocolDriverUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MulticastProtocolDriverUI.data,
      qt_meta_data_MulticastProtocolDriverUI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MulticastProtocolDriverUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MulticastProtocolDriverUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MulticastProtocolDriverUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MulticastProtocolDriverUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MulticastProtocolDriverUI::start()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
