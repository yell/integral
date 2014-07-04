#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <QFile>
#include <QTextStream>
#include <QtCore>
#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Computate_clicked();
    void on_docButton_clicked();
    void on_gaussButton_clicked();
    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    QShortcut *SH_Computate;
};

#endif // MAINWINDOW_H
