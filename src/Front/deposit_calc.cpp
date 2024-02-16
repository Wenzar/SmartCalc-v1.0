#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_pushButton_calculate_deposit_clicked() {
  clear_prev_deposit();
  double deposit_sum = ui->deposit_sum->text().toDouble();
  double period_placement = ui->period_placement->text().toDouble();
  double percentage_rate_dep = ui->percentage_rate_dep->text().toDouble();
  double central_bank_rate = ui->central_bank_rate->text().toDouble();
  if (deposit_sum != 0 && period_placement != 0 && percentage_rate_dep != 0 &&
      central_bank_rate != 0) {
    deposit_calculation();
  } else {
    ui->deposit_error->setText(INVALID_DATA_LINE);
  }
}

void MainWindow::deposit_calc_validator() {
  QRegularExpression regx("[0-9]*");
  QValidator *validator1 = new QRegularExpressionValidator(regx, this);
  ui->deposit_sum->setValidator(validator1);
  ui->period_placement->setValidator(validator1);
  ui->refill_sum->setValidator(validator1);
  ui->withdrawal_sum->setValidator(validator1);
  regx.setPattern("[0-9]*[.]?[0-9]*");
  QValidator *validator2 = new QRegularExpressionValidator(regx, this);
  ui->percentage_rate_dep->setValidator(validator2);
  ui->central_bank_rate->setValidator(validator2);
}

void MainWindow::deposit_calculation() {
  double deposit_sum = ui->deposit_sum->text().toDouble();
  QDate date_start_deposit = ui->beginning_term->date();
  QDate date_end_deposit = get_end_deposit_date();
  bool capitalization = ui->capitalization_of_percents->isChecked();
  QDate refill_date = ui->refill_date->date();
  double refill_sum = ui->refill_sum->text().toDouble();
  int refill_frequency = ui->refill_frequency->currentIndex();
  check_date_refill_or_withdraw(date_start_deposit, refill_sum,
                                refill_frequency, &refill_date);
  QDate withdrawal_date = ui->withdrawal_date->date();
  double withdrawal_sum = ui->withdrawal_sum->text().toDouble();
  int withdrawal_frequency = ui->withdrawal_frequency->currentIndex();
  check_date_refill_or_withdraw(date_start_deposit, withdrawal_sum,
                                withdrawal_frequency, &withdrawal_date);
  double sum_procent_of_period = 0.0;
  double sum_procent_of_year = 0.0;
  double total_sum_procent = 0.0;
  double sum_tax = 0.0;
  QDate date_payment = get_next_date_payment(date_start_deposit);
  date_start_deposit = date_start_deposit.addDays(1);
  QDate new_year = QDate(date_start_deposit.year(), 12, 31);
  for (; date_start_deposit <= date_end_deposit && deposit_sum != 0;
       date_start_deposit = date_start_deposit.addDays(1)) {
    if (refill_sum != 0 && date_start_deposit == refill_date) {
      add_refill(&deposit_sum, &refill_date);
    }
    if (withdrawal_sum != 0 && date_start_deposit == withdrawal_date) {
      sub_withdrawal(&deposit_sum, &withdrawal_date);
    }
    if (capitalization && date_start_deposit == date_payment &&
        date_start_deposit != date_end_deposit) {
      deposit_sum += sum_procent_of_period;
      add_sum_year_procent(&sum_procent_of_year, &sum_procent_of_period);
    }
    procent_calculation(deposit_sum, date_start_deposit, &sum_procent_of_period,
                        &total_sum_procent);
    if (date_start_deposit == date_payment ||
        date_start_deposit == date_end_deposit) {
      if (capitalization) {
        deposit_sum += sum_procent_of_period;
      }
      add_sum_year_procent(&sum_procent_of_year, &sum_procent_of_period);
      date_payment = get_next_date_payment(date_start_deposit);
    }
    if (date_start_deposit == new_year ||
        date_start_deposit == date_end_deposit) {
      tax_calculation(&sum_tax, &sum_procent_of_year);
      new_year = new_year.addYears(1);
    }
  }
  set_deposit_result(total_sum_procent, sum_tax, deposit_sum);
}

void MainWindow::clear_prev_deposit() {
  ui->accrued_interest->clear();
  ui->deposit_amount_with_interest->clear();
  ui->tax->clear();
  ui->income_after_taxes->clear();
  ui->deposit_error->clear();
}

QDate MainWindow::get_end_deposit_date() {
  QDate end_date = ui->beginning_term->date();
  double period_placement = ui->period_placement->text().toDouble();
  int period_placement_type = ui->period_placement_type->currentIndex();
  if (period_placement_type == 0) {
    end_date = end_date.addDays(period_placement);
  } else if (period_placement_type == 1) {
    end_date = end_date.addMonths(period_placement);
  } else {
    end_date = end_date.addYears(period_placement);
  }
  return end_date;
}

void MainWindow::check_date_refill_or_withdraw(const QDate date_start_deposit,
                                               const double sum,
                                               const int period,
                                               QDate *date_refill_or_withdraw) {
  if (sum != 0 && *date_refill_or_withdraw == date_start_deposit) {
    get_next_date_refill_or_withdraw(date_refill_or_withdraw, period);
  }
}

void MainWindow::get_next_date_refill_or_withdraw(QDate *date, const int type) {
  switch (type) {
    case 1:
      *date = date->addMonths(1);
      break;
    case 2:
      *date = date->addMonths(2);
      break;
    case 3:
      *date = date->addMonths(3);
      break;
    case 4:
      *date = date->addMonths(6);
      break;
    case 5:
      *date = date->addYears(1);
      break;
  }
}

QDate MainWindow::get_next_date_payment(QDate date_payment) {
  int frequency_payment = ui->frequency_of_payments->currentIndex();
  switch (frequency_payment) {
    case 0:
      date_payment = date_payment.addDays(1);
      break;
    case 1:
      date_payment = date_payment.addDays(7);
      break;
    case 2:
      date_payment = date_payment.addMonths(1);
      break;
    case 3:
      date_payment = date_payment.addMonths(3);
      break;
    case 4:
      date_payment = date_payment.addMonths(6);
      break;
    case 5:
      date_payment = date_payment.addYears(1);
      break;
    case 6:
      QDate end_date = get_end_deposit_date();
      int days = ui->beginning_term->date().daysTo(end_date);
      date_payment = ui->beginning_term->date().addDays(days);
      break;
  }
  return date_payment;
}

void MainWindow::add_refill(double *deposit_sum, QDate *refill_date) {
  *deposit_sum += ui->refill_sum->text().toDouble();
  int refill_frequency = ui->refill_frequency->currentIndex();
  get_next_date_refill_or_withdraw(refill_date, refill_frequency);
}

void MainWindow::sub_withdrawal(double *deposit_sum, QDate *withdrawal_date) {
  double withdrawal_sum = ui->withdrawal_sum->text().toDouble();
  *deposit_sum = (*deposit_sum - withdrawal_sum >= EPS)
                     ? *deposit_sum - withdrawal_sum
                     : *deposit_sum;
  int withdrawal_frequency = ui->withdrawal_frequency->currentIndex();
  get_next_date_refill_or_withdraw(withdrawal_date, withdrawal_frequency);
}

void MainWindow::add_sum_year_procent(double *sum_year_procent,
                                      double *sum_procent_of_period) {
  *sum_year_procent += *sum_procent_of_period;
  *sum_procent_of_period = 0.0;
}

void MainWindow::procent_calculation(const double deposit_sum, const QDate date,
                                     double *sum_procent_of_period,
                                     double *total_sum_procent) {
  double percentage_rate_dep = ui->percentage_rate_dep->text().toDouble() / 100;
  double daily_procent = deposit_sum * percentage_rate_dep / date.daysInYear();
  *sum_procent_of_period += daily_procent;
  *total_sum_procent += daily_procent;
}

void MainWindow::tax_calculation(double *sum_tax, double *sum_procent_of_year) {
  double central_bank_rate = ui->central_bank_rate->text().toDouble() / 100;
  double sum_tax_free = TAX_CALCULATION_SUM * central_bank_rate;
  if (*sum_procent_of_year > sum_tax_free) {
    *sum_tax += (*sum_procent_of_year - sum_tax_free) * TAX / 100;
  }
  *sum_procent_of_year = 0.0;
}

void MainWindow::set_deposit_result(const double total_sum_procent,
                                    const double sum_tax,
                                    const double deposit_sum) {
  char result_str[SIZE_BUFFER] = {'\0'};
  setlocale(LC_NUMERIC, "C");
  sprintf(result_str, "%.2f", total_sum_procent);
  ui->accrued_interest->setText(result_str);
  memset(result_str, '\0', SIZE_BUFFER);
  sprintf(result_str, "%.2f", sum_tax);
  ui->tax->setText(result_str);
  memset(result_str, '\0', SIZE_BUFFER);
  sprintf(result_str, "%.2f", deposit_sum);
  ui->deposit_amount_with_interest->setText(result_str);
  memset(result_str, '\0', SIZE_BUFFER);
  sprintf(result_str, "%.2f", total_sum_procent - sum_tax);
  ui->income_after_taxes->setText(result_str);
}

void MainWindow::set_today_date() {
  QDate date_today = QDate::currentDate();
  ui->beginning_term->setDate(date_today);
  ui->refill_date->setDate(date_today);
  ui->withdrawal_date->setDate(date_today);
}
