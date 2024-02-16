#include "mainwindow.h"
#include "ui_mainwindow.h"

#define AMOUNT_POINTS 100001

void MainWindow::on_plot_graph_clicked() {
  check_definifion_value();
  ui->customPlot->clearGraphs();
  ui->customPlot->replot();

  char *input_string = get_input_string();
  int output = input_string_validation(input_string);

  if (output == OK) {
    int amount_traits = 0;
    trait *r_p_n_array = reverse_polish_notation(input_string, &amount_traits);
    if (r_p_n_array != nullptr) {
      double x_min = ui->scope_definifion_min->value();
      double x_max = ui->scope_definifion_max->value();
      double step = (x_max - x_min) / (AMOUNT_POINTS - 1);

      QVector<double> x(AMOUNT_POINTS), y(AMOUNT_POINTS);
      double result = 0.0;
      int i = 0;
      for (double x_value = x_min; x_value <= x_max && output == OK;
           x_value += step, ++i) {
        trait *tmp = copy_array(r_p_n_array, amount_traits);
        output = calculation(tmp, amount_traits, &result, x_value);
        if (output == OK) {
          x[i] = x_value;
          y[i] = result;
        }
        free(tmp);
        tmp = nullptr;
      }
      if (output == OK) {
        plot_graph(x, y);
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

void MainWindow::check_definifion_value() {
  if (ui->scope_definifion_min->value() >= ui->scope_definifion_max->value()) {
    set_default_definifion();
  }
  set_definifion_value();
}

void MainWindow::set_default_definifion() {
  ui->scope_definifion_min->setValue(-10);
  ui->scope_definifion_max->setValue(10);
}

void MainWindow::set_definifion_value() {
  ui->customPlot->xAxis->setRange(ui->scope_definifion_min->value(),
                                  ui->scope_definifion_max->value());
  ui->customPlot->yAxis->setRange(ui->scope_definifion_min->value(),
                                  ui->scope_definifion_max->value());
}

trait *MainWindow::copy_array(trait *input_array, int amount_traits) {
  trait *output_array = (trait *)calloc(amount_traits, sizeof(trait));
  for (int i = 0; i < amount_traits; ++i) {
    output_array[i] = input_array[i];
  }
  return output_array;
}

void MainWindow::plot_graph(const QVector<double> x, const QVector<double> y) {
  ui->customPlot->addGraph();
  set_definifion_value();
  ui->customPlot->graph(0)->setData(x, y);
  graph_settings(ui->customPlot);
  ui->customPlot->replot();
}

void MainWindow::graph_settings(QCustomPlot *customPlot) {
  customPlot->addGraph();
  customPlot->graph(0)->setPen(
      QPen(Qt::blue));  // line color blue for first graph
  customPlot->graph(0)->setBrush(QBrush(
      QColor(0, 0, 255, 20)));  // graph will be filled with translucent blue

  // configure right and top axis to show ticks but no labels:
  // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
  customPlot->xAxis2->setVisible(true);
  customPlot->xAxis2->setTickLabels(false);
  customPlot->yAxis2->setVisible(true);
  customPlot->yAxis2->setTickLabels(false);

  // make left and bottom axes always transfer their ranges to right and top
  // axes:
  connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2,
          SLOT(setRange(QCPRange)));
  connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2,
          SLOT(setRange(QCPRange)));

  // let the ranges scale themselves so graph 0 fits perfectly in the visible
  // area:
  customPlot->graph(0)->rescaleAxes();

  // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select
  // graphs by clicking:
  customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom |
                              QCP::iSelectPlottables);
}
