/****************************************************************************
** Meta object code from reading C++ file 'userinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../userinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserInfo_t {
    QByteArrayData data[17];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserInfo_t qt_meta_stringdata_UserInfo = {
    {
QT_MOC_LITERAL(0, 0, 8), // "UserInfo"
QT_MOC_LITERAL(1, 9, 5), // "Error"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 9), // "ErrHeader"
QT_MOC_LITERAL(4, 26, 9), // "ErrorInfo"
QT_MOC_LITERAL(5, 36, 9), // "SetWidget"
QT_MOC_LITERAL(6, 46, 8), // "QWidget*"
QT_MOC_LITERAL(7, 55, 6), // "Widget"
QT_MOC_LITERAL(8, 62, 9), // "SetHeader"
QT_MOC_LITERAL(9, 72, 10), // "HeaderName"
QT_MOC_LITERAL(10, 83, 19), // "Signal_ShowAccounts"
QT_MOC_LITERAL(11, 103, 12), // "OnCreateUser"
QT_MOC_LITERAL(12, 116, 11), // "OnLoginUser"
QT_MOC_LITERAL(13, 128, 10), // "OnEditUser"
QT_MOC_LITERAL(14, 139, 12), // "OnEditCancel"
QT_MOC_LITERAL(15, 152, 10), // "OnSaveUser"
QT_MOC_LITERAL(16, 163, 10) // "OnAccounts"

    },
    "UserInfo\0Error\0\0ErrHeader\0ErrorInfo\0"
    "SetWidget\0QWidget*\0Widget\0SetHeader\0"
    "HeaderName\0Signal_ShowAccounts\0"
    "OnCreateUser\0OnLoginUser\0OnEditUser\0"
    "OnEditCancel\0OnSaveUser\0OnAccounts"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserInfo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    1,   69,    2, 0x06 /* Public */,
       8,    1,   72,    2, 0x06 /* Public */,
      10,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,
      13,    0,   78,    2, 0x08 /* Private */,
      14,    0,   79,    2, 0x08 /* Private */,
      15,    0,   80,    2, 0x08 /* Private */,
      16,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Error((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->SetWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 2: _t->SetHeader((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->Signal_ShowAccounts(); break;
        case 4: _t->OnCreateUser(); break;
        case 5: _t->OnLoginUser(); break;
        case 6: _t->OnEditUser(); break;
        case 7: _t->OnEditCancel(); break;
        case 8: _t->OnSaveUser(); break;
        case 9: _t->OnAccounts(); break;
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
            using _t = void (UserInfo::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserInfo::Error)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UserInfo::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserInfo::SetWidget)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UserInfo::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserInfo::SetHeader)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (UserInfo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserInfo::Signal_ShowAccounts)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UserInfo::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_UserInfo.data,
    qt_meta_data_UserInfo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UserInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserInfo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UserInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void UserInfo::Error(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UserInfo::SetWidget(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UserInfo::SetHeader(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UserInfo::Signal_ShowAccounts()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
