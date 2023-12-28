#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    char *get_input_array();
    void set_result(const double result);
};
#endif // MAINWINDOW_H
