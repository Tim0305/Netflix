#include "modificarusuariowindow.h"
#include "ui_modificarusuariowindow.h"

ModificarUsuarioWindow::ModificarUsuarioWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModificarUsuarioWindow)
{
    ui->setupUi(this);
}

ModificarUsuarioWindow::~ModificarUsuarioWindow()
{
    delete ui;
}

void ModificarUsuarioWindow::reset() {
    ui->usuarioEdit->clear();
    ui->passwordEdit->clear();
    ui->rolBox->clear();
}