#include "Pelicula.h"

Pelicula::Pelicula()
: Contenido()
{
}

Pelicula::Pelicula(
    int id,
    string nombre,
    string descripcion,
    int duracion,
    string genero,
    string portada,
    string video)
:
Contenido(
    id,
    nombre,
    descripcion,
    duracion,
    genero,
    portada,
    video)
{
}

Pelicula::~Pelicula()
{
}

double Pelicula::getCalificacion() const {

    return calificacion;
}