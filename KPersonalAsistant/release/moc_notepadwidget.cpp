/****************************************************************************
** Meta object code from reading C++ file 'notepadwidget.h'
**
** Created: Fri 21. Nov 11:32:43 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/ScreenTemplates/notepadwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notepadwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NotepadWidget[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   10, // methods
       4,   45, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      25,   15,   14,   14, 0x05,
      56,   45,   14,   14, 0x05,
      77,   14,   14,   14, 0x05,
     103,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     123,  118,   14,   14, 0x0a,
     167,   14,   14,   14, 0x0a,
     184,   14,   14,   14, 0x0a,

 // properties: name, type, flags
     207,  199, 0x0a095103,
     222,  217, 0x01095103,
     235,  217, 0x01095103,
     251,  217, 0x01095103,

       0        // eod
};

static const char qt_meta_stringdata_NotepadWidget[] = {
    "NotepadWidget\0\0_fullText\0sendReturn(QString)\0"
    "_character\0sendCharacter(QChar)\0"
    "deletePreviousCharacter()\0closeTextPad()\0"
    "item\0on_wordList_itemActivated(QListWidgetItem*)\0"
    "hidden_textPad()\0show_textPad()\0QString\0"
    "wordArray\0bool\0activeDelKey\0activeReturnKey\0"
    "autoHide\0"
};

const QMetaObject NotepadWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NotepadWidget,
      qt_meta_data_NotepadWidget, 0 }
};

const QMetaObject *NotepadWidget::metaObject() const
{
    return &staticMetaObject;
}

void *NotepadWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NotepadWidget))
        return static_cast<void*>(const_cast< NotepadWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int NotepadWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendReturn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: sendCharacter((*reinterpret_cast< QChar(*)>(_a[1]))); break;
        case 2: deletePreviousCharacter(); break;
        case 3: closeTextPad(); break;
        case 4: on_wordList_itemActivated((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: hidden_textPad(); break;
        case 6: show_textPad(); break;
        }
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = wordArray(); break;
        case 1: *reinterpret_cast< bool*>(_v) = activeDelKey(); break;
        case 2: *reinterpret_cast< bool*>(_v) = activeReturnKey(); break;
        case 3: *reinterpret_cast< bool*>(_v) = autoHide(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setWordArray(*reinterpret_cast< QString*>(_v)); break;
        case 1: setActiveDelKey(*reinterpret_cast< bool*>(_v)); break;
        case 2: setActiveReturnKey(*reinterpret_cast< bool*>(_v)); break;
        case 3: setAutoHide(*reinterpret_cast< bool*>(_v)); break;
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
void NotepadWidget::sendReturn(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NotepadWidget::sendCharacter(QChar _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NotepadWidget::deletePreviousCharacter()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void NotepadWidget::closeTextPad()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
