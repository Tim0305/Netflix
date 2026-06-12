#include "registrarusuariowindow.h"
#include "ui_registrarusuariowindow.h"

RegistrarUsuarioWindow::RegistrarUsuarioWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegistrarUsuarioWindow)
{
    ui->setupUi(this);
}

RegistrarUsuarioWindow::~RegistrarUsuarioWindow()
{
    delete ui;
}

void RegistrarUsuarioWindow::reset() {
    ui->usuarioEdit->clear();
    ui->passwordEdit->clear();
    ui->rolBox->clear();
}