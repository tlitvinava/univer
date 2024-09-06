#ifndef STAR8_H
#define STAR8_H

#include "figuremodel.h"

class Star8 : public FigureModel{
public:
    explicit Star8(FigureModel *parent = nullptr);

    void draw(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double calculatePerimetr()override;
    double calculateSquare()override;
};

#endif // STAR8_H
