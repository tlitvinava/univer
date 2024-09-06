#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>//основное окно, на котором будут происходить действия. создается автоматически когда выбираешь приложение qwidget
#include <QPainter>
#include "Rocket.h"//из такого необходимо добавить только то, что будет отображаться на окне, в моем случае ракета, не отрезок

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Rocket *R = new Rocket;//создаем обьекты, которые будут отображаться в окне нужного типа rocket //это сама рокета
    Rocket *F = new Rocket;//это пламя
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots://здесь создаются слоты для кнопок, думаю по видосикам ты разберешься как создавать кнопки, эти слоты добавляются автоматически
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();                 //больше в файле менять ничего не надо, большинство уже есть сначала

private:

protected:
void paintEvent (QPaintEvent*) override;

};

#endif // MAINWINDOW_H



