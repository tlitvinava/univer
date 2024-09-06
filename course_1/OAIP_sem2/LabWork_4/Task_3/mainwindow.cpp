#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qspinbox.h>
#include <qtablewidget.h>

void swapValues(int *val1, int *val2) {
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->inputCount, &QSpinBox::valueChanged, this,
            &MainWindow::refreshInputTable);
    refreshInputTable();
}

void MainWindow::refreshInputTable() {
    int inputCount = ui->inputCount->value();
    int oldCount = ui->inputTable->rowCount();
    ui->inputTable->setRowCount(inputCount);

    for (int i = oldCount; i < inputCount; i++) {
        QSpinBox *spinBox = new QSpinBox();
        spinBox->setMinimum(1);
        spinBox->setMaximum(100000000);
        spinBox->setValue(rand() % 900 + 10);
        connect(spinBox, &QSpinBox::valueChanged, this, &MainWindow::refreshOutput);
        ui->inputTable->setCellWidget(i, 0, spinBox);
    }

    refreshOutput();
}

QList<int> MainWindow::getInputValues() {
    QList<int> result;
    result.resize(ui->inputTable->rowCount());
    for (int i = 0; i < result.count(); i++) {
        QSpinBox *spinBox = (QSpinBox *)ui->inputTable->cellWidget(i, 0);
        result[i] = spinBox->value();
    }
    return result;
}

QList<int> MainWindow::compute(QList<int> input) {
    QList<int> result;

    for (int i = 0; i < input.count(); i += 3) {
        if (i + 2 >= input.count()) {
            int average = input[i];
            if (i + 1 < input.count()) {
                average += input[i + 1];
                average /= 2;
            }
            result.push_back(average);
            continue;
        }

        int val1 = input[i];
        int val2 = input[i + 1];
        int val3 = input[i + 2];

        if (val1 > val3)
            swapValues(&val1, &val3);

        if (val1 > val2)
            swapValues(&val1, &val2);

        if (val2 > val3)
            swapValues(&val2, &val3);

        result.push_back(val2);
    }
    return result;
};

void MainWindow::refreshOutput() {
    QList<int> inputs = getInputValues();
    QList<int> result = compute(inputs);

    ui->outputTable->setRowCount(result.count());
    for (int i = 0; i < result.count(); i++) {
        ui->outputTable->setItem(i, 0, new QTableWidgetItem(QString::number(result[i])));
    }
}
