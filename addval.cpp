#include "addval.h"
#include "ui_addval.h"
#include "connection.h"
#include "treeitem.h"
#include "treemodel.h"

#include <QtSql/QSqlQuery>


AddVal::AddVal(QWidget *parent,QString tName, QString structur):
    QDialog(parent),
    ui(new Ui::AddVal)
{
//    par =
    ui->setupUi(this);
    structure = structur;
    tblName = tName;
    int c =0;
    QSqlQuery query;
    query.prepare("select column_name,data_type from information_schema.columns where table_name = :name");
    query.bindValue(":name",tName);
    query.exec();
    while (query.next()) {
         QString name = query.value(0).toString();
         QString dType = query.value(1).toString();
         cols[c]=name;
         types[c]=dType;
         switch(c){
             case 1:
                 ui->Lbl1->setText(name);
                 ui->edLn1->setEnabled(1);
             break;
             case 2:
                 ui->Lbl2->setText(name);
                 ui->edLn2->setEnabled(1);
             break;
             case 3:
                 ui->Lbl3->setText(name);
                 ui->edLn3->setEnabled(1);
             break;
             case 4:
                 ui->Lbl4->setText(name);
                 ui->edLn4->setEnabled(1);
             break;
             case 5:
                 ui->Lbl5->setText(name);
                 ui->edLn5->setEnabled(1);
             break;
             case 6:
                 ui->Lbl6->setText(name);
                 ui->edLn6->setEnabled(1);
             break;
            default:
             break;

         }
         c++;
       }


}


AddVal::~AddVal()
{
    delete ui;
}


void AddVal::on_buttonBox_accepted()
{
    int lstidx=1;
    QString req = "INSERT INTO "+tblName +" ( ";
    for (int i=6;i>1 ;i-- ){
        if(!cols[i].isEmpty()){
            req = req + cols[i] + " , ";
        } else {          
            lstidx = i-1;
        }
    }
    req = req + cols[1] + " ) VALUES ( ";
    for (int i=1;i<lstidx;i++ ){
        req = req +" ? ,";
    }
    req = req +" ? )";
    QSqlQuery query;
    query.prepare(req);
    QString val;
    switch (lstidx) {
        case 6:
            val = ui->edLn6->text();
            tChanger(query,val,6);
        case 5:
            val = ui->edLn5->text();
            tChanger(query,val,5);
        case 4:
            val = ui->edLn4->text();
            tChanger(query,val,4);
        case 3:
            val = ui->edLn3->text();
            tChanger(query,val,3);
        case 2:
            val = ui->edLn2->text();
            tChanger(query,val,2);
        case 1:
            val = ui->edLn1->text();
            tChanger(query,val,1);

    }
    query.exec();

}

