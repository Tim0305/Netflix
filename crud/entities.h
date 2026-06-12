#pragma once
#include "Usuario.h"
#include "Pelicula.h"
#include <string>

struct UsuarioEntity : public Usuario {
    int id = 0;                 
    std::string nombre;
    std::string password;
    std::string rol;
};

struct PeliculaEntity : public Pelicula {
    int id = 0;                 
    std::string nombre;
    std::string genero;
    std::string descripcion;
    int duracion = 0;
    double calificacion = 0.0;
};
