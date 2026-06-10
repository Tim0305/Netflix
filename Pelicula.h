#include <iostream>
#include <string>
#include "Contenido.h"
using namespace std;

#ifndef PELICULA_H
#define PELICULA_H

class Pelicula: public Contenido{
	public:
		Pelicula();
    	Pelicula(int id, string nombre, int duracion, string genero);
    	void mostrar() override;
};

#endif
