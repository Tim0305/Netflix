#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "appdb.h"         
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
    else if (appDb().buscarUsuarioPorNombre(user)) {
        QMessageBox::critical(
            this,
            "Error",
            "El usuario ya existe");
    }
    else {
        int id = appDb().registrarUsuario(user, password, "cliente");
        QMessageBox::information(
            this,
            "Registro exitoso",
            QString("Usuario registrado con id %1").arg(id));
        emit return2LoginWindow();
    }
}

void SignUpWindow::reset() {
    ui->userEdit->clear();
    ui->passwordEdit->clear();
}
