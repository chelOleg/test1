/********************************************************************************
** Form generated from reading UI file 'addval.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDVAL_H
#define UI_ADDVAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddVal
{
public:
    QGridLayout *gridLayout;
    QLabel *Lbl5;
    QLineEdit *edLn1;
    QDialogButtonBox *buttonBox;
    QLineEdit *edLn4;
    QLineEdit *edLn3;
    QLabel *Lbl1;
    QLabel *Lbl4;
    QLabel *Lbl3;
    QLabel *Lbl2;
    QLabel *Lbl6;
    QLineEdit *edLn5;
    QLineEdit *edLn6;
    QLineEdit *edLn2;

    void setupUi(QDialog *AddVal)
    {
        if (AddVal->objectName().isEmpty())
            AddVal->setObjectName(QString::fromUtf8("AddVal"));
        AddVal->resize(368, 249);
        gridLayout = new QGridLayout(AddVal);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Lbl5 = new QLabel(AddVal);
        Lbl5->setObjectName(QString::fromUtf8("Lbl5"));

        gridLayout->addWidget(Lbl5, 5, 0, 1, 1);

        edLn1 = new QLineEdit(AddVal);
        edLn1->setObjectName(QString::fromUtf8("edLn1"));
        edLn1->setEnabled(false);

        gridLayout->addWidget(edLn1, 0, 2, 1, 1);

        buttonBox = new QDialogButtonBox(AddVal);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 7, 2, 1, 1);

        edLn4 = new QLineEdit(AddVal);
        edLn4->setObjectName(QString::fromUtf8("edLn4"));
        edLn4->setEnabled(false);

        gridLayout->addWidget(edLn4, 4, 2, 1, 1);

        edLn3 = new QLineEdit(AddVal);
        edLn3->setObjectName(QString::fromUtf8("edLn3"));
        edLn3->setEnabled(false);

        gridLayout->addWidget(edLn3, 2, 2, 1, 1);

        Lbl1 = new QLabel(AddVal);
        Lbl1->setObjectName(QString::fromUtf8("Lbl1"));

        gridLayout->addWidget(Lbl1, 0, 0, 1, 1);

        Lbl4 = new QLabel(AddVal);
        Lbl4->setObjectName(QString::fromUtf8("Lbl4"));

        gridLayout->addWidget(Lbl4, 4, 0, 1, 1);

        Lbl3 = new QLabel(AddVal);
        Lbl3->setObjectName(QString::fromUtf8("Lbl3"));

        gridLayout->addWidget(Lbl3, 2, 0, 1, 1);

        Lbl2 = new QLabel(AddVal);
        Lbl2->setObjectName(QString::fromUtf8("Lbl2"));

        gridLayout->addWidget(Lbl2, 1, 0, 1, 1);

        Lbl6 = new QLabel(AddVal);
        Lbl6->setObjectName(QString::fromUtf8("Lbl6"));

        gridLayout->addWidget(Lbl6, 6, 0, 1, 1);

        edLn5 = new QLineEdit(AddVal);
        edLn5->setObjectName(QString::fromUtf8("edLn5"));
        edLn5->setEnabled(false);

        gridLayout->addWidget(edLn5, 5, 2, 1, 1);

        edLn6 = new QLineEdit(AddVal);
        edLn6->setObjectName(QString::fromUtf8("edLn6"));
        edLn6->setEnabled(false);

        gridLayout->addWidget(edLn6, 6, 2, 1, 1);

        edLn2 = new QLineEdit(AddVal);
        edLn2->setObjectName(QString::fromUtf8("edLn2"));
        edLn2->setEnabled(false);

        gridLayout->addWidget(edLn2, 1, 2, 1, 1);


        retranslateUi(AddVal);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddVal, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddVal, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddVal);
    } // setupUi

    void retranslateUi(QDialog *AddVal)
    {
        AddVal->setWindowTitle(QApplication::translate("AddVal", "Dialog", nullptr));
        Lbl5->setText(QApplication::translate("AddVal", "title", nullptr));
        Lbl1->setText(QApplication::translate("AddVal", "title", nullptr));
        Lbl4->setText(QApplication::translate("AddVal", "title", nullptr));
        Lbl3->setText(QApplication::translate("AddVal", "title", nullptr));
        Lbl2->setText(QApplication::translate("AddVal", "title", nullptr));
        Lbl6->setText(QApplication::translate("AddVal", "title", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddVal: public Ui_AddVal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDVAL_H
