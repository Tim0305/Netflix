#ifndef USUARIOSWINDOW_H
#define USUARIOSWINDOW_H

#include <QWidget>

namespace Ui {
class UsuariosWindow;
}

class UsuariosWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UsuariosWindow(QWidget *parent = nullptr);
    ~UsuariosWindow();
    void reset();

private:
    Ui::UsuariosWindow *ui;
};

#endif // USUARIOSWINDOW_H
