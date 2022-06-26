#include "connection.h"
#include "ui_connection.h"

connection::connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connection)
{
    ui->setupUi(this);
}

connection::~connection()
{
    delete ui;
}

void connection::on_buttonBox_accepted()
{
    connection::db.setHostName(ui->hostLn->text());
    connection::db.setPort(ui->portLn->text().toInt());
    connection::db.setDatabaseName(ui->baseLn->text());
    connection::db.setUserName(ui->logLn->text());
    connection::db.setPassword(ui->passLn->text());
    bool ok = connection::db.open();
    if (ok){
        QMessageBox::information(0,"conected","connected");
    }
    else {
        QMessageBox::information(0,"er",db.lastError().text());
    }

}

