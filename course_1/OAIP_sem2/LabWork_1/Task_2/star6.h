#ifndef STAR6_H
#define STAR6_H

#include "figuremodel.h"

class Star6 : public FigureModel{
public:
    explicit Star6(FigureModel *parent = nullptr);

    void draw(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double calculatePerimetr()override;
    double calculateSquare()override;
};

#endif // STAR6_H
