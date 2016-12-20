/****************************************************************************
** Meta object code from reading C++ file 'o1requestor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../o1requestor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'o1requestor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_O1Requestor_t {
    QByteArrayData data[13];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_O1Requestor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_O1Requestor_t qt_meta_stringdata_O1Requestor = {
    {
QT_MOC_LITERAL(0, 0, 11), // "O1Requestor"
QT_MOC_LITERAL(1, 12, 3), // "get"
QT_MOC_LITERAL(2, 16, 14), // "QNetworkReply*"
QT_MOC_LITERAL(3, 31, 0), // ""
QT_MOC_LITERAL(4, 32, 15), // "QNetworkRequest"
QT_MOC_LITERAL(5, 48, 3), // "req"
QT_MOC_LITERAL(6, 52, 25), // "QList<O0RequestParameter>"
QT_MOC_LITERAL(7, 78, 17), // "signingParameters"
QT_MOC_LITERAL(8, 96, 4), // "post"
QT_MOC_LITERAL(9, 101, 4), // "data"
QT_MOC_LITERAL(10, 106, 15), // "QHttpMultiPart*"
QT_MOC_LITERAL(11, 122, 9), // "multiPart"
QT_MOC_LITERAL(12, 132, 3) // "put"

    },
    "O1Requestor\0get\0QNetworkReply*\0\0"
    "QNetworkRequest\0req\0QList<O0RequestParameter>\0"
    "signingParameters\0post\0data\0QHttpMultiPart*\0"
    "multiPart\0put"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_O1Requestor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    3, 0x0a /* Public */,
       8,    3,   39,    3, 0x0a /* Public */,
       8,    3,   46,    3, 0x0a /* Public */,
      12,    3,   53,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    0x80000000 | 2, 0x80000000 | 4, 0x80000000 | 6, QMetaType::QByteArray,    5,    7,    9,
    0x80000000 | 2, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 10,    5,    7,   11,
    0x80000000 | 2, 0x80000000 | 4, 0x80000000 | 6, QMetaType::QByteArray,    5,    7,    9,

       0        // eod
};

void O1Requestor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        O1Requestor *_t = static_cast<O1Requestor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QNetworkReply* _r = _t->get((*reinterpret_cast< const QNetworkRequest(*)>(_a[1])),(*reinterpret_cast< const QList<O0RequestParameter>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QNetworkReply**>(_a[0]) = _r; }  break;
        case 1: { QNetworkReply* _r = _t->post((*reinterpret_cast< const QNetworkRequest(*)>(_a[1])),(*reinterpret_cast< const QList<O0RequestParameter>(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QNetworkReply**>(_a[0]) = _r; }  break;
        case 2: { QNetworkReply* _r = _t->post((*reinterpret_cast< const QNetworkRequest(*)>(_a[1])),(*reinterpret_cast< const QList<O0RequestParameter>(*)>(_a[2])),(*reinterpret_cast< QHttpMultiPart*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QNetworkReply**>(_a[0]) = _r; }  break;
        case 3: { QNetworkReply* _r = _t->put((*reinterpret_cast< const QNetworkRequest(*)>(_a[1])),(*reinterpret_cast< const QList<O0RequestParameter>(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QNetworkReply**>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkRequest >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkRequest >(); break;
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
        }
    }
}

const QMetaObject O1Requestor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_O1Requestor.data,
      qt_meta_data_O1Requestor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *O1Requestor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *O1Requestor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_O1Requestor.stringdata0))
        return static_cast<void*>(const_cast< O1Requestor*>(this));
    return QObject::qt_metacast(_clname);
}

int O1Requestor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
