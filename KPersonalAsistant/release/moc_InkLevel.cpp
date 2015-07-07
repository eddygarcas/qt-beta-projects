/****************************************************************************
** Meta object code from reading C++ file 'InkLevel.h'
**
** Created: Fri 21. Nov 11:32:40 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/ScreenTemplates/InkLevel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InkLevel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InkLevel[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       7,   25, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      34,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   65,    9,    9, 0x0a,
      95,   93,    9,    9, 0x09,

 // properties: name, type, flags
     129,  121, 0x0009510b,
     142,  121, 0x0009510b,
     154,  121, 0x0009500b,
     167,  121, 0x0009500b,
     188,  180, 0x0a095103,
     205,  198, 0x43095103,
     224,  219, 0x01095103,

       0        // eod
};

static const char qt_meta_stringdata_InkLevel[] = {
    "InkLevel\0\0_colorTitle,_colorValue\0"
    "percent_value(std::string,int)\0value\0"
    "change_ink_value(int)\0i\0"
    "change_percent_value(int)\0int32_t\0"
    "widgetHeight\0widgetWidth\0minimumLevel\0"
    "maximumLevel\0QString\0colorText\0QColor\0"
    "colorRGBValue\0bool\0hasPercentValue\0"
};

const QMetaObject InkLevel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InkLevel,
      qt_meta_data_InkLevel, 0 }
};

const QMetaObject *InkLevel::metaObject() const
{
    return &staticMetaObject;
}

void *InkLevel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InkLevel))
        return static_cast<void*>(const_cast< InkLevel*>(this));
    return QWidget::qt_metacast(_clname);
}

int InkLevel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: percent_value((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: change_ink_value((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: change_percent_value((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int32_t*>(_v) = widgetHeight(); break;
        case 1: *reinterpret_cast< int32_t*>(_v) = widgetWidth(); break;
        case 2: *reinterpret_cast< int32_t*>(_v) = inkMinimumLevel(); break;
        case 3: *reinterpret_cast< int32_t*>(_v) = inkMaximumLevel(); break;
        case 4: *reinterpret_cast< QString*>(_v) = colorText(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = colorRGBValue(); break;
        case 6: *reinterpret_cast< bool*>(_v) = hasPercentValue(); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setWidgetHeight(*reinterpret_cast< int32_t*>(_v)); break;
        case 1: setWidgetWidth(*reinterpret_cast< int32_t*>(_v)); break;
        case 2: setInkMinimumLevel(*reinterpret_cast< int32_t*>(_v)); break;
        case 3: setInkMaximumLevel(*reinterpret_cast< int32_t*>(_v)); break;
        case 4: setColorText(*reinterpret_cast< QString*>(_v)); break;
        case 5: setColorRGBValue(*reinterpret_cast< QColor*>(_v)); break;
        case 6: setHasPercentValue(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void InkLevel::percent_value(std::string _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
