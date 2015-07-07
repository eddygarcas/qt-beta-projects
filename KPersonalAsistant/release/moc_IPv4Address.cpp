/****************************************************************************
** Meta object code from reading C++ file 'IPv4Address.h'
**
** Created: Fri 21. Nov 11:32:46 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/ScreenTemplates/IPv4Address.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IPv4Address.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IPv4Address[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   10, // methods
       1,   35, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   39,   12,   12, 0x0a,
      75,   39,   12,   12, 0x0a,
     106,   12,   12,   12, 0x0a,
     137,   12,   12,   12, 0x0a,

 // properties: name, type, flags
     164,  156, 0x0a095103,

       0        // eod
};

static const char qt_meta_stringdata_IPv4Address[] = {
    "IPv4Address\0\0ipAddressChanged(QString)\0"
    "_ipValue\0append_ip_address(QString)\0"
    "append_ip_address_value(QChar)\0"
    "remove_last_ip_address_value()\0"
    "finished_edition()\0QString\0addressTextLavel\0"
};

const QMetaObject IPv4Address::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IPv4Address,
      qt_meta_data_IPv4Address, 0 }
};

const QMetaObject *IPv4Address::metaObject() const
{
    return &staticMetaObject;
}

void *IPv4Address::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IPv4Address))
        return static_cast<void*>(const_cast< IPv4Address*>(this));
    return QWidget::qt_metacast(_clname);
}

int IPv4Address::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ipAddressChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: append_ip_address((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: append_ip_address_value((*reinterpret_cast< QChar(*)>(_a[1]))); break;
        case 3: remove_last_ip_address_value(); break;
        case 4: finished_edition(); break;
        }
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = addressTextLavel(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setAddressTextLavel(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
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
void IPv4Address::ipAddressChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
