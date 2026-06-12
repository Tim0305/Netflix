#include "Episodio.h"

Episodio::Episodio()
: Contenido()
{
    temporada = 1;
}

Episodio::Episodio(
    int id,
    string nombre,
    string descripcion,
    int duracion,
    string genero,
    string portada,
    string video,
    int temporada)
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
    this->temporada = temporada;
}

Episodio::~Episodio()
{
}

int Episodio::getTemporada() const {

    return temporada;
}

void Episodio::setTemporada(int temporada) {

    this->temporada = temporada;
}
