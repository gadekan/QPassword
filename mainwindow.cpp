#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Lbl_UiHeader->setText("Initializing..");
    m_DbRef = new DbConnection();
    QObject::connect(m_DbRef,   SIGNAL(Error(QString, QString)),    this, SLOT(OnError(QString, QString)));
    this->show();
    Initialize();
}

MainWindow::~MainWindow()
{
    m_DbRef->DeInitialize();
    delete ui;
}

void MainWindow::OnError(QString ErrHeader, QString ErrorInfo){
    QMessageBox::warning(this, ErrHeader, ErrorInfo);
}

void MainWindow::Initialize(){
    // connect to database
    m_DbRef->Initialize();
    // check user available if yes proceed to login else signup
    if(!m_DbRef->IsConnected()){
        ui->Lbl_UiHeader->setText("Not connected to database!");
        return;
    }

    //load user information page
    m_CurrWidget = new UserInfo(this, m_DbRef);
}

void MainWindow::OnSetWidget(QWidget *Widget){
    ui->Wid_Central->layout()->addWidget(Widget);
}

void MainWindow::OnSetHeader(QString HeaderName){
    ui->Lbl_UiHeader->setText(HeaderName);
}

void MainWindow::OnSignal_ShowAccounts(){
    m_CurrWidget->deleteLater();
    m_CurrWidget = nullptr;

    ui->Lbl_UiHeader->setText("Loading table..");
    m_CurrWidget = new Accounts(this, m_DbRef);
}
