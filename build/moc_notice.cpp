/****************************************************************************
** Meta object code from reading C++ file 'notice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../notice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Notice_t {
    QByteArrayData data[3];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Notice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Notice_t qt_meta_stringdata_Notice = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Notice"
QT_MOC_LITERAL(1, 7, 11), // "staviNotice"
QT_MOC_LITERAL(2, 19, 0) // ""

    },
    "Notice\0staviNotice\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Notice[] = {

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

void Notice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Notice *_t = static_cast<Notice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->staviNotice(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Notice::staticMetaObject = {
    { &KStatusNotifierItem::staticMetaObject, qt_meta_stringdata_Notice.data,
      qt_meta_data_Notice,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Notice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Notice::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Notice.stringdata0))
        return static_cast<void*>(const_cast< Notice*>(this));
    return KStatusNotifierItem::qt_metacast(_clname);
}

int Notice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KStatusNotifierItem::qt_metacall(_c, _id, _a);
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
