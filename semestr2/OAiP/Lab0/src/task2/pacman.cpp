#include "pacman.h"
Pacman::Pacman(int cx, int cy, int w, int h): Ellipse(cx, cy, w, h)
{}

void Pacman::Draw(QPainter *pr)
{
    
    pr->translate(center.x(), center.y());
    pr->rotate(angleOfRotating);
    pr->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    pr->drawPie(QRectF(-a/2, -b/2, a, b), 45*16, 270*16);
    pr->setBrush(QBrush(Qt::black, Qt::SolidPattern));
    pr->drawEllipse(-fabs(-a/2 + a/4), -fabs(-b/2 + b/4), fabs(a/10), fabs(b/10));
}

void Pacman::CountS()
{
    S = fabs(3.14*a*b/4)*3/4;
}
void Pacman::CountP()
{
    P = 2*3.14*sqrt((a*a + b*b)/8)*3/4 + 2*sqrt(a*a + b*b);
}