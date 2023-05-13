#pragma once
#include "ellipse.h"
class Circle: public Ellipse
{
public:
    Circle(int cx, int cy, int w, int h);
    // void Draw(QPainter *pr) override;
    void Draw(QPainter *pr) override;
};