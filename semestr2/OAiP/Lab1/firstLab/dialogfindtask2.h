#ifndef DIALOGFINDTASK2_H
#define DIALOGFINDTASK2_H

#include <QDialog>

namespace Ui {
class DialogFindTask2;
}

class DialogFindTask2 : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFindTask2(QWidget *parent = nullptr);
    ~DialogFindTask2();
    QString GetGroup();
    QString GetName();
    QString GetModel();
private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogFindTask2 *ui;
};

#endif // DIALOGFINDTASK2_H
