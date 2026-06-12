#include "Episodio.h"

Episodio::Episodio(){
	id = 0;
	duracion = 0;
	temporada = 0;

	titulo = "";
	descripcion = "";
	src = "";

	calificacion = 0;
}

Episodio::Episodio(
	int id,
	string titulo,
	int duracion,
	int temporada)
{
	this->id = id;
	this->titulo = titulo;
	this->duracion = duracion;
	this->temporada = temporada;

	descripcion = "";
	src = "";

	calificacion = 0;
}

double Episodio::getCalificacion(){
	return calificacion;
}

void Episodio::setCalificacion(double calificacion){
	this->calificacion = calificacion;
}

void Episodio::mostrar(){

	cout << "ID: " << id << endl;
	cout << "Titulo: " << titulo << endl;
	cout << "Duracion: " << duracion << endl;
	cout << "Temporada: " << temporada << endl;
	cout << "Calificacion: " << calificacion << endl;
}