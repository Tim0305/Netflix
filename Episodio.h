#ifndef EPISODIO_H
#define EPISODIO_H

#include "Contenido.h"

class Episodio : public Contenido {

private:

    int temporada;

public:

    Episodio();

    Episodio(
        int id,
        string nombre,
        string descripcion,
        int duracion,
        string genero,
        string portada,
        string video,
        int temporada
    );

    ~Episodio();

    int getTemporada() const;

    void setTemporada(int temporada);

    double getCalificacion() const override;
};

#endif