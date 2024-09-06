#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figuremodel.h"

class Rectangle : public FigureModel{
public:
    explicit Rectangle(FigureModel *parent = nullptr);

    void draw(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double calculatePerimetr()override;
    double calculateSquare()override;
};

#endif // RECTANGLE_H
