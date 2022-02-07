#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include "network_analysis.h"

using namespace cv;

using namespace std;

int main(int argc, char *argv[])
{
//    string output_file_name = "D:/phillll.jpg";
//    int number_of_nodes = 10;
//    int mat[100][100] = {{0, 1, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 0, 1, 1, 1}, {1, 1, 0, 0, 1, 1}, {0, 1, 0, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
//    GraphAnalysis g1(mat, number_of_nodes, output_file_name);

    QApplication a(argc, argv);
    QFile stylesheetFile("./SyNet.qss");
    stylesheetFile.open(QFile::ReadOnly);
    QString stylesheet=QLatin1String(stylesheetFile.readAll());
    a.setStyleSheet(stylesheet);
    MainWindow w;

    w.show();



    return a.exec();
}
