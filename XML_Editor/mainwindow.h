#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "general_functions.h"
#include <consistency.h>
#include "formatting_minifying.h"
#include "json.h"
#include "compressionCoding.h"
#include "compressionDecoding.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpe_triggered();

    void on_actionNew_triggered();

    void on_actionExit_triggered();

    void on_actionSaveAs_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCut_triggered();

    void on_ErrorCheck_clicked();

    void on_ErrorFix_clicked();

    void on_XMLtoJson_clicked();

    void on_Prettify_clicked();

    void on_Minify_clicked();

    void on_Compress_clicked();

    void on_checkBox_clicked();

    void on_Decompress_clicked();

    void on_actionSave_2_triggered();

    void on_ShowErrors_clicked();

private:
    Ui::MainWindow *ui;
    QString currentFile="";
};
#endif // MAINWINDOW_H
