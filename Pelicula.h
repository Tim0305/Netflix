#ifndef PELICULA_H
#define PELICULA_H

#include "Contenido.h"

class Pelicula : public Contenido {

public:

    Pelicula();

    Pelicula(
        int id,
        string nombre,
        string descripcion,
        int duracion,
        string genero,
        string portada,
        string video
    );

    ~Pelicula();

};

#endif