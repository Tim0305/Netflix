#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "appdb.h"         
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
        auto encontrado = appDb().buscarUsuarioPorNombre(user);
        if (encontrado && encontrado->password == password) {
            QMessageBox::information(
                this,
                "Bienvenido",
                QString("Hola %1 [%2]")
                    .arg(QString::fromStdString(encontrado->nombre))
                    .arg(QString::fromStdString(encontrado->rol)));
        } else {
            QMessageBox::critical(
                this,
                "Error",
                "Usuario o contraseña incorrectos");
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

