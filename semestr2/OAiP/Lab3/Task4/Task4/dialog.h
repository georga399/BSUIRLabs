#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString GetText();
    void SetLbl(QString txt);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
    QString text;

};

#endif // DIALOG_H
