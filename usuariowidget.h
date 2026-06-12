#ifndef USUARIOWIDGET_H
#define USUARIOWIDGET_H

#include <QWidget>

namespace Ui {
class UsuarioWidget;
}

class UsuarioWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UsuarioWidget(QWidget *parent = nullptr);
    ~UsuarioWidget();

private:
    Ui::UsuarioWidget *ui;
};

#endif // USUARIOWIDGET_H
