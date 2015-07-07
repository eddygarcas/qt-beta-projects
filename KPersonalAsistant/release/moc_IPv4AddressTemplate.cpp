/****************************************************************************
** Meta object code from reading C++ file 'IPv4AddressTemplate.h'
**
** Created: Fri 21. Nov 11:32:21 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/ScreenTemplates/IPv4AddressTemplate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IPv4AddressTemplate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IPv4AddressTemplate[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      30,   21,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_IPv4AddressTemplate[] = {
    "IPv4AddressTemplate\0\0_address\0"
    "giveBackAddress(QString)\0"
};

const QMetaObject IPv4AddressTemplate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IPv4AddressTemplate,
      qt_meta_data_IPv4AddressTemplate, 0 }
};

const QMetaObject *IPv4AddressTemplate::metaObject() const
{
    return &staticMetaObject;
}

void *IPv4AddressTemplate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IPv4AddressTemplate))
        return static_cast<void*>(const_cast< IPv4AddressTemplate*>(this));
    if (!strcmp(_clname, "Ui::IPv4AddressScreen"))
        return static_cast< Ui::IPv4AddressScreen*>(const_cast< IPv4AddressTemplate*>(this));
    if (!strcmp(_clname, "ScreenTemplate"))
        return static_cast< ScreenTemplate*>(const_cast< IPv4AddressTemplate*>(this));
    return QWidget::qt_metacast(_clname);
}

int IPv4AddressTemplate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: giveBackAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void IPv4AddressTemplate::giveBackAddress(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
