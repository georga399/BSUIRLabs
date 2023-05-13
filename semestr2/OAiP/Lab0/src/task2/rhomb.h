#pragma once
#include "figure.h"

class Rhomb: public GeomFigure
{
public:
    Rhomb(int cx, int cy, int w, int h);
    void SetWidth(int w) override;
    void SetHeight(int h) override;
protected:

};