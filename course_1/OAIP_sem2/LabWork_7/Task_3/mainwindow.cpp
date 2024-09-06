#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete hashTable;
    delete positiveTable;
}

void MainWindow::printHashTable(MyHashTable *ht, QTableWidget *qTableW)
{
    auto vec = ht->show();
    qTableW->clear();

    int maxColumnCount = 0;

    for (const auto& row : vec) {
        if (row.size() > maxColumnCount) {
            maxColumnCount = row.size();
        }
    }

    qTableW->setColumnCount(maxColumnCount);

    for (int j = 0; j < vec.size(); ++j) {
        QVector<int> currentVec = vec[j];
        qTableW->setRowCount(j + 1);
        for (int i = 0; i < currentVec.size(); ++i) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(currentVec[i]));
            qTableW->setItem(j, i, item);
        }
    }
}

void MainWindow::on_pushButton1_clicked()
{

    hashTable = new MyHashTable(ui->spinBox_size->value());
    positiveTable = new MyHashTable(ui->spinBox_size->value());
    negativeTable = new MyHashTable(ui->spinBox_size->value());
    hashTable->reset();
    positiveTable->reset();
    negativeTable->reset();
    hashTable->createRandomTable(ui->spinBox_size->value());
    printHashTable(hashTable, ui->tableWidget);
}

void MainWindow::splitToPositiveNegative() {
    for (int i = 0; i < hashTable->tableSize; ++i) {
        while (!hashTable->hashTable[i].isEmpty()) {
            int value = hashTable->hashTable[i].peek();
            hashTable->hashTable[i].pop();
            if (value >= 0) {
                positiveTable->hashTable[i].push(value);
            } else {
                negativeTable->hashTable[i].push(value);
            }
        }
    }
}

void MainWindow::on_pushButton_p_and_n_clicked()
{
    splitToPositiveNegative();
    printHashTable(positiveTable, ui->tableWidget_2);
    printHashTable(negativeTable, ui->tableWidget_3);
}
