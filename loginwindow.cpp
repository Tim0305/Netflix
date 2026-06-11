#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <iostream>

using namespace std;

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    // Iniciar sesion
    QString user = ui->userEdit->text();
    QString password = ui->passwordEdit->text();

    cout << "User: " << user.toStdString() << endl;
    cout << "Password: " << password.toStdString() << endl;
}

void LoginWindow::on_signupButton_clicked()
{
    // Ir al sign up page
    emit signup();
}

void LoginWindow::reset() {
    ui->userEdit->clear();
    ui->passwordEdit->clear();
}

