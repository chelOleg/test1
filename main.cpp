#include "mainwindow.h"
#include <QApplication>

#include <connection.h>

#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QtSql>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);


    MainWindow w;
    w.show();
    return a.exec();
}
