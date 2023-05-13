#pragma once
#include <QWidget>
#include "figure.h"
#include "ellipse.h"
#include "rectangle.h"
#include "triangle.h"
#include "star.h"
#include "rhomb.h"
#include "square.h"
#include "circle.h"
#include "nagon.h"
#include "pacman.h"
#include <QPainter>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QPointF>
#include <QSpinBox>
// #include <QtWidgets>
class WidgTask2 : public QWidget
{
private:
    GeomFigure *fgr = nullptr;
    QLabel *lblinfo;
    QRadioButton *btnEllipse;
    QRadioButton *btnCircle;
    QRadioButton *btnRectangle;
    QRadioButton *btnSquare;
    QRadioButton *btnRhomb;
    QRadioButton *btnTriangle;
    QRadioButton *btnStar5;
    QSpinBox *spbNstar;
    QRadioButton *btnHexagon;
    QSpinBox *spbNgon;
    QRadioButton *btnPacman;
    QRadioButton *btnMove;
    QRadioButton *btnCreate;
    QRadioButton *btnRotate;
    QRadioButton *btnChange;
    QPointF prevPosOfMouse;
    double angleOfRot = 0;
    QPointF vertOfChanged;
    int indofcurvert;
public:
    WidgTask2(QWidget *pwgt = 0);
    ~WidgTask2();
protected:
    virtual void paintEvent(QPaintEvent *pe);
    virtual void mousePressEvent(QMouseEvent *me);
    virtual void mouseMoveEvent(QMouseEvent *me);
};

