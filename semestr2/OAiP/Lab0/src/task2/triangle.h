#pragma once
#include "figure.h"
#include <QPainter>
class Triangle: public GeomFigure
{
private:
    // QVector<QPointF> pl;
public:
    Triangle(/* args */);
    Triangle(int cx, int cy, int a, int b);
    // void Draw(QPainter *pr) override;
    void SetWidth(int w) override;
    void SetHeight(int h) override;
};

