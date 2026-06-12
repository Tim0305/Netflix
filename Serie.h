#ifndef SERIE_H
#define SERIE_H

#include <vector>

#include "Contenido.h"
#include "Episodio.h"

using namespace std;

class Serie : public Contenido {

private:

    vector<Episodio> episodios;

public:

    Serie();

    Serie(
        int id,
        string nombre,
        string descripcion,
        int duracion,
        string genero,
        string portada,
        string video
    );

    ~Serie();

    void addEpisodio(Episodio episodio);

    vector<Episodio> getEpisodios() const;

    double operator+();
};

#endif