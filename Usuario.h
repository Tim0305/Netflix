#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

class Contenido;

class Usuario {

private:

    int id;
    string nombre;
    string password;
    string rol;

public:

    // Constructores
    Usuario();

    Usuario(
        int id,
        string nombre,
        string password,
        string rol
    );

    ~Usuario();

    // Getters
    int getId() const;
    string getNombre() const;
    string getPassword() const;
    string getRol() const;

    // Setters
    void setId(int id);
    void setNombre(string nombre);
    void setPassword(string password);
    void setRol(string rol);

    // Funciones
    bool autenticar(string passwordIngresado) const;

    void calificarContenido(
        Contenido* contenido,
        double calificacion
    );
};

#endif