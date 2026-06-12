#include "Usuario.h"

Usuario::Usuario(){
	id = 0;
	nombre = "";
	password = "";
	rol = "";
}

Usuario::Usuario(
	int id,
	string nombre,
	string password,
	string rol)
{
	this->id = id;
	this->nombre = nombre;
	this->password = password;
	this->rol = rol;
}

void Usuario::mostrar(){

	cout << "----- USUARIO -----" << endl;
	cout << "ID: " << id << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Rol: " << rol << endl;
}