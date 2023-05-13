#include "widgtask1.h"

WidgTask1::WidgTask1(QWidget *pwgt) : QWidget(pwgt)
{
    QVBoxLayout *task1boxLayout = new QVBoxLayout();
    QPushButton *btn1 = new QPushButton("Родительский класс: перемещающийся круг");
    QPushButton *btn2 = new QPushButton("Унаследованный класс: вращающееся колесо");
    task1boxLayout->addWidget(btn1);
    task1boxLayout->addWidget(btn2);
    this->setLayout(task1boxLayout);
    MouseObserver *movcircle = new MouseObserver();
    RotatWheel *wheel = new RotatWheel();
    QObject::connect(btn1, SIGNAL(clicked()), movcircle, SLOT(show()));
    QObject::connect(btn2, SIGNAL(clicked()), wheel, SLOT(show()));
    movcircle->resize(300, 300);
    wheel->resize(300, 300);
}