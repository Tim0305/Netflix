#include "Contenido.h"

Contenido::Contenido(
    int Id,
    string Nombre,
    string Descripcion,
    string Genero,
    double Calificacion)
{
    id = Id;
    nombre = Nombre;
    descripcion = Descripcion;
    genero = Genero;
    calificacion = Calificacion;
}

double Contenido::getCalificacion(){
    return calificacion;
}