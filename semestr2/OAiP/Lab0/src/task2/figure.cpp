#include "figure.h"
GeomFigure::GeomFigure(): countofangles(0)
{
}

void GeomFigure::Draw(QPainter *pr)
{
    QPolygonF polyg;
    for(int i = 0; i<countofangles; i++)
    {
        polyg << angles[i];
    }
    pr->drawPolygon(polyg);
    pr->drawEllipse(center, 3,3);
}

void GeomFigure::SetCenter(int x, int y)
{
    for(int i =0; i<countofangles; i++)
    {
        angles[i].setX(angles[i].x() + x -this->center.x());
        angles[i].setY(angles[i].y() + y - this->center.y());
    }
    this->center.setX(x);
    this->center.setY(y);
}

void GeomFigure::SetWidth(int w)
{
    this->a = w;
}

void GeomFigure::SetHeight(int h)
{
    this->b = h;
}

QPointF GeomFigure::GetCenter(){
    return center; 
}

void GeomFigure::Rotate(double angle)
{
    for(int i = 0; i<countofangles; i++)
    {
        double newx = (angles[i].x() - center.x())*cos(angle) - (angles[i].y() - center.y())*sin(angle) + center.x();
        double newy = (angles[i].y() - center.y())*cos(angle) + (angles[i].x() - center.x())*sin(angle) + center.y();
        angles[i].setX(newx);
        angles[i].setY(newy);
    }
}

QVector<QPointF> GeomFigure::GetPolyg()
{
    return angles;
}

int GeomFigure::GetCountOfAngles()
{
    return countofangles;
}

void GeomFigure::SetVerticle(int ind, QPointF newvert)
{
    angles[ind] = newvert;
    double xc = 0;
    double yc = 0;
    for(int i = 0; i<countofangles; i++)
    {
        xc+= angles[i].x();
        yc+= angles[i].y();
    }
    xc/=countofangles;
    yc/=countofangles;
    center.setX(xc);
    center.setY(yc);
}

int GeomFigure::GetWidth()
{
    return a;
}

int GeomFigure::GetHeight()
{
    return b;
}

void GeomFigure::CountS()
{
    double temp = 0;
    // for(int i = 1; i<countofangles; i++)
    // {
    //     temp+=fabs(angles[i-1].x() - center.x())*(angles[i].y() - center.y()) - (angles[i-1].y() - center.y())*(angles[i].x() - center.x())/2;
    // }
    // temp+=fabs(angles[countofangles-1].x() - center.x())*(angles[0].y() - center.y()) - (angles[countofangles-1].y() - center.y())*(angles[0].x() - center.x())/2;

    // for(int i = 1; i<countofangles; i++)
    // {
    //     temp += (angles[i-1].x()*angles[i].y());
    //     temp -= (angles[i].x()*angles[i-1].y());
    // }
    // temp+=angles[countofangles-1].x()*angles[0].y();
    // temp-=angles[countofangles-1].y()*angles[0].x();
    // for(int i = 1; i<countofangles; i++)
    // {
    //     double sa, sb, sc;
    //     double p;
    //     sc = sqrt((angles[i].x() - angles[i-1].x())*(angles[i].x() - angles[i-1].x()) + (angles[i].y() - angles[i-1].y())*(angles[i].y() - angles[i-1].y()));
    //     sa = sqrt((angles[i-1].x() - center.x())*(angles[i-1].x() - center.x()) + (angles[i-1].y() - center.y())*(angles[i-1].y() - center.y()));
    //     sb = sqrt((angles[i].x() - center.x())*(angles[i].x() - center.x()) + (angles[i].y() - center.y())*(angles[i].y() - center.y()));
    //     p = (sa+sb+sc)/2;
    //     temp+=sqrt(p*(p-sa)*(p-sb)*(p-sc));
    // }
    // double sa, sb, sc;
    // double p;
    // sc = sqrt((angles[0].x() - angles[countofangles-1].x())*(angles[0].x() - angles[countofangles-1].x()) + (angles[0].y() - angles[countofangles-1].y())*(angles[0].y() - angles[countofangles-1].y()));
    // sa = sqrt((angles[countofangles-1].x() - center.x())*(angles[countofangles-1].x() - center.x()) + (angles[countofangles-1].y() - center.y())*(angles[countofangles-1].y() - center.y()));
    // sb = sqrt((angles[0].x() - center.x())*(angles[0].x() - center.x()) + (angles[0].y() - center.y())*(angles[0].y() - center.y()));
    // p = (sa+sb+sc)/2;
    // temp+=sqrt(p*(p-sa)*(p-sb)*(p-sc));
    // for(int i = 1; i<countofangles; i++)
    // {
    //     temp+=((center.x() - angles[i].x())*(angles[i-1].y() - angles[i].y()) - (center.y() - angles[i].y())*(angles[i-1].x() - angles[i].x()))/2;
    // }
    // temp+=((center.x() - angles[0].x())*(angles[countofangles-1].y() - angles[0].y()) - (center.y() - angles[0].y())*(angles[countofangles-1].x() - angles[0].x()))/2;
    for(int i = 1; i<countofangles; i++)
    {
        temp+= ((angles[i-1].x() - center.x())*(angles[i].y() - center.y()) - (angles[i-1].y()-center.y())*(angles[i].x() - center.x()) )/2;
    }
    temp+= ((angles[countofangles-1].x() - center.x())*(angles[0].y() - center.y()) - (angles[countofangles-1].y()-center.y())*(angles[0].x() - center.x()) )/2;
    this->S = fabs(temp);
}

void GeomFigure::CountP()
{
    double temp = 0;
    for(int i = 1; i<countofangles; i++)
    {
        temp += sqrt((angles[i-1].x() - angles[i].x())*(angles[i-1].x() - angles[i].x()) + (angles[i-1].y() - angles[i].y())*(angles[i-1].y() - angles[i].y()));
    }
    temp += sqrt((angles[0].x() - angles[countofangles-1].x())*(angles[0].x() - angles[countofangles-1].x()) + (angles[0].y() - angles[countofangles-1].y())*(angles[0].y() - angles[countofangles-1].y()));

    this->P = temp;
}

double GeomFigure::GetS()
{
    return S;
}

double GeomFigure::GetP()
{
    return P;
}