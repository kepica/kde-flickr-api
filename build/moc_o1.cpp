/****************************************************************************
** Meta object code from reading C++ file 'o1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../o1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'o1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_O1_t {
    QByteArrayData data[24];
    char stringdata0[394];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_O1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_O1_t qt_meta_stringdata_O1 = {
    {
QT_MOC_LITERAL(0, 0, 2), // "O1"
QT_MOC_LITERAL(1, 3, 22), // "requestTokenUrlChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 19), // "authorizeUrlChanged"
QT_MOC_LITERAL(4, 47, 21), // "accessTokenUrlChanged"
QT_MOC_LITERAL(5, 69, 22), // "signatureMethodChanged"
QT_MOC_LITERAL(6, 92, 4), // "link"
QT_MOC_LITERAL(7, 97, 6), // "unlink"
QT_MOC_LITERAL(8, 104, 22), // "onVerificationReceived"
QT_MOC_LITERAL(9, 127, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(10, 149, 6), // "params"
QT_MOC_LITERAL(11, 156, 19), // "onTokenRequestError"
QT_MOC_LITERAL(12, 176, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(13, 204, 5), // "error"
QT_MOC_LITERAL(14, 210, 22), // "onTokenRequestFinished"
QT_MOC_LITERAL(15, 233, 20), // "onTokenExchangeError"
QT_MOC_LITERAL(16, 254, 23), // "onTokenExchangeFinished"
QT_MOC_LITERAL(17, 278, 15), // "signatureMethod"
QT_MOC_LITERAL(18, 294, 15), // "requestTokenUrl"
QT_MOC_LITERAL(19, 310, 17), // "requestParameters"
QT_MOC_LITERAL(20, 328, 25), // "QList<O0RequestParameter>"
QT_MOC_LITERAL(21, 354, 11), // "callbackUrl"
QT_MOC_LITERAL(22, 366, 12), // "authorizeUrl"
QT_MOC_LITERAL(23, 379, 14) // "accessTokenUrl"

    },
    "O1\0requestTokenUrlChanged\0\0"
    "authorizeUrlChanged\0accessTokenUrlChanged\0"
    "signatureMethodChanged\0link\0unlink\0"
    "onVerificationReceived\0QMap<QString,QString>\0"
    "params\0onTokenRequestError\0"
    "QNetworkReply::NetworkError\0error\0"
    "onTokenRequestFinished\0onTokenExchangeError\0"
    "onTokenExchangeFinished\0signatureMethod\0"
    "requestTokenUrl\0requestParameters\0"
    "QList<O0RequestParameter>\0callbackUrl\0"
    "authorizeUrl\0accessTokenUrl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_O1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       6,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    1,   75,    2, 0x09 /* Protected */,
      11,    1,   78,    2, 0x09 /* Protected */,
      14,    0,   81,    2, 0x09 /* Protected */,
      15,    1,   82,    2, 0x09 /* Protected */,
      16,    0,   85,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

 // properties: name, type, flags
      17, QMetaType::QString, 0x00495103,
      18, QMetaType::QUrl, 0x00495103,
      19, 0x80000000 | 20, 0x0009510b,
      21, QMetaType::QString, 0x00095103,
      22, QMetaType::QUrl, 0x00495103,
      23, QMetaType::QUrl, 0x00495103,

 // properties: notify_signal_id
       3,
       0,
       0,
       0,
       1,
       2,

       0        // eod
};

void O1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        O1 *_t = static_cast<O1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->requestTokenUrlChanged(); break;
        case 1: _t->authorizeUrlChanged(); break;
        case 2: _t->accessTokenUrlChanged(); break;
        case 3: _t->signatureMethodChanged(); break;
        case 4: _t->link(); break;
        case 5: _t->unlink(); break;
        case 6: _t->onVerificationReceived((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        case 7: _t->onTokenRequestError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 8: _t->onTokenRequestFinished(); break;
        case 9: _t->onTokenExchangeError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 10: _t->onTokenExchangeFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (O1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O1::requestTokenUrlChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (O1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O1::authorizeUrlChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (O1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O1::accessTokenUrlChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (O1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O1::signatureMethodChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        O1 *_t = static_cast<O1 *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->signatureMethod(); break;
        case 1: *reinterpret_cast< QUrl*>(_v) = _t->requestTokenUrl(); break;
        case 2: *reinterpret_cast< QList<O0RequestParameter>*>(_v) = _t->requestParameters(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->callbackUrl(); break;
        case 4: *reinterpret_cast< QUrl*>(_v) = _t->authorizeUrl(); break;
        case 5: *reinterpret_cast< QUrl*>(_v) = _t->accessTokenUrl(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        O1 *_t = static_cast<O1 *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSignatureMethod(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setRequestTokenUrl(*reinterpret_cast< QUrl*>(_v)); break;
        case 2: _t->setRequestParameters(*reinterpret_cast< QList<O0RequestParameter>*>(_v)); break;
        case 3: _t->setCallbackUrl(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setAuthorizeUrl(*reinterpret_cast< QUrl*>(_v)); break;
        case 5: _t->setAccessTokenUrl(*reinterpret_cast< QUrl*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject O1::staticMetaObject = {
    { &O0BaseAuth::staticMetaObject, qt_meta_stringdata_O1.data,
      qt_meta_data_O1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *O1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *O1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_O1.stringdata0))
        return static_cast<void*>(const_cast< O1*>(this));
    return O0BaseAuth::qt_metacast(_clname);
}

int O1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = O0BaseAuth::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void O1::requestTokenUrlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void O1::authorizeUrlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void O1::accessTokenUrlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void O1::signatureMethodChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
