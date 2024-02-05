/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <../Front/qcustomplot.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_div;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_mod;
    QLabel *label_4;
    QLabel *label;
    QPushButton *pushButton_result;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_mul;
    QLabel *label_3;
    QPushButton *pushButton_1;
    QPushButton *pushButton_6;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_right_par;
    QPushButton *pushButton_9;
    QPushButton *pushButton_log;
    QPushButton *pushButton_left_par;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_2;
    QLabel *result_show;
    QPushButton *pushButton_8;
    QLabel *label_2;
    QPushButton *pushButton_DEL;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QCustomPlot *widget;
    QPushButton *pushButton_0;
    QPushButton *pushButton_unar;
    QComboBox *Trigonometry;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(916, 604);
        MainWindow->setTabletTracking(false);
        MainWindow->setTabShape(QTabWidget::Triangular);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(120, 80, 761, 331));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_div = new QPushButton(gridLayoutWidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));

        gridLayout->addWidget(pushButton_div, 2, 4, 1, 1);

        pushButton_pow = new QPushButton(gridLayoutWidget);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        pushButton_pow->setMouseTracking(false);

        gridLayout->addWidget(pushButton_pow, 5, 0, 1, 1);

        pushButton_mod = new QPushButton(gridLayoutWidget);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setMouseTracking(false);

        gridLayout->addWidget(pushButton_mod, 2, 3, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 6, 8, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 5, 6, 1, 1);

        pushButton_result = new QPushButton(gridLayoutWidget);
        pushButton_result->setObjectName(QString::fromUtf8("pushButton_result"));
        pushButton_result->setMouseTracking(false);

        gridLayout->addWidget(pushButton_result, 6, 4, 1, 1);

        pushButton_dot = new QPushButton(gridLayoutWidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setMouseTracking(false);

        gridLayout->addWidget(pushButton_dot, 6, 3, 1, 1);

        pushButton_mul = new QPushButton(gridLayoutWidget);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));

        gridLayout->addWidget(pushButton_mul, 3, 4, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 6, 7, 1, 1);

        pushButton_1 = new QPushButton(gridLayoutWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setMouseTracking(false);

        gridLayout->addWidget(pushButton_1, 5, 1, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 4, 3, 1, 1);

        pushButton_minus = new QPushButton(gridLayoutWidget);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));

        gridLayout->addWidget(pushButton_minus, 4, 4, 1, 1);

        pushButton_AC = new QPushButton(gridLayoutWidget);
        pushButton_AC->setObjectName(QString::fromUtf8("pushButton_AC"));
        pushButton_AC->setMouseTracking(false);

        gridLayout->addWidget(pushButton_AC, 1, 3, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMouseTracking(false);

        gridLayout->addWidget(pushButton_4, 4, 1, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMouseTracking(false);

        gridLayout->addWidget(pushButton_7, 3, 1, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 4, 2, 1, 1);

        pushButton_right_par = new QPushButton(gridLayoutWidget);
        pushButton_right_par->setObjectName(QString::fromUtf8("pushButton_right_par"));

        gridLayout->addWidget(pushButton_right_par, 2, 2, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 3, 3, 1, 1);

        pushButton_log = new QPushButton(gridLayoutWidget);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setMouseTracking(false);

        gridLayout->addWidget(pushButton_log, 3, 0, 1, 1);

        pushButton_left_par = new QPushButton(gridLayoutWidget);
        pushButton_left_par->setObjectName(QString::fromUtf8("pushButton_left_par"));
        pushButton_left_par->setMouseTracking(false);

        gridLayout->addWidget(pushButton_left_par, 2, 1, 1, 1);

        pushButton_sqrt = new QPushButton(gridLayoutWidget);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));

        gridLayout->addWidget(pushButton_sqrt, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 5, 2, 1, 1);

        result_show = new QLabel(gridLayoutWidget);
        result_show->setObjectName(QString::fromUtf8("result_show"));
        result_show->setMinimumSize(QSize(251, 0));
        result_show->setMaximumSize(QSize(16777215, 16777215));
        result_show->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"	border-bottom: 1px solid gray;\n"
"}\n"
"\n"
"background-color : white;"));

        gridLayout->addWidget(result_show, 0, 0, 1, 5);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 3, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(17, 16777215));

        gridLayout->addWidget(label_2, 5, 5, 1, 1);

        pushButton_DEL = new QPushButton(gridLayoutWidget);
        pushButton_DEL->setObjectName(QString::fromUtf8("pushButton_DEL"));
        pushButton_DEL->setMouseTracking(false);

        gridLayout->addWidget(pushButton_DEL, 1, 4, 1, 1);

        pushButton_ln = new QPushButton(gridLayoutWidget);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setMouseTracking(false);

        gridLayout->addWidget(pushButton_ln, 4, 0, 1, 1);

        pushButton_plus = new QPushButton(gridLayoutWidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setMouseTracking(false);

        gridLayout->addWidget(pushButton_plus, 5, 4, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 5, 3, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 6, 9, 1, 1);

        widget = new QCustomPlot(gridLayoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout->addWidget(widget, 0, 6, 5, 4);

        pushButton_0 = new QPushButton(gridLayoutWidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setMouseTracking(false);

        gridLayout->addWidget(pushButton_0, 6, 2, 1, 1);

        pushButton_unar = new QPushButton(gridLayoutWidget);
        pushButton_unar->setObjectName(QString::fromUtf8("pushButton_unar"));
        pushButton_unar->setMouseTracking(false);

        gridLayout->addWidget(pushButton_unar, 6, 1, 1, 1);

        Trigonometry = new QComboBox(gridLayoutWidget);
        Trigonometry->addItem(QString());
        Trigonometry->addItem(QString());
        Trigonometry->addItem(QString::fromUtf8("tan(x)"));
        Trigonometry->addItem(QString());
        Trigonometry->addItem(QString());
        Trigonometry->addItem(QString());
        Trigonometry->setObjectName(QString::fromUtf8("Trigonometry"));
        Trigonometry->setContextMenuPolicy(Qt::DefaultContextMenu);
        Trigonometry->setAcceptDrops(false);
        Trigonometry->setLayoutDirection(Qt::LeftToRight);
        Trigonometry->setEditable(false);

        gridLayout->addWidget(Trigonometry, 1, 0, 1, 3);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_result->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_right_par->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_left_par->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        result_show->setText(QString());
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        label_2->setText(QString());
        pushButton_DEL->setText(QCoreApplication::translate("MainWindow", "DEL", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_unar->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        Trigonometry->setItemText(0, QCoreApplication::translate("MainWindow", "cos(x)", nullptr));
        Trigonometry->setItemText(1, QCoreApplication::translate("MainWindow", "sin(x)", nullptr));
        Trigonometry->setItemText(3, QCoreApplication::translate("MainWindow", "acos(x)", nullptr));
        Trigonometry->setItemText(4, QCoreApplication::translate("MainWindow", "asin(x)", nullptr));
        Trigonometry->setItemText(5, QCoreApplication::translate("MainWindow", "atan(x)", nullptr));

        Trigonometry->setCurrentText(QCoreApplication::translate("MainWindow", "cos(x)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
