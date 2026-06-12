#ifndef EPISODIO_H
#define EPISODIO_H

#include "Contenido.h"

// Forward declaration
class Serie;

class Episodio : public Contenido {

private:
  int temporada;
  Serie *serie;

public:
  Episodio();

  Episodio(int id, string nombre, string descripcion, int duracion,
           string genero, string video, int temporada, Serie *serie);

  ~Episodio();
  int getTemporada() const;
  Serie *getSerie() const;
  void setSerie(Serie *);
  void setTemporada(int temporada);
  string toString() override;
  void addCalificacion(double valor) override;
};

#endif
