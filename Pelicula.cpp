#include "Pelicula.h"

Pelicula::Pelicula(
    int Id,
    string Nombre,
    string Descripcion,
    string Genero,
    double Calificacion)
    :
    Contenido(
        Id,
        Nombre,
        Descripcion,
        Genero,
        Calificacion)
{}

double Pelicula::getCalificacion(){
    return calificacion;
}