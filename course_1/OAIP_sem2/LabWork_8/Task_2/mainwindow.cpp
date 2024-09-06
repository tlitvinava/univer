#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(Qt::white);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insertButton_clicked()
{
    scene->clear();
    heap.insert(ui->inBox_2->value());
    heap.drawTree(scene,0,0,0,0);
}

void MainWindow::on_maxButton_clicked()
{
    ui->output->setText("Максимальный элемент: " + QString::number(heap.getMax()));
}

void MainWindow::on_extractMaxButton_clicked()
{
    scene->clear();
    ui->output->setText("Максимальный элемент был извлечен: " + QString::number(heap.getMax()));
    heap.extractMax();
    heap.drawTree(scene,0,0,0,0);
}

void MainWindow::on_deleteButton_clicked()
{
    scene->clear();
    try
    {
        heap.remove(ui->inBox_2->value());
    }
    catch (...)
    {
        QMessageBox::warning(nullptr, "Неверный ввод", "Элемента с таким индексом не существует!");
    }

    heap.drawTree(scene,0,0,0,0);
}

void MainWindow::on_printButton_clicked()
{
    scene->clear();
    ui->label->setText(QString::fromStdString(heap.toString()));
    heap.drawTree(scene,0,0,0,0);
}

void MainWindow::on_clearButton_clicked()
{
    heap.clear();
    scene->clear();
    scene->update();
    ui->output->setText("");
    ui->label->setText("");
}

void MainWindow::on_sizeButton_clicked()
{
    ui->output->setText("Размер: " + QString::number(heap.getSize()));
}
