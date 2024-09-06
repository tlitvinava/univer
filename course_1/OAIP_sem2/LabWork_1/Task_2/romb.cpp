#include "romb.h"

Romb::Romb(FigureModel *parent) : FigureModel(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Romb::draw(QPainter *painter){
    QPolygon polygon;
    polygon << QPoint(centerX, centerY - mouseY)
            << QPoint(centerX - mouseX, centerY)
            << QPoint(centerX, centerY + mouseY)
            << QPoint(centerX + mouseX, centerY);
    painter->drawPolygon(polygon);
}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

double Romb::calculatePerimetr(){
    return 5;
}

double Romb::calculateSquare(){
    return 51;
}
