/****************************************************************************
** Meta object code from reading C++ file 'o2requestor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../o2requestor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'o2requestor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_O2Requestor_t {
    QByteArrayData data[23];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_O2Requestor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_O2Requestor_t qt_meta_stringdata_O2Requestor = {
    {
QT_MOC_LITERAL(0, 0, 11), // "O2Requestor"
QT_MOC_LITERAL(1, 12, 8), // "finished"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 2), // "id"
QT_MOC_LITERAL(4, 25, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(5, 53, 5), // "error"
QT_MOC_LITERAL(6, 59, 4), // "data"
QT_MOC_LITERAL(7, 64, 14), // "uploadProgress"
QT_MOC_LITERAL(8, 79, 9), // "bytesSent"
QT_MOC_LITERAL(9, 89, 10), // "bytesTotal"
QT_MOC_LITERAL(10, 100, 3), // "get"
QT_MOC_LITERAL(11, 104, 15), // "QNetworkRequest"
QT_MOC_LITERAL(12, 120, 3), // "req"
QT_MOC_LITERAL(13, 124, 4), // "post"
QT_MOC_LITERAL(14, 129, 3), // "put"
QT_MOC_LITERAL(15, 133, 17), // "onRefreshFinished"
QT_MOC_LITERAL(16, 151, 17), // "onRequestFinished"
QT_MOC_LITERAL(17, 169, 14), // "onRequestError"
QT_MOC_LITERAL(18, 184, 5), // "retry"
QT_MOC_LITERAL(19, 190, 6), // "finish"
QT_MOC_LITERAL(20, 197, 16), // "onUploadProgress"
QT_MOC_LITERAL(21, 214, 8), // "uploaded"
QT_MOC_LITERAL(22, 223, 5) // "total"

    },
    "O2Requestor\0finished\0\0id\0"
    "QNetworkReply::NetworkError\0error\0"
    "data\0uploadProgress\0bytesSent\0bytesTotal\0"
    "get\0QNetworkRequest\0req\0post\0put\0"
    "onRefreshFinished\0onRequestFinished\0"
    "onRequestError\0retry\0finish\0"
    "onUploadProgress\0uploaded\0total"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_O2Requestor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   69,    2, 0x06 /* Public */,
       7,    3,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   83,    2, 0x0a /* Public */,
      13,    2,   86,    2, 0x0a /* Public */,
      14,    2,   91,    2, 0x0a /* Public */,
      15,    1,   96,    2, 0x09 /* Protected */,
      16,    0,   99,    2, 0x09 /* Protected */,
      17,    1,  100,    2, 0x09 /* Protected */,
      18,    0,  103,    2, 0x09 /* Protected */,
      19,    0,  104,    2, 0x09 /* Protected */,
      20,    2,  105,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, QMetaType::QByteArray,    3,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::LongLong, QMetaType::LongLong,    3,    8,    9,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 11,   12,
    QMetaType::Int, 0x80000000 | 11, QMetaType::QByteArray,   12,    6,
    QMetaType::Int, 0x80000000 | 11, QMetaType::QByteArray,   12,    6,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   21,   22,

       0        // eod
};

void O2Requestor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        O2Requestor *_t = static_cast<O2Requestor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 1: _t->uploadProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        case 2: { int _r = _t->get((*reinterpret_cast< const QNetworkRequest(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->post((*reinterpret_cast< const QNetworkRequest(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->put((*reinterpret_cast< const QNetworkRequest(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: _t->onRefreshFinished((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 6: _t->onRequestFinished(); break;
        case 7: _t->onRequestError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 8: _t->retry(); break;
        case 9: _t->finish(); break;
        case 10: _t->onUploadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkRequest >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkRequest >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkRequest >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 7:
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
            typedef void (O2Requestor::*_t)(int , QNetworkReply::NetworkError , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O2Requestor::finished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (O2Requestor::*_t)(int , qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&O2Requestor::uploadProgress)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject O2Requestor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_O2Requestor.data,
      qt_meta_data_O2Requestor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *O2Requestor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *O2Requestor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_O2Requestor.stringdata0))
        return static_cast<void*>(const_cast< O2Requestor*>(this));
    return QObject::qt_metacast(_clname);
}

int O2Requestor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void O2Requestor::finished(int _t1, QNetworkReply::NetworkError _t2, QByteArray _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void O2Requestor::uploadProgress(int _t1, qint64 _t2, qint64 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
