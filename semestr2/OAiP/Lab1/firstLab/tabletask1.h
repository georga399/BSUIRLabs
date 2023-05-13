#ifndef TABLETASK1_H
#define TABLETASK1_H

#include <QDialog>
#include <QVector>
#include <QString>
#include <QTableWidget>
#include "date.h"
namespace Ui {
class TableTask1;
}

class TableTask1 : public QDialog
{
    Q_OBJECT

public:
    explicit TableTask1(QVector<Date> *dates, QString &path, Date &birthdate, QWidget *parent = nullptr);
    void SetDates(QVector<Date> &dates);
    void SetFilePath(QString &path);
    ~TableTask1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TableTask1 *ui;
    QVector<Date> * dates;
    QString filepath;
    Date birth;
};

#endif // TABLETASK1_H
