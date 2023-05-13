#include "widgtask2.h"

WidgTask2::WidgTask2(QWidget *pwgt) : QWidget(pwgt)
{
    this->resize(600, 600);
    QGroupBox *gbx = new QGroupBox("figures", this);
    btnEllipse = new QRadioButton("Ellipse");
    btnRectangle = new QRadioButton("Rectangle");
    btnSquare = new QRadioButton("Square");
    btnTriangle = new QRadioButton("Triangle");
    btnRhomb = new QRadioButton("Rhomb");
    btnStar5 = new QRadioButton("Star");
    btnCircle = new QRadioButton("Circle");
    btnHexagon = new QRadioButton("Polygon");
    btnPacman = new QRadioButton("Pacman");
    spbNgon = new QSpinBox();
    spbNstar = new QSpinBox();
    spbNgon->setRange(5, 10);
    spbNstar->setRange(5, 10);
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(btnEllipse);
    pvbxLayout->addWidget(btnCircle);
    pvbxLayout->addWidget(btnRectangle);
    pvbxLayout->addWidget(btnSquare);
    pvbxLayout->addWidget(btnRhomb);
    pvbxLayout->addWidget(btnTriangle);
    pvbxLayout->addWidget(btnStar5);
    pvbxLayout->addWidget(spbNstar);
    pvbxLayout->addWidget(btnHexagon);
    pvbxLayout->addWidget(spbNgon);
    pvbxLayout->addWidget(btnPacman);
    lblinfo = new QLabel("S = \nP = \ncenter:\nx: \ny: ");
    fgr = nullptr;
    pvbxLayout->addWidget(lblinfo);
    gbx->setLayout(pvbxLayout);

    QGroupBox *agbx = new QGroupBox("actions", this); 
    QVBoxLayout* actionsVbxLayout = new QVBoxLayout;
    btnMove = new QRadioButton("Move");
    btnCreate = new QRadioButton("New");
    btnRotate = new QRadioButton("Rotate");
    btnChange = new QRadioButton("Change");
    actionsVbxLayout->addWidget(btnCreate);
    actionsVbxLayout->addWidget(btnMove);
    actionsVbxLayout->addWidget(btnRotate);
    actionsVbxLayout->addWidget(btnChange);
    agbx->setLayout(actionsVbxLayout);
    agbx->move(0, 400);
    agbx->resize(gbx->width()-5, 120);
}

void WidgTask2::paintEvent(QPaintEvent *pe)
{
    Q_UNUSED(pe);
    QPainter painter(this);
    int counter = 0;
    if(fgr != nullptr)
    {
        fgr->Draw(&painter);
        lblinfo->setText(QString("S = ") + QString::number(fgr->GetS()) + QString("\nP = ") + QString::number(fgr->GetP()) + QString("\ncenter:\nx: ") + QString::number(fgr->GetCenter().x()) + QString("\ny: ") + QString::number(fgr->GetCenter().y()));
    }
    
}

void WidgTask2::mousePressEvent(QMouseEvent *pe)
{
    int cx = pe->position().x();
    int cy = pe->position().y();
    
    if(btnCreate->isChecked())
    {
        if(fgr != nullptr)
        {
            delete fgr;
            fgr = nullptr;
        }
        if(btnEllipse->isChecked()) fgr = new Ellipse(cx, cy, 0, 0);
        else if(btnRectangle->isChecked()) fgr = new Rectangle(cx, cy, 0, 0);
        else if(btnTriangle->isChecked()) fgr = new Triangle(cx, cy, 0, 0);
        else if(btnStar5->isChecked()) fgr = new Star(cx, cy, 0,0, spbNstar->value());
        else if(btnRhomb->isChecked()) fgr = new Rhomb(cx, cy, 0, 0);
        else if(btnSquare->isChecked()) fgr = new Square(cx, cy, 0, 0);
        else if(btnCircle->isChecked()) fgr = new Circle(cx, cy, 0, 0);
        else if(btnHexagon->isChecked()) fgr = new Nagon(cx, cy, 0,0, spbNgon->value());
        else if(btnPacman->isChecked()) fgr = new Pacman(cx, cy, 0, 0);
    }
    else if(btnMove->isChecked())
    {
        prevPosOfMouse = pe->position();
    }
    else if(btnRotate->isChecked())
    {
        angleOfRot = pe->position().x();
    }
    else if(btnChange->isChecked())
    {
        if(fgr != nullptr)
        {
            QVector<QPointF> verticles = fgr->GetPolyg();
            int i = 0;
            for(; i<fgr->GetCountOfAngles(); i++)
            {
                if((verticles[i].x() + 5> pe->position().x() && verticles[i].x() - 5 < pe->position().x()) && (verticles[i].y() + 5 > pe->position().y() && verticles[i].y() - 5 < pe->position().y()))
                {
                    indofcurvert = i;
                    vertOfChanged = verticles[i];
                    break;
                }
            }
            if(i == fgr->GetCountOfAngles() ) indofcurvert = -1;
            prevPosOfMouse = pe->position();
        }
    }
    update();
}

void WidgTask2::mouseMoveEvent(QMouseEvent *me)
{
    if(fgr!= nullptr)
    {
        if(this->btnCreate->isChecked())
        {
            fgr->SetWidth(me->position().x() - fgr->GetCenter().x());
            fgr->SetHeight(me->position().y() - fgr->GetCenter().y());
            fgr->CountP(); fgr->CountS();
        }
        else if(this->btnMove->isChecked())
        {
            fgr->SetCenter(fgr->GetCenter().x() + (me->position().x() - prevPosOfMouse.x()), fgr->GetCenter().y() + (me->position().y() - prevPosOfMouse.y()));
            prevPosOfMouse = me->position();
        }
        else if(this->btnRotate->isChecked())
        {
            fgr->Rotate(double(angleOfRot - me->position().x())*acos(-1)/(180));
            angleOfRot = me->position().x();
            fgr->CountP(); fgr->CountS();

        }
        else if(this->btnChange->isChecked())
        {
            if(indofcurvert>-1 && fgr != nullptr)
            {
                fgr->SetVerticle(indofcurvert, me->position());
                fgr->CountP(); fgr->CountS();
            }
            else if(fgr != nullptr && fgr->GetCountOfAngles() == 0)
            {
                fgr->SetWidth(fgr->GetWidth() + me->position().x() - prevPosOfMouse.x());
                fgr->SetHeight(fgr->GetHeight() + me->position().y() - prevPosOfMouse.y());
                prevPosOfMouse = me->position();
                fgr->CountP(); fgr->CountS();
            }
        }
    }
    update();
}

WidgTask2::~WidgTask2()
{
    if(fgr != nullptr) delete fgr;
}