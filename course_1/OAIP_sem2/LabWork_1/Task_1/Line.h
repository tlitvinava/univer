#ifndef LINE_H
#define LINE_H

#include <QWidget>//нужен для того чтобы было "окно" в котором можно рисовать

class Line:public QWidget{//хедр в котором обьявляются переменные и методы, реализация которых в сппшнике соответственно
public:                     //если что это хедр для родительского класса
    int y=0;
    void paintEvent(QPaintEvent *event);
    void drawR(QPainter *painter);
    void move();
    void moveDown();
    bool dr(int sch);
private:
    int m=1;
    int s=-1;
    bool be=false;
};

#endif // LINE_H

