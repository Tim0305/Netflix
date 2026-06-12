#ifndef MODIFICARUSUARIOWINDOW_H
#define MODIFICARUSUARIOWINDOW_H

#include <QWidget>

namespace Ui {
class ModificarUsuarioWindow;
}

class ModificarUsuarioWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ModificarUsuarioWindow(QWidget *parent = nullptr);
    ~ModificarUsuarioWindow();
    void reset();

private:
    Ui::ModificarUsuarioWindow *ui;
};

#endif // MODIFICARUSUARIOWINDOW_H
