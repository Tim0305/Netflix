#ifndef SERIE_H
#define SERIE_H

#include <vector>

#include "Contenido.h"
#include "Episodio.h"

using namespace std;

class Serie : public Contenido {

private:
  vector<Episodio *> episodios;

public:
  Serie();

  Serie(int id, string nombre, string descripcion, int duracion, string genero,
        string portada);

  ~Serie();
  void addEpisodio(Episodio* episodio);
  int getTemporadas();
  int getTotalEpisodios();
  double getCalificacion() override;
  void addCalificacion(double valor) override;
  vector<Episodio *> getEpisodios() const;
  string toString() override;
};

#endif
