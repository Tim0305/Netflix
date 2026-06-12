#include "Serie.h"

Serie::Serie() : Contenido()
{
}

Serie::Serie(
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

void Serie::agregarTemporada(Temporada temporada){
	temporadas.push_back(temporada);
}

double Serie::getCalificacion(){

	if(temporadas.size() == 0){
		return 0;
	}

	double suma = 0;

	for(int i = 0; i < temporadas.size(); i++){
		suma += temporadas[i].getCalificacion();
	}

	return suma / temporadas.size();
}

void Serie::mostrar(){

	cout << "----- SERIE -----" << endl;
	cout << "ID: " << id << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Genero: " << genero << endl;
	cout << "Duracion: " << duracion << endl;
	cout << "Calificacion: " << getCalificacion() << endl;
	cout << "Numero de temporadas: " << temporadas.size() << endl;
}