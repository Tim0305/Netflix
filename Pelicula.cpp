#include "Pelicula.h"

Pelicula::Pelicula() : Contenido()
{
}

Pelicula::Pelicula(
	int id,
	string nombre,
	int duracion,
	string genero)
	:
	Contenido(
		id,
		nombre,
		duracion,
		genero)
{
}

void Pelicula::mostrar(){

	cout << "----- PELICULA -----" << endl;
	cout << "ID: " << id << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Genero: " << genero << endl;
	cout << "Duracion: " << duracion << endl;
	cout << "Calificacion: " << calificacion << endl;
}