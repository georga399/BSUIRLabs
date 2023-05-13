#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "widgtask1.h"
#include "widgtask2.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_ButtonTask_1_clicked();

    void on_ButtonTask_2_clicked();

private:
    Ui::Widget *ui;
    WidgTask1 *task1;
    WidgTask2 *task2;
};
#endif // WIDGET_H
