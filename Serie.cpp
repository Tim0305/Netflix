#include "Serie.h"

Serie::Serie(
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

void Serie::AgregarTemporada(Temporada temp){
    temporadas.push_back(temp);
}

double Serie::getCalificacion(){
    return calificacion;
}