/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *opnBtn;
    QPushButton *addBtn;
    QLabel *label;
    QLineEdit *tNameEdt;
    QPushButton *cnctBtn;
    QTableView *tableView;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *connChck;
    QPushButton *treeShwBtn;
    QPushButton *treeAddBtn;
    QPushButton *treeDelBtn;
    QLabel *label_2;
    QLineEdit *treeNameEdt;
    QPushButton *pushBtn;
    QTreeView *MtreeView;
    QHBoxLayout *horizontalLayout;
    QLineEdit *fltEdit1;
    QLineEdit *fltEdit2;
    QLineEdit *fltEdit3;
    QLineEdit *fltEdit4;
    QLineEdit *fltEdit5;
    QLineEdit *fltEdit6;
    QPushButton *fltrBtn;
    QPushButton *exitBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(748, 413);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        opnBtn = new QPushButton(centralwidget);
        opnBtn->setObjectName(QString::fromUtf8("opnBtn"));
        opnBtn->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(opnBtn->sizePolicy().hasHeightForWidth());
        opnBtn->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(opnBtn, 0, 0, 1, 1);

        addBtn = new QPushButton(centralwidget);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setEnabled(false);
        sizePolicy1.setHeightForWidth(addBtn->sizePolicy().hasHeightForWidth());
        addBtn->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(addBtn, 0, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 3, 1, 1);

        tNameEdt = new QLineEdit(centralwidget);
        tNameEdt->setObjectName(QString::fromUtf8("tNameEdt"));

        gridLayout->addWidget(tNameEdt, 0, 4, 1, 1);

        cnctBtn = new QPushButton(centralwidget);
        cnctBtn->setObjectName(QString::fromUtf8("cnctBtn"));
        sizePolicy1.setHeightForWidth(cnctBtn->sizePolicy().hasHeightForWidth());
        cnctBtn->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(cnctBtn, 0, 5, 1, 1);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMaximumSize(QSize(16777215, 192));

        gridLayout->addWidget(tableView, 1, 0, 3, 5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 5, 1, 1);

        connChck = new QCheckBox(centralwidget);
        connChck->setObjectName(QString::fromUtf8("connChck"));
        connChck->setEnabled(false);
        sizePolicy1.setHeightForWidth(connChck->sizePolicy().hasHeightForWidth());
        connChck->setSizePolicy(sizePolicy1);
        connChck->setMouseTracking(false);
        connChck->setCheckable(true);

        gridLayout->addWidget(connChck, 3, 5, 1, 1);

        treeShwBtn = new QPushButton(centralwidget);
        treeShwBtn->setObjectName(QString::fromUtf8("treeShwBtn"));
        treeShwBtn->setEnabled(false);
        sizePolicy1.setHeightForWidth(treeShwBtn->sizePolicy().hasHeightForWidth());
        treeShwBtn->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(treeShwBtn, 4, 0, 1, 1);

        treeAddBtn = new QPushButton(centralwidget);
        treeAddBtn->setObjectName(QString::fromUtf8("treeAddBtn"));
        treeAddBtn->setEnabled(false);
        sizePolicy1.setHeightForWidth(treeAddBtn->sizePolicy().hasHeightForWidth());
        treeAddBtn->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(treeAddBtn, 4, 1, 1, 1);

        treeDelBtn = new QPushButton(centralwidget);
        treeDelBtn->setObjectName(QString::fromUtf8("treeDelBtn"));
        treeDelBtn->setEnabled(false);
        sizePolicy1.setHeightForWidth(treeDelBtn->sizePolicy().hasHeightForWidth());
        treeDelBtn->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(treeDelBtn, 4, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 3, 1, 1);

        treeNameEdt = new QLineEdit(centralwidget);
        treeNameEdt->setObjectName(QString::fromUtf8("treeNameEdt"));

        gridLayout->addWidget(treeNameEdt, 4, 4, 1, 1);

        pushBtn = new QPushButton(centralwidget);
        pushBtn->setObjectName(QString::fromUtf8("pushBtn"));
        pushBtn->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushBtn->sizePolicy().hasHeightForWidth());
        pushBtn->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushBtn, 4, 5, 1, 1);

        MtreeView = new QTreeView(centralwidget);
        MtreeView->setObjectName(QString::fromUtf8("MtreeView"));
        MtreeView->setMinimumSize(QSize(0, 71));

        gridLayout->addWidget(MtreeView, 5, 0, 1, 5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fltEdit1 = new QLineEdit(centralwidget);
        fltEdit1->setObjectName(QString::fromUtf8("fltEdit1"));
        fltEdit1->setMaximumSize(QSize(400, 16777215));

        horizontalLayout->addWidget(fltEdit1);

        fltEdit2 = new QLineEdit(centralwidget);
        fltEdit2->setObjectName(QString::fromUtf8("fltEdit2"));
        fltEdit2->setMaximumSize(QSize(400, 16777215));

        horizontalLayout->addWidget(fltEdit2);

        fltEdit3 = new QLineEdit(centralwidget);
        fltEdit3->setObjectName(QString::fromUtf8("fltEdit3"));
        fltEdit3->setMaximumSize(QSize(400, 16777215));

        horizontalLayout->addWidget(fltEdit3);

        fltEdit4 = new QLineEdit(centralwidget);
        fltEdit4->setObjectName(QString::fromUtf8("fltEdit4"));
        fltEdit4->setMaximumSize(QSize(400, 16777215));

        horizontalLayout->addWidget(fltEdit4);

        fltEdit5 = new QLineEdit(centralwidget);
        fltEdit5->setObjectName(QString::fromUtf8("fltEdit5"));
        fltEdit5->setMaximumSize(QSize(400, 16777215));

        horizontalLayout->addWidget(fltEdit5);

        fltEdit6 = new QLineEdit(centralwidget);
        fltEdit6->setObjectName(QString::fromUtf8("fltEdit6"));
        fltEdit6->setMaximumSize(QSize(400, 16777215));

        horizontalLayout->addWidget(fltEdit6);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 5);

        fltrBtn = new QPushButton(centralwidget);
        fltrBtn->setObjectName(QString::fromUtf8("fltrBtn"));
        fltrBtn->setEnabled(false);
        sizePolicy1.setHeightForWidth(fltrBtn->sizePolicy().hasHeightForWidth());
        fltrBtn->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(fltrBtn, 6, 5, 1, 1);

        exitBtn = new QPushButton(centralwidget);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));
        sizePolicy1.setHeightForWidth(exitBtn->sizePolicy().hasHeightForWidth());
        exitBtn->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(exitBtn, 7, 5, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 748, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        opnBtn->setText(QApplication::translate("MainWindow", "Show table", nullptr));
        addBtn->setText(QApplication::translate("MainWindow", "Add", nullptr));
        label->setText(QApplication::translate("MainWindow", "Table name", nullptr));
        cnctBtn->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        connChck->setText(QApplication::translate("MainWindow", "Connected", nullptr));
        treeShwBtn->setText(QApplication::translate("MainWindow", "Show", nullptr));
        treeAddBtn->setText(QApplication::translate("MainWindow", "Add", nullptr));
        treeDelBtn->setText(QApplication::translate("MainWindow", "Del", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Tree name", nullptr));
        pushBtn->setText(QApplication::translate("MainWindow", "Push data", nullptr));
        fltrBtn->setText(QApplication::translate("MainWindow", "Filter", nullptr));
        exitBtn->setText(QApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
