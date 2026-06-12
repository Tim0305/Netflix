#include "Serie.h"

Serie::Serie()
: Contenido()
{
}

Serie::Serie(
    int id,
    string nombre,
    string descripcion,
    int duracion,
    string genero,
    string portada,
    string video)
:
Contenido(
    id,
    nombre,
    descripcion,
    duracion,
    genero,
    portada,
    video)
{
}

Serie::~Serie()
{
}

void Serie::addEpisodio(Episodio episodio)
{
    episodios.push_back(episodio);
}

vector<Episodio> Serie::getEpisodios() const
{
    return episodios;
}

double Serie::calcularPromedio() const
{
    if (episodios.empty())
        return 0;

    double suma = 0;

    for (const Episodio& ep : episodios)
    {
        suma += ep.getCalificacion();
    }

    return suma / episodios.size();
}

double Serie::operator+()
{
    return calcularPromedio();
}

double Serie::getCalificacion() const
{
    return calcularPromedio();
}