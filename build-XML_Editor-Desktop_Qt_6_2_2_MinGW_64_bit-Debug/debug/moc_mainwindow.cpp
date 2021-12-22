/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../XML_Editor/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[42];
    char stringdata0[439];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 22), // "on_actionOpe_triggered"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(58, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(82, 25), // "on_actionSaveAs_triggered"
QT_MOC_LITERAL(108, 23), // "on_actionCopy_triggered"
QT_MOC_LITERAL(132, 24), // "on_actionPaste_triggered"
QT_MOC_LITERAL(157, 23), // "on_actionUndo_triggered"
QT_MOC_LITERAL(181, 23), // "on_actionRedo_triggered"
QT_MOC_LITERAL(205, 22), // "on_actionCut_triggered"
QT_MOC_LITERAL(228, 21), // "on_ErrorCheck_clicked"
QT_MOC_LITERAL(250, 19), // "on_ErrorFix_clicked"
QT_MOC_LITERAL(270, 20), // "on_XMLtoJson_clicked"
QT_MOC_LITERAL(291, 19), // "on_Prettify_clicked"
QT_MOC_LITERAL(311, 17), // "on_Minify_clicked"
QT_MOC_LITERAL(329, 19), // "on_Compress_clicked"
QT_MOC_LITERAL(349, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(369, 21), // "on_Decompress_clicked"
QT_MOC_LITERAL(391, 25), // "on_actionSave_2_triggered"
QT_MOC_LITERAL(417, 21) // "on_ShowErrors_clicked"

    },
    "MainWindow\0on_actionOpe_triggered\0\0"
    "on_actionNew_triggered\0on_actionExit_triggered\0"
    "on_actionSaveAs_triggered\0"
    "on_actionCopy_triggered\0"
    "on_actionPaste_triggered\0"
    "on_actionUndo_triggered\0on_actionRedo_triggered\0"
    "on_actionCut_triggered\0on_ErrorCheck_clicked\0"
    "on_ErrorFix_clicked\0on_XMLtoJson_clicked\0"
    "on_Prettify_clicked\0on_Minify_clicked\0"
    "on_Compress_clicked\0on_checkBox_clicked\0"
    "on_Decompress_clicked\0on_actionSave_2_triggered\0"
    "on_ShowErrors_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x08,    1 /* Private */,
       3,    0,  129,    2, 0x08,    2 /* Private */,
       4,    0,  130,    2, 0x08,    3 /* Private */,
       5,    0,  131,    2, 0x08,    4 /* Private */,
       6,    0,  132,    2, 0x08,    5 /* Private */,
       7,    0,  133,    2, 0x08,    6 /* Private */,
       8,    0,  134,    2, 0x08,    7 /* Private */,
       9,    0,  135,    2, 0x08,    8 /* Private */,
      10,    0,  136,    2, 0x08,    9 /* Private */,
      11,    0,  137,    2, 0x08,   10 /* Private */,
      12,    0,  138,    2, 0x08,   11 /* Private */,
      13,    0,  139,    2, 0x08,   12 /* Private */,
      14,    0,  140,    2, 0x08,   13 /* Private */,
      15,    0,  141,    2, 0x08,   14 /* Private */,
      16,    0,  142,    2, 0x08,   15 /* Private */,
      17,    0,  143,    2, 0x08,   16 /* Private */,
      18,    0,  144,    2, 0x08,   17 /* Private */,
      19,    0,  145,    2, 0x08,   18 /* Private */,
      20,    0,  146,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionOpe_triggered(); break;
        case 1: _t->on_actionNew_triggered(); break;
        case 2: _t->on_actionExit_triggered(); break;
        case 3: _t->on_actionSaveAs_triggered(); break;
        case 4: _t->on_actionCopy_triggered(); break;
        case 5: _t->on_actionPaste_triggered(); break;
        case 6: _t->on_actionUndo_triggered(); break;
        case 7: _t->on_actionRedo_triggered(); break;
        case 8: _t->on_actionCut_triggered(); break;
        case 9: _t->on_ErrorCheck_clicked(); break;
        case 10: _t->on_ErrorFix_clicked(); break;
        case 11: _t->on_XMLtoJson_clicked(); break;
        case 12: _t->on_Prettify_clicked(); break;
        case 13: _t->on_Minify_clicked(); break;
        case 14: _t->on_Compress_clicked(); break;
        case 15: _t->on_checkBox_clicked(); break;
        case 16: _t->on_Decompress_clicked(); break;
        case 17: _t->on_actionSave_2_triggered(); break;
        case 18: _t->on_ShowErrors_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
