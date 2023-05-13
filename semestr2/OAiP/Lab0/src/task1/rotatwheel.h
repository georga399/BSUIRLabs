#pragma once
#include "mouseobserver.h"
class RotatWheel: public MouseObserver
{
public:
    RotatWheel(QWidget *pwgt = 0);
protected:
    long long cangle = 0;
    virtual void paintEvent(QPaintEvent *pe);
    virtual void timerEvent(QTimerEvent *te);
    void drawWheel(int xc, int yc, QPainter *pr);
};