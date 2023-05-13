#ifndef INPUTTEXTDIALOG_H
#define INPUTTEXTDIALOG_H

#include <QDialog>

namespace Ui {
class InputTextDialog;
}

class InputTextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputTextDialog(QString lbl, QWidget *parent = nullptr);
    ~InputTextDialog();
    bool checkInput();
    QString getText();
private slots:
    void on_confBtn_clicked();

    void on_backBtn_clicked();

private:
    Ui::InputTextDialog *ui;
    bool validInput = false;
    QString text;
};

#endif // INPUTTEXTDIALOG_H
