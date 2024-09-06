#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "queue.h"

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
    void displayQueue(QListWidget *listWidget,const Queue &queue);

private slots:

    void on_randomButton_clicked();

    void on_newQueueButton_clicked();

    void on_frontButton_clicked();

    void on_backButton_clicked();

    void on_dequeueButton_clicked();

    void on_enqueueButton_clicked();

private:
    Ui::MainWindow *ui;
    Queue mainQueue;
};
#endif // MAINWINDOW_H
