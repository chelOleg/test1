#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "addval.h"
#include "treeitem.h"
#include "treemodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->fltEdit1->setFixedSize(0,0);
    ui->fltEdit2->setFixedSize(0,0);
    ui->fltEdit3->setFixedSize(0,0);
    ui->fltEdit4->setFixedSize(0,0);
    ui->fltEdit5->setFixedSize(0,0);
    ui->fltEdit6->setFixedSize(0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exitBtn_clicked()
{
    QCoreApplication::quit();
}


void MainWindow::on_cnctBtn_clicked()
{
    if(!QSqlDatabase::database().isOpen()){
        connection cw;
        cw.exec();

        if(QSqlDatabase::database().isOpen()){
            db = &cw.db;
            ui->connChck->setChecked(1);
            ui->opnBtn->setEnabled(1);
            ui->addBtn->setEnabled(1);
            ui->treeAddBtn->setEnabled(1);
            ui->treeDelBtn->setEnabled(1);
            ui->treeShwBtn->setEnabled(1);

        }
    }
    else{
        baseWarning("Already connected");
    }
}


void MainWindow::on_opnBtn_clicked()
{
    QString text = ui->tNameEdt->text();
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM "+text);

    ui->tableView->setModel(model);
    if (model->record().isEmpty()){
        QString bw = "Wrong name of table";
        baseWarning(bw);

        ui->tableView->setModel(model);
    }
\
}


void MainWindow::on_dconnBtn_clicked()
{
    if(QSqlDatabase::database().isOpen()){
        QSqlDatabase::database().close();
        if(!QSqlDatabase::database().isOpen()){
            ui->connChck->setChecked(0);
            ui->opnBtn->setEnabled(0);
        }
    }
}


void MainWindow::on_addBtn_clicked()
{
    QString tName = ui->tNameEdt->text();
    if(QSqlDatabase::database().tables().contains(tName)){
        AddVal av(this,tName);
        av.exec();
    }
    else{
        QString bw = "Wrong name of table";
        baseWarning(bw);
    }
}


void MainWindow::on_treeShwBtn_clicked()
{
    QStringList head;
    QStringList types;
    QSqlQuery query;
    QVector<QString> data;

    QString text = ui->treeNameEdt->text();

    if (query.exec("select * from "+text)){
        QSqlRecord rec = query.record();
        for (int j=2; j<rec.count();j++){
                head << rec.field(j).name();
                types << QString::number(rec.field(j).typeID());
                //23 - int ;1043 - varchar; 25 - text
        }
        ui->pushBtn->setEnabled(1);
        TreeModel *model = new TreeModel(head,types,query,text);
        ui->MtreeView->setModel(model);
        ui->fltrBtn->setEnabled(1);
        ui->fltEdit1->setFixedSize(qMin(ui->MtreeView->header()->sectionSize(0),400),20);
        ui->fltEdit2->setFixedSize(qMin(ui->MtreeView->header()->sectionSize(1),400),20);
        ui->fltEdit3->setFixedSize(qMin(ui->MtreeView->header()->sectionSize(2),400),20);
        ui->fltEdit4->setFixedSize(qMin(ui->MtreeView->header()->sectionSize(3),400),20);
        ui->fltEdit5->setFixedSize(qMin(ui->MtreeView->header()->sectionSize(4),400),20);
        ui->fltEdit6->setFixedSize(qMin(ui->MtreeView->header()->sectionSize(5),400),20);
    }
    else {
        baseWarning("Wrong name of table");
    }

}


void MainWindow::on_treeAddBtn_clicked()
{
    QModelIndex index = ui->MtreeView->selectionModel()->currentIndex();
    QAbstractItemModel *model = ui->MtreeView->model();

    model->insertRows(index.row(),1,index);
    for (int column = 0; column < model->columnCount(index); ++column) {
        QModelIndex child = model->index(0, column, index);
        model->setData(child, QVariant("No data "+QString::number(column)), Qt::EditRole);
    }

}


void MainWindow::on_treeDelBtn_clicked()
{
    QModelIndex index = ui->MtreeView->selectionModel()->currentIndex();
    QAbstractItemModel *model = ui->MtreeView->model();
    model->removeRows(index.row(),1,index.parent());
}


void MainWindow::on_pushBtn_clicked()
{
    ui->MtreeView->model()->revert();

}


void MainWindow::on_fltrBtn_clicked()
{
    QAbstractItemModel *model = ui->MtreeView->model();
    QList<QModelIndex> items;
    QSet<QModelIndex> res;
    QModelIndexList result;
    QStringList filters;
    int lenth = 0;
    filters << ui->fltEdit1->text();
    filters << ui->fltEdit2->text();
    filters << ui->fltEdit3->text();
    filters << ui->fltEdit4->text();
    filters << ui->fltEdit5->text();
    filters << ui->fltEdit6->text();

    for (int i = 0;i<filters.size();i++ ) {
        if (!filters[i].isEmpty()){
            items = model->match(model->index(0,i),Qt::DisplayRole,QVariant::fromValue(filters[i]),-1,Qt::MatchRecursive);
            if (i!=0){
                for (int k=0; k<items.size();k++){
                    items[k] = items[k].siblingAtColumn(0);
                }
            }
            if (!res.isEmpty())
                res = res.intersect(items.toSet());
            else {
                res = items.toSet();
            }
        }
    }
    if (!res.isEmpty()){
        items.clear();
        foreach (QModelIndex idx, res){
            items << idx.parent();
        }
        while (!items.size()==lenth){
            lenth = items.size();
            foreach (QModelIndex idx, items){
                items << idx.parent();
            }
        }
        res.unite(items.toSet());
        foreach(QModelIndex r,res){
            result << r;
        }
        for (int row = 0; row< model->rowCount();row++ ) {
            recHideFilter(model->index(row,0),result);
        }
    }
}

void MainWindow::recHideFilter(QModelIndex item,QModelIndexList shwList){
    if (shwList.contains(item)){
        for (int i =0;i<ui->MtreeView->model()->rowCount(item);i++){
            recHideFilter(ui->MtreeView->model()->index(i,0,item), shwList);
        }
    } else {
        ui->MtreeView->setRowHidden(item.row(),item.parent(),1);
    }

}

