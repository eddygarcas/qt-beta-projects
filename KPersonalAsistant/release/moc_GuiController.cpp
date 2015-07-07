/****************************************************************************
** Meta object code from reading C++ file 'GuiController.h'
**
** Created: Fri 21. Nov 11:32:16 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/GuiController/GuiController.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GuiController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GuiController[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      22,   15,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GuiController[] = {
    "GuiController\0\0_index\0setCurrentIndex(int32_t)\0"
};

const QMetaObject GuiController::staticMetaObject = {
    { &QStackedWidget::staticMetaObject, qt_meta_stringdata_GuiController,
      qt_meta_data_GuiController, 0 }
};

const QMetaObject *GuiController::metaObject() const
{
    return &staticMetaObject;
}

void *GuiController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GuiController))
        return static_cast<void*>(const_cast< GuiController*>(this));
    return QStackedWidget::qt_metacast(_clname);
}

int GuiController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setCurrentIndex((*reinterpret_cast< int32_t(*)>(_a[1]))); break;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
