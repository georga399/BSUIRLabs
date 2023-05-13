#include "triangle.h"

Triangle::Triangle(){
    this->countofangles = 3;
}

Triangle::Triangle(int cx, int cy, int a, int b)
{
    this->countofangles = 3;
    this->center.setX(cx);
    this->center.setY(cy);
    angles.push_back(QPointF(this->center.x(), this->center.y() + (double)b/sqrt(b)));
    angles.push_back(QPointF(this->center.x() + a/2, this->center.y() - (double)b/(2*sqrt(3))));
    angles.push_back(QPointF(this->center.x() - a/2, this->center.y() - (double)b/(2*sqrt(3))));
}

void Triangle::SetWidth(int w)
{
    this->a = w;
    angles[1] = QPointF(this->center.x() + a/2, this->center.y() + (double)b/(2*sqrt(3)));
    angles[2] = QPointF(this->center.x() - a/2, this->center.y() + (double)b/(2*sqrt(3)));  
}
    
void Triangle::SetHeight(int h)
{
    this->b = h;
    angles[0] = QPointF(this->center.x(), this->center.y() - (double)b/sqrt(3));
}