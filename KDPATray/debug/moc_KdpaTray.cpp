/****************************************************************************
** Meta object code from reading C++ file 'KdpaTray.h'
**
** Created: Fri 21. Nov 11:49:58 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KdpaTray.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KdpaTray.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KdpaTray[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x08,
      36,   29,    9,    9, 0x08,
      85,    9,    9,    9, 0x08,
      99,    9,    9,    9, 0x08,
     116,    9,    9,    9, 0x08,
     127,    9,    9,    9, 0x08,
     140,    9,    9,    9, 0x08,
     161,    9,    9,    9, 0x08,
     181,    9,    9,    9, 0x08,
     206,    9,    9,    9, 0x08,
     221,    9,    9,    9, 0x08,
     236,    9,    9,    9, 0x08,
     260,    9,    9,    9, 0x08,
     281,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_KdpaTray[] = {
    "KdpaTray\0\0index\0setIcon(int)\0reason\0"
    "iconActivated(QSystemTrayIcon::ActivationReason)\0"
    "showMessage()\0messageClicked()\0"
    "newKNota()\0configEnds()\0publishInitalIP(int)\0"
    "publishFinalIP(int)\0publishPingInterval(int)\0"
    "checkServers()\0stopScanning()\0"
    "publishSubNetValue(int)\0publishNetValue(int)\0"
    "publishMaskValue(int)\0"
};

const QMetaObject KdpaTray::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_KdpaTray,
      qt_meta_data_KdpaTray, 0 }
};

const QMetaObject *KdpaTray::metaObject() const
{
    return &staticMetaObject;
}

void *KdpaTray::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KdpaTray))
        return static_cast<void*>(const_cast< KdpaTray*>(this));
    return QWidget::qt_metacast(_clname);
}

int KdpaTray::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setIcon((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 2: showMessage(); break;
        case 3: messageClicked(); break;
        case 4: newKNota(); break;
        case 5: configEnds(); break;
        case 6: publishInitalIP((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: publishFinalIP((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: publishPingInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: checkServers(); break;
        case 10: stopScanning(); break;
        case 11: publishSubNetValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: publishNetValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: publishMaskValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
