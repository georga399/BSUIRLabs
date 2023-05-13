#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionGet_all_variables_triggered();

    void on_actionCount_of_classes_triggered();

    void on_actionCount_of_arrays_triggered();

    void on_actionGet_prototypes_of_func_triggered();

    void on_actionGet_all_positions_of_changing_vars_and_arrays_triggered();

    void on_actionGet_local_vars_triggered();

    void on_actionGet_overrided_funcs_triggered();

    void on_actionDeeps_of_branches_triggered();

    void on_actionLogic_warnings_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
