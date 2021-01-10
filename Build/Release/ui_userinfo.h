/********************************************************************************
** Form generated from reading UI file 'userinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_H
#define UI_USERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInfo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbl_FirstName;
    QLineEdit *line_FirstName;
    QLabel *lbl_LastName;
    QLineEdit *line_LastName;
    QLabel *lbl_Pin;
    QLineEdit *line_Pin;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_Create;
    QPushButton *btn_Edit;

    void setupUi(QWidget *UserInfo)
    {
        if (UserInfo->objectName().isEmpty())
            UserInfo->setObjectName(QString::fromUtf8("UserInfo"));
        UserInfo->resize(400, 300);
        verticalLayout = new QVBoxLayout(UserInfo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbl_FirstName = new QLabel(UserInfo);
        lbl_FirstName->setObjectName(QString::fromUtf8("lbl_FirstName"));

        verticalLayout->addWidget(lbl_FirstName);

        line_FirstName = new QLineEdit(UserInfo);
        line_FirstName->setObjectName(QString::fromUtf8("line_FirstName"));

        verticalLayout->addWidget(line_FirstName);

        lbl_LastName = new QLabel(UserInfo);
        lbl_LastName->setObjectName(QString::fromUtf8("lbl_LastName"));

        verticalLayout->addWidget(lbl_LastName);

        line_LastName = new QLineEdit(UserInfo);
        line_LastName->setObjectName(QString::fromUtf8("line_LastName"));

        verticalLayout->addWidget(line_LastName);

        lbl_Pin = new QLabel(UserInfo);
        lbl_Pin->setObjectName(QString::fromUtf8("lbl_Pin"));

        verticalLayout->addWidget(lbl_Pin);

        line_Pin = new QLineEdit(UserInfo);
        line_Pin->setObjectName(QString::fromUtf8("line_Pin"));
        line_Pin->setMaxLength(6);
        line_Pin->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(line_Pin);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(UserInfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/logo_qt.png")));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label = new QLabel(UserInfo);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFrameShape(QFrame::StyledPanel);
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/logo_sqlite.png")));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_Create = new QPushButton(UserInfo);
        btn_Create->setObjectName(QString::fromUtf8("btn_Create"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_Create->sizePolicy().hasHeightForWidth());
        btn_Create->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(btn_Create);

        btn_Edit = new QPushButton(UserInfo);
        btn_Edit->setObjectName(QString::fromUtf8("btn_Edit"));

        verticalLayout->addWidget(btn_Edit);


        retranslateUi(UserInfo);

        QMetaObject::connectSlotsByName(UserInfo);
    } // setupUi

    void retranslateUi(QWidget *UserInfo)
    {
        UserInfo->setWindowTitle(QApplication::translate("UserInfo", "Form", nullptr));
        lbl_FirstName->setText(QApplication::translate("UserInfo", "First Name:", nullptr));
        lbl_LastName->setText(QApplication::translate("UserInfo", "Last Name:", nullptr));
        lbl_Pin->setText(QApplication::translate("UserInfo", "Pin:", nullptr));
        line_Pin->setText(QString());
        label_2->setText(QString());
        label->setText(QString());
        btn_Create->setText(QApplication::translate("UserInfo", "Create", nullptr));
        btn_Edit->setText(QApplication::translate("UserInfo", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInfo: public Ui_UserInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_H
