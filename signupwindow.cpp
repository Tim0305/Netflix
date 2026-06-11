#include "signupwindow.h"
#include "ui_signupwindow.h"
#include <iostream>

using namespace std;

SignUpWindow::SignUpWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_returnButton_clicked()
{
    // Regresar al login page
    emit return2LoginWindow();
}


void SignUpWindow::on_signinButton_clicked()
{
    // Registrar un nuevo usuario
    QString user = ui->userEdit->text();
    QString password = ui->passwordEdit->text();

    cout << "User: " << user.toStdString() << endl;
    cout << "Password: " << password.toStdString() << endl;

    // Regresar al login page
    emit return2LoginWindow();
}

void SignUpWindow::reset() {
    ui->userEdit->clear();
    ui->passwordEdit->clear();
}
