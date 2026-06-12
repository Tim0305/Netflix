#include "Usuario.h"
#include "Contenido.h"

Usuario::Usuario()
{
    id = 0;
    nombre = "";
    password = "";
    rol = "cliente";
}

Usuario::Usuario(
    int id,
    string nombre,
    string password,
    string rol)
{
    this->id = id;
    this->nombre = nombre;
    this->password = password;
    this->rol = rol;
}

Usuario::~Usuario()
{
}

// GETTERS

int Usuario::getId() const
{
    return id;
}

string Usuario::getNombre() const
{
    return nombre;
}

string Usuario::getPassword() const
{
    return password;
}

string Usuario::getRol() const
{
    return rol;
}

// SETTERS

void Usuario::setId(int id)
{
    this->id = id;
}

void Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Usuario::setPassword(string password)
{
    this->password = password;
}

void Usuario::setRol(string rol)
{
    this->rol = rol;
}

// AUTENTICACION

bool Usuario::autenticar(
    string passwordIngresado) const
{
    return password == passwordIngresado;
}

// CALIFICAR CONTENIDO

void Usuario::calificarContenido(
    Contenido* contenido,
    double calificacion)
{
    contenido->addCalificacion(calificacion);
}