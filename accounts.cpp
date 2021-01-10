#include "accounts.h"
#include "ui_accounts.h"

Accounts::Accounts(QMainWindow *parent, DbConnection *DBRef) :
    QWidget(parent),
    ui(new Ui::Accounts)
{
    m_DbRef = DBRef;
    ui->setupUi(this);
    InitializeConnections();
    InitializeUI();

    this->setFont(parent->font());
    ui->tbl_Accs->setFont(parent->font());
    emit SetHeader("User Accounts");
    emit SetWidget(this);
}

Accounts::~Accounts()
{
    delete ui;
}

void Accounts::InitializeConnections(){
    QObject::connect(this, SIGNAL(Error(QString, QString)), parent(), SLOT(OnError(QString, QString)));
    QObject::connect(this, SIGNAL(SetWidget(QWidget *)),    parent(), SLOT(OnSetWidget(QWidget *)));
    QObject::connect(this, SIGNAL(SetHeader(QString)),      parent(), SLOT(OnSetHeader(QString)));

    QObject::connect(ui->tbl_Accs,      SIGNAL(itemSelectionChanged()), this, SLOT(OnItemSelected()));
    QObject::connect(ui->btn_New,       SIGNAL(clicked()), this, SLOT(OnNew()));
    QObject::connect(ui->btn_Delete,    SIGNAL(clicked()), this, SLOT(OnDelete()));
    QObject::connect(ui->btn_Edit,      SIGNAL(clicked()), this, SLOT(OnEdit()));
}

void Accounts::InitializeUI(){
    ui->stackedWidget->setCurrentIndex(PAGE_ACCOUNTS);

    ui->btn_New->show();
    ui->btn_Edit->hide();
    ui->btn_Delete->hide();
    ui->btn_Save->hide();
    ui->btn_Cancel->hide();

    ui->tbl_Accs->clearContents();

    QList<Account> TempAccs;
    QSqlError err = m_DbRef->GetAccounts(&TempAccs);
    if(err.type() != QSqlError::NoError){
        emit Error(tr("Accounts"), tr("Error: \n") + err.text());
        return;
    }

    ui->tbl_Accs->setRowCount(TempAccs.size());
    Account TempAcc;
    for(int row = 0; row < TempAccs.size(); row++) {
        QTableWidgetItem *newItem;
        newItem = new QTableWidgetItem(QString::number(TempAccs[row].PKey));
        ui->tbl_Accs->setItem(row, 0, newItem);

        newItem = new QTableWidgetItem(TempAccs[row].Provider);
        ui->tbl_Accs->setItem(row, 1, newItem);

        newItem = new QTableWidgetItem(TempAccs[row].UserName);
        ui->tbl_Accs->setItem(row, 2, newItem);
    }
    ui->tbl_Accs->setColumnHidden(0, true);
    ui->tbl_Accs->selectRow(0);
}

void Accounts::OnItemSelected(){
    int CurrRow = ui->tbl_Accs->currentRow();
    if(CurrRow >= 0){
        ui->btn_Edit->show();
        ui->btn_Delete->show();
    }
    else{
        ui->btn_Edit->hide();
        ui->btn_Delete->hide();
    }
}

void Accounts::OnNew(){
    emit SetHeader("New");
    ui->stackedWidget->setCurrentIndex(PAGE_ACCOUNT);

    ui->btn_New->hide();
    ui->btn_Edit->hide();
    ui->btn_Delete->hide();

    ui->line_Provider->clear();
    ui->line_UserID->clear();
    ui->line_Pass->clear();
    ui->line_Hint->clear();

    ui->btn_Save->show();
    QObject::connect(ui->btn_Save,      SIGNAL(clicked()),this, SLOT(OnNewSave()));

    ui->btn_Cancel->show();
    QObject::connect(ui->btn_Cancel,    SIGNAL(clicked()),this, SLOT(OnNewCancelled()));
}

void Accounts::OnNewCancelled(){
    emit SetHeader("User Accounts");
    ui->stackedWidget->setCurrentIndex(PAGE_ACCOUNTS);

    ui->btn_New->show();
    OnItemSelected();

    ui->btn_Save->hide();
    QObject::disconnect(ui->btn_Save,   SIGNAL(clicked()),this, SLOT(OnNewSave()));

    ui->btn_Cancel->hide();
    QObject::disconnect(ui->btn_Cancel, SIGNAL(clicked()),this, SLOT(OnNewCancelled()));
}

void Accounts::OnNewSave(){
    Account NewAcc;
    NewAcc.Provider = ui->line_Provider->text();
    NewAcc.UserName = ui->line_UserID->text();
    NewAcc.Password = ui->line_Pass->text();
    NewAcc.Hint     = ui->line_Hint->text();

    if(!ValidateAccount(NewAcc)){
        return;
    }

    QSqlError err;
    err = m_DbRef->AddAccount(&NewAcc);
    if(err.type() != QSqlError::NoError){
        emit Error(tr("New"), tr("Error: \n") + err.text());
        return;
    }

    int row = ui->tbl_Accs->rowCount();
    ui->tbl_Accs->setRowCount(row + 1);
    QTableWidgetItem *newItem;
    newItem = new QTableWidgetItem(QString::number(NewAcc.PKey));
    ui->tbl_Accs->setItem(row, 0, newItem);

    newItem = new QTableWidgetItem(NewAcc.Provider);
    ui->tbl_Accs->setItem(row, 1, newItem);

    newItem = new QTableWidgetItem(NewAcc.UserName);
    ui->tbl_Accs->setItem(row, 2, newItem);
}

bool Accounts::ValidateAccount(Account NewAcc){
    if(NewAcc.Provider == ""){
        emit Error(tr("Account"), tr("Please enter Provider..!"));
        return false;
    }

    if(NewAcc.UserName == ""){
        emit Error(tr("Account"), tr("Please enter UserID..!"));
        return false;
    }

    if(NewAcc.Password == ""){
        emit Error(tr("Account"), tr("Please enter password..!"));
        return false;
    }
    return true;
}

void Accounts::OnDelete(){
    Account Acc;
    int m_CurrRow = ui->tbl_Accs->currentRow();
    if(m_CurrRow >= 0){
        int m_PK = ui->tbl_Accs->item(m_CurrRow, 0)->text().toInt();
        Acc.PKey = m_PK;

        QSqlError err = m_DbRef->DeleteAccount(&Acc);
        if(err.type() != QSqlError::NoError){
            emit Error(tr("New"), tr("Error: \n") + err.text());
            return;
        }

        ui->tbl_Accs->removeRow(m_CurrRow);
    }
    else {
        emit Error(tr("Delete Account"), tr("Please select row..!"));
    }
}

void Accounts::OnEdit(){
    emit SetHeader("Edit");
    ui->stackedWidget->setCurrentIndex(PAGE_ACCOUNT);

    ui->btn_New->hide();
    ui->btn_Edit->hide();
    ui->btn_Delete->hide();

    ui->btn_Save->show();
    QObject::connect(ui->btn_Save,      SIGNAL(clicked()),this, SLOT(OnEditSave()));

    ui->btn_Cancel->show();
    QObject::connect(ui->btn_Cancel,    SIGNAL(clicked()),this, SLOT(OnEditCancelled()));

    Account Acc;
    int m_CurrRow = ui->tbl_Accs->currentRow();
    int m_PK = ui->tbl_Accs->item(m_CurrRow, 0)->text().toInt();
    Acc.PKey = m_PK;

    QSqlError err = m_DbRef->GetAccountFromKey(&Acc);
    if(err.type() != QSqlError::NoError){
        emit Error(tr("Edit"), tr("Error: \n") + err.text());
        return;
    }

    ui->line_Provider->setText(Acc.Provider);
    ui->line_UserID->setText(Acc.UserName);
    ui->line_Pass->setText(Acc.Password);
    ui->line_Hint->setText(Acc.Hint);
}

void Accounts::OnEditCancelled(){
    emit SetHeader("User Accounts");
    ui->stackedWidget->setCurrentIndex(PAGE_ACCOUNTS);

    ui->btn_New->show();
    OnItemSelected();

    ui->btn_Save->hide();
    QObject::disconnect(ui->btn_Save,   SIGNAL(clicked()),this, SLOT(OnEditSave()));

    ui->btn_Cancel->hide();
    QObject::disconnect(ui->btn_Cancel, SIGNAL(clicked()),this, SLOT(OnEditCancelled()));
}

void Accounts::OnEditSave(){
    int m_CurrRow = ui->tbl_Accs->currentRow();
    Account Acc;
    Acc.PKey        = ui->tbl_Accs->item(m_CurrRow, 0)->text().toInt();
    Acc.Provider    = ui->line_Provider->text();
    Acc.UserName    = ui->line_UserID->text();
    Acc.Password    = ui->line_Pass->text();
    Acc.Hint        = ui->line_Hint->text();

    QSqlError err = m_DbRef->EditAccount(&Acc);
    if(err.type() != QSqlError::NoError){
        emit Error(tr("Edit"), tr("Error: \n") + err.text());
        return;
    }

    ui->tbl_Accs->item(m_CurrRow, 1)->setText(Acc.Provider);
    ui->tbl_Accs->item(m_CurrRow, 2)->setText(Acc.UserName);

    OnEditCancelled();
}
