#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_mul,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_left_par,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_right_par,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_pow,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_unar,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(function_button()));
    connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(function_button()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(function_button()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button =(QPushButton *)sender();
    QString numbers;

    numbers = (ui->result_show->text() + button->text());
    ui->result_show->setText(numbers);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::function_button() {
    QPushButton *button = (QPushButton *)sender();
    QString text_prev = ui->result_show->text();
    ui->result_show->setText(text_prev + button->text() + '(');
}

void MainWindow::operations()
{
    QPushButton *button =(QPushButton *)sender();
    double all_numbers;

    if(button->text()=="+/-"){
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers=-all_numbers;
        ui->result_show->setText(QString::number(all_numbers,'g',15));
    }

}

void MainWindow::math_operations()
{
    num_first = ui->result_show->text().toDouble();
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->result_show->setText("");
}

void MainWindow::on_Trigonometry_activated(int index)
{
    if(index == 0){
        QString text_prev = ui->result_show->text();
        ui->result_show->setText(text_prev + "cos(");
    }
    if(index == 1){
        QString text_prev = ui->result_show->text();
        ui->result_show->setText(text_prev + "sin(");
    }
    if(index == 2){
        QString text_prev = ui->result_show->text();
        ui->result_show->setText(text_prev + "tan(");
    }
    if(index == 3){
        QString text_prev = ui->result_show->text();
        ui->result_show->setText(text_prev + "acos(");
    }
    if(index == 4){
        QString text_prev = ui->result_show->text();
        ui->result_show->setText(text_prev + "asin(");
    }
    if(index == 5){
        QString text_prev = ui->result_show->text();
        ui->result_show->setText(text_prev + "atan(");
    }
}

