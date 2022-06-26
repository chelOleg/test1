#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>


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
    void on_exitBtn_clicked();

    void on_cnctBtn_clicked();

    void on_opnBtn_clicked();

    void on_dconnBtn_clicked();

    void on_addBtn_clicked();

    void on_treeShwBtn_clicked();

    void on_treeAddBtn_clicked();

    void on_treeDelBtn_clicked();

    void on_pushBtn_clicked();

    void on_fltrBtn_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase *db;

    void recHideFilter(QModelIndex item,QModelIndexList shwList);
};



#endif // MAINWINDOW_H
