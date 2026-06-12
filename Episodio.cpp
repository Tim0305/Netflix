#include "Episodio.h"
#include "Serie.h"
#include <sstream>

Episodio::Episodio() : Contenido() { temporada = 1; }

Episodio::Episodio(int id, string nombre, string descripcion, int duracion,
                   string genero, string video, int temporada, Serie *serie)
    : Contenido(id, nombre, descripcion, duracion, genero, "", video) {
  this->temporada = temporada;
  this->serie = serie;
}

Episodio::~Episodio() {}

Serie *Episodio::getSerie() const { return serie; }

void Episodio::setSerie(Serie* serie) {
    this->serie = serie;
}

int Episodio::getTemporada() const { return temporada; }

void Episodio::setTemporada(int temporada) { this->temporada = temporada; }

void Episodio::addCalificacion(double valor) {
    calificacion = calificacion * numeroCalificaciones;
    calificacion += valor;
    numeroCalificaciones++;
    calificacion /= numeroCalificaciones;
}

string Episodio::toString() {
  stringstream ss;
  ss << "===============================" << endl;
  ss << "ID: " << getId() << endl;
  ss << "Nombre: " << getNombre() << endl;
  ss << "Descripcion: " << getDescripcion() << endl;
  ss << "Duracion: " << getDuracion() << " minutos" << endl;
  ss << "Calificacion: " << getCalificacion() << endl;
  ss << "Genero: " << getGenero() << endl;
  if (serie)
    ss << "Serie: " << serie->getNombre() << endl;
  ss << "Teporada: " << getTemporada() << endl;
  ss << "===============================" << endl;
  return ss.str();
}
