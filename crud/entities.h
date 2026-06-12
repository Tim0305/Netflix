#pragma once
#include "Usuario.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include <string>

struct UsuarioEntity : public Usuario {
    int id = 0;                 
    string nombre;
    string password;
    string rol;
};

struct PeliculaEntity : public Pelicula {
    int id = 0;                 
    string nombre;
    string descripcion;
    double duracion = 0.0;
    int numeroCalificaciones = 0;
    string genero;
    string portada;
    string video;
};

struct SerieEntity : public Serie {
    int id = 0;                 
    string nombre;
    string descripcion;
    double duracion = 0.0;
    int numeroCalificaciones = 0;
    string genero;
    string portada;
    string video;
};

struct EpisodioEntity : public Episodio {
    int id = 0; 
    int serie_id = 0;
    int temporada = 0;         
    string nombre;
    string descripcion;
    double duracion = 0.0;
    double calificacion = 0.0;
    int numeroCalificaciones = 0;
    string genero;
    string portada;
    string video;
};

struct CalificacionEntity {
    int id = 0;
    int contenido_id = 0;
    double valor = 0.0;
};