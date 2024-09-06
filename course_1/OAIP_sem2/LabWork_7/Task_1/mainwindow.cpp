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
}


void MainWindow::displayQueue(QListWidget *QueueListWidget,const Queue &queue) {
    QueueListWidget->clear();
    for (int i = 0; i < queue.getSize(); ++i) {
        int num = queue.peekAt(i);
        QueueListWidget->addItem(QString::number(num));
    }
}

void MainWindow::on_randomButton_clicked()
{
    mainQueue.clearQueue();
    mainQueue.fillQueueRandomly(ui->spinBox->value());
    displayQueue(ui->newListWidget, mainQueue);
}

void MainWindow::on_newQueueButton_clicked()
{
    mainQueue.moveMinToFront();
    displayQueue(ui->newListWidget, mainQueue);
}

void MainWindow::on_frontButton_clicked()
{
    ui->label_2->setText(QString::number(mainQueue.front()));
}

void MainWindow::on_backButton_clicked()
{
    ui->label_2->setText(QString::number(mainQueue.back()));
}

void MainWindow::on_dequeueButton_clicked()
{
    mainQueue.dequeue();
    displayQueue(ui->newListWidget, mainQueue);
}

void MainWindow::on_enqueueButton_clicked()
{
    mainQueue.enqueue(ui->spinBox->value());
    displayQueue(ui->newListWidget, mainQueue);
}


