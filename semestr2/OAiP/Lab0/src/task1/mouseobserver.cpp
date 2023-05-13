#include "mouseobserver.h"

MouseObserver::MouseObserver(QWidget *pwgt): QWidget(pwgt)
{
    setMouseTracking(true);
} 

void MouseObserver::mouseMoveEvent(QMouseEvent *pe)
{
    cx = pe->position().x() - 25;
    cy = pe->position().y() - 25;
    update();
}

void MouseObserver::paintEvent(QPaintEvent *pe)
{
    Q_UNUSED(pe);
    QPainter pr(this);
    pr.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    pr.drawEllipse(cx, cy, 50, 50);

}