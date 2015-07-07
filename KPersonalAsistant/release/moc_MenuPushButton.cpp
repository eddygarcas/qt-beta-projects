/****************************************************************************
** Meta object code from reading C++ file 'MenuPushButton.h'
**
** Created: Fri 21. Nov 11:32:45 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/ScreenTemplates/MenuPushButton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MenuPushButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MenuPushButton[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   10, // methods
       5,   20, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   50,   15,   15, 0x0a,

 // properties: name, type, flags
      90,   84, 0x45095103,
     102,   84, 0x45095103,
     121,  115, 0x15095103,
     137,  132, 0x01095103,
     159,  151, 0x0a095103,

       0        // eod
};

static const char qt_meta_stringdata_MenuPushButton[] = {
    "MenuPushButton\0\0_test\0text_to_status_bar(QString)\0"
    "checked\0menu_button_clicked(bool)\0"
    "QIcon\0onfocusIcon\0outfocusIcon\0QSize\0"
    "buttonSize\0bool\0buttonEnabled\0QString\0"
    "buttonInformation\0"
};

const QMetaObject MenuPushButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_MenuPushButton,
      qt_meta_data_MenuPushButton, 0 }
};

const QMetaObject *MenuPushButton::metaObject() const
{
    return &staticMetaObject;
}

void *MenuPushButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MenuPushButton))
        return static_cast<void*>(const_cast< MenuPushButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int MenuPushButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: text_to_status_bar((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: menu_button_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        }
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QIcon*>(_v) = onfocusIcon(); break;
        case 1: *reinterpret_cast< QIcon*>(_v) = outfocusIcon(); break;
        case 2: *reinterpret_cast< QSize*>(_v) = buttonSize(); break;
        case 3: *reinterpret_cast< bool*>(_v) = buttonEnabled(); break;
        case 4: *reinterpret_cast< QString*>(_v) = buttonInformation(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setOnfocusIcon(*reinterpret_cast< QIcon*>(_v)); break;
        case 1: setOutfocusIcon(*reinterpret_cast< QIcon*>(_v)); break;
        case 2: setButtonSize(*reinterpret_cast< QSize*>(_v)); break;
        case 3: setButtonEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 4: setButtonInformation(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MenuPushButton::text_to_status_bar(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
