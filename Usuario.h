#include <iostream>
#include <string>
using namespace std;

#ifndef USUARIO_H
#define USUARIO_H

class Usuario{
	private:
		int id;
    	string nombre, password, rol;
    public:
		Usuario();
    	Usuario(int id, string nombre, string password, string rol);
    	void mostrar();
};

#endif
