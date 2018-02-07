/****************************************************************************
** Meta object code from reading C++ file 'irtdata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Interface/RTData/irtdata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'irtdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_iRTData_t {
    QByteArrayData data[25];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iRTData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iRTData_t qt_meta_stringdata_iRTData = {
    {
QT_MOC_LITERAL(0, 0, 7), // "iRTData"
QT_MOC_LITERAL(1, 8, 14), // "tagListChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16), // "QList<iTagInfo*>"
QT_MOC_LITERAL(4, 41, 4), // "tags"
QT_MOC_LITERAL(5, 46, 7), // "tagList"
QT_MOC_LITERAL(6, 54, 15), // "QList<QObject*>"
QT_MOC_LITERAL(7, 70, 7), // "allTags"
QT_MOC_LITERAL(8, 78, 12), // "allAddresses"
QT_MOC_LITERAL(9, 91, 18), // "QList<TagAddress*>"
QT_MOC_LITERAL(10, 110, 5), // "names"
QT_MOC_LITERAL(11, 116, 7), // "tagInfo"
QT_MOC_LITERAL(12, 124, 4), // "name"
QT_MOC_LITERAL(13, 129, 8), // "contains"
QT_MOC_LITERAL(14, 138, 11), // "tagInfoName"
QT_MOC_LITERAL(15, 150, 9), // "iTagInfo*"
QT_MOC_LITERAL(16, 160, 6), // "ignore"
QT_MOC_LITERAL(17, 167, 6), // "showUI"
QT_MOC_LITERAL(18, 174, 4), // "show"
QT_MOC_LITERAL(19, 179, 8), // "QWidget*"
QT_MOC_LITERAL(20, 188, 6), // "parent"
QT_MOC_LITERAL(21, 195, 13), // "insertTagInfo"
QT_MOC_LITERAL(22, 209, 3), // "pos"
QT_MOC_LITERAL(23, 213, 7), // "tagName"
QT_MOC_LITERAL(24, 221, 13) // "removeTagInfo"

    },
    "iRTData\0tagListChanged\0\0QList<iTagInfo*>\0"
    "tags\0tagList\0QList<QObject*>\0allTags\0"
    "allAddresses\0QList<TagAddress*>\0names\0"
    "tagInfo\0name\0contains\0tagInfoName\0"
    "iTagInfo*\0ignore\0showUI\0show\0QWidget*\0"
    "parent\0insertTagInfo\0pos\0tagName\0"
    "removeTagInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iRTData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       1,  130, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   92,    2, 0x0a /* Public */,
       7,    0,   93,    2, 0x0a /* Public */,
       8,    0,   94,    2, 0x0a /* Public */,
      10,    0,   95,    2, 0x0a /* Public */,
      11,    1,   96,    2, 0x0a /* Public */,
      13,    2,   99,    2, 0x0a /* Public */,
      13,    1,  104,    2, 0x2a /* Public | MethodCloned */,
      17,    2,  107,    2, 0x0a /* Public */,
      17,    1,  112,    2, 0x2a /* Public | MethodCloned */,
      17,    0,  115,    2, 0x2a /* Public | MethodCloned */,
      21,    2,  116,    2, 0x0a /* Public */,
      21,    1,  121,    2, 0x2a /* Public | MethodCloned */,
      24,    1,  124,    2, 0x0a /* Public */,
      24,    1,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    0x80000000 | 6,
    0x80000000 | 3,
    0x80000000 | 9,
    QMetaType::QStringList,
    QMetaType::QObjectStar, QMetaType::QString,   12,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 15,   14,   16,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 19,   18,   20,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Int, QMetaType::QString,   22,   23,
    QMetaType::Bool, QMetaType::Int,   22,
    QMetaType::Bool, QMetaType::QString,   23,
    QMetaType::Bool, QMetaType::Int,   22,

 // properties: name, type, flags
       5, 0x80000000 | 6, 0x00495009,

 // properties: notify_signal_id
       0,

       0        // eod
};

void iRTData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        iRTData *_t = static_cast<iRTData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tagListChanged((*reinterpret_cast< const QList<iTagInfo*>(*)>(_a[1]))); break;
        case 1: { QList<QObject*> _r = _t->tagList();
            if (_a[0]) *reinterpret_cast< QList<QObject*>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QList<iTagInfo*> _r = _t->allTags();
            if (_a[0]) *reinterpret_cast< QList<iTagInfo*>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QList<TagAddress*> _r = _t->allAddresses();
            if (_a[0]) *reinterpret_cast< QList<TagAddress*>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QStringList _r = _t->names();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 5: { QObject* _r = _t->tagInfo((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->contains((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< iTagInfo*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->contains((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->showUI((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 9: _t->showUI((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->showUI(); break;
        case 11: { bool _r = _t->insertTagInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->insertTagInfo((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->removeTagInfo((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->removeTagInfo((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<iTagInfo*> >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< iTagInfo* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (iRTData::*_t)(const QList<iTagInfo*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iRTData::tagListChanged)) {
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
        iRTData *_t = static_cast<iRTData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QObject*>*>(_v) = _t->tagList(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject iRTData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_iRTData.data,
      qt_meta_data_iRTData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *iRTData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iRTData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_iRTData.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "iLoadSave"))
        return static_cast< iLoadSave*>(this);
    return QObject::qt_metacast(_clname);
}

int iRTData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
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
void iRTData::tagListChanged(const QList<iTagInfo*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
