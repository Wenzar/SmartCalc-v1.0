#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h" // the header file of QCustomPlot

extern "C" {
#include "../Back/general.h"
#include "../Back/validation.h"
#include "../Back/reverse_polish_notation.h"
#include  "../Back/calculation.h" 
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setupSimpleDemo(QCustomPlot *customPlot);

private:
    Ui::MainWindow *ui;

private slots:
    void digits_numbers();
    void on_pushButton_dot_clicked();
    void operations();
    void on_pushButton_AC_clicked();
    void function_button();
    void on_Trigonometry_activated(int index);
    void on_pushButton_result_clicked();
    char *get_input_string();
    void set_result(const double result);
    void on_pushButton_DEL_clicked();
    double get_x_value();
};
#endif // MAINWINDOW_H
