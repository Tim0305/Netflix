#include "usuariowidget.h"
#include "ui_usuariowidget.h"

UsuarioWidget::UsuarioWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UsuarioWidget)
{
    ui->setupUi(this);
}

UsuarioWidget::~UsuarioWidget()
{
    delete ui;
}
