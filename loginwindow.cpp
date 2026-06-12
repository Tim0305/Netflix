#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <iostream>
#include <QMessageBox>

using namespace std;

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    ADMIN_USER = "admin";
    ADMIN_PASSWORD = "admin";
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
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

        if (user == ADMIN_USER && password == ADMIN_PASSWORD) {
            cout << "Administrador" << endl;
            // Ir a la vista de administrador
            emit gotoAdmin();
        }
    }
}

void LoginWindow::on_signupButton_clicked()
{
    // Ir al sign up page
    emit gotoSignup();
}

void LoginWindow::reset() {
    ui->userEdit->clear();
    ui->passwordEdit->clear();
}

