/****************************************************************************
** Meta object code from reading C++ file 'InkMenuModelAction.h'
**
** Created: Fri 21. Nov 11:32:52 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/Actions/InkMenuModelAction.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InkMenuModelAction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InkMenuModelAction[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_InkMenuModelAction[] = {
    "InkMenuModelAction\0"
};

const QMetaObject InkMenuModelAction::staticMetaObject = {
    { &ModelAction::staticMetaObject, qt_meta_stringdata_InkMenuModelAction,
      qt_meta_data_InkMenuModelAction, 0 }
};

const QMetaObject *InkMenuModelAction::metaObject() const
{
    return &staticMetaObject;
}

void *InkMenuModelAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InkMenuModelAction))
        return static_cast<void*>(const_cast< InkMenuModelAction*>(this));
    if (!strcmp(_clname, "IMenuAction"))
        return static_cast< IMenuAction*>(const_cast< InkMenuModelAction*>(this));
    return ModelAction::qt_metacast(_clname);
}

int InkMenuModelAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
