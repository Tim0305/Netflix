#include <iostream>
#include <string>
using namespace std;

#ifndef EPISODIO_H
#define EPISODIO_H

class Episodio{
	private:
		int id, duracion, temporada;
    	string titulo, descripcion, src;
    	double calificacion;
    public:
    	Episodio();
    	Episodio(int id, string titulo, int duracion, int temporada);
    	double getCalificacion();
    	void setCalificacion(double calificacion);
    	void mostrar();
};

#endif