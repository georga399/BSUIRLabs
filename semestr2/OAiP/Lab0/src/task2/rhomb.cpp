#include "rhomb.h"

Rhomb::Rhomb(int cx, int cy, int w, int h)
{
    center.setX(cx);
    center.setY(cy);
    this->a = w;
    this->b = h;
    angles.push_back(QPointF(center.x() + a/2, center.y()));
    angles.push_back(QPointF(center.x(), center.y() + b/2));
    angles.push_back(QPointF(center.x() - a/2, center.y()));
    angles.push_back(QPointF(center.x(), center.y() - b/2));
    countofangles = 4;
}
void Rhomb::SetWidth(int w)
{
    this->a = w;
    angles[0].setX(center.x() + a/2);
    angles[2].setX(center.x() - a/2); 
}
void Rhomb::SetHeight(int h)
{
    this->b = h;
    angles[1].setY(center.y() + b/2);
    angles[3].setY(center.y() - b/2); 
}