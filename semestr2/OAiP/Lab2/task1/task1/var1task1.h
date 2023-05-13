#ifndef VAR1TASK1_H
#define VAR1TASK1_H

#include <QWidget>
#include "conversation.h"
#include "custlist.h"
#include <QVector>
namespace Ui {
class var1task1;
}

class var1task1 : public QWidget
{
    Q_OBJECT

public:
    explicit var1task1(QWidget *parent = nullptr);
    ~var1task1();
    void UpdateTable();


private slots:
    void on_OpenBtn_clicked();

    void on_RewrFileBtn_clicked();

    void on_NewConvBtn_clicked();

    void on_DeleteConvBtn_clicked();

    void on_CityFindBtn_clicked();

    void on_NumbFindBtn_clicked();

    void on_DelAbBtn_clicked();

    void on_SortBtn_clicked();

    void on_ChangeBtn_clicked();

private:
    Ui::var1task1 *ui;
    CustList<Conversation> lst;
//    QVector<Conversation> lst;
};

#endif // VAR1TASK1_H
