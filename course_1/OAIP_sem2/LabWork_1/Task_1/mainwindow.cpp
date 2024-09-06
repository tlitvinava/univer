#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Rocket.h"
#include <QPainter>
#include <QPixmap>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    int width = 1500; // ширина в пикселях                      //здесь мы добавляем задний фон но это не обязательно
    int height = 840;
    ui->setupUi(this);
    QPixmap bkgnd("/home/taisa/Загрузки/640px-Безмятежность.png");

    bkgnd = bkgnd.scaled(width, height, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()//это деструктор, стоит по умолчанию
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)// отрисовка обьекта. указываем обьекту класса ракета который мы создали в хедре нарисовать себя своим методом
{
    QPainter painter(this);//указать чтобы пэинтер тебе рисовал именно тот обьект, который ты добавила в окно
    R->drawRocket(&painter);//отрисовка ракеты
    R->drawFlame(&painter);//отрисовка пламени

}

void MainWindow::on_pushButton_clicked()//здесь мы прописываем то, что происходит при нажатии кнопки
{
    R->engineStarted=true;
    //R->setVisible(true);
    //QPainter painter(this);

    //R->drawFlame(&painter);

 qDebug()<<"In mw1"<<R->engineStarted;//это тебе не надо
    R->move();//эти две строки для начального движения ракеты
    repaint();//без репэинта у тебя не будет изменятся фигура

    for(int i=0;i<450;i++){//цикл в котором ракета по шагу равному 2 плавно поднимается вверх
        R->move();
        repaint();
    }
    //R->setVisible(false);
    R->engineStarted=false;
    qDebug()<<"In mw2"<<R->engineStarted;//тоже не надо
    repaint();//это так, на крайняк, думаю можно не писать

}

void MainWindow::on_pushButton_2_clicked()//то же самое что в предыдущей кнопке, тольк ракета опускается вниз
{
    R->engineStarted=true;

    if(R->y < 720){//это нижняя граница чтобы ракета не улетала в землю
        return;
    }



    for(int i=450;i>0;i--){
        R->moveDown();
        repaint();
    }

    R->engineStarted=false;
    repaint();




}

