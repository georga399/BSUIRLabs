#ifndef TASK1WIDGET_H
#define TASK1WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Task1Widget; }
QT_END_NAMESPACE

class Task1Widget : public QWidget
{
    Q_OBJECT

public:
    Task1Widget(QWidget *parent = nullptr);
    ~Task1Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Task1Widget *ui;
};
#endif // TASK1WIDGET_H
