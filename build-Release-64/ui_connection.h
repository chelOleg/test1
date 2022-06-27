/********************************************************************************
** Form generated from reading UI file 'connection.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTION_H
#define UI_CONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_connection
{
public:
    QFormLayout *formLayout;
    QDialogButtonBox *buttonBox;
    QLineEdit *hostLn;
    QLineEdit *baseLn;
    QLineEdit *logLn;
    QLineEdit *passLn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *portLn;

    void setupUi(QDialog *connection)
    {
        if (connection->objectName().isEmpty())
            connection->setObjectName(QString::fromUtf8("connection"));
        connection->resize(326, 204);
        formLayout = new QFormLayout(connection);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        buttonBox = new QDialogButtonBox(connection);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(5, QFormLayout::FieldRole, buttonBox);

        hostLn = new QLineEdit(connection);
        hostLn->setObjectName(QString::fromUtf8("hostLn"));

        formLayout->setWidget(0, QFormLayout::FieldRole, hostLn);

        baseLn = new QLineEdit(connection);
        baseLn->setObjectName(QString::fromUtf8("baseLn"));

        formLayout->setWidget(2, QFormLayout::FieldRole, baseLn);

        logLn = new QLineEdit(connection);
        logLn->setObjectName(QString::fromUtf8("logLn"));

        formLayout->setWidget(3, QFormLayout::FieldRole, logLn);

        passLn = new QLineEdit(connection);
        passLn->setObjectName(QString::fromUtf8("passLn"));
        passLn->setEnabled(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, passLn);

        label = new QLabel(connection);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label);

        label_2 = new QLabel(connection);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(connection);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(connection);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(connection);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        portLn = new QLineEdit(connection);
        portLn->setObjectName(QString::fromUtf8("portLn"));

        formLayout->setWidget(1, QFormLayout::FieldRole, portLn);


        retranslateUi(connection);
        QObject::connect(buttonBox, SIGNAL(accepted()), connection, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), connection, SLOT(reject()));

        QMetaObject::connectSlotsByName(connection);
    } // setupUi

    void retranslateUi(QDialog *connection)
    {
        connection->setWindowTitle(QApplication::translate("connection", "Connection window", nullptr));
        hostLn->setText(QApplication::translate("connection", "127.0.0.1", nullptr));
        baseLn->setText(QApplication::translate("connection", "testdb", nullptr));
        logLn->setText(QApplication::translate("connection", "sampleuser", nullptr));
        passLn->setText(QApplication::translate("connection", "password", nullptr));
        label->setText(QApplication::translate("connection", "password", nullptr));
        label_2->setText(QApplication::translate("connection", "login", nullptr));
        label_3->setText(QApplication::translate("connection", "base", nullptr));
        label_4->setText(QApplication::translate("connection", "host", nullptr));
        label_5->setText(QApplication::translate("connection", "port", nullptr));
        portLn->setText(QApplication::translate("connection", "5432", nullptr));
    } // retranslateUi

};

namespace Ui {
    class connection: public Ui_connection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTION_H
