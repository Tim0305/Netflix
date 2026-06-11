#include "signupwindow.h"
#include "ui_signupwindow.h"
#include <iostream>
#include <QMessageBox>

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
    // Iniciar sesion
    string user = ui->userEdit->text().toStdString();
    string password = ui->passwordEdit->text().toStdString();

    // Validaciones
    if (user.empty() || password.empty())
        QMessageBox::critical(
            this,
            "Error",
            "Usuario o contraseña inválidos");
    else {
        cout << "User: " << user << endl;
        cout << "Password: " << password << endl;
        // Regresar al login page
        emit return2LoginWindow();
    }
}

void SignUpWindow::reset() {
    ui->userEdit->clear();
    ui->passwordEdit->clear();
}
