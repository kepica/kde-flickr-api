/****************************************************************************
** Meta object code from reading C++ file 'o0baseauth.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../o0baseauth.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'o0baseauth.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_O0BaseAuth_t {
    QByteArrayData data[23];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_O0BaseAuth_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_O0BaseAuth_t qt_meta_stringdata_O0BaseAuth = {
    {
QT_MOC_LITERAL(0, 0, 10), // "O0BaseAuth"
QT_MOC_LITERAL(1, 11, 11), // "openBrowser"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "url"
QT_MOC_LITERAL(4, 28, 12), // "closeBrowser"
QT_MOC_LITERAL(5, 41, 16), // "linkingSucceeded"
QT_MOC_LITERAL(6, 58, 13), // "linkingFailed"
QT_MOC_LITERAL(7, 72, 13), // "linkedChanged"
QT_MOC_LITERAL(8, 86, 15), // "clientIdChanged"
QT_MOC_LITERAL(9, 102, 19), // "clientSecretChanged"
QT_MOC_LITERAL(10, 122, 16), // "localPortChanged"
QT_MOC_LITERAL(11, 139, 12), // "tokenChanged"
QT_MOC_LITERAL(12, 152, 18), // "tokenSecretChanged"
QT_MOC_LITERAL(13, 171, 18), // "extraTokensChanged"
QT_MOC_LITERAL(14, 190, 4), // "link"
QT_MOC_LITERAL(15, 195, 6), // "unlink"
QT_MOC_LITERAL(16, 202, 6), // "linked"
QT_MOC_LITERAL(17, 209, 5), // "token"
QT_MOC_LITERAL(18, 215, 11), // "tokenSecret"
QT_MOC_LITERAL(19, 227, 11), // "extraTokens"
QT_MOC_LITERAL(20, 239, 8), // "clientId"
QT_MOC_LITERAL(21, 248, 12), // "clientSecret"
QT_MOC_LITERAL(22, 261, 9) // "localPort"

    },
    "O0BaseAuth\0openBrowser\0\0url\0closeBrowser\0"
    "linkingSucceeded\0linkingFailed\0"
    "linkedChanged\0clientIdChanged\0"
    "clientSecretChanged\0localPortChanged\0"
    "tokenChanged\0tokenSecretChanged\0"
    "extraTokensChanged\0link\0unlink\0linked\0"
    "token\0tokenSecret\0extraTokens\0clientId\0"
    "clientSecret\0localPort"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_O0BaseAuth[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       7,   94, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    0,   82,    2, 0x06 /* Public */,
       5,    0,   83,    2, 0x06 /* Public */,
       6,    0,   84,    2, 0x06 /* Public */,
       7,    0,   85,    2, 0x06 /* Public */,
       8,    0,   86,    2, 0x06 /* Public */,
       9,    0,   87,    2, 0x06 /* Public */,
      10,    0,   88,    2, 0x06 /* Public */,
      11,    0,   89,    2, 0x06 /* Public */,
      12,    0,   90,    2, 0x06 /* Public */,
      13,    0,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   92,    2, 0x0a /* Public */,
      15,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QUrl,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      16, QMetaType::Bool, 0x00495103,
      17, QMetaType::QString, 0x00495001,
      18, QMetaType::QString, 0x00495001,
      19, QMetaType::QVariantMap, 0x00495001,
      20, QMetaType::QString, 0x00495103,
      21, QMetaType::QString, 0x00495103,
      22, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       4,
       8,
       9,
      10,
       5,
       6,
       7,

       0        // eod
};

void O0BaseAuth::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        O0BaseAuth *_t = static_cast<O0BaseAuth *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openBrowser((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 1: _t->closeBrowser(); break;
        case 2: _t->linkingSucceeded(); break;
        case 3: _t->linkingFailed(); break;
        case 4: _t->linkedChanged(); break;
        case 5: _t->clientIdChanged(); break;
        case 6: _t->clientSecretChanged(); break;
        case 7: _t->localPortChanged(); break;
        case 8: _t->tokenChanged(); break;
        case 9: _t->tokenSecretChanged(); break;
        case 10: _t->extraTokensChanged(); break;
        case 11: _t->link(); break;
        case 12: _t->unlink(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (O0BaseAuth::*_t)(const QUrl & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O0BaseAuth::openBrowser)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (O0BaseAuth::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O0BaseAuth::closeBrowser)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (O0BaseAuth::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O0BaseAuth::linkingSucceeded)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (O0BaseAuth::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O0BaseAuth::linkingFailed)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (O0BaseAuth::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O0BaseAuth::linkedChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (O0BaseAuth::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O0BaseAuth::clientIdChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (O0BaseAuth::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O0BaseAuth::clientSecretChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (O0BaseAuth::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O0BaseAuth::localPortChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (O0BaseAuth::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O0BaseAuth::tokenChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (O0BaseAuth::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O0BaseAuth::tokenSecretChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (O0BaseAuth::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O0BaseAuth::extraTokensChanged)) {
                *result = 10;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        O0BaseAuth *_t = static_cast<O0BaseAuth *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->linked(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->token(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->tokenSecret(); break;
        case 3: *reinterpret_cast< QVariantMap*>(_v) = _t->extraTokens(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->clientId(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->clientSecret(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->localPort(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        O0BaseAuth *_t = static_cast<O0BaseAuth *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLinked(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setClientId(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setClientSecret(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setLocalPort(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject O0BaseAuth::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_O0BaseAuth.data,
      qt_meta_data_O0BaseAuth,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *O0BaseAuth::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *O0BaseAuth::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_O0BaseAuth.stringdata0))
        return static_cast<void*>(const_cast< O0BaseAuth*>(this));
    return QObject::qt_metacast(_clname);
}

int O0BaseAuth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void O0BaseAuth::openBrowser(const QUrl & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void O0BaseAuth::closeBrowser()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void O0BaseAuth::linkingSucceeded()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void O0BaseAuth::linkingFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void O0BaseAuth::linkedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void O0BaseAuth::clientIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void O0BaseAuth::clientSecretChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void O0BaseAuth::localPortChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void O0BaseAuth::tokenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void O0BaseAuth::tokenSecretChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void O0BaseAuth::extraTokensChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
