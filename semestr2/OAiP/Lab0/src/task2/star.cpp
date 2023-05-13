#include "star.h"

Star::Star(int cx, int cy, int w, int h, int n)
{
    countofangles = 2*n;
    this->center = QPointF(cx, cy);
    this->diameter = w;
    for(int i = 0; i<countofangles; i++)
    {
        if(i%2)
        {
            angles.push_back(QPointF(center.x() + cos(double(i)*360*acos(-1)/(180*countofangles))*diameter/2, center.y() - sin(double(i)*360*acos(-1)/(180*countofangles)))*diameter/2);
        }
        else
        {
            angles.push_back(QPointF(center.x() + cos(double(i)*360*acos(-1)/(180*countofangles))*diameter/4 + center.x(),  center.y() - sin(double(i)*360*acos(-1)/(180*countofangles)))*diameter/4);
        }
    }
}

void Star::SetWidth(int w)
{
    this->diameter = w;
    double temp = 0;
    for(int i = 0; i<countofangles; i++)
    {
        if(i%2)
        {
            angles[i] = (QPointF(center.x() + cos(temp*acos(-1)/180)*diameter/2, center.y() + sin(temp*acos(-1)/180)*diameter/2));
        }
        else
        {
            angles[i] =(QPointF(center.x() + cos(temp*acos(-1)/180)*diameter/4, center.y() + sin(temp*acos(-1)/180)*diameter/4));
        }
        temp+=360/countofangles;
    }
}