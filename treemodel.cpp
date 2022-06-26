#include "treemodel.h"
#include "treeitem.h"
#include "connection.h"



TreeModel::TreeModel(const QStringList &headers, QStringList types, QSqlQuery query, QString name, QObject *parent)
    : QAbstractItemModel(parent)
{
    QVector<QVariant> rootData;
    foreach (QString header, headers)
        rootData << header;

    rootItem = new TreeItem(-1,rootData);
    tName = name;
    dTypes = types;
    setupModelData(query, rootItem);
}

TreeModel::~TreeModel()
{
    delete rootItem;
}

int TreeModel::columnCount(const QModelIndex & /* parent */) const
{
    return rootItem->columnCount();
}


QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    TreeItem *item = getItem(index);

    return item->data(index.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

TreeItem *TreeModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return rootItem;
}

TreeItem* TreeModel::item(const QModelIndex index){
    return getItem(index);
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();

    TreeItem *parentItem = getItem(parent);

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}


bool TreeModel::insertRows( int position, int rows, const QModelIndex &parent)
{
    TreeItem *parentItem = getItem(parent);
    if (parentItem->id == -99)
        return false;
    bool success;
    int id = -99;
    if (parentItem->childCount()<1)
        position=0;

    beginInsertRows(parent, 0, rows - 1);
    success = parentItem->insertChildren(id, position, rows, rootItem->columnCount());
    endInsertRows();
    addetItms << parentItem->child(0);
    return success;
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = getItem(index);
    TreeItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->childNumber(), 0, parentItem);
}


bool TreeModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    TreeItem *parentItem = getItem(parent);
    bool success = true;
    delitedItms << parentItem->child(position)->id;
    delitedItms.append(parentItem->child(position)->allChildren());
    beginRemoveRows(parent, position, position + rows - 1);
    success = parentItem->removeChildren(position, rows);
    endRemoveRows();

    return success;
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem = getItem(parent);

    return parentItem->childCount();
}

bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    TreeItem *item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result)
        emit dataChanged(index, index, {role});

    return result;
}

bool TreeModel::setHeaderData(int section, Qt::Orientation orientation,
                              const QVariant &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal)
        return false;

    bool result = rootItem->setData(section, value);

    if (result)
        emit headerDataChanged(orientation, section, section);

    return result;
}

void TreeModel::revert(){
    QSqlQuery query;
    QString req;
    QString pool;
    if (!addetItms.isEmpty()){
        req = "insert into "+tName+" ( " + pColumnName;
        for (int j=0;j<rootItem->columnCount();j++){
            req = req + " , " + rootItem->data(j).toString();
        }
        req = req + " ) values ";
        pool ="( ?";
        for (int j=0;j<rootItem->columnCount();j++)
            pool = pool +", ?";
        pool = pool+ " )";
        for (int j=0; j<addetItms.size()-1;j++)
            req = req + pool + ", ";
        req = req + pool + " RETURNING  id";
        query.prepare(req);
        for (int i=0; i < addetItms.size();i++){
            query.addBindValue(addetItms[i]->parent()->id);
            for (int j = 0; j < addetItms[i]->columnCount();j++){
                setAsType(&query,addetItms[i]->data(j),dTypes[j]);
            }
        }
        if (!query.exec()){
            baseWarning(query.lastError().text());
        } else {
            int counter = 0;
            while (query.next()){
                addetItms[counter]->id = query.value(0).toInt();
            }
            addetItms.clear();
            QMessageBox::information(0,"Succses","Values inserted");
        }
    }
    if (!delitedItms.isEmpty()){
        req = "delete from "+tName+" where id in ( "+ QString::number(delitedItms[0]);
        for (int i =1; i<delitedItms.size();i++){
            req = req+ ", " + QString::number(delitedItms[i]);
        }
        req = req+ " )";
        if (!query.exec(req)){
            baseWarning(query.lastError().text());
        } else {
            delitedItms.clear();
            QMessageBox::information(0,"Succses","Values delited");
        }
    }

}

void TreeModel::setAsType(QSqlQuery * query,QVariant value, QString vType){
    if (vType == "23")
        query-> addBindValue(value.toInt());
    else
        query-> addBindValue(value.toString());
}

void TreeModel::setupModelData(QSqlQuery query, TreeItem *parent)
{

    parents.clear();
    addetItms.clear();
    updatedItms.clear();
    delitedItms.clear();
    QList<int> indentations;
    parents << parent;
    indentations << 0;


    while(query.next())
    {
        if (query.value(1).isNull()){
            rootItem->insertChildren(query.value(0).toInt(),rootItem->childCount(),1,rootItem->columnCount());
            for (int column = 0; column <rootItem->columnCount();column++){
                rootItem->child(rootItem->childCount() - 1)->setData(column, query.value(column+2).toString());
            }
            parents << rootItem->child(rootItem->childCount() - 1);
        }
        else {
            for (int i = parents.size()-1;i>0;i--){
                if (parents[i]->id ==query.value(1).toInt()){
                    parents[i]->insertChildren(query.value(0).toInt(),parents[i]->childCount(),1,parents[i]->columnCount());
                    for (int column = 0; column <parents[i]->columnCount();column++){
                        parents[i]->child(parents[i]->childCount() - 1)->setData(column, query.value(column+2).toString());
                    }
                    parents << parents[i]->child(parents[i]->childCount() - 1);
                    break;
                }
            }

        }
    }
}




