#pragma once 
#include "ellipse.h"
class Pacman: public Ellipse
{
public:
    Pacman(int cx, int cy, int w, int h);
    void Draw(QPainter *pr) override;
    void CountS() override;
    void CountP() override;
};

