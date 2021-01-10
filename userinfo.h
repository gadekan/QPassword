#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include <QMainWindow>
#include <QString>

#include "mainwindow.h"
#include "dbconnection.h"

namespace Ui {
class UserInfo;
}

class UserInfo : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfo(QMainWindow *parent = nullptr, DbConnection *DBRef = nullptr);
    ~UserInfo();

private:
    Ui::UserInfo *ui;
    DbConnection *m_DbRef;
    int m_UserKey = -1;
    QString m_Pin = "";

    void InitializeUI();
    void InitializeConnections();
    void LoadUser();
    bool ValidateUserInput();

private slots:
    void OnCreateUser();
    void OnLoginUser();
    void OnEditUser();
    void OnEditCancel();
    void OnSaveUser();

    void OnAccounts();

signals:
    void Error(QString ErrHeader, QString ErrorInfo);
    void SetWidget(QWidget *Widget);
    void SetHeader(QString HeaderName);

    void Signal_ShowAccounts();

};

#endif // USERINFO_H
