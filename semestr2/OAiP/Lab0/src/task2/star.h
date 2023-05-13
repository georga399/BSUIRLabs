#pragma once
#include "figure.h"
class Star: public GeomFigure
{
private:
    double diameter;
public:
    Star(int cx, int cy, int w, int h, int n);
    void SetWidth(int w) override;
};