#include "userinfo.h"
#include "ui_userinfo.h"

UserInfo::UserInfo(QMainWindow *parent, DbConnection *DBRef) :
    QWidget(parent),
    ui(new Ui::UserInfo)
{
    m_DbRef = DBRef;
    ui->setupUi(this);
    InitializeConnections();
    InitializeUI();

    // set widget after initialization
    emit SetHeader("User Inforamtion");
    emit SetWidget(this);
}

UserInfo::~UserInfo()
{
    m_DbRef = nullptr;
    delete ui;
}

void UserInfo::InitializeConnections(){
    // framework specific connections
    QObject::connect(this, SIGNAL(Error(QString, QString)), parent(), SLOT(OnError(QString, QString)));
    QObject::connect(this, SIGNAL(SetWidget(QWidget *)),    parent(), SLOT(OnSetWidget(QWidget *)));
    QObject::connect(this, SIGNAL(SetHeader(QString)),      parent(), SLOT(OnSetHeader(QString)));

    QObject::connect(this, SIGNAL(Signal_ShowAccounts()),   parent(), SLOT(OnSignal_ShowAccounts()));
}

void UserInfo::InitializeUI(){
    ui->line_FirstName->clear();
    ui->line_LastName->clear();
    ui->line_Pin->clear();

    ui->btn_Edit->hide();

    LoadUser();
    if(m_Pin == ""){
        emit SetHeader("Create User");
        ui->btn_Create->setText("Create");
        QObject::connect (ui->btn_Create, SIGNAL(clicked()), this, SLOT(OnCreateUser()));
        return;
    }

    else{
        emit SetHeader("Enter Pin");
        ui->line_FirstName->setDisabled(true);
        ui->line_LastName->setDisabled(true);
        ui->line_Pin->clear();

        ui->btn_Create->setText("Login");
        QObject::connect(ui->btn_Create, SIGNAL(clicked()), this, SLOT(OnLoginUser()));
    }

}

void UserInfo::LoadUser(){
    User currUser = m_DbRef->GetUser();
    ui->line_FirstName->setText (currUser.FirstName);
    ui->line_LastName->setText  (currUser.LastName);
    m_Pin       = currUser.Pin;
    m_UserKey   = currUser._key;
}

bool UserInfo::ValidateUserInput(){
    if(ui->line_FirstName->text() == ""){
        emit Error(tr("User Info"), tr("Please enter First Name..!"));
        return false;
    }

    // check if last name is empty
    if(ui->line_LastName->text() == ""){
        emit Error(tr("User Info"), tr("Please enter Last Name..!"));
        return false;
    }

    // check if Pin is empty & 6 digit
    if(ui->line_Pin->text() == "" || ui->line_Pin->text().length() != 6){
        emit Error(tr("User Info"), tr("Please enter Pin of 6 digits..!"));
        return false;
    }
    return true;
}

void UserInfo::OnCreateUser(){
    // check if first name is empty
    if(!ValidateUserInput()){
        return;
    }

    User NewUser;
    NewUser.FirstName   = ui->line_FirstName->text();
    NewUser.LastName    = ui->line_LastName->text();
    NewUser.Pin         = ui->line_Pin->text();

    QSqlError err = m_DbRef->CreateUser(NewUser);
    if(err.type() != QSqlError::NoError){
        emit Error(tr("User Info"), tr("Error: \n") + err.text());
        return;
    }

    LoadUser();
    ui->line_FirstName->setDisabled(true);
    ui->line_LastName->setDisabled(true);
    ui->line_Pin->clear();

    QObject::disconnect(ui->btn_Create, SIGNAL(clicked()), this, SLOT(OnCreateUser()));
    QObject::connect (ui->btn_Create, SIGNAL(clicked()), this, SLOT(OnLoginUser()));
    ui->btn_Create->setText("Login");
}

void UserInfo::OnEditUser(){
    ui->line_FirstName->setEnabled(true);
    ui->line_LastName->setEnabled(true);

    QObject::disconnect (ui->btn_Create, SIGNAL(clicked()), this, SLOT(OnAccounts()));
    QObject::connect    (ui->btn_Create, SIGNAL(clicked()), this, SLOT(OnSaveUser()));
    ui->btn_Create->setText("Save");

    QObject::disconnect (ui->btn_Edit, SIGNAL(clicked()), this, SLOT(OnEditUser()));
    QObject::connect    (ui->btn_Edit, SIGNAL(clicked()), this, SLOT(OnEditCancel()));
    ui->btn_Edit->setText("Cancel");
}

void UserInfo::OnEditCancel(){
    LoadUser();
    ui->line_FirstName->setDisabled(true);
    ui->line_LastName->setDisabled(true);

    QObject::disconnect (ui->btn_Create, SIGNAL(clicked()), this, SLOT(OnSaveUser()));
    QObject::connect    (ui->btn_Create, SIGNAL(clicked()), this, SLOT(OnAccounts()));
    ui->btn_Create->setText("Accounts");

    QObject::disconnect (ui->btn_Edit, SIGNAL(clicked()), this, SLOT(OnEditCancel()));
    QObject::connect    (ui->btn_Edit, SIGNAL(clicked()), this, SLOT(OnEditUser()));
    ui->btn_Edit->setText("Edit");
}

void UserInfo::OnSaveUser(){
    if(ValidateUserInput() == false){
        return;
    }

    User NewUser;
    NewUser.FirstName   = ui->line_FirstName->text();
    NewUser.LastName    = ui->line_LastName->text();
    NewUser.Pin         = ui->line_Pin->text();
    NewUser._key        = m_UserKey;

    QSqlError err = m_DbRef->SaveUser(NewUser);
    if(err.type() != QSqlError::NoError){
        emit Error(tr("User Info"), tr("Error: \n") + err.text());
        return;
    }
    LoadUser();
    ui->line_FirstName->setDisabled(true);
    ui->line_LastName->setDisabled(true);

    QObject::disconnect (ui->btn_Create, SIGNAL(clicked()), this, SLOT(OnSaveUser()));
    QObject::connect    (ui->btn_Create, SIGNAL(clicked()), this, SLOT(OnAccounts()));
    ui->btn_Create->setText("Accounts");

    QObject::disconnect (ui->btn_Edit, SIGNAL(clicked()), this, SLOT(OnEditCancel()));
    QObject::connect    (ui->btn_Edit, SIGNAL(clicked()), this, SLOT(OnEditUser()));
    ui->btn_Edit->setText("Edit");
}

void UserInfo::OnLoginUser(){
    if(m_Pin != ui->line_Pin->text()){
        emit Error(tr("User Info"), tr("Incorrect Pin.."));
        return;
    }

    QObject::disconnect (ui->btn_Create, SIGNAL(clicked()), this, SLOT(OnLoginUser()));
    QObject::connect    (ui->btn_Create, SIGNAL(clicked()), this, SLOT(OnAccounts()));
    ui->btn_Create->setText("Accounts");

    QObject::connect    (ui->btn_Edit, SIGNAL(clicked()), this, SLOT(OnEditUser()));
    ui->btn_Edit->setText("Edit");
    ui->btn_Edit->show();
}

void UserInfo::OnAccounts(){
    emit Signal_ShowAccounts();
}
