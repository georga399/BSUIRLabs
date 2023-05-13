#ifndef DIALOGNEWCONV_H
#define DIALOGNEWCONV_H

#include <QDialog>
#include <QDate>
#include "conversation.h"
namespace Ui {
class DialogNewConv;
}

class DialogNewConv : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewConv(QWidget *parent = nullptr);
    Conversation getConversation();
    bool correctInput();
    ~DialogNewConv();
private slots:

    void on_confBtn_clicked();

    void on_backBtn_clicked();

private:
    Ui::DialogNewConv *ui;
    Conversation conv;
    bool toChange = false;
};

#endif // DIALOGNEWCONV_H
