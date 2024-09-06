#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->treeView->setModel(model);
    ui->treeView->header()->hide();
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tree = new BinarySearchTree();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tree;
}

void MainWindow::showT(QStandardItem* parent, Node* treeNode)
{
    if (treeNode == nullptr)
    {
        return;
    }

    QStandardItem* child = new QStandardItem(QString::number(treeNode->key) + ": " + treeNode->value);
    parent->appendRow(child);

    showT(child, treeNode->left);
    showT(child, treeNode->right);
}

void MainWindow::on_addButton_clicked()
{
    tree->addNode(QInputDialog::getInt(nullptr, tr("Ввод пользователя"), "Введите ключ:"), QInputDialog::getText(nullptr, tr("Ввод пользователя"), "Введите значение:"));
    model->clear();
    showT(model->invisibleRootItem(), tree->getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_deleteButton_clicked()
{
    tree->deleteNode(QInputDialog::getInt(nullptr, tr("Ввод пользователя"), "Введите ключ:"));
    model->clear();
    showT(model->invisibleRootItem(), tree->getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_findButton_clicked()
{
    QMessageBox::information(nullptr, tr("Поиск"), tree->findNode(QInputDialog::getInt(nullptr, tr("Ввод пользователя"), "Введите ключ:")));
}

void MainWindow::on_orderButton_clicked()
{
    auto vec = tree->inOrder();
    QString str;
    for (auto& e : vec)
    {
        str += QString::number(e.first) + " - " + e.second + "\n";
    }
    ui->textBrowser->setText(str);
}

void MainWindow::on_reverseButton_clicked()
{
    auto vec = tree->postOrder();
    QString str;
    for (auto& e : vec)
    {
        str += QString::number(e.first) + " - " + e.second + "\n";
    }
    ui->textBrowser->setText(str);
}

void MainWindow::on_byValueButton_clicked()
{
    auto vec = tree->valueOrder();
    QString str;
    for (auto& e : vec)
    {
        str += QString::number(e.first) + " - " + e.second + "\n";
    }
    ui->textBrowser->setText(str);
}

void MainWindow::on_balanceButton_clicked()
{
    tree->balanceTree();
    model->clear();
    showT(model->invisibleRootItem(), tree->getRoot());
    ui->treeView->expandAll();
}
