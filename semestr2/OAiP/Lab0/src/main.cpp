#include <QtWidgets>
#include <QPainter>
#include "task1/widgtask1.h"
#include "task2/widgtask2.h"
int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget mainwgt;
    mainwgt.resize(250, 90);
    QVBoxLayout mainpvboxLayout;
    QPushButton buttontask1("First task");
    QPushButton buttontask2("Second task");
    mainpvboxLayout.addWidget(&buttontask1);
    mainpvboxLayout.addWidget(&buttontask2);
    mainwgt.setLayout(&mainpvboxLayout);
    mainwgt.show();
    WidgTask1 wgttask1;
    WidgTask2 wgttask2;
    QObject::connect(&buttontask1, SIGNAL(clicked()), &wgttask1, SLOT(show()));
    QObject::connect(&buttontask2, SIGNAL(clicked()), &wgttask2, SLOT(show()));
    return app.exec();
}