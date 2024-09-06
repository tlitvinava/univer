#include "star5.h"

Star5::Star5(FigureModel *parent) : FigureModel(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Star5::draw(QPainter *painter){
    QPolygon polygon;
    int radios = qMax(mouseX, mouseY);
    for (int i = 0; i < 10; ++i) {
        double angle = 36 * i;  // Угол в градусах
        double radian = qDegreesToRadians(angle);  // Угол в радианах
        int currentRadios = (i % 2 == 0) ? radios : radios / 2;
        int dx = currentRadios * cos(radian);
        int dy = currentRadios * sin(radian);
        polygon << QPoint(centerX + dx, centerY + dy);
    }
    painter->drawPolygon(polygon);
}

void Star5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

double Star5::calculatePerimetr(){
    return 8;
}

double Star5::calculateSquare(){
    return 81;
}
