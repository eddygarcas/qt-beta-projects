/****************************************************************************
** Meta object code from reading C++ file 'ProgressBarTemplate.h'
**
** Created: Fri 21. Nov 11:32:27 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/ScreenTemplates/ProgressBarTemplate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProgressBarTemplate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ProgressBarTemplate[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      41,   26,   21,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ProgressBarTemplate[] = {
    "ProgressBarTemplate\0\0bool\0_progressValue\0"
    "changeProgressValue(int32_t)\0"
};

const QMetaObject ProgressBarTemplate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ProgressBarTemplate,
      qt_meta_data_ProgressBarTemplate, 0 }
};

const QMetaObject *ProgressBarTemplate::metaObject() const
{
    return &staticMetaObject;
}

void *ProgressBarTemplate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProgressBarTemplate))
        return static_cast<void*>(const_cast< ProgressBarTemplate*>(this));
    if (!strcmp(_clname, "Ui::ProgressBarScreen"))
        return static_cast< Ui::ProgressBarScreen*>(const_cast< ProgressBarTemplate*>(this));
    if (!strcmp(_clname, "ScreenTemplate"))
        return static_cast< ScreenTemplate*>(const_cast< ProgressBarTemplate*>(this));
    return QWidget::qt_metacast(_clname);
}

int ProgressBarTemplate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = changeProgressValue((*reinterpret_cast< int32_t(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
