#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <triangle.h>//добавляем хедры всех фигур которые должны отображаться в в окне
#include <circle.h>
#include <line.h>
#include <square.h>
#include <rectangle.h>
#include <romb.h>
#include <hexagon.h>
#include <star5.h>
#include <star6.h>
#include <star8.h>
#include <star.h>
#include"figuremodel.h"

#include <QGraphicsProxyWidget>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTransform>
#include <QLineEdit>
#include <QTimer>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    //QGraphicsView view(&scene);
        //view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

}

MainWindow::~MainWindow()
{
    delete ui;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::updateAreaDisplay(QString newArea) {//между этих двух комментариев должен быть подсчет площади, периметра и центра фигуры но он пока в разработке
    ui->label_2->setText("S: " + newArea);
}

void MainWindow::updatePerimetrDisplay(QString newP) {
    ui->label_3->setText("P: " + newP);
}

void MainWindow::updateCenterDisplay(QString newX, QString newY) {
    ui->label_4->setText("CenterX: " + newX);
    ui->label_5->setText("CenterY: " + newY);
}

void MainWindow::infoFigure(FigureModel* figure){
    QTimer *timer = new QTimer(this);

    static double oldS = figure->square;
    static double oldP = figure->perimetr;
    static int oldX = figure->centerX;
    static int oldY = figure->centerY;
    connect(timer, &QTimer::timeout, [this, figure]{
        figure->calculateSquare();
        figure->calculatePerimetr();
        if (figure->square != oldS) {
            MainWindow::updateAreaDisplay(QString::number(figure->square));
            oldS = figure->square;
        }
        if (figure->perimetr != oldP) {
            MainWindow::updatePerimetrDisplay(QString::number(figure->perimetr));
            oldP = figure->perimetr;
        }
        if (figure->centerX != oldX || figure->centerY != oldY) {
            MainWindow::updateCenterDisplay(QString::number(figure->centerX), QString::number(figure->centerY));
            oldX = figure->centerX;
            oldY = figure->centerY;
        }
    });
}

//////////////////////////////////////////////////////////////////////

void MainWindow::on_pushButton_clicked()//создаем кнопки для каждой из фигур и при их нажатии создаем обьект нужного класса и добавляем на сцену + в форме добавляем graphics view - поле где будем все рисовать
{
    Triangle *tr = new Triangle();
    scene->addItem(tr);
    lastFigureModel=tr;//это потом пригодится для увеличения/уменьшения фигуры и поворота

}


void MainWindow::on_pushButton_2_clicked()
{
    Circle *cr = new Circle();
    scene->addItem(cr);
    lastFigureModel=cr;
}


void MainWindow::on_pushButton_3_clicked()
{
    Square *sq = new Square();
    scene->addItem(sq);
    lastFigureModel=sq;

}


void MainWindow::on_pushButton_4_clicked()
{
    Rectangle *rec = new Rectangle();
    scene->addItem(rec);
    lastFigureModel=rec;

}


void MainWindow::on_pushButton_5_clicked()
{
    Line *ln = new Line();
    scene->addItem(ln);
    lastFigureModel=ln;

}


void MainWindow::on_pushButton_6_clicked()
{
    Romb *rh = new Romb();
    scene->addItem(rh);
    lastFigureModel=rh;

}


void MainWindow::on_pushButton_7_clicked()
{
    Hexagon *hg = new Hexagon();
    scene->addItem(hg);
    lastFigureModel=hg;

}


void MainWindow::on_pushButton_8_clicked()
{
    Star *st8 = new Star(8);
    scene->addItem(st8);
    lastFigureModel=st8;

}


void MainWindow::on_pushButton_9_clicked()
{
    Star *st5 = new Star(5);
    scene->addItem(st5);
    lastFigureModel=st5;

}


void MainWindow::on_pushButton_10_clicked()
{
    Star *st6 = new Star(6);
    scene->addItem(st6);
    lastFigureModel=st6;

}


void MainWindow::on_pushButton_11_clicked()//метод для вращения
{
    QTransform transform = lastFigureModel->transform(); // Получаем текущую трансформацию

    // Переносим центр координат в центр фигуры
    transform.translate(lastFigureModel->centerX, lastFigureModel->centerY);

    // Вращаем
    qreal angle = 45.0; // ваш угол вращения
    transform.rotate(angle);

    // Возвращаем центр координат обратно
    transform.translate(-lastFigureModel->centerX, -lastFigureModel->centerY);

    // Применяем трансформацию к фигуре
    lastFigureModel->setTransform(transform);

}


void MainWindow::on_pushButton_12_clicked()//метод очистки поля
{
        scene->clear();
}

void MainWindow::on_pushButton_13_clicked()//масштабирование в 2 раза
{
    //QTransform transform; // Объявляем transform здесь
    QTransform transform = lastFigureModel->transform(); // Получаем текущую трансформацию


    // Переносим центр координат в центр фигуры
    transform.translate(lastFigureModel->centerX, lastFigureModel->centerY);

    // Масштабируем
    qreal scaleFactor = 2.0; // ваш масштаб
    transform.scale(scaleFactor, scaleFactor);

    // Возвращаем центр координат обратно
    transform.translate(-lastFigureModel->centerX, -lastFigureModel->centerY);

    // Применяем трансформацию к фигуре
    lastFigureModel->setTransform(transform);
}


void MainWindow::on_pushButton_14_clicked()//масштабирование в 0.5 раз
{
    //QTransform transform; // Объявляем transform здесь
    QTransform transform = lastFigureModel->transform(); // Получаем текущую трансформацию


    // Переносим центр координат в центр фигуры
    transform.translate(lastFigureModel->centerX, lastFigureModel->centerY);

    // Масштабируем
    qreal scaleFactor = 0.5; // ваш масштаб
    transform.scale(scaleFactor, scaleFactor);

    // Возвращаем центр координат обратно
    transform.translate(-lastFigureModel->centerX, -lastFigureModel->centerY);

    // Применяем трансформацию к фигуре
    lastFigureModel->setTransform(transform);
}


void MainWindow::on_pushButton_15_clicked()//вращение но уже в другую сторону
{
    QTransform transform = lastFigureModel->transform(); // Получаем текущую трансформацию

    // Переносим центр координат в центр фигуры
    transform.translate(lastFigureModel->centerX, lastFigureModel->centerY);

    // Вращаем
    qreal angle = -45.0; // ваш угол вращения
    transform.rotate(angle);

    // Возвращаем центр координат обратно
    transform.translate(-lastFigureModel->centerX, -lastFigureModel->centerY);

    // Применяем трансформацию к фигуре
    lastFigureModel->setTransform(transform);
    //lineEdit->setText("Новое значение");

}


void MainWindow::on_lineEdit_editingFinished()
{

}

