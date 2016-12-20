/****************************************************************************
** Meta object code from reading C++ file 'o2replyserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../o2replyserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'o2replyserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_O2ReplyServer_t {
    QByteArrayData data[10];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_O2ReplyServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_O2ReplyServer_t qt_meta_stringdata_O2ReplyServer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "O2ReplyServer"
QT_MOC_LITERAL(1, 14, 20), // "verificationReceived"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(4, 58, 20), // "onIncomingConnection"
QT_MOC_LITERAL(5, 79, 12), // "onBytesReady"
QT_MOC_LITERAL(6, 92, 16), // "parseQueryParams"
QT_MOC_LITERAL(7, 109, 11), // "QByteArray*"
QT_MOC_LITERAL(8, 121, 4), // "data"
QT_MOC_LITERAL(9, 126, 12) // "replyContent"

    },
    "O2ReplyServer\0verificationReceived\0\0"
    "QMap<QString,QString>\0onIncomingConnection\0"
    "onBytesReady\0parseQueryParams\0QByteArray*\0"
    "data\0replyContent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_O2ReplyServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   42, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 3, 0x80000000 | 7,    8,

 // properties: name, type, flags
       9, QMetaType::QByteArray, 0x00095103,

       0        // eod
};

void O2ReplyServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        O2ReplyServer *_t = static_cast<O2ReplyServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->verificationReceived((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        case 1: _t->onIncomingConnection(); break;
        case 2: _t->onBytesReady(); break;
        case 3: { QMap<QString,QString> _r = _t->parseQueryParams((*reinterpret_cast< QByteArray*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMap<QString,QString>*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (O2ReplyServer::*_t)(QMap<QString,QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O2ReplyServer::verificationReceived)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        O2ReplyServer *_t = static_cast<O2ReplyServer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QByteArray*>(_v) = _t->replyContent(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        O2ReplyServer *_t = static_cast<O2ReplyServer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setReplyContent(*reinterpret_cast< QByteArray*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject O2ReplyServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_O2ReplyServer.data,
      qt_meta_data_O2ReplyServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *O2ReplyServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *O2ReplyServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_O2ReplyServer.stringdata0))
        return static_cast<void*>(const_cast< O2ReplyServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int O2ReplyServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
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
void O2ReplyServer::verificationReceived(QMap<QString,QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
