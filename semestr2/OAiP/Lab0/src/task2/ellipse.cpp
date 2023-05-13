#include "ellipse.h"

Ellipse::Ellipse(){}

Ellipse::Ellipse(int cx, int cy, int a, int b)
{
    this->center.setX(cx);
    this->center.setY(cy);
    this->a = a;
    this->b = b;
    countofangles = 0;
    angleOfRotating = 0;
}

void Ellipse::Draw(QPainter *pr)
{
    qDebug() << "Drawing ellipse";
    pr->drawEllipse(center, 2,2);
    pr->translate(center.x(), center.y());
    pr->rotate(angleOfRotating);
    pr->drawEllipse(-a/2, -b/2, a, b);
}

void Ellipse::CountS()
{
    S = fabs(3.14*a*b/4);
}

void Ellipse::CountP()
{
    P = 2*3.14*sqrt((a*a + b*b)/8);
}

void Ellipse::Rotate(double angle)
{
    qDebug() << "Ellipse rotating";
    angleOfRotating+= angle*180/acos(-1);
}