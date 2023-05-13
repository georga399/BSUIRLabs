#include "task1widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Task1Widget w;
    w.show();
    return a.exec();
}
