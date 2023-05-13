#include "nagon.h"

Nagon::Nagon(int cx, int cy, int w, int h, int n)
{
    this->center.setX(cx);
    this->center.setY(cy);
    this->a = w;
    this->b = h;
    this->countofangles = n;
    for(int i = 0; i<countofangles; i++)
    {
        angles.push_back(QPointF(center.x() + cos(double(i)*360*acos(-1)/(180*countofangles))*a/2, center.y() - sin(double(i)*360*acos(-1)/(180*countofangles)))*b/2);
    }
}

void Nagon::SetWidth(int w)
{
    this->a = w;
    double temp =0;
    for(int i = 0; i<countofangles; i++)
    {
        angles[i] = (QPointF(center.x() + cos(temp*acos(-1)/180)*a/2, center.y() + sin(temp*acos(-1)/180)*b/2));
        temp+=360/countofangles;
    }
}
void Nagon::SetHeight(int h)
{
    this->b = h;
    double temp =0;
    for(int i = 0; i<countofangles; i++)
    {
        angles[i] = (QPointF(center.x() + cos(temp*acos(-1)/180)*a/2, center.y() + sin(temp*acos(-1)/180)*b/2));
        temp+=360/countofangles;
    }
}