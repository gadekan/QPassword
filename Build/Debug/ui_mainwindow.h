/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *Wid_Central;
    QVBoxLayout *verticalLayout;
    QLabel *Lbl_UiHeader;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(499, 537);
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setIconSize(QSize(30, 30));
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockNestingEnabled(false);
        Wid_Central = new QWidget(MainWindow);
        Wid_Central->setObjectName(QString::fromUtf8("Wid_Central"));
        verticalLayout = new QVBoxLayout(Wid_Central);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Lbl_UiHeader = new QLabel(Wid_Central);
        Lbl_UiHeader->setObjectName(QString::fromUtf8("Lbl_UiHeader"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Lbl_UiHeader->sizePolicy().hasHeightForWidth());
        Lbl_UiHeader->setSizePolicy(sizePolicy);
        Lbl_UiHeader->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Lbl_UiHeader);

        MainWindow->setCentralWidget(Wid_Central);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QPassword", nullptr));
        Lbl_UiHeader->setText(QApplication::translate("MainWindow", "UI Header", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
