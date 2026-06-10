#include "Episodio.h"
#include <iostream>

using namespace std;

Episodio::Episodio()
{
}

Episodio::Episodio(
    int numero,
    string titulo,
    int duracion)
{
    this->numero = numero;
    this->titulo = titulo;
    this->duracion = duracion;
}

void Episodio::mostrarInfo()
{
    cout << "Episodio " << numero
         << ": " << titulo << endl;
}