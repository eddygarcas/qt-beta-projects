/****************************************************************************
** Meta object code from reading C++ file 'ScreenTitle.h'
**
** Created: Fri 21. Nov 11:32:36 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/ScreenTemplates/ScreenTitle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScreenTitle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScreenTitle[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   10, // properties
       0,    0, // enums/sets

 // properties: name, type, flags
      20,   12, 0x0a095103,

       0        // eod
};

static const char qt_meta_stringdata_ScreenTitle[] = {
    "ScreenTitle\0QString\0screenTitle\0"
};

const QMetaObject ScreenTitle::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ScreenTitle,
      qt_meta_data_ScreenTitle, 0 }
};

const QMetaObject *ScreenTitle::metaObject() const
{
    return &staticMetaObject;
}

void *ScreenTitle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScreenTitle))
        return static_cast<void*>(const_cast< ScreenTitle*>(this));
    return QWidget::qt_metacast(_clname);
}

int ScreenTitle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = screenTitle(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setScreenTitle(*reinterpret_cast< QString*>(_v)); break;
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
