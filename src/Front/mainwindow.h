#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qcustomplot.h"  // the header file of QCustomPlot

#define SIZE_BUFFER 255
#define EPS 1e-07
#define TAX 13
#define TAX_CALCULATION_SUM 1e+06

extern "C" {
#include "../Back/calculation.h"
#include "../Back/general.h"
#include "../Back/reverse_polish_notation.h"
#include "../Back/validation.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = 0);
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
  char *get_input_string();
  void set_result(const double result);
  void on_pushButton_DEL_clicked();
  double get_x_value();

  void on_plot_graph_clicked();
  void check_definifion_value();
  void set_default_definifion();
  void set_definifion_value();
  trait *copy_array(trait *input_array, int amount_traits);
  void plot_graph(const QVector<double> x, const QVector<double> y);
  void graph_settings(QCustomPlot *customPlot);
  void on_pushButton_calculate_credit_clicked();
  void clear_prev_calc();
  void differentiated_calc(double credit_sum, const int loan_period,
                           const double percentage_rate);
  void set_differentiated_result(const double start_payment,
                                 const double end_payment,
                                 const double overpayment,
                                 const double payment_total);
  void annuities_calc(double credit_sum, const int loan_period,
                      double percentage_rate);
  void set_annuities_result(const double payment, const double overpayment,
                            const double payment_total);
  void x_value_validator();
  void credit_calc_validator();
  void start_settings();
  void set_validators();
  void clear_prev_deposit();
  void deposit_calculation();
  QDate get_end_deposit_date();
  void check_date_refill_or_withdraw(const QDate date_start_deposit,
                                     const double sum, const int period,
                                     QDate *date_refill_or_withdraw);
  void get_next_date_refill_or_withdraw(QDate *date, const int type);
  QDate get_next_date_payment(QDate date_payment);
  void on_pushButton_calculate_deposit_clicked();
  void add_refill(double *deposit_sum,
                                     QDate *refill_date);
  void sub_withdrawal(double *deposit_sum, QDate *withdrawal_date);
  void add_sum_year_procent(double *sum_procent_of_year,
                                           double *sum_procent_of_period);
  void procent_calculation(const double deposit_sum, const QDate date,
                                       double *sum_procent_of_period,
                                       double *total_sum_procent);
  void tax_calculation(double *sum_tax, double *sum_procent_of_year);
  void set_deposit_result(const double total_sum_procent,
                                      const double sum_tax,
                                      const double deposit_sum);
    void set_today_date();
    void deposit_calc_validator();
};
#endif  // MAINWINDOW_H
