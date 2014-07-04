#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "c:/users/usoft/integration.c"

#define __USE_MINGW_ANSI_STDIO 1    // Provides correct work with long double in MinGW gcc
#define NORM_FORM_MAX 1.0e+17L      // values modulo greater than this will be displayed with scientific form
#define NORM_FORM_MIN 1.0e-08L      // ............. less (...)

static char CurrentVariable;
static int CurrentDelay;

static char temp[32];
static int error_src;
static IntResult result_src;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString part1 = "QComboBox { border: 2px solid black; border-radius: 5px; background-color: rgb(255, 255, 255); }";
    QString part2 = "QComboBox::down-arrow { image:url(:/new/prefix1/da.png); }";
    QString part3 = "QComboBox::drop-down { border-width: 1px; }";
    QString part4 = "QComboBox QAbstractItemView { border: 2px solid transparent; border-radius: 5px; selection-color: rgb(255, 255, 255); selection-background-color: rgb(76, 76, 76); outline: none; }";
    
    ui->dX->setStyleSheet(part1 + part2 + part3 + part4);
    ui->TimeToCalculate->setStyleSheet(part1 + part2 + part3 + part4);
    ui->InfoTable->setStyleSheet("QTableWidget { border: 2px solid rgb(0, 0, 0); border-radius: 6px; }");
    
    SH_Computate = new QShortcut(QKeySequence(Qt::Key_Return), this);
    QObject::connect(SH_Computate, SIGNAL(activated()), this, SLOT(on_Computate_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Computate_clicked()
{

    QByteArray ba_var = ui->dX->currentText().toLocal8Bit();
    char *var_str = ba_var.data();
    CurrentVariable = var_str[1];

    switch(ui->TimeToCalculate->currentIndex()){

        case 0 : CurrentDelay = 3000; break;
        case 1 : CurrentDelay = 15000; break;
        case 2 : CurrentDelay = 90000; break;
    }

    QString a_qstr = ui->lineEdit_a->text();
    QString b_qstr = ui->lineEdit_b->text();
    QString f_qstr = ui->lineEdit_f->text();

    QByteArray ba_a = a_qstr.toLocal8Bit();
    char *a_str = ba_a.data();

    QByteArray ba_b = b_qstr.toLocal8Bit();
    char *b_str = ba_b.data();

    QByteArray ba_f = f_qstr.toLocal8Bit();
    char *f_str = ba_f.data();

    int *error;
    error = &error_src;

    IntResult *result;
    result = &result_src;

    ui->Message->setStyleSheet("QLabel { color: black }");
    ui->Message->setText("computing ...");
    ui->Message->repaint();

    ui->InfoTable->setStyleSheet("QTableWidget {border: 2px solid rgb(0, 0, 0); border-radius: 6px;}");
    ui->InfoTable->repaint();

    clock_t index = clock();

    integrate(a_str, b_str, f_str, CurrentVariable, ABS_EPS, REL_EPS, MAX_INTERVALS, CurrentDelay, result, error);

    int delay = (int)(clock() - index);

    if(*error == SUCCESS){
        ui->Message->setStyleSheet("QLabel { color: rgb(30, 200, 0) }");
        ui->InfoTable->setStyleSheet("QTableWidget {border: 2px solid rgb(30, 200, 0); border-radius: 6px;}");
    }

    else if(*error == MAX_DELAY_ERR || *error == MAX_INTERVALS_ERR){
        ui->Message->setStyleSheet("QLabel { color: rgb(100, 100, 100) }");
        ui->InfoTable->setStyleSheet("QTableWidget {border: 2px solid rgb(100, 100, 100); border-radius: 6px;}");
    }

    else{
        ui->Message->setStyleSheet("QLabel { color: rgb(255, 0, 0) }");
        ui->InfoTable->setStyleSheet("QTableWidget {border: 2px solid rgb(255, 0, 0); border-radius: 6px;}");
    }

    ui->Message->setText(QString(QLatin1String(error_msg(*error))));

    if(*error != SUCCESS && *error != MAX_DELAY_ERR && *error != MAX_INTERVALS_ERR){
        ui->Value->setText("");
        ui->AbsEps->setText("");
    }

    else
        switch(result->mode){

            case 'C' : {

                if(isgreater(fabsl(result->value), NORM_FORM_MAX) || isless(fabsl(result->value), NORM_FORM_MIN))
                    sprintf(temp, "%.8Le", result->value);

                else{
                    sprintf(temp, "%.8Lf", result->value);
                }

                ui->Value->setText(QString(QLatin1String(temp)));
                ui->AbsEps->setText("");     
                break;
            }

            case '+' : {

                ui->Value->setText("+Infinity");
                ui->AbsEps->setText("");
                break;
            }

            case '-' : {

                ui->Value->setText("-Infinity");
                ui->AbsEps->setText("");
                break;
            }

            default : {

                if(isgreater(fabsl(result->value), NORM_FORM_MAX) || isless(fabsl(result->value), NORM_FORM_MIN))
                    sprintf(temp, "%.8Le", result->value);
                else
                    sprintf(temp, "%.8Lf", result->value);

                ui->Value->setText(QString(QLatin1String(temp)));

                sprintf(temp, "%.4Le", result->eps);

                ui->AbsEps->setText("(abs.eps = " + QString(QLatin1String(temp)) + ")");
            }
        }

    QFile file("c:\\gq_log.txt");
    QTextStream out(&file);

    if(file.open(QIODevice::Append | QIODevice::Text))
    {
          out << f_str << " " << var_str << ", " << var_str[1] << " from " << a_str << " to " << b_str << "\n";

          if(*error == SUCCESS || *error == MAX_DELAY_ERR || *error == MAX_INTERVALS_ERR){

              out << "\tMessage      : " << error_msg(*error) << "\n";
              out << "\tElapsed Time : " << delay << " (" << CurrentDelay << ") ms\n";

              switch(result->mode){

                  case '+' : {
                      out << "\tValue = +Infinity\n";
                      break;
                  }

                  case '-' : {
                      out << "\tValue = -Infinity\n";
                      break;
                  }

                  case 'C' : {
                      sprintf(temp, "%.32Lf", result->value);
                      out << "\tValue = " << temp << "\n";
                      break;
                  }

                  default : {

                      sprintf(temp, "%.32Lf", result->value);
                      out << "\tValue    = " << temp << "\n";
                      sprintf(temp, "%.32Lf", result->eps);
                      out << "\tAbs. Eps = " << temp << "\n";
                  }
              }
          }
          else
              out << "\tMessage : " << error_msg(*error) << "\n";

          for(int i = 0; i < 64; i++)
              out << "-";

          out << "\n";
    }

    file.close();
}

void MainWindow::on_docButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/monstaHD/Gaussian_Quadrature"));
}

void MainWindow::on_clearButton_clicked()
{
    ui->lineEdit_a->setText("");
    ui->lineEdit_b->setText("");
    ui->lineEdit_f->setText("");
}

void MainWindow::on_gaussButton_clicked()
{
    QDesktopServices::openUrl(QUrl("http://en.wikipedia.org/wiki/Gaussian_quadrature"));
}
