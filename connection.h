#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include <QtSql>
#include <QTableView>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class connection;
}

class connection : public QDialog
{
    Q_OBJECT

public:
    explicit connection(QWidget *parent = nullptr);
    ~connection();

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

private slots:
    void on_buttonBox_accepted();

private:
    Ui::connection *ui;

};



inline void baseWarning(QString text){
    QMessageBox::warning(0,"Warning",text);
}
#endif // CONNECTION_H
