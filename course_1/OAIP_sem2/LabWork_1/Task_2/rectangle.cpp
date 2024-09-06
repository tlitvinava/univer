#include "rectangle.h"

Rectangle::Rectangle(FigureModel *parent) : FigureModel(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Rectangle::draw(QPainter *painter){
    QPolygon polygon;
    polygon << QPoint(centerX - mouseX / 2, centerY - mouseY / 2)
            << QPoint(centerX - mouseX / 2, centerY + mouseY / 2)
            << QPoint(centerX + mouseX / 2, centerY + mouseY / 2)
            << QPoint(centerX + mouseX / 2, centerY - mouseY / 2);
    painter->drawPolygon(polygon);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

double Rectangle::calculatePerimetr(){
    return 4;
}

double Rectangle::calculateSquare(){
    return 41;
}
