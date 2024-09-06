#include "star6.h"

Star6::Star6(FigureModel *parent) : FigureModel(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Star6::draw(QPainter *painter){
    QPolygon polygon;
    int radios = qMax(mouseX, mouseY);
    for (int i = 0; i < 12; ++i) {
        double angle = 30 * i;  // Угол в градусах
        double radian = qDegreesToRadians(angle);  // Угол в радианах
        int currentRadios = (i % 2 == 0) ? radios : radios / 2;
        int dx = currentRadios * cos(radian);
        int dy = currentRadios * sin(radian);
        polygon << QPoint(centerX + dx, centerY + dy);
    }
    painter->drawPolygon(polygon);
}

void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

double Star6::calculatePerimetr(){
    return 9;
}

double Star6::calculateSquare(){
    return 91;
}
