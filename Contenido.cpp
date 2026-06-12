#include "Contenido.h"

Contenido::Contenido(){
	id = 0;
	nombre = "";
	duracion = 0;
	genero = "";
	descripcion = "";
	portada = "";
	src = "";
	calificacion = 0;
	numcalificaciones = 0;
}

Contenido::Contenido(
	int id,
	string nombre,
	int duracion,
	string genero)
{
	this->id = id;
	this->nombre = nombre;
	this->duracion = duracion;
	this->genero = genero;

	descripcion = "";
	portada = "";
	src = "";

	calificacion = 0;
	numcalificaciones = 0;
}

double Contenido::getCalificacion(){
	return calificacion;
}

string Contenido::getGenero(){
	return genero;
}

string Contenido::getNombre(){
	return nombre;
}

void Contenido::setCalificacion(double calificacion){
	this->calificacion = calificacion;
}