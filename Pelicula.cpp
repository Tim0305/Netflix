#include "Pelicula.h"

Pelicula::Pelicula() : Contenido() {}

Pelicula::Pelicula(int id, string nombre, string descripcion, int duracion,
                   string genero, string portada, string video)
    : Contenido(id, nombre, descripcion, duracion, genero, portada, video) {}

Pelicula::Pelicula(int id, string nombre, string descripcion, int duracion,
                   string genero, string portada, string video, double calificacion, int numeroCalificaciones)
    : Contenido(id, nombre, descripcion, duracion, genero, portada, video, calificacion, numeroCalificaciones) {}

Pelicula::~Pelicula() {}

void Pelicula::addCalificacion(double valor) {
    calificacion = calificacion * numeroCalificaciones;
    calificacion += valor;
    numeroCalificaciones++;
    calificacion /= numeroCalificaciones;
}
