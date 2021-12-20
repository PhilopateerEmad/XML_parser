/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpe;
    QAction *actionSaveAs;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionSave_2;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QPushButton *ErrorCheck;
    QPushButton *ShowErrors;
    QPushButton *ErrorFix;
    QPushButton *Prettify;
    QPushButton *XMLtoJson;
    QPushButton *Minify;
    QPushButton *Compress;
    QPushButton *Decompress;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1253, 781);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/icons/new-document.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/imgs/C:/Users/koko/Downloads/new-document.png"), QSize(), QIcon::Normal, QIcon::On);
        actionNew->setIcon(icon);
        actionOpe = new QAction(MainWindow);
        actionOpe->setObjectName(QString::fromUtf8("actionOpe"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/icons/open.png"), QSize(), QIcon::Normal, QIcon::On);
        actionOpe->setIcon(icon1);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/icons/save-icon-free-12.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/imgs/icons/save-as-512.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSaveAs->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imgs/icons/exit.png"), QSize(), QIcon::Normal, QIcon::On);
        actionExit->setIcon(icon3);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imgs/icons/copy.png"), QSize(), QIcon::Normal, QIcon::On);
        actionCopy->setIcon(icon4);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imgs/icons/paste.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPaste->setIcon(icon5);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/imgs/icons/undo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionUndo->setIcon(icon6);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/imgs/icons/redo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionRedo->setIcon(icon7);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/imgs/icons/cut.png"), QSize(), QIcon::Normal, QIcon::On);
        actionCut->setIcon(icon8);
        actionSave_2 = new QAction(MainWindow);
        actionSave_2->setObjectName(QString::fromUtf8("actionSave_2"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/imgs/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_2->setIcon(icon9);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(160, 10, 941, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(horizontalLayoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(false);
        checkBox->setTristate(false);

        horizontalLayout->addWidget(checkBox);

        ErrorCheck = new QPushButton(horizontalLayoutWidget);
        ErrorCheck->setObjectName(QString::fromUtf8("ErrorCheck"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/imgs/icons/check.png"), QSize(), QIcon::Normal, QIcon::On);
        ErrorCheck->setIcon(icon10);

        horizontalLayout->addWidget(ErrorCheck);

        ShowErrors = new QPushButton(horizontalLayoutWidget);
        ShowErrors->setObjectName(QString::fromUtf8("ShowErrors"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/imgs/icons/bug.png"), QSize(), QIcon::Normal, QIcon::On);
        ShowErrors->setIcon(icon11);

        horizontalLayout->addWidget(ShowErrors);

        ErrorFix = new QPushButton(horizontalLayoutWidget);
        ErrorFix->setObjectName(QString::fromUtf8("ErrorFix"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/imgs/icons/repeair.png"), QSize(), QIcon::Normal, QIcon::On);
        ErrorFix->setIcon(icon12);

        horizontalLayout->addWidget(ErrorFix);

        Prettify = new QPushButton(horizontalLayoutWidget);
        Prettify->setObjectName(QString::fromUtf8("Prettify"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/imgs/icons/indent.png"), QSize(), QIcon::Normal, QIcon::On);
        Prettify->setIcon(icon13);

        horizontalLayout->addWidget(Prettify);

        XMLtoJson = new QPushButton(horizontalLayoutWidget);
        XMLtoJson->setObjectName(QString::fromUtf8("XMLtoJson"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/imgs/icons/json.png"), QSize(), QIcon::Normal, QIcon::On);
        XMLtoJson->setIcon(icon14);

        horizontalLayout->addWidget(XMLtoJson);

        Minify = new QPushButton(horizontalLayoutWidget);
        Minify->setObjectName(QString::fromUtf8("Minify"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/imgs/icons/minify.png"), QSize(), QIcon::Normal, QIcon::On);
        Minify->setIcon(icon15);

        horizontalLayout->addWidget(Minify);

        Compress = new QPushButton(horizontalLayoutWidget);
        Compress->setObjectName(QString::fromUtf8("Compress"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/imgs/icons/compress.png"), QSize(), QIcon::Normal, QIcon::On);
        Compress->setIcon(icon16);

        horizontalLayout->addWidget(Compress);

        Decompress = new QPushButton(horizontalLayoutWidget);
        Decompress->setObjectName(QString::fromUtf8("Decompress"));

        horizontalLayout->addWidget(Decompress);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 60, 581, 611));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(false);

        verticalLayout->addWidget(textEdit);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(620, 60, 601, 611));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit_2 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setReadOnly(true);

        verticalLayout_2->addWidget(textEdit_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1253, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpe);
        menuFile->addAction(actionSave_2);
        menuFile->addAction(actionSaveAs);
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpe);
        toolBar->addAction(actionSave_2);
        toolBar->addAction(actionSaveAs);
        toolBar->addAction(actionExit);
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addAction(actionCut);
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionOpe->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "SaveAs", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        actionCut->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
        actionSave_2->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));
        ErrorCheck->setText(QCoreApplication::translate("MainWindow", "Error Check", nullptr));
        ShowErrors->setText(QCoreApplication::translate("MainWindow", "Show Errors", nullptr));
        ErrorFix->setText(QCoreApplication::translate("MainWindow", "Fix Errors", nullptr));
        Prettify->setText(QCoreApplication::translate("MainWindow", "Prettify", nullptr));
        XMLtoJson->setText(QCoreApplication::translate("MainWindow", "XML to JSON", nullptr));
        Minify->setText(QCoreApplication::translate("MainWindow", "Minify", nullptr));
        Compress->setText(QCoreApplication::translate("MainWindow", "Compress", nullptr));
        Decompress->setText(QCoreApplication::translate("MainWindow", "Decompress", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
