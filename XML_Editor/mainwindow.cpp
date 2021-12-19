#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
QMessageBox::information(this, "Info", "Note:Remove the Preprocessor Tag to be able to convert to JSON Successfully");
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_actionOpe_triggered()
{
    QString fileName=QFileDialog::getOpenFileName(this,"Open this File");
    QFile file(fileName);
    currentFile=fileName;
    if(!file.open(QIODevice::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"Warning","Can't Open File: "+file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream in(&file);

    QString text=in.readAll();

    ui->textEdit->setText(text);
    file.close();
    QMessageBox::warning(this, "Warning", "Note: Remove the Preprocessor line to be able to convert to JSON successfully");

}


void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
    ui->textEdit_2->setText(QString());
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
void MainWindow::on_actionSave_2_triggered()
{
    QFile sFile("input.xml");
    if(sFile.open(QFile::WriteOnly|QFile::Text)){
        QTextStream out(&sFile);
        out<<ui->textEdit->toPlainText();
        sFile.flush();
        sFile.close();
    }
}
void MainWindow::on_actionSaveAs_triggered()
{
    QString fileName=QFileDialog::getSaveFileName(this,"Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"Warning","Can't Open File: "+file.errorString());
        return;
    }
    currentFile=fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.close();

}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionCut_triggered()
{
        ui->textEdit->cut();
}


void MainWindow::on_ErrorCheck_clicked()
{

    QString in = ui->textEdit->toPlainText();

    if(in == ""){
        QMessageBox::warning(this, "Warning", "No Text To Be Converted");
        return;
    }
  on_actionSave_2_triggered();

    vector<string>x;
    string inq = in.toLocal8Bit().constData();
    vector<string> linesQ = get_XML_Vector(inq);


    if(check_consistency(linesQ)==true){
        QMessageBox::information(this, "Info", "This File is Consistent and contains no Errors");

    }else{
        QMessageBox::information(this, "Info", "This File is inconsistent and contains Errors");

    }
}


void MainWindow::on_ErrorFix_clicked()
{


           QString in = ui->textEdit->toPlainText();

           if(in == ""){
               QMessageBox::warning(this, "Warning", "No Text To Be Converted");
               return;
           }
  on_actionSave_2_triggered();
           vector<string> input;
          readFile("input.xml",input);

           if(check_consistency(input)==true){
               ui->textEdit_2->clear();
               QMessageBox::information(this, "Info", "This File has no errors to fix");
               return;

           }else{
               fix_errors(input);
               writeFile("fixed.xml",input);
               QFile x("fixed.xml");
               if(!x.open(QFile::ReadOnly | QFile::Text))
               {
                   QMessageBox::warning(this,"Warning" , "Cannot Open File : " + x.errorString());
               }
               QTextStream out(&x);
               QString text = out.readAll();
               ui->textEdit_2->setPlainText(text);
               x.close();
           }

}


void MainWindow::on_XMLtoJson_clicked()
{


           QString in = ui->textEdit->toPlainText();

           if(in == ""){
               QMessageBox::warning(this, "Warning", "No Text To Be Converted");
               return;
           }
  on_actionSave_2_triggered();


           string inq = in.toLocal8Bit().constData();
           vector<string> linesQ = get_XML_Vector(inq);

           int linesQSize = linesQ.size();
           node *root;
           root = make_tree(linesQ, linesQSize);
           string out = "";
           out  = iteration(root, out);
           QString res = QString::fromStdString(out);

           ui->textEdit_2->setText(res);

           // to file
           QString fname = QFileDialog::getSaveFileName(this, "Choose the Location to Save the JSON File", QDir::currentPath());
           QFile fileQ(fname);
           if(!fileQ.open(QFile::WriteOnly | QFile::Text)){
               QMessageBox::warning(this, "Warning", "Cannot Save File!");
               return;
           }
           QTextStream outt(&fileQ);
           outt << res;
           fileQ.flush();
           fileQ.close();
           QMessageBox::information(this, "Info", "File Coverted Successfully!\nThe JSON File Can Be Found at: " + fname);
           ui->textEdit_2->setLineWrapMode(QTextEdit::NoWrap);
                   QFile inn(fname);
                   if(!fileQ.open(QFile::ReadOnly | QFile::Text)){
                       QMessageBox::warning(this, "Warning", "Cannot Open the Results File!");
                       return;
                   }
                   QTextStream inp(&inn);
                   inn.close();
}


void MainWindow::on_Prettify_clicked()
{

    QString in = ui->textEdit->toPlainText();

    if(in == ""){
        QMessageBox::warning(this, "Warning", "No Text To Be Converted");
        return;
    }
  on_actionSave_2_triggered();
    vector<string> xml;
    readFile("input.xml", xml);
    prettifying_func(xml,"pretify.txt");
    QFile x("pretify.txt");
    if(!x.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Warning" , "Cannot Open File : " + x.errorString());
    }
    QTextStream out(&x);
    QString text = out.readAll();
    ui->textEdit_2->setPlainText(text);
    x.close();

}





void MainWindow::on_Minify_clicked()
{

    QString in = ui->textEdit->toPlainText();

    if(in == ""){
        QMessageBox::warning(this, "Warning", "No Text To Be Converted");
        return;
    }
  on_actionSave_2_triggered();


    string inq = in.toLocal8Bit().constData();
    vector<string> linesQ = get_XML_Vector(inq);
 writeFile("input.xml", linesQ);

    vector<string> xml;
    readFile("input.xml", xml);
    minifying_func(xml,"minify.txt");
    QFile x("minify.txt");
    if(!x.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Warning" , "Cannot Open File : " + x.errorString());
    }
    QTextStream out(&x);
    QString text = out.readAll();
    ui->textEdit_2->setPlainText(text);
    x.close();
}


void MainWindow::on_Compress_clicked()
{


    QString in = ui->textEdit->toPlainText();

    if(in == ""){
        QMessageBox::warning(this, "Warning", "No Text To Be Converted");
        return;
    }

  on_actionSave_2_triggered();
    CompressionCoding c1("input.xml", "compressed.xml");

int original_file_size = 0;
int compressed_file_size = 0;
 QFile original_file("input.xml");
   QFile compressed_file("compressed.xml");

   if (original_file.open(QIODevice::ReadOnly)){
       original_file_size = original_file.size();  //when file does open.
       original_file.close();
   }

if (compressed_file.open(QIODevice::ReadOnly)){
    compressed_file_size = compressed_file.size();  //when file does open.
    compressed_file.close();
}
if(!compressed_file.open(QFile::ReadOnly | QFile::Text))
{
    QMessageBox::warning(this,"Warning" , "Cannot Open File : " + compressed_file.errorString());
}

QTextStream out(&compressed_file);
QString text = out.readAll();
ui->textEdit_2->setPlainText(text);
compressed_file.close();

QMessageBox::information(this, "Compression Info" ,"File Size before Compresion is : "+QString::number(original_file_size)+" bytes \n"+
                             "File Size after Compresion is: "+QString::number(compressed_file_size)+" bytes \n");
}

void MainWindow::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()){
        QFile stylesheetFile("./Darkeum.qss");
        stylesheetFile.open(QFile::ReadOnly);
        QString stylesheet=QLatin1String(stylesheetFile.readAll());
        setStyleSheet(stylesheet);

    }else{
        QFile stylesheetFile("./SyNet.qss");
        stylesheetFile.open(QFile::ReadOnly);
        QString stylesheet=QLatin1String(stylesheetFile.readAll());
        setStyleSheet(stylesheet);
    }


}


void MainWindow::on_Decompress_clicked()
{

    QString in = ui->textEdit->toPlainText();

    if(in == ""){
        QMessageBox::warning(this, "Warning", "No Text To Be Converted");
        return;
    }
    CompressionDecoding("compressed.xml", "decompressed.xml");
    on_actionSave_2_triggered();

    QFile decompressed_file("decompressed.xml");
    if(!decompressed_file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Warning" , "Cannot Open File : " + decompressed_file.errorString());
    }

    QTextStream out(&decompressed_file);
    QString text = out.readAll();
    ui->textEdit_2->setPlainText(text);
    decompressed_file.close();
}





void MainWindow::on_ShowErrors_clicked()
{

            QString in = ui->textEdit->toPlainText();

            if(in == ""){
                QMessageBox::warning(this, "Warning", "No Text To Be Converted");
                return;
            }
    on_actionSave_2_triggered();
            vector<string> input;
           readFile("input.xml",input);

            if(check_consistency(input)==true){
                ui->textEdit_2->clear();
                QMessageBox::information(this, "Info", "This File has no errors to show");
                return;

            }else{
                detect_errors(input);
                writeFile("detected.xml",input);
                QFile x("detected.xml");
                if(!x.open(QFile::ReadOnly | QFile::Text))
                {
                    QMessageBox::warning(this,"Warning" , "Cannot Open File : " + x.errorString());
                }
                QTextStream out(&x);
                QString text = out.readAll();
                ui->textEdit_2->setPlainText(text);
                x.close();
            }
}

