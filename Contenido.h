#include <iostream>
#include <string>
using namespace std;

#ifndef CONTENIDO_H
#define CONTENIDO_H

class Contenido{
	protected:
		int id, duracion, numcalificaciones;
    	double calificacion;
    	string nombre, genero, descripcion, portada, src;
	public:
		Contenido();
    	Contenido(int id, string nombre, int duracion, string genero);
    	double getCalificacion();
    	string getGenero();
    	string getNombre();
    	void setCalificacion(double calificacion);
    	virtual void mostrar()= 0;
};

#endif
