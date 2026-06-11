#include "mainwindow.h"
#include "./ui_mainwindow.h"

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
        &LoginWindow::signup,
        this,
        &MainWindow::showSignUpWindow);

    connect(
        signUpWindow,
        &SignUpWindow::return2LoginWindow,
        this,
        &MainWindow::showLoginWindow);
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
