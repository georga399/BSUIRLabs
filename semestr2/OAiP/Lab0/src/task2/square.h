#pragma once
#include "figure.h"
class Square: public GeomFigure
{
private:
    double size;   
public:
    Square(int cx, int cy, int w, int h);
    void SetWidth(int w) override;
    void SetHeight(int h) override;
};



