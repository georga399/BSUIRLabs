#include "circle.h"

Circle::Circle(int cx, int cy, int w, int h) : Ellipse(cx, cy, w, h)
{
    
}

void Circle::Draw(QPainter *pr)
{
    pr->drawEllipse(center, 2,2);
    pr->translate(center.x(), center.y());
    pr->rotate(angleOfRotating);
    double D = a;
    pr->drawEllipse(-D/2, -D/2, D, D);
}