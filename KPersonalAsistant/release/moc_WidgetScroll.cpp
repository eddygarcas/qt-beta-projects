/****************************************************************************
** Meta object code from reading C++ file 'WidgetScroll.h'
**
** Created: Fri 21. Nov 11:32:38 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/ScreenTemplates/WidgetScroll.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetScroll.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WidgetScroll[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   10, // methods
       4,   40, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      22,   14,   13,   13, 0x05,
      74,   55,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     121,  114,   13,   13, 0x0a,
     170,  160,   13,   13, 0x0a,
     201,  194,   13,   13, 0x0a,
     225,   13,   13,   13, 0x0a,

 // properties: name, type, flags
     254,  246, 0x0009510b,
     269,  264, 0x01095103,
     281,  246, 0x0009510b,
     294,  246, 0x0009510b,

       0        // eod
};

static const char qt_meta_stringdata_WidgetScroll[] = {
    "WidgetScroll\0\0logInfo\0"
    "send_widget_information(QString)\0"
    "str_value,selected\0"
    "send_selected_information(QString,bool)\0"
    "_value\0on_verticalScrollBar_valueChanged(int)\0"
    "clk_value\0on_widget_clicked(bool)\0"
    "hidden\0scrollBars_hidden(bool)\0"
    "scroll_hidden_text()\0int32_t\0timerTime\0"
    "bool\0activeTimer\0widgetHeight\0widgetWidth\0"
};

const QMetaObject WidgetScroll::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetScroll,
      qt_meta_data_WidgetScroll, 0 }
};

const QMetaObject *WidgetScroll::metaObject() const
{
    return &staticMetaObject;
}

void *WidgetScroll::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetScroll))
        return static_cast<void*>(const_cast< WidgetScroll*>(this));
    return QWidget::qt_metacast(_clname);
}

int WidgetScroll::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: send_widget_information((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: send_selected_information((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: on_verticalScrollBar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_widget_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: scrollBars_hidden((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: scroll_hidden_text(); break;
        }
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int32_t*>(_v) = timerTime(); break;
        case 1: *reinterpret_cast< bool*>(_v) = activeTimer(); break;
        case 2: *reinterpret_cast< int32_t*>(_v) = widgetHeight(); break;
        case 3: *reinterpret_cast< int32_t*>(_v) = widgetWidth(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setTimerTime(*reinterpret_cast< int32_t*>(_v)); break;
        case 1: setActiveTimer(*reinterpret_cast< bool*>(_v)); break;
        case 2: setWidgetHeight(*reinterpret_cast< int32_t*>(_v)); break;
        case 3: setWidgetWidth(*reinterpret_cast< int32_t*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WidgetScroll::send_widget_information(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WidgetScroll::send_selected_information(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
