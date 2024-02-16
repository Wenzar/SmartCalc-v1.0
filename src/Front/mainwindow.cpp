#include "mainwindow.h"

#include "ui_mainwindow.h"

// double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_left_par, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_right_par, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_unar, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(function_button()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(function_button()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(function_button()));

  start_settings();
  ui->label_22->setStyleSheet("border-image: url(../images/draw_text.png);");
}

void MainWindow::start_settings() {
  set_validators();
  ui->annuities->setChecked(true);
  set_today_date();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString numbers;

  numbers = (ui->result_show->text() + button->text());
  ui->result_show->setText(numbers);
}

void MainWindow::on_pushButton_dot_clicked() {
  // if (!(ui->result_show->text().contains('.')))
  ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::function_button() {
  QPushButton *button = (QPushButton *)sender();
  QString prev_text = ui->result_show->text();
  ui->result_show->setText(prev_text + button->text() + '(');
}

void MainWindow::operations() {
  QPushButton *button = (QPushButton *)sender();
  double all_numbers;

  if (button->text() == "+/-") {
    all_numbers = (ui->result_show->text()).toDouble();
    all_numbers = -all_numbers;
    ui->result_show->setText(QString::number(all_numbers, 'g', 15));
  }
}

void MainWindow::on_pushButton_AC_clicked() { ui->result_show->clear(); }

void MainWindow::on_Trigonometry_activated(int index) {
  if (index == 0) {
    QString prev_text = ui->result_show->text();
    ui->result_show->setText(prev_text + "cos(");
  }
  if (index == 1) {
    QString prev_text = ui->result_show->text();
    ui->result_show->setText(prev_text + "sin(");
  }
  if (index == 2) {
    QString prev_text = ui->result_show->text();
    ui->result_show->setText(prev_text + "tan(");
  }
  if (index == 3) {
    QString prev_text = ui->result_show->text();
    ui->result_show->setText(prev_text + "acos(");
  }
  if (index == 4) {
    QString prev_text = ui->result_show->text();
    ui->result_show->setText(prev_text + "asin(");
  }
  if (index == 5) {
    QString prev_text = ui->result_show->text();
    ui->result_show->setText(prev_text + "atan(");
  }
}

void MainWindow::on_pushButton_result_clicked() {
  char *input_string = get_input_string();
  ui->result_show->clear();
  int output = input_string_validation(input_string);
  if (output == OK) {
    int amount_traits = 0;
    trait *r_p_n_array = reverse_polish_notation(input_string, &amount_traits);
    if (r_p_n_array != nullptr) {
      double result = 0.0;
      double x_value = get_x_value();
      output = calculation(r_p_n_array, amount_traits, &result, x_value);
      if (output == OK) {
        set_result(result);
      }
      free(r_p_n_array);
      r_p_n_array = nullptr;
    } else {
      output = SYNTAX_ERROR;
    }
  }
  if (output != OK) {
    ui->result_show->setText(SYNTAX_ERROR_LINE);
  }
  free(input_string);
}

char *MainWindow::get_input_string() {
  QString text = ui->result_show->text();
  size_t size = text.size();
  char *input_string = nullptr;
  if (size > 0) {
    input_string = (char *)calloc(size + 1, sizeof(char));
    std::string convert = text.toStdString();
    for (size_t i = 0; i < size; i++) {
      input_string[i] = convert[i];
    }
    input_string[size] = '\0';
  }
  return input_string;
}

void MainWindow::set_result(const double result) {
  if (isinf(result) || isnan(result) == OK) {
    char result_str[255] = {'\0'};
    sprintf(result_str, "%.10g", result);
    ui->result_show->setText(result_str);
  } else {
    ui->result_show->setText(INVALID_DATA_LINE);
  }
}

void MainWindow::on_pushButton_DEL_clicked() {
  QString prev_text = ui->result_show->text();
  prev_text.remove(prev_text.size() - 1, 1);
  ui->result_show->setText(prev_text);
}

double MainWindow::get_x_value() {
  double x_value = ui->x_value->text().toDouble();
  return x_value;
}

void MainWindow::set_validators() {
  x_value_validator();
  credit_calc_validator();
  deposit_calc_validator();
}

void MainWindow::x_value_validator() {
  QRegularExpression regx("[-]?([0-9]*)[.]?[0-9]*");
  QValidator *validator = new QRegularExpressionValidator(regx, this);
  ui->x_value->setValidator(validator);
}
