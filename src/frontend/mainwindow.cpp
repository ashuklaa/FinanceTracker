#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <login.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->LoginButton, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
    connect(ui->SignupButton, &QPushButton::clicked, this, &MainWindow::onSignupClicked);
    loginManager = new ftk::backend::login::LoginManager("test.db");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoginClicked(){
    std::string username = QString(ui->UsernameLine->text()).toStdString();
    // TODO: ADD ENCRYPTION TO PASSWORD AT INGEST TO PREVENT PLAINTEXT LEAK
    std::string password = QString(ui->PasswordLine->text()).toStdString();

    bool loginSuccess = loginManager->authenticateExistingUser(username, password);
    // if (loginSuccess){
    //     
    //
    // }

}

void MainWindow::onSignupClicked(){
    std::string username = QString(ui->UsernameLine->text()).toStdString();
    // TODO: ADD ENCRYPTION TO PASSWORD AT INGEST TO PREVENT PLAINTEXT LEAK
    std::string password = QString(ui->PasswordLine->text()).toStdString();

    bool signupSuccess = loginManager->registerNewUser(username, password);
}
