#include "square.h"
Square::Square(int cx, int cy, int w, int h)
{
    this->center.setX(cx);
    this->center.setY(cy);
    this->a = w;
    this->b = h;
    this->size = sqrt(a*a + b*b);
    angles.push_back(QPointF(center.x() + size/2, center.y() + size/2));
    angles.push_back(QPointF(center.x() + size/2, center.y() - size/2));
    angles.push_back(QPointF(center.x() - size/2, center.y() - size/2));
    angles.push_back(QPointF(center.x() - size/2, center.y() + size/2));
    countofangles = 4;
}

void Square::SetWidth(int w)
{
    this->a = w;
    this->size = sqrt(a*a + b*b);
    angles[0] = (QPointF(center.x() + size/2, center.y() + size/2));
    angles[1] = (QPointF(center.x() + size/2, center.y() - size/2));
    angles[2] = (QPointF(center.x() - size/2, center.y() - size/2));
    angles[3] = (QPointF(center.x() - size/2, center.y() + size/2));
}
void Square::SetHeight(int h)
{
    this->b = h;
    this->size = sqrt(a*a + b*b);
    angles[0] = (QPointF(center.x() + size/2, center.y() + size/2));
    angles[1] = (QPointF(center.x() + size/2, center.y() - size/2));
    angles[2] = (QPointF(center.x() - size/2, center.y() - size/2));
    angles[3] = (QPointF(center.x() - size/2, center.y() + size/2));
}