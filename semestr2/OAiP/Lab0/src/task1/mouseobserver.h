#pragma once
#include <QtWidgets>
#include <QPainter>
class MouseObserver: public QWidget
{
public:
    MouseObserver(QWidget *pwgt = 0);
protected:
    virtual void mouseMoveEvent(QMouseEvent *pe);
    virtual void paintEvent(QPaintEvent *pe);
    int cx;
    int cy; 
};
