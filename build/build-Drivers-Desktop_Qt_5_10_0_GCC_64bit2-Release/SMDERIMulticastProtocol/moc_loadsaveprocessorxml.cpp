/****************************************************************************
** Meta object code from reading C++ file 'loadsaveprocessorxml.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../lib/loadSaveProcessor/src/loadsaveprocessorxml.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loadsaveprocessorxml.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_loadSaveProcessorXml_t {
    QByteArrayData data[5];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_loadSaveProcessorXml_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_loadSaveProcessorXml_t qt_meta_stringdata_loadSaveProcessorXml = {
    {
QT_MOC_LITERAL(0, 0, 20), // "loadSaveProcessorXml"
QT_MOC_LITERAL(1, 21, 13), // "resXmlRefresh"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "resXmlFilePathChanged"
QT_MOC_LITERAL(4, 58, 14) // "resXmlFilePath"

    },
    "loadSaveProcessorXml\0resXmlRefresh\0\0"
    "resXmlFilePathChanged\0resXmlFilePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_loadSaveProcessorXml[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       1,   26, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       1,

       0        // eod
};

void loadSaveProcessorXml::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        loadSaveProcessorXml *_t = static_cast<loadSaveProcessorXml *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resXmlRefresh(); break;
        case 1: _t->resXmlFilePathChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (loadSaveProcessorXml::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&loadSaveProcessorXml::resXmlRefresh)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (loadSaveProcessorXml::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&loadSaveProcessorXml::resXmlFilePathChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        loadSaveProcessorXml *_t = static_cast<loadSaveProcessorXml *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getResXmlFilePath(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        loadSaveProcessorXml *_t = static_cast<loadSaveProcessorXml *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setResXmlFilePath(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject loadSaveProcessorXml::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_loadSaveProcessorXml.data,
      qt_meta_data_loadSaveProcessorXml,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *loadSaveProcessorXml::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *loadSaveProcessorXml::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_loadSaveProcessorXml.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "iLoadSaveProcessor"))
        return static_cast< iLoadSaveProcessor*>(this);
    return QObject::qt_metacast(_clname);
}

int loadSaveProcessorXml::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
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
void loadSaveProcessorXml::resXmlRefresh()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void loadSaveProcessorXml::resXmlFilePathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
