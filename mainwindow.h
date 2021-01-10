#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/************* Include Qt classes below *************/
#include <QObject>
#include <QMainWindow>
#include <QMessageBox>

/************* Include User classes below *************/
#include "dbconnection.h"
#include "userinfo.h"
#include "accounts.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void OnError(QString ErrHeader, QString ErrorInfo);
    void OnSetWidget(QWidget *Widget);
    void OnSetHeader(QString HeaderName);

    void OnSignal_ShowAccounts();

private:
    Ui::MainWindow *ui;
    DbConnection *m_DbRef;
    QWidget *m_CurrWidget;

    void Initialize();
};

#define SIGNAL_LOGIN_SUCCESS 1

#endif // MAINWINDOW_H
