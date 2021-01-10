/********************************************************************************
** Form generated from reading UI file 'accounts.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTS_H
#define UI_ACCOUNTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Accounts
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_Accs;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tbl_Accs;
    QWidget *page_Acc;
    QFormLayout *formLayout;
    QLabel *lbl_Provider;
    QLineEdit *line_Provider;
    QLabel *lbl_UserID;
    QLineEdit *line_UserID;
    QLabel *lbl_Pass;
    QLineEdit *line_Pass;
    QLabel *lbl_Hint;
    QLineEdit *line_Hint;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_New;
    QPushButton *btn_Edit;
    QPushButton *btn_Delete;
    QPushButton *btn_Save;
    QPushButton *btn_Cancel;

    void setupUi(QWidget *Accounts)
    {
        if (Accounts->objectName().isEmpty())
            Accounts->setObjectName(QString::fromUtf8("Accounts"));
        Accounts->resize(425, 300);
        verticalLayout = new QVBoxLayout(Accounts);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(Accounts);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_Accs = new QWidget();
        page_Accs->setObjectName(QString::fromUtf8("page_Accs"));
        verticalLayout_2 = new QVBoxLayout(page_Accs);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tbl_Accs = new QTableWidget(page_Accs);
        if (tbl_Accs->columnCount() < 3)
            tbl_Accs->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tbl_Accs->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tbl_Accs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tbl_Accs->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tbl_Accs->setObjectName(QString::fromUtf8("tbl_Accs"));
        tbl_Accs->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl_Accs->setAlternatingRowColors(false);
        tbl_Accs->setSelectionMode(QAbstractItemView::SingleSelection);
        tbl_Accs->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(tbl_Accs);

        stackedWidget->addWidget(page_Accs);
        page_Acc = new QWidget();
        page_Acc->setObjectName(QString::fromUtf8("page_Acc"));
        formLayout = new QFormLayout(page_Acc);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lbl_Provider = new QLabel(page_Acc);
        lbl_Provider->setObjectName(QString::fromUtf8("lbl_Provider"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lbl_Provider);

        line_Provider = new QLineEdit(page_Acc);
        line_Provider->setObjectName(QString::fromUtf8("line_Provider"));
        line_Provider->setClearButtonEnabled(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, line_Provider);

        lbl_UserID = new QLabel(page_Acc);
        lbl_UserID->setObjectName(QString::fromUtf8("lbl_UserID"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lbl_UserID);

        line_UserID = new QLineEdit(page_Acc);
        line_UserID->setObjectName(QString::fromUtf8("line_UserID"));
        line_UserID->setClearButtonEnabled(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, line_UserID);

        lbl_Pass = new QLabel(page_Acc);
        lbl_Pass->setObjectName(QString::fromUtf8("lbl_Pass"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lbl_Pass);

        line_Pass = new QLineEdit(page_Acc);
        line_Pass->setObjectName(QString::fromUtf8("line_Pass"));
        line_Pass->setClearButtonEnabled(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, line_Pass);

        lbl_Hint = new QLabel(page_Acc);
        lbl_Hint->setObjectName(QString::fromUtf8("lbl_Hint"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lbl_Hint);

        line_Hint = new QLineEdit(page_Acc);
        line_Hint->setObjectName(QString::fromUtf8("line_Hint"));
        line_Hint->setClearButtonEnabled(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, line_Hint);

        stackedWidget->addWidget(page_Acc);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_New = new QPushButton(Accounts);
        btn_New->setObjectName(QString::fromUtf8("btn_New"));

        horizontalLayout->addWidget(btn_New);

        btn_Edit = new QPushButton(Accounts);
        btn_Edit->setObjectName(QString::fromUtf8("btn_Edit"));

        horizontalLayout->addWidget(btn_Edit);

        btn_Delete = new QPushButton(Accounts);
        btn_Delete->setObjectName(QString::fromUtf8("btn_Delete"));

        horizontalLayout->addWidget(btn_Delete);

        btn_Save = new QPushButton(Accounts);
        btn_Save->setObjectName(QString::fromUtf8("btn_Save"));

        horizontalLayout->addWidget(btn_Save);

        btn_Cancel = new QPushButton(Accounts);
        btn_Cancel->setObjectName(QString::fromUtf8("btn_Cancel"));
        btn_Cancel->setEnabled(true);

        horizontalLayout->addWidget(btn_Cancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Accounts);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Accounts);
    } // setupUi

    void retranslateUi(QWidget *Accounts)
    {
        Accounts->setWindowTitle(QApplication::translate("Accounts", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbl_Accs->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Accounts", "Acc ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl_Accs->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Accounts", "Website", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl_Accs->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Accounts", "User Name", nullptr));
        lbl_Provider->setText(QApplication::translate("Accounts", "Provider :", nullptr));
        lbl_UserID->setText(QApplication::translate("Accounts", "User ID :", nullptr));
        lbl_Pass->setText(QApplication::translate("Accounts", "Password :", nullptr));
        lbl_Hint->setText(QApplication::translate("Accounts", "Hint :", nullptr));
        btn_New->setText(QApplication::translate("Accounts", "New", nullptr));
        btn_Edit->setText(QApplication::translate("Accounts", "Edit", nullptr));
        btn_Delete->setText(QApplication::translate("Accounts", "Delete", nullptr));
        btn_Save->setText(QApplication::translate("Accounts", "Save", nullptr));
        btn_Cancel->setText(QApplication::translate("Accounts", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Accounts: public Ui_Accounts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTS_H
