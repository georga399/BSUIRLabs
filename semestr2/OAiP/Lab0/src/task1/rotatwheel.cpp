#include "rotatwheel.h"

RotatWheel::RotatWheel(QWidget *pwgt) : MouseObserver(pwgt)
{
    startTimer(10);
}

void RotatWheel::paintEvent(QPaintEvent *pe)
{
    Q_UNUSED(pe);
    QPainter pr(this);
    pr.translate(cx+25, cy+25);
    pr.rotate(cangle);
    qreal rx = -(50*0.5);
    qreal ry = -(50*0.5);
    // pr.drawEllipse(rx, ry, 50, 50);
    drawWheel(100, 100, &pr);
}

void RotatWheel::timerEvent(QTimerEvent *te)
{
    Q_UNUSED(te);
    cangle+=1;
    update();
}

void RotatWheel::drawWheel(int xc, int yc, QPainter *pr)
{
    QPolygonF poly;
    for(int i = 0; i<12; i++)
    {
        qreal fAngle = 2 * 3.14 * i /12;
        int xi = 40*cos(fAngle);
        int yi = 40*sin(fAngle);
        poly << QPointF(xi, yi);
    }

    pr->setBrush(QBrush(Qt::gray, Qt::SolidPattern));
    pr->drawPolygon(poly);
    pr->setBrush(QBrush(Qt::white, Qt::SolidPattern));
    pr->drawEllipse(-15, -15, 30, 30);
}
