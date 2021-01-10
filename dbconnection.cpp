#include "dbconnection.h"

DbConnection::DbConnection()
{

}

//!
//    \fn DbConnection::Initialize()

//    \brief Constructs a vector with x and y coordinates from a 2D \a point, and a
//    z coordinate of 0.

/**
 * Sum numbers in a vector.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
int DbConnection::Initialize(){
    QSqlError err;
    QSqlDatabase _db;

    if(!QSqlDatabase::isDriverAvailable("QSQLITE")){
        emit Error("Driver not found!", "QSQLITE driver not found");
        return 0;
    }
    _db = QSqlDatabase::addDatabase("QSQLITE");
    m_db = &_db;
    m_db->setHostName("localhost");
    m_db->setDatabaseName("qpass.db");
    m_db->setUserName("aniket");
    m_db->setPassword("makeinindia");

    if (!m_db->open("aniket", "makeinindia")) {
        err = m_db->lastError();
        *m_db = QSqlDatabase();
        QSqlDatabase::removeDatabase("");
        if (err.type() != QSqlError::NoError)
            emit Error(tr("Unable to open database"), tr("Error: \n") + err.text());
        return 0;
    }
    // on successful database connectin, create tables
    CreateTables();
    return 1;
}

void DbConnection::DeInitialize(){
    QSqlDatabase::removeDatabase("");
}

void DbConnection::CreateTables(){
    // get available tables from database
    QStringList dbTables = m_db->tables();

    // find users table
    if (!dbTables.contains("users"))
        CreateTableUsers();
    // find accounts table
    if (!dbTables.contains("accounts"))
        CreateTableAccounts();
}

void DbConnection::CreateTableUsers(){
    emit Error(tr("User Table"), tr("Users table not available in database..\nCreating new..!"));
    QSqlQuery query;
    query.prepare("CREATE TABLE users ( "
              "user_id INTEGER PRIMARY KEY AUTOINCREMENT, "
              "FirstName TEXT NOT NULL, "
              "LastName TEXT NOT NULL, "
              "Pin TEXT NOT NULL);");
    query.exec();
}

void DbConnection::CreateTableAccounts(){
    emit Error(tr("Account Table"), tr("Accounts table not available in database..\nCreating new..!"));
    QSqlQuery query;
    query.prepare("CREATE TABLE accounts ( "
              "account_id INTEGER PRIMARY KEY AUTOINCREMENT, "
              "Provider TEXT NOT NULL, "
              "UserName TEXT NOT NULL, "
              "Password TEXT NOT NULL, "
              "Hint TEXT, "
              "CONSTRAINT UQ_ACCOUNT UNIQUE (Provider,UserName));");
    query.exec();
}

bool DbConnection::IsConnected(){
    return m_db->isOpen();
}

User DbConnection::GetUser(){
    //TODO: query to get user.
    User tempUser;
    QSqlQuery query("SELECT user_id, FirstName, LastName, Pin FROM users");
    while (query.next()) {
        tempUser._key       = query.value(0).toInt();
        tempUser.FirstName  = query.value(1).toString();
        tempUser.LastName   = query.value(2).toString();
        tempUser.Pin        = query.value(3).toString();
    }
    return tempUser;
}

QSqlError DbConnection::CreateUser(User NewUser){
    QSqlQuery query;
    query.prepare("INSERT INTO users (FirstName, LastName, Pin) "
                  "VALUES (?, ?, ?)");
    query.bindValue(0, NewUser.FirstName);
    query.bindValue(1, NewUser.LastName);
    query.bindValue(2, NewUser.Pin);
    query.exec();
    return query.lastError();
}

QSqlError DbConnection::SaveUser(User NewUser){
    QSqlQuery query;
    query.prepare("UPDATE users "
                  "SET "
                  "FirstName        = ?, "
                  "LastName         = ?, "
                  "Pin              = ? "
                  "WHERE user_id    = ?");

    query.bindValue(0, NewUser.FirstName);
    query.bindValue(1, NewUser.LastName);
    query.bindValue(2, NewUser.Pin);
    query.bindValue(3, NewUser._key);
    query.exec();
    return query.lastError();
}

QSqlError DbConnection::GetAccounts(QList<Account> *Accounts){
    Account tempAcc;
    Accounts->clear();

    QSqlQuery query("SELECT account_id, Provider, UserName, Password, Hint FROM accounts");
    while (query.next()) {
        tempAcc.PKey        = query.value(0).toInt();
        tempAcc.Provider    = query.value(1).toString();
        tempAcc.UserName    = query.value(2).toString();
        tempAcc.Password    = query.value(3).toString();
        tempAcc.Hint        = query.value(4).toString();
        Accounts->append(tempAcc);
    }
    return query.lastError();
}

QSqlError DbConnection::AddAccount(Account *NewAccount){
    QSqlQuery query;
    query.prepare("INSERT INTO accounts (Provider, UserName, Password, Hint) "
                  "VALUES (?, ?, ?, ?);");
    query.bindValue(0, NewAccount->Provider);
    query.bindValue(1, NewAccount->UserName);
    query.bindValue(2, NewAccount->Password);
    query.bindValue(3, NewAccount->Hint);
    query.exec();
    if(query.lastError().type() != QSqlError::NoError)
        return query.lastError();

    query.clear();
    query.prepare("SELECT account_id FROM accounts WHERE (Provider = ? AND UserName = ?);");
    query.bindValue(0, NewAccount->Provider);
    query.bindValue(1, NewAccount->UserName);
    query.exec();
    while (query.next()) {
        NewAccount->PKey = query.value(0).toInt();
    }
    return query.lastError();
}

QSqlError DbConnection::GetAccountKey(Account *Acc){
    QSqlQuery query;
    query.prepare("SELECT account_id FROM accounts WHERE (Provider = ? AND UserName = ?);");
    query.bindValue(0, Acc->Provider);
    query.bindValue(1, Acc->UserName);
    query.exec();
    while (query.next()) {
        Acc->PKey = query.value(0).toInt();
    }
    return query.lastError();
}

QSqlError DbConnection::GetAccountFromKey(Account *Acc){
    QSqlQuery query;
    query.prepare("SELECT account_id, Provider, UserName, Password, Hint FROM accounts WHERE (account_id = ?);");
    query.bindValue(0, Acc->PKey);
    query.exec();
    while (query.next()) {
        Acc->PKey        = query.value(0).toInt();
        Acc->Provider    = query.value(1).toString();
        Acc->UserName    = query.value(2).toString();
        Acc->Password    = query.value(3).toString();
        Acc->Hint        = query.value(4).toString();
    }
    return query.lastError();
}

QSqlError DbConnection::DeleteAccount(Account *Acc){
    QSqlQuery query;
    query.prepare("DELETE FROM accounts WHERE (account_id = ?);");
    query.bindValue(0, Acc->PKey);
    query.exec();
    return query.lastError();
}

QSqlError DbConnection::EditAccount(Account *Acc){
    QSqlQuery query;
    query.prepare("UPDATE accounts "
                  "SET "
                  "Provider = ?, "
                  "UserName = ?, "
                  "Password = ?, "
                  "Hint     = ? "
                  "WHERE account_id = ?");

    query.bindValue(0, Acc->Provider);
    query.bindValue(1, Acc->UserName);
    query.bindValue(2, Acc->Password);
    query.bindValue(3, Acc->Hint);
    query.bindValue(4, Acc->PKey);
    query.exec();
    return query.lastError();
}
