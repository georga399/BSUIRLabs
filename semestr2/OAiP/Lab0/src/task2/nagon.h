#pragma once
#include "figure.h"
class Nagon : public GeomFigure
{
private:
    /* data */
public:
    Nagon(int cx, int cy, int w, int h, int n);
    void SetWidth(int w) override;
    void SetHeight(int h) override;
};



