#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_pushButton_calculate_credit_clicked() {
  clear_prev_calc();
  double credit_sum = ui->credit_sum->text().toDouble();
  int loan_period = ui->loan_period->text().toInt();
  double percentage_rate = ui->percentage_rate->text().toDouble();
  if (credit_sum != 0 && loan_period != 0 && percentage_rate != 0) {
    int period_type = ui->credit_period_choice->currentIndex();
    if (!period_type) {
      loan_period *= 12;
    }
    percentage_rate /= 100;
    bool type_payment = ui->differentiated->isChecked();
    if (type_payment) {
      differentiated_calc(credit_sum, loan_period, percentage_rate);
    } else {
      annuities_calc(credit_sum, loan_period, percentage_rate);
    }
  } else {
    ui->credit_error->setText(INVALID_DATA_LINE);
  }
}

void MainWindow::clear_prev_calc() {
  ui->credit_error->clear();
  ui->monthly_payment->clear();
  ui->total_payout->clear();
  ui->overpayment_loan->clear();
}

void MainWindow::credit_calc_validator() {
  QRegularExpression re("[0-9]*");
  QValidator *validator1 = new QRegularExpressionValidator(re, this);
  ui->credit_sum->setValidator(validator1);
  ui->loan_period->setValidator(validator1);
  re.setPattern("[0-9]*[.]?[0-9]*");
  QValidator *validator2 = new QRegularExpressionValidator(re, this);
  ui->percentage_rate->setValidator(validator2);
}

void MainWindow::annuities_calc(double credit_sum, const int loan_period,
                                double percentage_rate) {
  percentage_rate /= 12;
  double payment = credit_sum * percentage_rate /
                   (1 - pow(1 + percentage_rate, -loan_period));
  double payment_total = payment * loan_period;
  double overpayment = payment_total - credit_sum;
  set_annuities_result(payment, overpayment, payment_total);
}

void MainWindow::set_annuities_result(const double payment,
                                      const double overpayment,
                                      const double payment_total) {
  char result_str[SIZE_BUFFER] = {'\0'};
  setlocale(LC_NUMERIC, "C");
  sprintf(result_str, "%.2f", payment);
  ui->monthly_payment->setText(result_str);
  memset(result_str, '\0', SIZE_BUFFER);
  sprintf(result_str, "%.2f", overpayment);
  ui->overpayment_loan->setText(result_str);
  memset(result_str, '\0', SIZE_BUFFER);
  sprintf(result_str, "%.2f", payment_total);
  ui->total_payout->setText(result_str);
}

void MainWindow::differentiated_calc(double credit_sum, const int loan_period,
                                     const double percentage_rate) {
  QDate date_start_term = QDate::currentDate();
  double start_payment = 0.0;
  double end_payment = 0.0;
  double principal_payment = credit_sum / loan_period;
  double procent_payment = 0.0;
  double payment = 0.0;
  double total_payment = 0.0;
  double overpayment = -credit_sum;
  for (int i = 0; i < loan_period; ++i, credit_sum -= principal_payment,
           date_start_term = date_start_term.addMonths(1)) {
    procent_payment = credit_sum * percentage_rate *
                      date_start_term.daysInMonth() /
                      date_start_term.daysInYear();
    payment = principal_payment + procent_payment;
    if (i == 0) {
      start_payment = payment;
    } else if (i != 0 && i == loan_period - 1) {
      end_payment = payment;
    }
    total_payment += payment;
  }
  overpayment += total_payment;
  if (loan_period == 1) {
    set_annuities_result(start_payment, overpayment, total_payment);
  } else {
    set_differentiated_result(start_payment, end_payment, overpayment,
                              total_payment);
  }
}

void MainWindow::set_differentiated_result(const double start_payment,
                                           const double end_payment,
                                           const double overpayment,
                                           const double payment_total) {
  char result_str[SIZE_BUFFER] = {'\0'};
  setlocale(LC_NUMERIC, "C");
  sprintf(result_str, "%.2f", start_payment);
  strcat(result_str, "...");
  char str[SIZE_BUFFER] = {'\0'};
  sprintf(str, "%.2f", end_payment);
  strcat(result_str, str);
  ui->monthly_payment->setText(result_str);
  memset(result_str, '\0', SIZE_BUFFER);
  sprintf(result_str, "%.2f", overpayment);
  ui->overpayment_loan->setText(result_str);
  memset(result_str, '\0', SIZE_BUFFER);
  sprintf(result_str, "%.2f", payment_total);
  ui->total_payout->setText(result_str);
}
