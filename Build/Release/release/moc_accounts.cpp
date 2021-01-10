/****************************************************************************
** Meta object code from reading C++ file 'accounts.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../accounts.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accounts.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Accounts_t {
    QByteArrayData data[18];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Accounts_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Accounts_t qt_meta_stringdata_Accounts = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Accounts"
QT_MOC_LITERAL(1, 9, 5), // "Error"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 9), // "ErrHeader"
QT_MOC_LITERAL(4, 26, 9), // "ErrorInfo"
QT_MOC_LITERAL(5, 36, 9), // "SetWidget"
QT_MOC_LITERAL(6, 46, 8), // "QWidget*"
QT_MOC_LITERAL(7, 55, 6), // "Widget"
QT_MOC_LITERAL(8, 62, 9), // "SetHeader"
QT_MOC_LITERAL(9, 72, 10), // "HeaderName"
QT_MOC_LITERAL(10, 83, 14), // "OnItemSelected"
QT_MOC_LITERAL(11, 98, 5), // "OnNew"
QT_MOC_LITERAL(12, 104, 14), // "OnNewCancelled"
QT_MOC_LITERAL(13, 119, 9), // "OnNewSave"
QT_MOC_LITERAL(14, 129, 6), // "OnEdit"
QT_MOC_LITERAL(15, 136, 15), // "OnEditCancelled"
QT_MOC_LITERAL(16, 152, 10), // "OnEditSave"
QT_MOC_LITERAL(17, 163, 8) // "OnDelete"

    },
    "Accounts\0Error\0\0ErrHeader\0ErrorInfo\0"
    "SetWidget\0QWidget*\0Widget\0SetHeader\0"
    "HeaderName\0OnItemSelected\0OnNew\0"
    "OnNewCancelled\0OnNewSave\0OnEdit\0"
    "OnEditCancelled\0OnEditSave\0OnDelete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Accounts[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    1,   74,    2, 0x06 /* Public */,
       8,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   80,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,
      12,    0,   82,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,
      14,    0,   84,    2, 0x08 /* Private */,
      15,    0,   85,    2, 0x08 /* Private */,
      16,    0,   86,    2, 0x08 /* Private */,
      17,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Accounts::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Accounts *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Error((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->SetWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 2: _t->SetHeader((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->OnItemSelected(); break;
        case 4: _t->OnNew(); break;
        case 5: _t->OnNewCancelled(); break;
        case 6: _t->OnNewSave(); break;
        case 7: _t->OnEdit(); break;
        case 8: _t->OnEditCancelled(); break;
        case 9: _t->OnEditSave(); break;
        case 10: _t->OnDelete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Accounts::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Accounts::Error)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Accounts::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Accounts::SetWidget)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Accounts::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Accounts::SetHeader)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Accounts::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Accounts.data,
    qt_meta_data_Accounts,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Accounts::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Accounts::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Accounts.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Accounts::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Accounts::Error(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Accounts::SetWidget(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Accounts::SetHeader(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
