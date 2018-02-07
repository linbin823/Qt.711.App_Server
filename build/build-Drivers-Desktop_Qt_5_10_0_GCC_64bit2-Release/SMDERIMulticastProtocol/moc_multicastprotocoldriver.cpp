/****************************************************************************
** Meta object code from reading C++ file 'multicastprotocoldriver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Drivers/SMDERIMulticastProtocol/multicastprotocoldriver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multicastprotocoldriver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MulticastProtocolDriver_t {
    QByteArrayData data[50];
    char stringdata0[576];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MulticastProtocolDriver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MulticastProtocolDriver_t qt_meta_stringdata_MulticastProtocolDriver = {
    {
QT_MOC_LITERAL(0, 0, 23), // "MulticastProtocolDriver"
QT_MOC_LITERAL(1, 24, 14), // "msgEventString"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 3), // "msg"
QT_MOC_LITERAL(4, 44, 12), // "dataReceived"
QT_MOC_LITERAL(5, 57, 12), // "dataAccepted"
QT_MOC_LITERAL(6, 70, 10), // "driverInfo"
QT_MOC_LITERAL(7, 81, 10), // "DriverInfo"
QT_MOC_LITERAL(8, 92, 4), // "save"
QT_MOC_LITERAL(9, 97, 19), // "iLoadSaveProcessor*"
QT_MOC_LITERAL(10, 117, 9), // "processor"
QT_MOC_LITERAL(11, 127, 4), // "load"
QT_MOC_LITERAL(12, 132, 5), // "start"
QT_MOC_LITERAL(13, 138, 4), // "stop"
QT_MOC_LITERAL(14, 143, 7), // "restart"
QT_MOC_LITERAL(15, 151, 5), // "state"
QT_MOC_LITERAL(16, 157, 19), // "availableRWStrategy"
QT_MOC_LITERAL(17, 177, 10), // "QList<int>"
QT_MOC_LITERAL(18, 188, 4), // "addr"
QT_MOC_LITERAL(19, 193, 16), // "isAddressCorrect"
QT_MOC_LITERAL(20, 210, 18), // "addressErrorString"
QT_MOC_LITERAL(21, 229, 22), // "setRelatedTagAddresses"
QT_MOC_LITERAL(22, 252, 18), // "QList<TagAddress*>"
QT_MOC_LITERAL(23, 271, 19), // "relatedTagAddresses"
QT_MOC_LITERAL(24, 291, 6), // "showUI"
QT_MOC_LITERAL(25, 298, 4), // "show"
QT_MOC_LITERAL(26, 303, 8), // "QWidget*"
QT_MOC_LITERAL(27, 312, 6), // "parent"
QT_MOC_LITERAL(28, 319, 19), // "setMulticastAddress"
QT_MOC_LITERAL(29, 339, 12), // "QHostAddress"
QT_MOC_LITERAL(30, 352, 4), // "port"
QT_MOC_LITERAL(31, 357, 19), // "setNetworkInterface"
QT_MOC_LITERAL(32, 377, 17), // "QNetworkInterface"
QT_MOC_LITERAL(33, 395, 16), // "networkInterface"
QT_MOC_LITERAL(34, 412, 16), // "multicastAddress"
QT_MOC_LITERAL(35, 429, 13), // "multicastPort"
QT_MOC_LITERAL(36, 443, 24), // "_processPendingDatagrams"
QT_MOC_LITERAL(37, 468, 9), // "_setState"
QT_MOC_LITERAL(38, 478, 11), // "enum_states"
QT_MOC_LITERAL(39, 490, 17), // "_watchDogTimeOver"
QT_MOC_LITERAL(40, 508, 8), // "_getTime"
QT_MOC_LITERAL(41, 517, 10), // "QDateTime&"
QT_MOC_LITERAL(42, 528, 1), // "t"
QT_MOC_LITERAL(43, 530, 4), // "year"
QT_MOC_LITERAL(44, 535, 5), // "month"
QT_MOC_LITERAL(45, 541, 3), // "day"
QT_MOC_LITERAL(46, 545, 4), // "hour"
QT_MOC_LITERAL(47, 550, 6), // "minute"
QT_MOC_LITERAL(48, 557, 6), // "second"
QT_MOC_LITERAL(49, 564, 11) // "millisecond"

    },
    "MulticastProtocolDriver\0msgEventString\0"
    "\0msg\0dataReceived\0dataAccepted\0"
    "driverInfo\0DriverInfo\0save\0"
    "iLoadSaveProcessor*\0processor\0load\0"
    "start\0stop\0restart\0state\0availableRWStrategy\0"
    "QList<int>\0addr\0isAddressCorrect\0"
    "addressErrorString\0setRelatedTagAddresses\0"
    "QList<TagAddress*>\0relatedTagAddresses\0"
    "showUI\0show\0QWidget*\0parent\0"
    "setMulticastAddress\0QHostAddress\0port\0"
    "setNetworkInterface\0QNetworkInterface\0"
    "networkInterface\0multicastAddress\0"
    "multicastPort\0_processPendingDatagrams\0"
    "_setState\0enum_states\0_watchDogTimeOver\0"
    "_getTime\0QDateTime&\0t\0year\0month\0day\0"
    "hour\0minute\0second\0millisecond"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MulticastProtocolDriver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  154,    2, 0x06 /* Public */,
       4,    0,  157,    2, 0x06 /* Public */,
       5,    0,  158,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  159,    2, 0x0a /* Public */,
       8,    1,  160,    2, 0x0a /* Public */,
      11,    1,  163,    2, 0x0a /* Public */,
      12,    0,  166,    2, 0x0a /* Public */,
      13,    0,  167,    2, 0x0a /* Public */,
      14,    0,  168,    2, 0x0a /* Public */,
      15,    0,  169,    2, 0x0a /* Public */,
      16,    0,  170,    2, 0x0a /* Public */,
      16,    1,  171,    2, 0x0a /* Public */,
      19,    1,  174,    2, 0x0a /* Public */,
      20,    1,  177,    2, 0x0a /* Public */,
      21,    1,  180,    2, 0x0a /* Public */,
      24,    2,  183,    2, 0x0a /* Public */,
      24,    1,  188,    2, 0x2a /* Public | MethodCloned */,
      24,    0,  191,    2, 0x2a /* Public | MethodCloned */,
      28,    2,  192,    2, 0x0a /* Public */,
      31,    1,  197,    2, 0x0a /* Public */,
      34,    0,  200,    2, 0x0a /* Public */,
      35,    0,  201,    2, 0x0a /* Public */,
      33,    0,  202,    2, 0x0a /* Public */,
      36,    0,  203,    2, 0x08 /* Private */,
      37,    1,  204,    2, 0x08 /* Private */,
      39,    0,  207,    2, 0x08 /* Private */,
      40,    8,  208,    2, 0x08 /* Private */,
      40,    7,  225,    2, 0x28 /* Private | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    0x80000000 | 7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    0x80000000 | 17,
    0x80000000 | 17, QMetaType::QString,   18,
    QMetaType::Bool, QMetaType::QString,   18,
    QMetaType::QString, QMetaType::QString,   18,
    QMetaType::Int, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 26,   25,   27,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 29, QMetaType::Int,   18,   30,
    QMetaType::Int, 0x80000000 | 32,   33,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 38,   15,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 41, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   42,   43,   44,   45,   46,   47,   48,   49,
    QMetaType::Bool, 0x80000000 | 41, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   42,   43,   44,   45,   46,   47,   48,

       0        // eod
};

void MulticastProtocolDriver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MulticastProtocolDriver *_t = static_cast<MulticastProtocolDriver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->msgEventString((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->dataReceived(); break;
        case 2: _t->dataAccepted(); break;
        case 3: { DriverInfo _r = _t->driverInfo();
            if (_a[0]) *reinterpret_cast< DriverInfo*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->save((*reinterpret_cast< iLoadSaveProcessor*(*)>(_a[1]))); break;
        case 5: _t->load((*reinterpret_cast< iLoadSaveProcessor*(*)>(_a[1]))); break;
        case 6: { int _r = _t->start();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->stop();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->restart();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->state();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { QList<int> _r = _t->availableRWStrategy();
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 11: { QList<int> _r = _t->availableRWStrategy((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->isAddressCorrect((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->addressErrorString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { int _r = _t->setRelatedTagAddresses((*reinterpret_cast< const QList<TagAddress*>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->showUI((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 16: _t->showUI((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->showUI(); break;
        case 18: { int _r = _t->setMulticastAddress((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 19: { int _r = _t->setNetworkInterface((*reinterpret_cast< const QNetworkInterface(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 20: { QString _r = _t->multicastAddress();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 21: { int _r = _t->multicastPort();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 22: _t->networkInterface(); break;
        case 23: _t->_processPendingDatagrams(); break;
        case 24: _t->_setState((*reinterpret_cast< enum_states(*)>(_a[1]))); break;
        case 25: _t->_watchDogTimeOver(); break;
        case 26: { bool _r = _t->_getTime((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 27: { bool _r = _t->_getTime((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkInterface >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MulticastProtocolDriver::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MulticastProtocolDriver::msgEventString)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MulticastProtocolDriver::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MulticastProtocolDriver::dataReceived)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MulticastProtocolDriver::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MulticastProtocolDriver::dataAccepted)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MulticastProtocolDriver::staticMetaObject = {
    { &iDriver::staticMetaObject, qt_meta_stringdata_MulticastProtocolDriver.data,
      qt_meta_data_MulticastProtocolDriver,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MulticastProtocolDriver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MulticastProtocolDriver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MulticastProtocolDriver.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "iDriver_iid"))
        return static_cast< iDriver*>(this);
    return iDriver::qt_metacast(_clname);
}

int MulticastProtocolDriver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = iDriver::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void MulticastProtocolDriver::msgEventString(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MulticastProtocolDriver::dataReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MulticastProtocolDriver::dataAccepted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

QT_PLUGIN_METADATA_SECTION const uint qt_section_alignment_dummy = 42;

#ifdef QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0xc4, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0xb0, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '/',  0x00, 'c',  'o',  'm',  '.',  'c',  's', 
    'i',  'c',  '7',  '1',  '1',  '.',  'a',  'p', 
    'p',  'S',  'e',  'r',  'v',  'e',  'r',  '.', 
    'd',  'r',  'i',  'v',  'e',  'r',  's',  '.', 
    'm',  'u',  'l',  't',  'i',  'c',  'a',  's', 
    't',  'P',  'r',  'o',  't',  'o',  'c',  'o', 
    'l',  0x00, 0x00, 0x00, 0x9b, 0x0b, 0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x17, 0x00, 'M',  'u', 
    'l',  't',  'i',  'c',  'a',  's',  't',  'P', 
    'r',  'o',  't',  'o',  'c',  'o',  'l',  'D', 
    'r',  'i',  'v',  'e',  'r',  0x00, 0x00, 0x00,
    0x1a, '@',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x11, 0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, 0x95, 0x14, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x94, 0x00, 0x00, 0x00,
    'L',  0x00, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00,
    'x',  0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0xc4, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0xb0, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '/',  0x00, 'c',  'o',  'm',  '.',  'c',  's', 
    'i',  'c',  '7',  '1',  '1',  '.',  'a',  'p', 
    'p',  'S',  'e',  'r',  'v',  'e',  'r',  '.', 
    'd',  'r',  'i',  'v',  'e',  'r',  's',  '.', 
    'm',  'u',  'l',  't',  'i',  'c',  'a',  's', 
    't',  'P',  'r',  'o',  't',  'o',  'c',  'o', 
    'l',  0x00, 0x00, 0x00, 0x95, 0x0b, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1b, 0x0f, 0x00, 0x00, 0x09, 0x00, 'c',  'l', 
    'a',  's',  's',  'N',  'a',  'm',  'e',  0x00,
    0x17, 0x00, 'M',  'u',  'l',  't',  'i',  'c', 
    'a',  's',  't',  'P',  'r',  'o',  't',  'o', 
    'c',  'o',  'l',  'D',  'r',  'i',  'v',  'e', 
    'r',  0x00, 0x00, 0x00, '1',  0x00, 0x00, 0x00,
    0x05, 0x00, 'd',  'e',  'b',  'u',  'g',  0x00,
    0x1a, '@',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 'L',  0x00, 0x00, 0x00,
    'h',  0x00, 0x00, 0x00, 0x94, 0x00, 0x00, 0x00,
    0xa0, 0x00, 0x00, 0x00
};
#endif // QT_NO_DEBUG

QT_MOC_EXPORT_PLUGIN(MulticastProtocolDriver, MulticastProtocolDriver)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
