/****************************************************************************
** Meta object code from reading C++ file 'modbusmasterprotocoldriver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Drivers/Modbus/modbusmasterprotocoldriver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbusmasterprotocoldriver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModbusMasterProtocolDriver_t {
    QByteArrayData data[48];
    char stringdata0[573];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModbusMasterProtocolDriver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModbusMasterProtocolDriver_t qt_meta_stringdata_ModbusMasterProtocolDriver = {
    {
QT_MOC_LITERAL(0, 0, 26), // "ModbusMasterProtocolDriver"
QT_MOC_LITERAL(1, 27, 10), // "driverInfo"
QT_MOC_LITERAL(2, 38, 10), // "DriverInfo"
QT_MOC_LITERAL(3, 49, 0), // ""
QT_MOC_LITERAL(4, 50, 4), // "save"
QT_MOC_LITERAL(5, 55, 19), // "iLoadSaveProcessor*"
QT_MOC_LITERAL(6, 75, 9), // "processor"
QT_MOC_LITERAL(7, 85, 4), // "load"
QT_MOC_LITERAL(8, 90, 5), // "start"
QT_MOC_LITERAL(9, 96, 4), // "stop"
QT_MOC_LITERAL(10, 101, 7), // "restart"
QT_MOC_LITERAL(11, 109, 5), // "state"
QT_MOC_LITERAL(12, 115, 19), // "availableRWStrategy"
QT_MOC_LITERAL(13, 135, 10), // "QList<int>"
QT_MOC_LITERAL(14, 146, 4), // "addr"
QT_MOC_LITERAL(15, 151, 16), // "isAddressCorrect"
QT_MOC_LITERAL(16, 168, 18), // "addressErrorString"
QT_MOC_LITERAL(17, 187, 22), // "setRelatedTagAddresses"
QT_MOC_LITERAL(18, 210, 18), // "QList<TagAddress*>"
QT_MOC_LITERAL(19, 229, 19), // "relatedTagAddresses"
QT_MOC_LITERAL(20, 249, 6), // "showUI"
QT_MOC_LITERAL(21, 256, 4), // "show"
QT_MOC_LITERAL(22, 261, 8), // "QWidget*"
QT_MOC_LITERAL(23, 270, 6), // "parent"
QT_MOC_LITERAL(24, 277, 15), // "_initParameters"
QT_MOC_LITERAL(25, 293, 9), // "_setState"
QT_MOC_LITERAL(26, 303, 11), // "enum_states"
QT_MOC_LITERAL(27, 315, 16), // "_scheduleProcess"
QT_MOC_LITERAL(28, 332, 10), // "_readyRead"
QT_MOC_LITERAL(29, 343, 12), // "_addressArea"
QT_MOC_LITERAL(30, 356, 14), // "_addressOffset"
QT_MOC_LITERAL(31, 371, 14), // "_dataQualifier"
QT_MOC_LITERAL(32, 386, 8), // "dataType"
QT_MOC_LITERAL(33, 395, 17), // "const TagAddress*"
QT_MOC_LITERAL(34, 413, 1), // "t"
QT_MOC_LITERAL(35, 415, 16), // "_prepareDataUnit"
QT_MOC_LITERAL(36, 432, 22), // "QList<QModbusDataUnit>"
QT_MOC_LITERAL(37, 455, 4), // "list"
QT_MOC_LITERAL(38, 460, 11), // "_readValues"
QT_MOC_LITERAL(39, 472, 15), // "QModbusDataUnit"
QT_MOC_LITERAL(40, 488, 4), // "unit"
QT_MOC_LITERAL(41, 493, 12), // "_writeValues"
QT_MOC_LITERAL(42, 506, 16), // "QModbusDataUnit&"
QT_MOC_LITERAL(43, 523, 10), // "_readValue"
QT_MOC_LITERAL(44, 534, 11), // "TagAddress*"
QT_MOC_LITERAL(45, 546, 5), // "index"
QT_MOC_LITERAL(46, 552, 11), // "_writeValue"
QT_MOC_LITERAL(47, 564, 8) // "_isDWord"

    },
    "ModbusMasterProtocolDriver\0driverInfo\0"
    "DriverInfo\0\0save\0iLoadSaveProcessor*\0"
    "processor\0load\0start\0stop\0restart\0"
    "state\0availableRWStrategy\0QList<int>\0"
    "addr\0isAddressCorrect\0addressErrorString\0"
    "setRelatedTagAddresses\0QList<TagAddress*>\0"
    "relatedTagAddresses\0showUI\0show\0"
    "QWidget*\0parent\0_initParameters\0"
    "_setState\0enum_states\0_scheduleProcess\0"
    "_readyRead\0_addressArea\0_addressOffset\0"
    "_dataQualifier\0dataType\0const TagAddress*\0"
    "t\0_prepareDataUnit\0QList<QModbusDataUnit>\0"
    "list\0_readValues\0QModbusDataUnit\0unit\0"
    "_writeValues\0QModbusDataUnit&\0_readValue\0"
    "TagAddress*\0index\0_writeValue\0_isDWord"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModbusMasterProtocolDriver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  154,    3, 0x0a /* Public */,
       4,    1,  155,    3, 0x0a /* Public */,
       7,    1,  158,    3, 0x0a /* Public */,
       8,    0,  161,    3, 0x0a /* Public */,
       9,    0,  162,    3, 0x0a /* Public */,
      10,    0,  163,    3, 0x0a /* Public */,
      11,    0,  164,    3, 0x0a /* Public */,
      12,    0,  165,    3, 0x0a /* Public */,
      12,    1,  166,    3, 0x0a /* Public */,
      15,    1,  169,    3, 0x0a /* Public */,
      16,    1,  172,    3, 0x0a /* Public */,
      17,    1,  175,    3, 0x0a /* Public */,
      20,    2,  178,    3, 0x0a /* Public */,
      20,    1,  183,    3, 0x2a /* Public | MethodCloned */,
      20,    0,  186,    3, 0x2a /* Public | MethodCloned */,
      24,    0,  187,    3, 0x08 /* Private */,
      25,    1,  188,    3, 0x08 /* Private */,
      27,    0,  191,    3, 0x08 /* Private */,
      28,    0,  192,    3, 0x08 /* Private */,
      29,    1,  193,    3, 0x08 /* Private */,
      30,    1,  196,    3, 0x08 /* Private */,
      31,    2,  199,    3, 0x08 /* Private */,
      35,    2,  204,    3, 0x08 /* Private */,
      38,    2,  209,    3, 0x08 /* Private */,
      41,    2,  214,    3, 0x08 /* Private */,
      43,    3,  219,    3, 0x08 /* Private */,
      46,    3,  226,    3, 0x08 /* Private */,
      47,    1,  233,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    0x80000000 | 13,
    0x80000000 | 13, QMetaType::QString,   14,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::QString, QMetaType::QString,   14,
    QMetaType::Int, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 22,   21,   23,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 26,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString,   14,
    QMetaType::Int, QMetaType::QString,   14,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 33,   32,   34,
    0x80000000 | 36, QMetaType::Int, 0x80000000 | 18,   32,   37,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 39,   37,   40,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 42,   37,   40,
    QMetaType::Void, 0x80000000 | 44, 0x80000000 | 39, QMetaType::UInt,   34,   40,   45,
    QMetaType::Void, 0x80000000 | 44, 0x80000000 | 42, QMetaType::UInt,   34,   40,   45,
    QMetaType::Bool, QMetaType::QString,   14,

       0        // eod
};

void ModbusMasterProtocolDriver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModbusMasterProtocolDriver *_t = static_cast<ModbusMasterProtocolDriver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { DriverInfo _r = _t->driverInfo();
            if (_a[0]) *reinterpret_cast< DriverInfo*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->save((*reinterpret_cast< iLoadSaveProcessor*(*)>(_a[1]))); break;
        case 2: _t->load((*reinterpret_cast< iLoadSaveProcessor*(*)>(_a[1]))); break;
        case 3: { int _r = _t->start();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->stop();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->restart();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->state();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { QList<int> _r = _t->availableRWStrategy();
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 8: { QList<int> _r = _t->availableRWStrategy((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->isAddressCorrect((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->addressErrorString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->setRelatedTagAddresses((*reinterpret_cast< const QList<TagAddress*>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->showUI((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 13: _t->showUI((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->showUI(); break;
        case 15: _t->_initParameters(); break;
        case 16: _t->_setState((*reinterpret_cast< enum_states(*)>(_a[1]))); break;
        case 17: _t->_scheduleProcess(); break;
        case 18: _t->_readyRead(); break;
        case 19: { int _r = _t->_addressArea((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 20: { int _r = _t->_addressOffset((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->_dataQualifier((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const TagAddress*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: { QList<QModbusDataUnit> _r = _t->_prepareDataUnit((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QList<TagAddress*>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<QModbusDataUnit>*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->_readValues((*reinterpret_cast< const QList<TagAddress*>(*)>(_a[1])),(*reinterpret_cast< const QModbusDataUnit(*)>(_a[2]))); break;
        case 24: _t->_writeValues((*reinterpret_cast< const QList<TagAddress*>(*)>(_a[1])),(*reinterpret_cast< QModbusDataUnit(*)>(_a[2]))); break;
        case 25: _t->_readValue((*reinterpret_cast< TagAddress*(*)>(_a[1])),(*reinterpret_cast< const QModbusDataUnit(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 26: _t->_writeValue((*reinterpret_cast< TagAddress*(*)>(_a[1])),(*reinterpret_cast< QModbusDataUnit(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 27: { bool _r = _t->_isDWord((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject ModbusMasterProtocolDriver::staticMetaObject = {
    { &iDriver::staticMetaObject, qt_meta_stringdata_ModbusMasterProtocolDriver.data,
      qt_meta_data_ModbusMasterProtocolDriver,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ModbusMasterProtocolDriver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusMasterProtocolDriver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModbusMasterProtocolDriver.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "iDriver_iid"))
        return static_cast< iDriver*>(this);
    return iDriver::qt_metacast(_clname);
}

int ModbusMasterProtocolDriver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 28;
    }
    return _id;
}

QT_PLUGIN_METADATA_SECTION const uint qt_section_alignment_dummy = 42;

#ifdef QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0xbc, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0xa8, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '*',  0x00, 'c',  'o',  'm',  '.',  'c',  's', 
    'i',  'c',  '7',  '1',  '1',  '.',  'a',  'p', 
    'p',  'S',  'e',  'r',  'v',  'e',  'r',  '.', 
    'd',  'r',  'i',  'v',  'e',  'r',  's',  '.', 
    'm',  'o',  'd',  'b',  'u',  's',  'M',  'a', 
    's',  't',  'e',  'r',  0x9b, 0x0a, 0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x1a, 0x00, 'M',  'o', 
    'd',  'b',  'u',  's',  'M',  'a',  's',  't', 
    'e',  'r',  'P',  'r',  'o',  't',  'o',  'c', 
    'o',  'l',  'D',  'r',  'i',  'v',  'e',  'r', 
    0x1a, '@',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x11, 0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, 0x95, 0x13, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x8c, 0x00, 0x00, 0x00,
    'D',  0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
    'p',  0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0xbc, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0xa8, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '*',  0x00, 'c',  'o',  'm',  '.',  'c',  's', 
    'i',  'c',  '7',  '1',  '1',  '.',  'a',  'p', 
    'p',  'S',  'e',  'r',  'v',  'e',  'r',  '.', 
    'd',  'r',  'i',  'v',  'e',  'r',  's',  '.', 
    'm',  'o',  'd',  'b',  'u',  's',  'M',  'a', 
    's',  't',  'e',  'r',  0x95, 0x0a, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1b, 0x0e, 0x00, 0x00, 0x09, 0x00, 'c',  'l', 
    'a',  's',  's',  'N',  'a',  'm',  'e',  0x00,
    0x1a, 0x00, 'M',  'o',  'd',  'b',  'u',  's', 
    'M',  'a',  's',  't',  'e',  'r',  'P',  'r', 
    'o',  't',  'o',  'c',  'o',  'l',  'D',  'r', 
    'i',  'v',  'e',  'r',  '1',  0x00, 0x00, 0x00,
    0x05, 0x00, 'd',  'e',  'b',  'u',  'g',  0x00,
    0x1a, '@',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 'D',  0x00, 0x00, 0x00,
    '`',  0x00, 0x00, 0x00, 0x8c, 0x00, 0x00, 0x00,
    0x98, 0x00, 0x00, 0x00
};
#endif // QT_NO_DEBUG

QT_MOC_EXPORT_PLUGIN(ModbusMasterProtocolDriver, ModbusMasterProtocolDriver)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
