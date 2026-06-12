#include "peliculasadminwindow.h"
#include "ui_peliculasadminwindow.h"

PeliculasAdminWindow::PeliculasAdminWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PeliculasAdminWindow)
{
    ui->setupUi(this);
}

PeliculasAdminWindow::~PeliculasAdminWindow()
{
    delete ui;
}

void PeliculasAdminWindow::reset() {
    ui->buscarEdit->clear();
    ui->listWidget->clear();
}