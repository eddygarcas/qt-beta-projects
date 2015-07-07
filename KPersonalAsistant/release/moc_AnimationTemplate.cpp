/****************************************************************************
** Meta object code from reading C++ file 'AnimationTemplate.h'
**
** Created: Fri 21. Nov 11:32:23 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/ScreenTemplates/AnimationTemplate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnimationTemplate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AnimationTemplate[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      42,   18,   18,   18, 0x0a,
      65,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AnimationTemplate[] = {
    "AnimationTemplate\0\0next_animation_frame()\0"
    "start_timer_interval()\0stop_timer_interval()\0"
};

const QMetaObject AnimationTemplate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AnimationTemplate,
      qt_meta_data_AnimationTemplate, 0 }
};

const QMetaObject *AnimationTemplate::metaObject() const
{
    return &staticMetaObject;
}

void *AnimationTemplate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AnimationTemplate))
        return static_cast<void*>(const_cast< AnimationTemplate*>(this));
    if (!strcmp(_clname, "Ui::AnimationScreen"))
        return static_cast< Ui::AnimationScreen*>(const_cast< AnimationTemplate*>(this));
    if (!strcmp(_clname, "ScreenTemplate"))
        return static_cast< ScreenTemplate*>(const_cast< AnimationTemplate*>(this));
    return QWidget::qt_metacast(_clname);
}

int AnimationTemplate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: next_animation_frame(); break;
        case 1: start_timer_interval(); break;
        case 2: stop_timer_interval(); break;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
