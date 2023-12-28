#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

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
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString numbers;

  numbers = (ui->result_show->text() + button->text());
  ui->result_show->setText(numbers);
}

void MainWindow::on_pushButton_dot_clicked() {
  if (!(ui->result_show->text().contains('.')))
    ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::function_button() {
  QPushButton *button = (QPushButton *)sender();
  QString text_prev = ui->result_show->text();
  ui->result_show->setText(text_prev + button->text() + '(');
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
    QString text_prev = ui->result_show->text();
    ui->result_show->setText(text_prev + "cos(");
  }
  if (index == 1) {
    QString text_prev = ui->result_show->text();
    ui->result_show->setText(text_prev + "sin(");
  }
  if (index == 2) {
    QString text_prev = ui->result_show->text();
    ui->result_show->setText(text_prev + "tan(");
  }
  if (index == 3) {
    QString text_prev = ui->result_show->text();
    ui->result_show->setText(text_prev + "acos(");
  }
  if (index == 4) {
    QString text_prev = ui->result_show->text();
    ui->result_show->setText(text_prev + "asin(");
  }
  if (index == 5) {
    QString text_prev = ui->result_show->text();
    ui->result_show->setText(text_prev + "atan(");
  }
}

void MainWindow::on_pushButton_result_clicked() {
  char *input_array = get_input_array();
  ui->result_show->clear();
  int output = input_array_validation(input_array);
  if (output == OK) {
    int amount_tokens = 0;
    token *reverse_polish_notation_array =
        reverse_polish_notation(input_array, &amount_tokens);
    if (reverse_polish_notation_array != nullptr) {
    //   double x_value = ui->x_value->text().toDouble();
      double result = 0.0;
      output = calculation(reverse_polish_notation_array, amount_tokens, &result);
      if (output == OK) {
        set_result(result);
      }
      free(reverse_polish_notation_array);
      reverse_polish_notation_array = nullptr;
    } else {
      output = SYNTAX_ERROR;
    }
  }
  if (output != OK) {
    ui->result_show->setText(SYNTAX_ERROR_LINE);
  }

free(input_array);
}

char *MainWindow::get_input_array() {
  QString text = ui->result_show->text();
  size_t size = text.size();
  char *input_array = nullptr;
  if (size > 0) {
    input_array = (char *)calloc(size + 1, sizeof(char));
    std::string convert = text.toStdString();
    for (size_t i = 0; i < size; i++) {
      input_array[i] = convert[i];
    }
    input_array[size] = '\0';
  }
  return input_array;
}

void MainWindow::set_result(const double result) {
  if (isinf(result) || isnan(result) == OK) {
    char result_str[255] = {'\0'};
    // setlocale(LC_NUMERIC, "C");
    sprintf(result_str, "%.10g", result);
    ui->result_show->setText(result_str);
  } else {
    ui->result_show->setText(INVALID_DATA_LINE);
  }
}
