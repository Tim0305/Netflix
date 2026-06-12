#include "usuarioswindow.h"
#include "ui_usuarioswindow.h"

UsuariosWindow::UsuariosWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UsuariosWindow)
{
    ui->setupUi(this);
}

UsuariosWindow::~UsuariosWindow()
{
    delete ui;
}

void UsuariosWindow::reset() {
    ui->buscarEdit->clear();
    ui->listWidget->clear();
}
