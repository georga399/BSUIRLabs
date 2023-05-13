#include "rectangle.h"

Rectangle::Rectangle(int cx, int cy, int w, int h)
{
    center.setX(cx);
    center.setY(cy);
    this->a = w;
    this->b = h;
    countofangles = 4;
    angles.push_back(QPoint(center.x() + a/2, center.y() + b/2));
    angles.push_back(QPoint(center.x() - a/2, center.y() + b/2));
    angles.push_back(QPoint(center.x() - a/2, center.y() - b/2));
    angles.push_back(QPoint(center.x() + a/2, center.y() - b/2));
    
}

Rectangle::Rectangle()
{
    countofangles = 4;
}

// void Rectangle::Draw(QPainter *pr)
// {
//     pr->drawRect(center.x(), center.y(), a, b);
// }

void Rectangle::SetWidth(int w)
{
    this->a = w;
    angles[0] = QPoint(center.x() + a/2, center.y() + b/2);
    angles[1] = QPoint(center.x() - a/2, center.y() + b/2);
    angles[2] = QPoint(center.x() - a/2, center.y() - b/2);
    angles[3] = QPoint(center.x() + a/2, center.y() - b/2);
    
}

void Rectangle::SetHeight(int h)
{
    this->b = h;
    angles[0] = QPoint(center.x() + a/2, center.y() + b/2);
    angles[1] = QPoint(center.x() - a/2, center.y() + b/2);
    angles[2] = QPoint(center.x() - a/2, center.y() - b/2);
    angles[3] = QPoint(center.x() + a/2, center.y() - b/2);
}

// void Rectangle::SetCenter(int x, int y)
// {
//     GeomFigure::SetCenter(x, y);
//     angles[0] = QPoint(center.x() + a/2, center.y() + b/2);
//     angles[1] = QPoint(center.x() - a/2, center.y() + b/2);
//     angles[2] = QPoint(center.x() - a/2, center.y() - b/2);
//     angles[3] = QPoint(center.x() + a/2, center.y() - b/2);
// }