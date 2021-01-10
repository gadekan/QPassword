#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QObject>
#include <QDebug>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QList>

typedef struct {
    int _key;
    QString FirstName;
    QString LastName;
    QString Pin;
}User;

typedef struct {
    int PKey;
    QString Provider;
    QString UserName;
    QString Password;
    QString Hint;
}Account;

class DbConnection : public QObject
{
    Q_OBJECT
public:
    DbConnection();
    int Initialize();
    void DeInitialize();
    bool IsConnected();

    User GetUser();
    QSqlError CreateUser(User NewUser);
    QSqlError SaveUser(User NewUser);

    QSqlError GetAccounts(QList<Account> *Accounts);
    QSqlError GetAccountFromKey(Account *Acc);
    QSqlError AddAccount(Account *NewAccount);
    QSqlError GetAccountKey(Account *Acc);
    QSqlError DeleteAccount(Account *Acc);
    QSqlError EditAccount(Account *Acc);


private:
    QSqlDatabase *m_db;
    void CreateTables();
    void CreateTableUsers();
    void CreateTableAccounts();

signals:
    void Error(QString ErrHeader, QString ErrorInfo);
};

#endif // DBCONNECTION_H
