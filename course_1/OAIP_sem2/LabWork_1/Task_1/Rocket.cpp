#include <QPainter>
#include "Rocket.h"//подключаем хедр

Rocket::Rocket() {//это основной класс, в котором мы задаем рисование ракеты и пламени, но не забываем, что методы движения ракета уже унаследовала от линии и писать их здесь не нужно
    engineStarted=false;
}

void Rocket::paintEvent(QPaintEvent *event)//обьявляем пэинтер и вызываем его
{
    QPainter painter(this);
    drawR(&painter);
    drawRocket(&painter);
}

void Rocket::drawRocket(QPainter *painter)//отрисовка ракеты
{
    drawR(painter);
    QPen pen;//свойства линии
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(5);
    painter->setPen(pen);

    QBrush brush;//свойства заливки
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);

    QPolygon pol;//функции рисования
    pol<<QPoint(100,700-y)<<QPoint(100,500-y)<<QPoint(150,450-y)<<QPoint(200,500-y)<<QPoint(200,700-y)<<QPoint(220,720-y)<<QPoint(80,720-y)<<QPoint(100,700-y);
    painter->drawPolygon(pol);

    QPolygon pol1;
    pol1<<QPoint(100,700-y)<<QPoint(200,700-y);
    painter->drawPolygon(pol1);

    QPolygon pol2;
    pol2<<QPoint(100,500-y)<<QPoint(200,500-y);
    painter->drawPolygon(pol2);

    QBrush brush1;
    brush1.setColor(Qt::blue);
    brush1.setStyle(Qt::SolidPattern);
    painter->setBrush(brush1);

    painter->drawEllipse(125, 525-y, 50,50);
}

void Rocket::drawFlame(QPainter *painter)//то же самое с пламенем
{
    qDebug()<<engineStarted;
    if(engineStarted){
    drawR(painter);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(5);
    painter->setPen(pen);

    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);

    QPolygon flame;
    flame<<QPoint(100,720-y)<<QPoint(120,750-y)<<QPoint(140,730-y)<<QPoint(160,760-y)<<QPoint(180,725-y)<<QPoint(190,745-y)<<QPoint(200,720-y);
    painter->drawPolygon(flame);
    }
}





