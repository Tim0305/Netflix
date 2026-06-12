#include "generoswindow.h"
#include "ui_generoswindow.h"

GenerosWindow::GenerosWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GenerosWindow)
{
    ui->setupUi(this);
}

GenerosWindow::~GenerosWindow()
{
    delete ui;
}
