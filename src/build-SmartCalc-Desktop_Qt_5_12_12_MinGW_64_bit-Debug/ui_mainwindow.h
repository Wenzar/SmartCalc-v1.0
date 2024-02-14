/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "../Front/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *Trigonometry;
    QPushButton *pushButton_1;
    QPushButton *pushButton_7;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_x;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_9;
    QSpinBox *scope_definifion_min;
    QPushButton *pushButton_div;
    QLabel *label_3;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_6;
    QPushButton *pushButton_log;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_ln;
    QLabel *label_5;
    QLabel *label_2;
    QPushButton *plot_graph;
    QLabel *label_6;
    QSpinBox *scope_definifion_max;
    QLineEdit *x_value;
    QPushButton *pushButton_0;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_3;
    QPushButton *pushButton_DEL;
    QPushButton *pushButton_unar;
    QPushButton *pushButton_2;
    QPushButton *pushButton_result;
    QPushButton *pushButton_4;
    QPushButton *pushButton_sqrt;
    QLabel *result_show;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_left_par;
    QPushButton *pushButton_right_par;
    QCustomPlot *customPlot;
    QLabel *label_22;
    QWidget *credit_calc;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *total_payout;
    QLineEdit *percentage_rate;
    QLabel *label;
    QLineEdit *monthly_payment;
    QLabel *label_10;
    QLabel *label_4;
    QLabel *label_14;
    QLineEdit *loan_period;
    QPushButton *pushButton_calculate_credit;
    QLabel *label_9;
    QLabel *label_16;
    QLabel *label_12;
    QLineEdit *overpayment_loan;
    QLabel *label_8;
    QLabel *label_17;
    QRadioButton *differentiated;
    QLabel *label_7;
    QLineEdit *credit_sum;
    QLabel *credit_error;
    QRadioButton *annuities;
    QComboBox *credit_period_choice;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_18;
    QLabel *label_15;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *refill_sum;
    QComboBox *withdrawal_frequency;
    QLabel *label_24;
    QLineEdit *withdrawal_sum;
    QLabel *label_19;
    QComboBox *period_placement_type;
    QLabel *label_25;
    QDateEdit *beginning_term;
    QLabel *label228;
    QLineEdit *central_bank_rate;
    QComboBox *refill_frequency;
    QLabel *label_20;
    QDateEdit *refill_date;
    QLabel *label_26;
    QLabel *label_21;
    QLineEdit *percentage_rate_dep;
    QLabel *label_29;
    QLineEdit *deposit_sum;
    QCheckBox *capitalization_of_percents;
    QComboBox *frequency_of_payments;
    QLineEdit *period_placement;
    QLabel *label_27;
    QDateEdit *withdrawal_date;
    QLabel *label_23;
    QLabel *label_33;
    QLabel *label_32;
    QLabel *label_31;
    QLabel *label_30;
    QLineEdit *income_after_taxes;
    QLineEdit *tax;
    QLineEdit *deposit_amount_with_interest;
    QLineEdit *accrued_interest;
    QLabel *label_28;
    QPushButton *pushButton_calculate_deposit;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *deposit_error;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(830, 527);
        MainWindow->setMinimumSize(QSize(830, 527));
        MainWindow->setMaximumSize(QSize(830, 527));
        MainWindow->setTabletTracking(false);
        MainWindow->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"	background-color:  rgb(237, 239, 243);\n"
"	border:  grey;\n"
"}"));
        MainWindow->setTabShape(QTabWidget::Triangular);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 831, 531));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 821, 501));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        gridLayoutWidget->setFont(font1);
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Trigonometry = new QComboBox(gridLayoutWidget);
        Trigonometry->addItem(QString());
        Trigonometry->addItem(QString());
        Trigonometry->addItem(QString::fromUtf8("tan(x)"));
        Trigonometry->addItem(QString());
        Trigonometry->addItem(QString());
        Trigonometry->addItem(QString());
        Trigonometry->setObjectName(QString::fromUtf8("Trigonometry"));
        Trigonometry->setFont(font1);
        Trigonometry->setContextMenuPolicy(Qt::DefaultContextMenu);
        Trigonometry->setAcceptDrops(false);
        Trigonometry->setLayoutDirection(Qt::LeftToRight);
        Trigonometry->setEditable(false);

        gridLayout->addWidget(Trigonometry, 2, 0, 1, 1);

        pushButton_1 = new QPushButton(gridLayoutWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setFont(font1);
        pushButton_1->setMouseTracking(false);

        gridLayout->addWidget(pushButton_1, 6, 1, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setFont(font1);
        pushButton_7->setMouseTracking(false);

        gridLayout->addWidget(pushButton_7, 4, 1, 1, 1);

        pushButton_mul = new QPushButton(gridLayoutWidget);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setFont(font1);

        gridLayout->addWidget(pushButton_mul, 4, 4, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font1);

        gridLayout->addWidget(pushButton_5, 5, 2, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setFont(font1);

        gridLayout->addWidget(pushButton_8, 4, 2, 1, 1);

        pushButton_x = new QPushButton(gridLayoutWidget);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setFont(font1);

        gridLayout->addWidget(pushButton_x, 7, 0, 1, 1);

        pushButton_plus = new QPushButton(gridLayoutWidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setFont(font1);
        pushButton_plus->setMouseTracking(false);

        gridLayout->addWidget(pushButton_plus, 6, 4, 1, 1);

        pushButton_dot = new QPushButton(gridLayoutWidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setFont(font1);
        pushButton_dot->setMouseTracking(false);

        gridLayout->addWidget(pushButton_dot, 7, 3, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setFont(font1);

        gridLayout->addWidget(pushButton_9, 4, 3, 1, 1);

        scope_definifion_min = new QSpinBox(gridLayoutWidget);
        scope_definifion_min->setObjectName(QString::fromUtf8("scope_definifion_min"));
        scope_definifion_min->setFont(font);
        scope_definifion_min->setMinimum(-1000000);
        scope_definifion_min->setMaximum(1000000);
        scope_definifion_min->setValue(-10);

        gridLayout->addWidget(scope_definifion_min, 7, 6, 1, 1);

        pushButton_div = new QPushButton(gridLayoutWidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setFont(font1);

        gridLayout->addWidget(pushButton_div, 3, 4, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        pushButton_minus = new QPushButton(gridLayoutWidget);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setFont(font1);

        gridLayout->addWidget(pushButton_minus, 5, 4, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font1);

        gridLayout->addWidget(pushButton_6, 5, 3, 1, 1);

        pushButton_log = new QPushButton(gridLayoutWidget);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setFont(font1);
        pushButton_log->setMouseTracking(false);

        gridLayout->addWidget(pushButton_log, 4, 0, 1, 1);

        pushButton_pow = new QPushButton(gridLayoutWidget);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        pushButton_pow->setFont(font1);
        pushButton_pow->setMouseTracking(false);

        gridLayout->addWidget(pushButton_pow, 6, 0, 1, 1);

        pushButton_ln = new QPushButton(gridLayoutWidget);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setFont(font1);
        pushButton_ln->setMouseTracking(false);

        gridLayout->addWidget(pushButton_ln, 5, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 7, 8, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(17, 16777215));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 6, 5, 1, 1);

        plot_graph = new QPushButton(gridLayoutWidget);
        plot_graph->setObjectName(QString::fromUtf8("plot_graph"));
        plot_graph->setFont(font1);

        gridLayout->addWidget(plot_graph, 7, 9, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 7, 5, 1, 1);

        scope_definifion_max = new QSpinBox(gridLayoutWidget);
        scope_definifion_max->setObjectName(QString::fromUtf8("scope_definifion_max"));
        scope_definifion_max->setFont(font);
        scope_definifion_max->setMinimum(-1000000);
        scope_definifion_max->setMaximum(1000000);
        scope_definifion_max->setValue(10);

        gridLayout->addWidget(scope_definifion_max, 7, 7, 1, 1);

        x_value = new QLineEdit(gridLayoutWidget);
        x_value->setObjectName(QString::fromUtf8("x_value"));
        x_value->setMaximumSize(QSize(75, 16777215));
        x_value->setFont(font1);

        gridLayout->addWidget(x_value, 2, 2, 1, 1);

        pushButton_0 = new QPushButton(gridLayoutWidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setFont(font1);
        pushButton_0->setMouseTracking(false);

        gridLayout->addWidget(pushButton_0, 7, 2, 1, 1);

        pushButton_mod = new QPushButton(gridLayoutWidget);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setFont(font1);
        pushButton_mod->setMouseTracking(false);

        gridLayout->addWidget(pushButton_mod, 3, 3, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font1);

        gridLayout->addWidget(pushButton_3, 6, 3, 1, 1);

        pushButton_DEL = new QPushButton(gridLayoutWidget);
        pushButton_DEL->setObjectName(QString::fromUtf8("pushButton_DEL"));
        pushButton_DEL->setFont(font1);
        pushButton_DEL->setMouseTracking(false);

        gridLayout->addWidget(pushButton_DEL, 2, 4, 1, 1);

        pushButton_unar = new QPushButton(gridLayoutWidget);
        pushButton_unar->setObjectName(QString::fromUtf8("pushButton_unar"));
        pushButton_unar->setFont(font1);
        pushButton_unar->setMouseTracking(false);

        gridLayout->addWidget(pushButton_unar, 7, 1, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font1);

        gridLayout->addWidget(pushButton_2, 6, 2, 1, 1);

        pushButton_result = new QPushButton(gridLayoutWidget);
        pushButton_result->setObjectName(QString::fromUtf8("pushButton_result"));
        pushButton_result->setFont(font1);
        pushButton_result->setMouseTracking(false);

        gridLayout->addWidget(pushButton_result, 7, 4, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font1);
        pushButton_4->setMouseTracking(false);

        gridLayout->addWidget(pushButton_4, 5, 1, 1, 1);

        pushButton_sqrt = new QPushButton(gridLayoutWidget);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setFont(font1);

        gridLayout->addWidget(pushButton_sqrt, 3, 0, 1, 1);

        result_show = new QLabel(gridLayoutWidget);
        result_show->setObjectName(QString::fromUtf8("result_show"));
        result_show->setMinimumSize(QSize(251, 0));
        result_show->setMaximumSize(QSize(16777215, 200000));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(16);
        result_show->setFont(font2);
        result_show->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"	border-bottom: 1px solid gray;\n"
"	background-color : white;\n"
"}\n"
"\n"
""));
        result_show->setMargin(0);

        gridLayout->addWidget(result_show, 1, 0, 1, 5);

        pushButton_AC = new QPushButton(gridLayoutWidget);
        pushButton_AC->setObjectName(QString::fromUtf8("pushButton_AC"));
        pushButton_AC->setFont(font1);
        pushButton_AC->setMouseTracking(false);

        gridLayout->addWidget(pushButton_AC, 2, 3, 1, 1);

        pushButton_left_par = new QPushButton(gridLayoutWidget);
        pushButton_left_par->setObjectName(QString::fromUtf8("pushButton_left_par"));
        pushButton_left_par->setFont(font1);
        pushButton_left_par->setMouseTracking(false);

        gridLayout->addWidget(pushButton_left_par, 3, 1, 1, 1);

        pushButton_right_par = new QPushButton(gridLayoutWidget);
        pushButton_right_par->setObjectName(QString::fromUtf8("pushButton_right_par"));
        pushButton_right_par->setFont(font1);

        gridLayout->addWidget(pushButton_right_par, 3, 2, 1, 1);

        customPlot = new QCustomPlot(gridLayoutWidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setMinimumSize(QSize(400, 350));
        customPlot->setFont(font1);

        gridLayout->addWidget(customPlot, 0, 6, 6, 4);

        label_22 = new QLabel(gridLayoutWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout->addWidget(label_22, 0, 0, 1, 5);

        tabWidget->addTab(tab, QString());
        credit_calc = new QWidget();
        credit_calc->setObjectName(QString::fromUtf8("credit_calc"));
        gridLayoutWidget_2 = new QWidget(credit_calc);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 821, 501));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(11);
        gridLayoutWidget_2->setFont(font3);
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(6);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        total_payout = new QLineEdit(gridLayoutWidget_2);
        total_payout->setObjectName(QString::fromUtf8("total_payout"));
        total_payout->setMaximumSize(QSize(200, 16777215));
        total_payout->setFont(font3);

        gridLayout_2->addWidget(total_payout, 11, 1, 1, 1);

        percentage_rate = new QLineEdit(gridLayoutWidget_2);
        percentage_rate->setObjectName(QString::fromUtf8("percentage_rate"));
        percentage_rate->setMaximumSize(QSize(200, 16777215));
        percentage_rate->setFont(font3);

        gridLayout_2->addWidget(percentage_rate, 2, 1, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Segoe UI"));
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        font4.setKerning(true);
        label->setFont(font4);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        monthly_payment = new QLineEdit(gridLayoutWidget_2);
        monthly_payment->setObjectName(QString::fromUtf8("monthly_payment"));
        monthly_payment->setMaximumSize(QSize(200, 16777215));
        monthly_payment->setFont(font3);

        gridLayout_2->addWidget(monthly_payment, 10, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font3);
        label_10->setFrameShadow(QFrame::Plain);
        label_10->setLineWidth(1);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_10, 11, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font4);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font3);

        gridLayout_2->addWidget(label_14, 0, 2, 1, 1);

        loan_period = new QLineEdit(gridLayoutWidget_2);
        loan_period->setObjectName(QString::fromUtf8("loan_period"));
        loan_period->setMaximumSize(QSize(200, 16777215));
        loan_period->setFont(font3);

        gridLayout_2->addWidget(loan_period, 1, 1, 1, 1);

        pushButton_calculate_credit = new QPushButton(gridLayoutWidget_2);
        pushButton_calculate_credit->setObjectName(QString::fromUtf8("pushButton_calculate_credit"));
        pushButton_calculate_credit->setMaximumSize(QSize(200, 16777215));
        pushButton_calculate_credit->setFont(font3);
        pushButton_calculate_credit->setAutoDefault(false);

        gridLayout_2->addWidget(pushButton_calculate_credit, 7, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font3);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_9, 12, 0, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font3);
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_16, 2, 2, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font3);

        gridLayout_2->addWidget(label_12, 11, 2, 1, 1);

        overpayment_loan = new QLineEdit(gridLayoutWidget_2);
        overpayment_loan->setObjectName(QString::fromUtf8("overpayment_loan"));
        overpayment_loan->setMaximumSize(QSize(200, 16777215));
        overpayment_loan->setFont(font3);

        gridLayout_2->addWidget(overpayment_loan, 12, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(16777215, 20));
        label_8->setFont(font3);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_8, 10, 0, 1, 1);

        label_17 = new QLabel(gridLayoutWidget_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setMaximumSize(QSize(16777215, 20));
        label_17->setFont(font4);
        label_17->setLayoutDirection(Qt::LeftToRight);
        label_17->setTextFormat(Qt::AutoText);
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_17, 3, 0, 1, 1);

        differentiated = new QRadioButton(gridLayoutWidget_2);
        differentiated->setObjectName(QString::fromUtf8("differentiated"));
        differentiated->setFont(font3);

        gridLayout_2->addWidget(differentiated, 4, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(16777215, 20));
        label_7->setFont(font4);
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setAutoFillBackground(false);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        credit_sum = new QLineEdit(gridLayoutWidget_2);
        credit_sum->setObjectName(QString::fromUtf8("credit_sum"));
        credit_sum->setMaximumSize(QSize(200, 16777215));
        credit_sum->setFont(font3);

        gridLayout_2->addWidget(credit_sum, 0, 1, 1, 1);

        credit_error = new QLabel(gridLayoutWidget_2);
        credit_error->setObjectName(QString::fromUtf8("credit_error"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Segoe UI"));
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setWeight(75);
        credit_error->setFont(font5);

        gridLayout_2->addWidget(credit_error, 7, 2, 1, 1);

        annuities = new QRadioButton(gridLayoutWidget_2);
        annuities->setObjectName(QString::fromUtf8("annuities"));
        annuities->setFont(font3);

        gridLayout_2->addWidget(annuities, 3, 1, 1, 1);

        credit_period_choice = new QComboBox(gridLayoutWidget_2);
        credit_period_choice->addItem(QString());
        credit_period_choice->addItem(QString());
        credit_period_choice->setObjectName(QString::fromUtf8("credit_period_choice"));
        credit_period_choice->setMaximumSize(QSize(100, 16777215));
        credit_period_choice->setFont(font3);
        credit_period_choice->setIconSize(QSize(16, 16));

        gridLayout_2->addWidget(credit_period_choice, 1, 2, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(16777215, 20));
        label_11->setFont(font5);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_11, 8, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font3);

        gridLayout_2->addWidget(label_13, 10, 2, 1, 1);

        label_18 = new QLabel(gridLayoutWidget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font3);

        gridLayout_2->addWidget(label_18, 12, 2, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMaximumSize(QSize(175, 16777215));
        label_15->setFont(font3);

        gridLayout_2->addWidget(label_15, 1, 3, 1, 1);

        tabWidget->addTab(credit_calc, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayoutWidget_3 = new QWidget(tab_2);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(0, 0, 821, 501));
        gridLayoutWidget_3->setFont(font);
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        refill_sum = new QLineEdit(gridLayoutWidget_3);
        refill_sum->setObjectName(QString::fromUtf8("refill_sum"));
        refill_sum->setFont(font);

        gridLayout_3->addWidget(refill_sum, 7, 3, 1, 1);

        withdrawal_frequency = new QComboBox(gridLayoutWidget_3);
        withdrawal_frequency->addItem(QString());
        withdrawal_frequency->addItem(QString());
        withdrawal_frequency->addItem(QString());
        withdrawal_frequency->addItem(QString());
        withdrawal_frequency->addItem(QString());
        withdrawal_frequency->addItem(QString());
        withdrawal_frequency->setObjectName(QString::fromUtf8("withdrawal_frequency"));
        withdrawal_frequency->setFont(font);

        gridLayout_3->addWidget(withdrawal_frequency, 8, 1, 1, 1);

        label_24 = new QLabel(gridLayoutWidget_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font);

        gridLayout_3->addWidget(label_24, 5, 0, 1, 1);

        withdrawal_sum = new QLineEdit(gridLayoutWidget_3);
        withdrawal_sum->setObjectName(QString::fromUtf8("withdrawal_sum"));
        withdrawal_sum->setFont(font);

        gridLayout_3->addWidget(withdrawal_sum, 8, 3, 1, 1);

        label_19 = new QLabel(gridLayoutWidget_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font);

        gridLayout_3->addWidget(label_19, 0, 0, 1, 1);

        period_placement_type = new QComboBox(gridLayoutWidget_3);
        period_placement_type->addItem(QString());
        period_placement_type->addItem(QString());
        period_placement_type->addItem(QString());
        period_placement_type->setObjectName(QString::fromUtf8("period_placement_type"));
        period_placement_type->setFont(font);

        gridLayout_3->addWidget(period_placement_type, 1, 2, 1, 1);

        label_25 = new QLabel(gridLayoutWidget_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font);

        gridLayout_3->addWidget(label_25, 6, 0, 1, 1);

        beginning_term = new QDateEdit(gridLayoutWidget_3);
        beginning_term->setObjectName(QString::fromUtf8("beginning_term"));
        beginning_term->setFont(font);

        gridLayout_3->addWidget(beginning_term, 2, 1, 1, 1);

        label228 = new QLabel(gridLayoutWidget_3);
        label228->setObjectName(QString::fromUtf8("label228"));
        label228->setFont(font);

        gridLayout_3->addWidget(label228, 3, 0, 1, 1);

        central_bank_rate = new QLineEdit(gridLayoutWidget_3);
        central_bank_rate->setObjectName(QString::fromUtf8("central_bank_rate"));
        central_bank_rate->setFont(font);

        gridLayout_3->addWidget(central_bank_rate, 4, 1, 1, 1);

        refill_frequency = new QComboBox(gridLayoutWidget_3);
        refill_frequency->addItem(QString());
        refill_frequency->addItem(QString());
        refill_frequency->addItem(QString());
        refill_frequency->addItem(QString());
        refill_frequency->addItem(QString());
        refill_frequency->addItem(QString());
        refill_frequency->setObjectName(QString::fromUtf8("refill_frequency"));
        refill_frequency->setFont(font);

        gridLayout_3->addWidget(refill_frequency, 7, 1, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);

        gridLayout_3->addWidget(label_20, 1, 0, 1, 1);

        refill_date = new QDateEdit(gridLayoutWidget_3);
        refill_date->setObjectName(QString::fromUtf8("refill_date"));
        refill_date->setFont(font);

        gridLayout_3->addWidget(refill_date, 7, 2, 1, 1);

        label_26 = new QLabel(gridLayoutWidget_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font);

        gridLayout_3->addWidget(label_26, 7, 0, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font);

        gridLayout_3->addWidget(label_21, 2, 0, 1, 1);

        percentage_rate_dep = new QLineEdit(gridLayoutWidget_3);
        percentage_rate_dep->setObjectName(QString::fromUtf8("percentage_rate_dep"));
        percentage_rate_dep->setFont(font);

        gridLayout_3->addWidget(percentage_rate_dep, 3, 1, 1, 1);

        label_29 = new QLabel(gridLayoutWidget_3);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font);

        gridLayout_3->addWidget(label_29, 0, 4, 1, 1);

        deposit_sum = new QLineEdit(gridLayoutWidget_3);
        deposit_sum->setObjectName(QString::fromUtf8("deposit_sum"));
        deposit_sum->setFont(font);

        gridLayout_3->addWidget(deposit_sum, 0, 1, 1, 1);

        capitalization_of_percents = new QCheckBox(gridLayoutWidget_3);
        capitalization_of_percents->setObjectName(QString::fromUtf8("capitalization_of_percents"));
        capitalization_of_percents->setFont(font);

        gridLayout_3->addWidget(capitalization_of_percents, 6, 1, 1, 1);

        frequency_of_payments = new QComboBox(gridLayoutWidget_3);
        frequency_of_payments->addItem(QString());
        frequency_of_payments->addItem(QString());
        frequency_of_payments->addItem(QString());
        frequency_of_payments->addItem(QString());
        frequency_of_payments->addItem(QString());
        frequency_of_payments->addItem(QString());
        frequency_of_payments->addItem(QString());
        frequency_of_payments->setObjectName(QString::fromUtf8("frequency_of_payments"));
        frequency_of_payments->setFont(font);

        gridLayout_3->addWidget(frequency_of_payments, 5, 1, 1, 1);

        period_placement = new QLineEdit(gridLayoutWidget_3);
        period_placement->setObjectName(QString::fromUtf8("period_placement"));
        period_placement->setFont(font);

        gridLayout_3->addWidget(period_placement, 1, 1, 1, 1);

        label_27 = new QLabel(gridLayoutWidget_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font);

        gridLayout_3->addWidget(label_27, 8, 0, 1, 1);

        withdrawal_date = new QDateEdit(gridLayoutWidget_3);
        withdrawal_date->setObjectName(QString::fromUtf8("withdrawal_date"));
        withdrawal_date->setFont(font);

        gridLayout_3->addWidget(withdrawal_date, 8, 2, 1, 1);

        label_23 = new QLabel(gridLayoutWidget_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font);

        gridLayout_3->addWidget(label_23, 4, 0, 1, 1);

        label_33 = new QLabel(gridLayoutWidget_3);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font);

        gridLayout_3->addWidget(label_33, 4, 5, 1, 1);

        label_32 = new QLabel(gridLayoutWidget_3);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setFont(font);

        gridLayout_3->addWidget(label_32, 3, 5, 1, 1);

        label_31 = new QLabel(gridLayoutWidget_3);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font);

        gridLayout_3->addWidget(label_31, 2, 5, 1, 1);

        label_30 = new QLabel(gridLayoutWidget_3);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setFont(font);

        gridLayout_3->addWidget(label_30, 1, 5, 1, 1);

        income_after_taxes = new QLineEdit(gridLayoutWidget_3);
        income_after_taxes->setObjectName(QString::fromUtf8("income_after_taxes"));
        income_after_taxes->setFont(font);

        gridLayout_3->addWidget(income_after_taxes, 4, 6, 1, 1);

        tax = new QLineEdit(gridLayoutWidget_3);
        tax->setObjectName(QString::fromUtf8("tax"));
        tax->setFont(font);

        gridLayout_3->addWidget(tax, 3, 6, 1, 1);

        deposit_amount_with_interest = new QLineEdit(gridLayoutWidget_3);
        deposit_amount_with_interest->setObjectName(QString::fromUtf8("deposit_amount_with_interest"));
        deposit_amount_with_interest->setFont(font);

        gridLayout_3->addWidget(deposit_amount_with_interest, 2, 6, 1, 1);

        accrued_interest = new QLineEdit(gridLayoutWidget_3);
        accrued_interest->setObjectName(QString::fromUtf8("accrued_interest"));
        accrued_interest->setFont(font);

        gridLayout_3->addWidget(accrued_interest, 1, 6, 1, 1);

        label_28 = new QLabel(gridLayoutWidget_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font);
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_28, 0, 5, 1, 2);

        pushButton_calculate_deposit = new QPushButton(gridLayoutWidget_3);
        pushButton_calculate_deposit->setObjectName(QString::fromUtf8("pushButton_calculate_deposit"));
        pushButton_calculate_deposit->setFont(font);

        gridLayout_3->addWidget(pushButton_calculate_deposit, 5, 5, 2, 2);

        label_34 = new QLabel(gridLayoutWidget_3);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font);

        gridLayout_3->addWidget(label_34, 0, 2, 1, 1);

        label_35 = new QLabel(gridLayoutWidget_3);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setFont(font);

        gridLayout_3->addWidget(label_35, 7, 4, 1, 1);

        label_36 = new QLabel(gridLayoutWidget_3);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setFont(font);

        gridLayout_3->addWidget(label_36, 8, 4, 1, 1);

        deposit_error = new QLabel(gridLayoutWidget_3);
        deposit_error->setObjectName(QString::fromUtf8("deposit_error"));
        deposit_error->setFont(font);

        gridLayout_3->addWidget(deposit_error, 5, 3, 2, 2);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        Trigonometry->setItemText(0, QApplication::translate("MainWindow", "cos(x)", nullptr));
        Trigonometry->setItemText(1, QApplication::translate("MainWindow", "sin(x)", nullptr));
        Trigonometry->setItemText(3, QApplication::translate("MainWindow", "acos(x)", nullptr));
        Trigonometry->setItemText(4, QApplication::translate("MainWindow", "asin(x)", nullptr));
        Trigonometry->setItemText(5, QApplication::translate("MainWindow", "atan(x)", nullptr));

        Trigonometry->setCurrentText(QApplication::translate("MainWindow", "cos(x)", nullptr));
        pushButton_1->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "7", nullptr));
        pushButton_mul->setText(QApplication::translate("MainWindow", "*", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "5", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "8", nullptr));
        pushButton_x->setText(QApplication::translate("MainWindow", "x", nullptr));
        pushButton_plus->setText(QApplication::translate("MainWindow", "+", nullptr));
        pushButton_dot->setText(QApplication::translate("MainWindow", ".", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "9", nullptr));
        pushButton_div->setText(QApplication::translate("MainWindow", "/", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "x=", nullptr));
        pushButton_minus->setText(QApplication::translate("MainWindow", "-", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "6", nullptr));
        pushButton_log->setText(QApplication::translate("MainWindow", "log", nullptr));
        pushButton_pow->setText(QApplication::translate("MainWindow", "^", nullptr));
        pushButton_ln->setText(QApplication::translate("MainWindow", "ln", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        plot_graph->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "0x", nullptr));
        pushButton_0->setText(QApplication::translate("MainWindow", "0", nullptr));
        pushButton_mod->setText(QApplication::translate("MainWindow", "mod", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton_DEL->setText(QApplication::translate("MainWindow", "DEL", nullptr));
        pushButton_unar->setText(QApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton_result->setText(QApplication::translate("MainWindow", "=", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "4", nullptr));
        pushButton_sqrt->setText(QApplication::translate("MainWindow", "sqrt", nullptr));
        result_show->setText(QString());
        pushButton_AC->setText(QApplication::translate("MainWindow", "AC", nullptr));
        pushButton_left_par->setText(QApplication::translate("MainWindow", "(", nullptr));
        pushButton_right_par->setText(QApplication::translate("MainWindow", ")", nullptr));
        label_22->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\230\320\275\320\266\320\265\320\275\320\265\321\200\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\211\320\260\321\217 \321\201\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_10->setText(QApplication::translate("MainWindow", " \320\236\320\261\321\211\320\260\321\217 \320\262\321\213\320\277\320\273\320\260\321\202\320\260", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "C\321\200\320\276\320\272 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\342\202\275", nullptr));
        pushButton_calculate_credit->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\277\320\273\320\260\321\202\320\260 \320\277\320\276 \320\272\321\200\320\265\320\264\320\270\321\202\321\203", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "%", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\342\202\275", nullptr));
        label_8->setText(QApplication::translate("MainWindow", " \320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\265\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\320\276\320\263\320\276 \320\277\320\273\320\260\321\202\320\265\320\266\320\260:", nullptr));
        differentiated->setText(QApplication::translate("MainWindow", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        credit_error->setText(QString());
        annuities->setText(QApplication::translate("MainWindow", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\265", nullptr));
        credit_period_choice->setItemText(0, QApplication::translate("MainWindow", "\320\233\320\265\321\202", nullptr));
        credit_period_choice->setItemText(1, QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));

        label_11->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\342\202\275", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\342\202\275", nullptr));
        label_15->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(credit_calc), QApplication::translate("MainWindow", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        refill_sum->setInputMask(QString());
        withdrawal_frequency->setItemText(0, QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\276\320\262\320\276\320\265", nullptr));
        withdrawal_frequency->setItemText(1, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        withdrawal_frequency->setItemText(2, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 2 \320\274\320\265\321\201\321\217\321\206\320\260", nullptr));
        withdrawal_frequency->setItemText(3, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\272\320\262\320\260\321\200\321\202\320\260\320\273", nullptr));
        withdrawal_frequency->setItemText(4, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\277\320\276\320\273\320\263\320\276\320\264\320\260", nullptr));
        withdrawal_frequency->setItemText(5, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));

        label_24->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\320\277\320\273\320\260\321\202", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\320\241\321\203\320\274\320\274\320\260 \320\262\320\272\320\273\320\260\320\264\320\260", nullptr));
        period_placement_type->setItemText(0, QApplication::translate("MainWindow", "\320\224\320\275\320\265\320\271", nullptr));
        period_placement_type->setItemText(1, QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        period_placement_type->setItemText(2, QApplication::translate("MainWindow", "\320\233\320\265\321\202", nullptr));

        label_25->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\276\320\262", nullptr));
        label228->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        refill_frequency->setItemText(0, QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\276\320\262\320\276\320\265", nullptr));
        refill_frequency->setItemText(1, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        refill_frequency->setItemText(2, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 2 \320\274\320\265\321\201\321\217\321\206\320\260", nullptr));
        refill_frequency->setItemText(3, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\272\320\262\320\260\321\200\321\202\320\260\320\273", nullptr));
        refill_frequency->setItemText(4, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\277\320\276\320\273\320\263\320\276\320\264\320\260", nullptr));
        refill_frequency->setItemText(5, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));

        label_20->setText(QApplication::translate("MainWindow", "\320\241\321\200\320\276\320\272 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\265", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\320\276 \321\201\321\200\320\276\320\272\320\260", nullptr));
        label_29->setText(QString());
        capitalization_of_percents->setText(QString());
        frequency_of_payments->setItemText(0, QApplication::translate("MainWindow", "\320\232\320\260\320\266\320\264\321\213\320\271 \320\264\320\265\320\275\321\214", nullptr));
        frequency_of_payments->setItemText(1, QApplication::translate("MainWindow", "\320\232\320\260\320\266\320\264\321\203\321\216 \320\275\320\265\320\264\320\265\320\273\321\216", nullptr));
        frequency_of_payments->setItemText(2, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        frequency_of_payments->setItemText(3, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\272\320\262\320\260\321\200\321\202\320\260\320\273", nullptr));
        frequency_of_payments->setItemText(4, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\277\320\276\320\273\320\263\320\276\320\264\320\260", nullptr));
        frequency_of_payments->setItemText(5, QApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));
        frequency_of_payments->setItemText(6, QApplication::translate("MainWindow", "\320\222 \320\272\320\276\320\275\321\206\320\265 \321\201\321\200\320\276\320\272\320\260", nullptr));

        label_27->setText(QApplication::translate("MainWindow", "\320\241\320\275\321\217\321\202\320\270\320\265", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207\320\265\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260 \320\246\320\221", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "\320\224\320\276\321\205\320\276\320\264 \320\267\320\260 \320\262\321\213\321\207\320\265\321\202\320\276\320\274 \320\275\320\260\320\273\320\276\320\263\320\276\320\262", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\273\320\276\320\263", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "\320\241\321\203\320\274\320\274\320\260 \320\262\320\272\320\273\320\260\320\264\320\260 \321\201 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\260\320\274\320\270", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        pushButton_calculate_deposit->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_34->setText(QApplication::translate("MainWindow", "\342\202\275", nullptr));
        label_35->setText(QApplication::translate("MainWindow", "\342\202\275", nullptr));
        label_36->setText(QApplication::translate("MainWindow", "\342\202\275", nullptr));
        deposit_error->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\224\320\265\320\277\320\276\320\267\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
