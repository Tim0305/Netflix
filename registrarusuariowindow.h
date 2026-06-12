#ifndef REGISTRARUSUARIOWINDOW_H
#define REGISTRARUSUARIOWINDOW_H

#include <QWidget>

namespace Ui {
class RegistrarUsuarioWindow;
}

class RegistrarUsuarioWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrarUsuarioWindow(QWidget *parent = nullptr);
    ~RegistrarUsuarioWindow();
    void reset();

private:
    Ui::RegistrarUsuarioWindow *ui;
};

#endif // REGISTRARUSUARIOWINDOW_H
