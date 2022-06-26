#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QtSql>
#include "treeitem.h"


class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    TreeModel(const QStringList &headers,QStringList types, QSqlQuery query,QString name,
              QObject *parent = 0);
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    bool setHeaderData(int section, Qt::Orientation orientation,
                       const QVariant &value, int role = Qt::EditRole) override;

//    bool insertColumns(int position, int columns,
//                       const QModelIndex &parent = QModelIndex()) override;
    bool insertRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex()) override;

    TreeItem* item(const QModelIndex index);

    void revert() override;

    void filtredData();


private:
    void setupModelData(QSqlQuery query, TreeItem *parent);

    void setAsType(QSqlQuery * query,QVariant value, QString vType);
    TreeItem *getItem(const QModelIndex &index) const;
    TreeItem *rootItem;

    QString tName;
    QString pColumnName = "parent_id";
    QStringList dTypes;

    QList<TreeItem*> parents;
    QList<TreeItem*> addetItms;
    QList<TreeItem*> updatedItms;
    QList<int> delitedItms;
};

//class TreeModel : public QAbstractItemModel
//{
//    Q_OBJECT

//public:
//    TreeModel(const QStringList &headers, const QString &data,
//              QObject *parent = nullptr);
//    ~TreeModel();
//    QVariant data(const QModelIndex &index, int role) const override;
//    QVariant headerData(int section, Qt::Orientation orientation,
//                       int role = Qt::DisplayRole) const override;

//    QModelIndex index(int row, int column,
//                     const QModelIndex &parent = QModelIndex()) const override;
//    QModelIndex parent(const QModelIndex &index) const override;


//    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
//    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
//    Qt::ItemFlags flags(const QModelIndex &index) const override;
//    bool setData(const QModelIndex &index, const QVariant &value,
//               int role = Qt::EditRole) override;
//    bool setHeaderData(int section, Qt::Orientation orientation,
//                     const QVariant &value, int role = Qt::EditRole) override;

//    bool insertColumns(int position, int columns,
//                     const QModelIndex &parent = QModelIndex()) override;
//    bool removeColumns(int position, int columns,
//                     const QModelIndex &parent = QModelIndex()) override;
//    bool insertRows(int position, int rows,
//                  const QModelIndex &parent = QModelIndex()) override;
//    bool removeRows(int position, int rows,
//                  const QModelIndex &parent = QModelIndex()) override;

//  private:
//      void setupModelData(const QStringList &lines, TreeItem *parent);
//      TreeItem *getItem(const QModelIndex &index) const;

//      TreeItem *rootItem;
//  };


//public:
//    explicit TreeModel(QObject *parent = nullptr);

//    // Header:
//    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

//    // Basic functionality:
//    QModelIndex index(int row, int column,
//                      const QModelIndex &parent = QModelIndex()) const override;
//    QModelIndex parent(const QModelIndex &index) const override;

//    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
//    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

//    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

//private:
//};

#endif // TREEMODEL_H
