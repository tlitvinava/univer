#include "star8.h"

Star8::Star8(FigureModel *parent) : FigureModel(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Star8::draw(QPainter *painter){
    QPolygon polygon;
    int radios = qMax(mouseX, mouseY);
    for (int i = 0; i < 16; ++i) {
        double angle = 22.5 * i;  // Угол в градусах
        double radian = qDegreesToRadians(angle);  // Угол в радианах
        int currentRadios = (i % 2 == 0) ? radios : radios / 2;
        int dx = currentRadios * cos(radian);
        int dy = currentRadios * sin(radian);
        polygon << QPoint(centerX + dx, centerY + dy);
    }
    painter->drawPolygon(polygon);
}

void Star8::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

double Star8::calculatePerimetr(){
    return 10;
}

double Star8::calculateSquare(){
    return 101;
}
