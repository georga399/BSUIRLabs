#ifndef WIDGTASK1_H
#define WIDGTASK1_H

#include <QWidget>
#include <QString>
#include <QVector>
#include "date.h"

namespace Ui {
class WidgTask1;
}

class WidgTask1 : public QWidget
{
    Q_OBJECT

public:
    explicit WidgTask1(QWidget *parent = nullptr);
    ~WidgTask1();

private slots:
    void on_buttonRead_clicked();

    void on_pushButton_clicked();

    void on_birthBtn_clicked();

private:
    Ui::WidgTask1 *ui;
    QString path;
    QVector<Date> Alldates;
    Date birthday;
};

#endif // WIDGTASK1_H
