#ifndef FINDEDELEMDIALOG_H
#define FINDEDELEMDIALOG_H

#include <QDialog>
#include "conversation.h"
#include "custvector.h"
namespace Ui {
class FindedElemDialog;
}

class FindedElemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindedElemDialog(CustVector<Conversation> *lst, QWidget *parent = nullptr);
    ~FindedElemDialog();

private:
    Ui::FindedElemDialog *ui;
    CustVector<Conversation> *lst;
};

#endif // FINDEDELEMDIALOG_H
