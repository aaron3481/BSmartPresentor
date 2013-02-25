/****************************************************************************
** Meta object code from reading C++ file 'ConnectionManager.hpp'
**
** Created: Sun Feb 24 17:21:16 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ConnectionManager.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConnectionManager.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IncomeDataThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      38,   18,   17,   17, 0x05,
      88,   64,   17,   17, 0x05,
     111,   17,   17,   17, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_IncomeDataThread[] = {
    "IncomeDataThread\0\0slideCount,fileName\0"
    "recordHeader(int,QString)\0"
    "slideNum,animCount,note\0slide(int,int,QString)\0"
    "received()\0"
};

void IncomeDataThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        IncomeDataThread *_t = static_cast<IncomeDataThread *>(_o);
        switch (_id) {
        case 0: _t->recordHeader((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->slide((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->received(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData IncomeDataThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject IncomeDataThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_IncomeDataThread,
      qt_meta_data_IncomeDataThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IncomeDataThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IncomeDataThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IncomeDataThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IncomeDataThread))
        return static_cast<void*>(const_cast< IncomeDataThread*>(this));
    return QThread::qt_metacast(_clname);
}

int IncomeDataThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void IncomeDataThread::recordHeader(int _t1, const QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IncomeDataThread::slide(int _t1, int _t2, const QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IncomeDataThread::received()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
static const uint qt_meta_data_ConnectionManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       6,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      42,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      78,   19,   18,   18, 0x0a,
     139,  119,   18,   18, 0x0a,
     189,  165,   18,   18, 0x0a,
     217,  212,   18,   18, 0x0a,
     250,  242,   18,   18, 0x0a,
     271,   18,   18,   18, 0x0a,
     290,   18,  282,   18, 0x0a,
     309,  304,   18,   18, 0x0a,
     339,  333,   18,   18, 0x0a,

 // properties: name, type, flags
     377,  360, 0x00095409,
     405,  390, 0x00095409,
     427,  419, 0x00095409,
     459,  434, 0x00095409,
     467,  282, 0x0a095401,
     482,  282, 0x0a095401,

       0        // eod
};

static const char qt_meta_stringdata_ConnectionManager[] = {
    "ConnectionManager\0\0event,btAddr,eventData\0"
    "BTDeviceSignal(int,QString,QString)\0"
    "handleBTDeviceEvent(int,QString,QString)\0"
    "slideCount,fileName\0recordHeader(int,QString)\0"
    "slideNum,animCount,note\0slide(int,int,QString)\0"
    "addr\0connectToServer(QString)\0command\0"
    "sendCommand(QString)\0received()\0QString\0"
    "getFileName()\0page\0gotoPageUpdate(QString)\0"
    "click\0clickUpdate(QString)\0LocalDeviceInfo*\0"
    "localDevInfo\0DeviceListing*\0deviceListing\0"
    "Record*\0record\0bb::cascades::DataModel*\0"
    "s_model\0s_currentSlide\0s_currentNote\0"
};

void ConnectionManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConnectionManager *_t = static_cast<ConnectionManager *>(_o);
        switch (_id) {
        case 0: _t->BTDeviceSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->handleBTDeviceEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->recordHeader((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->slide((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->connectToServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sendCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->received(); break;
        case 7: { QString _r = _t->getFileName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: _t->gotoPageUpdate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->clickUpdate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConnectionManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConnectionManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ConnectionManager,
      qt_meta_data_ConnectionManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConnectionManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConnectionManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConnectionManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectionManager))
        return static_cast<void*>(const_cast< ConnectionManager*>(this));
    return QObject::qt_metacast(_clname);
}

int ConnectionManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< LocalDeviceInfo**>(_v) = localDevInfo(); break;
        case 1: *reinterpret_cast< DeviceListing**>(_v) = deviceListing(); break;
        case 2: *reinterpret_cast< Record**>(_v) = record(); break;
        case 3: *reinterpret_cast< bb::cascades::DataModel**>(_v) = model(); break;
        case 4: *reinterpret_cast< QString*>(_v) = getSCurrentSlide(); break;
        case 5: *reinterpret_cast< QString*>(_v) = getSCurrentNote(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ConnectionManager::BTDeviceSignal(int _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
