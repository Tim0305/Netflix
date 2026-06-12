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

    addCalificacion(
        episodio.getCalificacion()
    );
}
vector<Episodio> Serie::getEpisodios() const
{
    return episodios;
}

double Serie::operator+()
{
    return getCalificacion();
}