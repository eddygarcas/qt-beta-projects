/****************************************************************************
** Meta object code from reading C++ file 'TextListMenuTemplate.h'
**
** Created: Fri 21. Nov 11:32:18 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/ScreenTemplates/TextListMenuTemplate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TextListMenuTemplate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TextListMenuTemplate[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_TextListMenuTemplate[] = {
    "TextListMenuTemplate\0"
};

const QMetaObject TextListMenuTemplate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TextListMenuTemplate,
      qt_meta_data_TextListMenuTemplate, 0 }
};

const QMetaObject *TextListMenuTemplate::metaObject() const
{
    return &staticMetaObject;
}

void *TextListMenuTemplate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TextListMenuTemplate))
        return static_cast<void*>(const_cast< TextListMenuTemplate*>(this));
    if (!strcmp(_clname, "Ui::TextListScreen"))
        return static_cast< Ui::TextListScreen*>(const_cast< TextListMenuTemplate*>(this));
    if (!strcmp(_clname, "ScreenTemplate"))
        return static_cast< ScreenTemplate*>(const_cast< TextListMenuTemplate*>(this));
    if (!strcmp(_clname, "IMenuTemplate"))
        return static_cast< IMenuTemplate*>(const_cast< TextListMenuTemplate*>(this));
    return QWidget::qt_metacast(_clname);
}

int TextListMenuTemplate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
