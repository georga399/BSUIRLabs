#pragma once
#include "figure.h"
#include <QPainter>
class Rectangle: public GeomFigure
{
private:
    
public:
    Rectangle(/* args */);
    Rectangle(int cx, int cy, int w, int h);
    // void Draw(QPainter *pr) override;
    void SetWidth(int w) override;
    void SetHeight(int h) override;
    // void SetCenter(int x, int y) override;
protected:
    
};

