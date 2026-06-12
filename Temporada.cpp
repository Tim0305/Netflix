#include "Temporada.h"

Temporada::Temporada(){
	numero = 0;
}

Temporada::Temporada(int numero){
	this->numero = numero;
}

void Temporada::agregarEpisodio(Episodio episodio){
	episodios.push_back(episodio);
}

double Temporada::getCalificacion(){

	if(episodios.size() == 0){
		return 0;
	}

	double suma = 0;

	for(int i = 0; i < episodios.size(); i++){
		suma += episodios[i].getCalificacion();
	}

	return suma / episodios.size();
}

void Temporada::mostrar(){

	cout << "Temporada " << numero << endl;

	for(int i = 0; i < episodios.size(); i++){
		episodios[i].mostrar();
	}
}