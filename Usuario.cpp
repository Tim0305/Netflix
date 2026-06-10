#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

class Usuario
{
private:
    int id;
    string nombre;
    string password;
    string rol;

public:
    Usuario();

    Usuario(
        int id,
        string nombre,
        string password,
        string rol);

    void mostrarInfo();
};

#endif
