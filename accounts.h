#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <QWidget>
#include <QMainWindow>
#include <QString>
#include <QList>

#include "mainwindow.h"
#include "dbconnection.h"

namespace Ui {
class Accounts;
}

class Accounts : public QWidget
{
    Q_OBJECT

public:
    explicit Accounts(QMainWindow *parent = nullptr, DbConnection *DBRef = nullptr);
    ~Accounts();

private:
    Ui::Accounts *ui;
    DbConnection *m_DbRef;

    void InitializeUI();
    void InitializeConnections();

    bool ValidateAccount(Account NewAcc);


private slots:
    void OnItemSelected();

    void OnNew();
    void OnNewCancelled();
    void OnNewSave();

    void OnEdit();
    void OnEditCancelled();
    void OnEditSave();

    void OnDelete();

signals:
    void Error(QString ErrHeader, QString ErrorInfo);
    void SetWidget(QWidget *Widget);
    void SetHeader(QString HeaderName);
};

#define PAGE_ACCOUNTS   0
#define PAGE_ACCOUNT    1
#endif // ACCOUNTS_H
