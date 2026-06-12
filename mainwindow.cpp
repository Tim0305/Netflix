#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Crear las vistas
    loginWindow = new LoginWindow();
    signUpWindow = new SignUpWindow();

    // Agregar las vistas al stack
    ui->stackedWidget->addWidget(loginWindow);
    ui->stackedWidget->addWidget(signUpWindow);

    // Mostrar el login page
    showLoginWindow();

    // Receptores de senales
    connect(
        loginWindow,
        &LoginWindow::gotoSignup,
        this,
        &MainWindow::showSignUpWindow);

    connect(
        signUpWindow,
        &SignUpWindow::return2LoginWindow,
        this,
        &MainWindow::showLoginWindow);

    connect(
        loginWindow,
        &LoginWindow::gotoAdmin,
        this,
        &MainWindow::showAdminWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showLoginWindow() {
    ui->stackedWidget->setCurrentWidget(loginWindow);
    loginWindow->reset();
}

void MainWindow::showSignUpWindow() {
    ui->stackedWidget->setCurrentWidget(signUpWindow);
    signUpWindow->reset();
}

void MainWindow::showAdminWindow() {
    AdminWindow* adminWindow = new AdminWindow();
    ui->stackedWidget->addWidget(adminWindow);
    ui->stackedWidget->setCurrentWidget(adminWindow);

    connect(
        adminWindow,
        &AdminWindow::logout,
        this,
        &MainWindow::logout);
}

void MainWindow::logout() {
    QMessageBox::StandardButton respuesta;

    respuesta = QMessageBox::question(
        this,
        "Cerrar sesión",
        "¿Deseas cerrar sesión?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (respuesta == QMessageBox::No)
        return;

    QWidget* widget = ui->stackedWidget->currentWidget();
    showLoginWindow();
    ui->stackedWidget->removeWidget(widget);
    widget->deleteLater();

}
