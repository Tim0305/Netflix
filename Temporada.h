#include <iostream>
#include <string>
#include <vector>
#include "Episodio.h"
using namespace std;

#ifndef TEMPORADA_H
#define TEMPORADA_H

class Temporada{
	private:
		int numero;
    	vector<Episodio> episodios;
    public:
    	Temporada();
    	Temporada(int numero);
    	void agregarEpisodio(Episodio episodio);
    	double getCalificacion();
    	void mostrar();
};

#endif