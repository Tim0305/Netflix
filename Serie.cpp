#include "Serie.h"
#include "Episodio.h"
#include <sstream>

Serie::Serie() : Contenido() {}

Serie::Serie(int id, string nombre, string descripcion, int duracion,
             string genero, string portada)
    : Contenido(id, nombre, descripcion, duracion, genero, portada, "") {}

Serie::~Serie() {
  for (Episodio* episodio : episodios) {
    delete episodio;
  }
}

void Serie::addEpisodio(Episodio *episodio) {
  episodio->setSerie(this);
  episodios.push_back(episodio);
  addCalificacion(episodio->getCalificacion());
}

vector<Episodio *> Serie::getEpisodios() const { return episodios; }

double Serie::getCalificacion() {
  double calificacion = 0;
  for (auto episodio : episodios) {
    calificacion += episodio->getCalificacion();
  }

  return calificacion / episodios.size();
}

void Serie::addCalificacion(double valor) {
  return;
}

int Serie::getTemporadas() {
  int temporadas = 0;
  for (auto ep: episodios) {
    if (ep->getTemporada() > temporadas)
      temporadas = ep->getTemporada();
  }

  return temporadas;
}

int Serie::getTotalEpisodios() {
  return episodios.size();
}

string Serie::toString() {
  stringstream ss;
  ss << "===============================" << endl;
  ss << "ID: " << getId() << endl;
  ss << "Nombre: " << getNombre() << endl;
  ss << "Descripcion: " << getDescripcion() << endl;
  ss << "Duracion: " << getDuracion() << " minutos" << endl;
  ss << "Calificacion: " << getCalificacion() << endl;
  ss << "Genero: " << getGenero() << endl;
  ss << "Temporadas: " << getTemporadas() << endl;
  ss << "Episodios: " << getTotalEpisodios();
  for (auto ep: episodios) {
    ss << endl << "   [" << ep->getId() << "] - " << ep->getNombre();
  }
  ss << endl << "===============================" << endl;
  return ss.str();
}
