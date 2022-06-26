#ifndef ADDVAL_H
#define ADDVAL_H

#include <QDialog>
#include <QSqlQuery>
#include <QLabel>
#include <QLineEdit>

#include "treeitem.h"
#include "treemodel.h"

namespace Ui {
class AddVal;
}

class AddVal : public QDialog
{
    Q_OBJECT

public:

    explicit AddVal(QWidget *parent = nullptr,QString tName= nullptr,QString structure = "table");
    ~AddVal();

    void setParent(TreeItem p);
    void updaeteModel(TreeModel m);



private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddVal *ui;

    QString structure;
//    TreeItem par;
    QString tblName;
    QString cols[7];
    QString types[7];

    void tChanger(QSqlQuery query, QString val, int i){
        if(!types[i].compare("character varying") ){
                query.addBindValue(val);

        }
        else if (!types[i].compare("integer")) {
            query.addBindValue(val.toInt());
        }
    }

};


#endif // ADDVAL_H
