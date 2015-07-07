/****************************************************************************
** Meta object code from reading C++ file 'StatusBar.h'
**
** Created: Fri 21. Nov 11:32:41 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/ScreenTemplates/StatusBar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StatusBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StatusBar[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       1,   15, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,

 // properties: name, type, flags
      39,   31, 0x0a095002,

       0        // eod
};

static const char qt_meta_stringdata_StatusBar[] = {
    "StatusBar\0\0statusText(QString)\0QString\0"
    "statusText\0"
};

const QMetaObject StatusBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StatusBar,
      qt_meta_data_StatusBar, 0 }
};

const QMetaObject *StatusBar::metaObject() const
{
    return &staticMetaObject;
}

void *StatusBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StatusBar))
        return static_cast<void*>(const_cast< StatusBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int StatusBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: statusText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        }
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: statusText(*reinterpret_cast< QString*>(_v)); break;
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
QT_END_MOC_NAMESPACE
