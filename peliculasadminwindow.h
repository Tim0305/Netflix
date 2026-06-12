#ifndef PELICULASADMINWINDOW_H
#define PELICULASADMINWINDOW_H

#include <QWidget>

namespace Ui {
class PeliculasAdminWindow;
}

class PeliculasAdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PeliculasAdminWindow(QWidget *parent = nullptr);
    ~PeliculasAdminWindow();
    void reset();

private:
    Ui::PeliculasAdminWindow *ui;
};

#endif // PELICULASADMINWINDOW_H
