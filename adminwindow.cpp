#include "adminwindow.h"
#include "ui_adminwindow.h"

using namespace std;

AdminWindow::AdminWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    // Crear vistas del admin
    peliculasWindow = new PeliculasAdminWindow();
    usuariosWindow = new UsuariosWindow();
    modificarUsuarioWindow = new ModificarUsuarioWindow();
    registrarUsuarioWindow = new RegistrarUsuarioWindow();

    // Agregar las vistas al stack
    ui->stackedWidget->addWidget(peliculasWindow);
    ui->stackedWidget->addWidget(usuariosWindow);
    ui->stackedWidget->addWidget(modificarUsuarioWindow);
    ui->stackedWidget->addWidget(registrarUsuarioWindow);

    // Eventos

    showPeliculasWindow();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_sidebar_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    // Detectar cuando cambia la seleccion
    if (current) {
        string text = current->text().toStdString();

        if (text == "Películas"){
            // Ir a peliculas
            showPeliculasWindow();
        }
        else if (text == "Series") {
            // Ir a usuarios
            showSeriesWindow();
        }
        else if (text == "Usuarios") {
            // Ir a usuarios
            showUsuarioWindow();
        }
        else if (text == "Géneros") {
            // Ir a generos
            showGenerosWindow();

        }
        else if (text == "Cerrar sesión") {
            // Cerrar sesion
            emit logout();
        }
    }
}

void AdminWindow::showPeliculasWindow() {
    ui->stackedWidget->setCurrentWidget(peliculasWindow);
    peliculasWindow->reset();
}

void AdminWindow::showSeriesWindow() {
    //ui->stackedWidget->setCurrentWidget(seriesAdminWindow);
    //seriesAdminWindow->reset();
    return;
}

void AdminWindow::showUsuarioWindow() {
    ui->stackedWidget->setCurrentWidget(usuariosWindow);
    usuariosWindow->reset();
}

void AdminWindow::showRegistrarUsuarioWindow() {
    ui->stackedWidget->setCurrentWidget(registrarUsuarioWindow);
    registrarUsuarioWindow->reset();
}

void AdminWindow::showModificarUsuarioWindow() {
    ui->stackedWidget->setCurrentWidget(modificarUsuarioWindow);
    modificarUsuarioWindow->reset();
}

void AdminWindow::showGenerosWindow() {
    return;
}
