#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include <QListWidgetItem>
#include "peliculasadminwindow.h"
#include "usuarioswindow.h"
#include "modificarusuariowindow.h"
#include "registrarusuariowindow.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

signals:
    void logout();

private slots:
    void on_sidebar_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::AdminWindow *ui;

    // Vistas
    PeliculasAdminWindow* peliculasWindow;
    //SeriesAdminWindow* seriesAdminWindow;
    UsuariosWindow* usuariosWindow;
    RegistrarUsuarioWindow* registrarUsuarioWindow;
    ModificarUsuarioWindow* modificarUsuarioWindow;

    void showPeliculasWindow();
    void showSeriesWindow();
    void showUsuarioWindow();
    void showRegistrarUsuarioWindow();
    void showModificarUsuarioWindow();
    void showGenerosWindow();
};

#endif // ADMINWINDOW_H
