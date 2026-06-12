#include "generowidget.h"
#include "ui_generowidget.h"

GeneroWidget::GeneroWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GeneroWidget)
{
    ui->setupUi(this);
}

GeneroWidget::~GeneroWidget()
{
    delete ui;
}
