#include <iostream>
#include <string>
#include <vector>
#include "Contenido.h"
#include "Temporada.h"
using namespace std;

#ifndef SERIE_H
#define SERIE_H

class Serie: public Contenido{
	protected:
		vector<Temporada> temporadas;
	public:
		Serie();
    	Serie(int id, string nombre, int duracion, string genero);
    	void agregarTemporada(Temporada temporada);
    	double getCalificacion();
    	void mostrar() override;
};

#endif