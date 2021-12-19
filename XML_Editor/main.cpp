#include "mainwindow.h"
#include <QApplication>
#include <QFile>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile stylesheetFile("./SyNet.qss");
    stylesheetFile.open(QFile::ReadOnly);
    QString stylesheet=QLatin1String(stylesheetFile.readAll());
    a.setStyleSheet(stylesheet);
    MainWindow w;
    w.show();
    return a.exec();
}
