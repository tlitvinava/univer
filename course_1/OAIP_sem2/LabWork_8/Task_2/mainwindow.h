#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "heaparray.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_insertButton_clicked();

    void on_maxButton_clicked();

    void on_extractMaxButton_clicked();

    void on_deleteButton_clicked();

    void on_printButton_clicked();

    void on_clearButton_clicked();

    void on_sizeButton_clicked();

private:
    Ui::MainWindow *ui;
    HeapArray<int> heap;
    QGraphicsScene* scene;
};
#endif // MAINWINDOW_H
