#include "Temporada.h"
#include <iostream>

using namespace std;

Temporada::Temporada()
{
}

Temporada::Temporada(int numero)
{
    this->numero = numero;
}

void Temporada::agregarEpisodio(Episodio episodio)
{
    episodios.push_back(episodio);
}

void Temporada::mostrarInfo()
{
    cout << "Temporada " << numero << endl;

    for (auto &ep : episodios)
    {
        ep.mostrarInfo();
    }
}