#pragma once
#include <QWidget>
#include <QPainter>
#include <QPointF>
#include <QVector>
class GeomFigure
{
private:
    
public:
    GeomFigure(/* args */);
    virtual void Draw(QPainter *pr);
    virtual void SetCenter(int x, int y);
    virtual void SetWidth(int w);
    virtual void SetHeight(int h);
    int GetWidth();
    int GetHeight();
    virtual void Rotate(double angle);
    QVector<QPointF> GetPolyg();
    QPointF GetCenter();
    int GetCountOfAngles();
    virtual void SetVerticle(int ind, QPointF newvert);
    double GetS();
    double GetP();
    virtual void CountS();
    virtual void CountP();
protected:
    int countofangles;
    QPointF center;
    int a, b;
    double S, P;
    QVector<QPointF> angles;    
};

