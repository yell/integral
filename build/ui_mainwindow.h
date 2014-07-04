/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit_f;
    QLabel *int_sign;
    QLineEdit *lineEdit_a;
    QLineEdit *lineEdit_b;
    QComboBox *dX;
    QPushButton *Computate;
    QLabel *Message;
    QLabel *Value;
    QLabel *AbsEps;
    QComboBox *TimeToCalculate;
    QTableWidget *InfoTable;
    QPushButton *quitButton;
    QPushButton *docButton;
    QPushButton *clearButton;
    QPushButton *gaussButton;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(960, 480);
        MainWindow->setMinimumSize(QSize(960, 480));
        MainWindow->setMaximumSize(QSize(960, 480));
        QFont font;
        font.setFamily(QStringLiteral("Harabara"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit_f = new QLineEdit(centralWidget);
        lineEdit_f->setObjectName(QStringLiteral("lineEdit_f"));
        lineEdit_f->setGeometry(QRect(130, 217, 360, 32));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(14);
        lineEdit_f->setFont(font1);
        lineEdit_f->setStyleSheet(QLatin1String("border: 2px solid rgb(255, 42, 0);\n"
"    border-radius: 6px;\n"
"    padding: 0 8px;\n"
"selection-color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(238, 79, 0);"));
        int_sign = new QLabel(centralWidget);
        int_sign->setObjectName(QStringLiteral("int_sign"));
        int_sign->setGeometry(QRect(70, 150, 51, 171));
        int_sign->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/integral.png")));
        lineEdit_a = new QLineEdit(centralWidget);
        lineEdit_a->setObjectName(QStringLiteral("lineEdit_a"));
        lineEdit_a->setGeometry(QRect(23, 325, 144, 28));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(13);
        lineEdit_a->setFont(font2);
        lineEdit_a->setStyleSheet(QLatin1String("border: 2px solid rgb(255, 42, 0);\n"
"    border-radius: 6px;\n"
"    padding: 0 8px;\n"
"selection-color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(238, 79, 0);"));
        lineEdit_a->setAlignment(Qt::AlignCenter);
        lineEdit_b = new QLineEdit(centralWidget);
        lineEdit_b->setObjectName(QStringLiteral("lineEdit_b"));
        lineEdit_b->setGeometry(QRect(23, 120, 144, 28));
        lineEdit_b->setFont(font2);
        lineEdit_b->setStyleSheet(QLatin1String("border: 2px solid rgb(255, 42, 0);\n"
"    border-radius: 6px;\n"
"    padding: 0 8px;\n"
"selection-color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(238, 79, 0);"));
        lineEdit_b->setAlignment(Qt::AlignCenter);
        dX = new QComboBox(centralWidget);
        dX->setObjectName(QStringLiteral("dX"));
        dX->setGeometry(QRect(495, 217, 51, 32));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        dX->setFont(font3);
        dX->setStyleSheet(QStringLiteral(""));
        dX->setMaxVisibleItems(11);
        dX->setIconSize(QSize(16, 16));
        dX->setDuplicatesEnabled(false);
        dX->setFrame(true);
        dX->setModelColumn(0);
        Computate = new QPushButton(centralWidget);
        Computate->setObjectName(QStringLiteral("Computate"));
        Computate->setEnabled(true);
        Computate->setGeometry(QRect(557, 212, 44, 44));
        QFont font4;
        font4.setFamily(QStringLiteral("Stencil"));
        font4.setPointSize(22);
        font4.setBold(true);
        font4.setWeight(75);
        Computate->setFont(font4);
        Computate->setFocusPolicy(Qt::WheelFocus);
        Computate->setStyleSheet(QLatin1String("border: 2px solid rgb(255, 42, 0);\n"
"    border-radius: 6px;\n"
"    padding: 0 8px;\n"
"selection-color: rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.931818 rgba(255, 105, 0, 255));"));
        Computate->setAutoDefault(true);
        Computate->setDefault(true);
        Computate->setFlat(false);
        Message = new QLabel(centralWidget);
        Message->setObjectName(QStringLiteral("Message"));
        Message->setGeometry(QRect(630, 180, 300, 24));
        QFont font5;
        font5.setFamily(QStringLiteral("Arial"));
        font5.setPointSize(14);
        font5.setBold(false);
        font5.setItalic(true);
        font5.setWeight(50);
        Message->setFont(font5);
        Message->setAlignment(Qt::AlignCenter);
        Value = new QLabel(centralWidget);
        Value->setObjectName(QStringLiteral("Value"));
        Value->setGeometry(QRect(622, 220, 310, 28));
        QFont font6;
        font6.setFamily(QStringLiteral("Arial"));
        font6.setPointSize(16);
        font6.setBold(false);
        font6.setWeight(50);
        Value->setFont(font6);
        Value->setAlignment(Qt::AlignCenter);
        AbsEps = new QLabel(centralWidget);
        AbsEps->setObjectName(QStringLiteral("AbsEps"));
        AbsEps->setGeometry(QRect(622, 260, 310, 24));
        QFont font7;
        font7.setFamily(QStringLiteral("Arial"));
        font7.setPointSize(13);
        font7.setBold(false);
        font7.setWeight(50);
        AbsEps->setFont(font7);
        AbsEps->setAlignment(Qt::AlignCenter);
        TimeToCalculate = new QComboBox(centralWidget);
        TimeToCalculate->setObjectName(QStringLiteral("TimeToCalculate"));
        TimeToCalculate->setGeometry(QRect(5, 217, 56, 32));
        QFont font8;
        font8.setFamily(QStringLiteral("Arial"));
        font8.setPointSize(14);
        font8.setBold(true);
        font8.setItalic(false);
        font8.setWeight(75);
        TimeToCalculate->setFont(font8);
        TimeToCalculate->setStyleSheet(QStringLiteral(""));
        TimeToCalculate->setMaxVisibleItems(11);
        TimeToCalculate->setIconSize(QSize(16, 16));
        TimeToCalculate->setDuplicatesEnabled(false);
        TimeToCalculate->setFrame(true);
        TimeToCalculate->setModelColumn(0);
        InfoTable = new QTableWidget(centralWidget);
        InfoTable->setObjectName(QStringLiteral("InfoTable"));
        InfoTable->setGeometry(QRect(612, 164, 330, 144));
        InfoTable->setStyleSheet(QStringLiteral(""));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(485, 30, 60, 25));
        QFont font9;
        font9.setFamily(QStringLiteral("Harabara"));
        font9.setPointSize(22);
        font9.setBold(true);
        font9.setWeight(75);
        quitButton->setFont(font9);
        quitButton->setStyleSheet(QLatin1String("border: 0px;\n"
"color: rgb(255, 80, 0);;\n"
" \n"
"   \n"
""));
        docButton = new QPushButton(centralWidget);
        docButton->setObjectName(QStringLiteral("docButton"));
        docButton->setGeometry(QRect(295, 30, 181, 25));
        docButton->setFont(font9);
        docButton->setStyleSheet(QLatin1String("border: 0px;\n"
"color: rgb(255, 120, 0);"));
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(70, 150, 51, 171));
        clearButton->setStyleSheet(QLatin1String("border: 0px;\n"
"background-color: transparent;"));
        gaussButton = new QPushButton(centralWidget);
        gaussButton->setObjectName(QStringLiteral("gaussButton"));
        gaussButton->setGeometry(QRect(25, 30, 260, 25));
        gaussButton->setFont(font9);
        gaussButton->setStyleSheet(QLatin1String("border: 0px;\n"
"color: rgb(60, 60, 60);"));
        MainWindow->setCentralWidget(centralWidget);
        InfoTable->raise();
        lineEdit_f->raise();
        int_sign->raise();
        lineEdit_a->raise();
        lineEdit_b->raise();
        dX->raise();
        Computate->raise();
        Message->raise();
        Value->raise();
        AbsEps->raise();
        TimeToCalculate->raise();
        quitButton->raise();
        docButton->raise();
        clearButton->raise();
        gaussButton->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(false);
        menuBar->setGeometry(QRect(0, 0, 960, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);
        QObject::connect(quitButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        dX->setCurrentIndex(8);
        TimeToCalculate->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GQ", 0));
        int_sign->setText(QString());
        dX->clear();
        dX->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "dp", 0)
         << QApplication::translate("MainWindow", "dq", 0)
         << QApplication::translate("MainWindow", "dr", 0)
         << QApplication::translate("MainWindow", "ds", 0)
         << QApplication::translate("MainWindow", "dt", 0)
         << QApplication::translate("MainWindow", "du", 0)
         << QApplication::translate("MainWindow", "dv", 0)
         << QApplication::translate("MainWindow", "dw", 0)
         << QApplication::translate("MainWindow", "dx", 0)
         << QApplication::translate("MainWindow", "dy", 0)
         << QApplication::translate("MainWindow", "dz", 0)
        );
        Computate->setText(QApplication::translate("MainWindow", "=", 0));
        Message->setText(QApplication::translate("MainWindow", "input your data", 0));
        Value->setText(QString());
        AbsEps->setText(QString());
        TimeToCalculate->clear();
        TimeToCalculate->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "  3s", 0)
         << QApplication::translate("MainWindow", "15s", 0)
         << QApplication::translate("MainWindow", "90s", 0)
        );
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
        docButton->setText(QApplication::translate("MainWindow", "Documentation", 0));
        clearButton->setText(QString());
        gaussButton->setText(QApplication::translate("MainWindow", "Gaussian Quadrature", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
