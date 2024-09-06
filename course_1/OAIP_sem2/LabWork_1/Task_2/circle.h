#ifndef CIRCLE_H
#define CIRCLE_H

#include "figuremodel.h"//подключение основного файла

class Circle : public FigureModel{//наследование
public:
    int rad = 0;
    explicit Circle(FigureModel *parent = nullptr);

    void draw(QPainter *painter) override;//для методов которые в родительском файле обьявлены virtual пишем в наследниках override для переопределения и теперь если мы в наследнике обратимся к этой функции ошибки не будет, но реализацию необходимо написать в спп
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
    double calculatePerimetr() override;
    double calculateSquare() override;
};

#endif // CIRCLE_H
