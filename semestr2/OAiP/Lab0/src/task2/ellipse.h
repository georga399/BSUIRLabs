#pragma once
#include <QWidget>
#include <QPainter>
#include "figure.h"
class Ellipse: public GeomFigure
{
private:
    
public:
    Ellipse(/* args */);
    Ellipse(int cx, int cy, int a, int b);
    virtual void Draw(QPainter *pr) override;
    virtual void CountS() override;
    virtual void CountP() override;
    void Rotate(double angle) override;
protected:
   double angleOfRotating;
};
