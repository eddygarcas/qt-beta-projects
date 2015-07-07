/****************************************************************************
** Meta object code from reading C++ file 'MainMenuModelAction.h'
**
** Created: Fri 21. Nov 11:32:51 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/Actions/MainMenuModelAction.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainMenuModelAction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainMenuModelAction[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_MainMenuModelAction[] = {
    "MainMenuModelAction\0"
};

const QMetaObject MainMenuModelAction::staticMetaObject = {
    { &ModelAction::staticMetaObject, qt_meta_stringdata_MainMenuModelAction,
      qt_meta_data_MainMenuModelAction, 0 }
};

const QMetaObject *MainMenuModelAction::metaObject() const
{
    return &staticMetaObject;
}

void *MainMenuModelAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainMenuModelAction))
        return static_cast<void*>(const_cast< MainMenuModelAction*>(this));
    if (!strcmp(_clname, "IMenuAction"))
        return static_cast< IMenuAction*>(const_cast< MainMenuModelAction*>(this));
    return ModelAction::qt_metacast(_clname);
}

int MainMenuModelAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
