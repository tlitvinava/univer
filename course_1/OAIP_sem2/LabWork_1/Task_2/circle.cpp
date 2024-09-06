#include "circle.h"

Circle::Circle(FigureModel *parent) : FigureModel(parent){//задаем координаты центра фигуры и места в котором пользователь отпустит мышку, инициализируем пока что нулями
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
    int rad = 0;


}

void Circle::draw(QPainter *painter){//отрисовка круга в реальном времени
    int r = qMax(mouseX, mouseY);//отслеживание движений мышки
    this->rad=r;
    painter->drawEllipse(QPointF(centerX, centerY), r, r);//рисование круга
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {//здесь все что в предыдущем методе засовываем в один
    draw(painter);
}

double Circle::calculatePerimetr(){
    perimetr=2*3.14*this->rad;
    return perimetr;
    //return 1;
}

double Circle::calculateSquare(){
    square=3.14*this->rad*this->rad;
    return square;
    //return 11;
}
