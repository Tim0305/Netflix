#include "Contenido.h"
#include <sstream>

Contenido::Contenido() {
  id = 0;
  nombre = "";
  descripcion = "";
  duracion = 0;

  calificacion = 0;
  numeroCalificaciones = 0;

  genero = "";
  portada = "";
  video = "";
}

Contenido::Contenido(int id, string nombre, string descripcion, int duracion,
                     string genero, string portada, string video) {
  this->id = id;
  this->nombre = nombre;
  this->descripcion = descripcion;
  this->duracion = duracion;

  this->genero = genero;
  this->portada = portada;
  this->video = video;

  numeroCalificaciones = 0;
}

Contenido::~Contenido() {}

// Getters

int Contenido::getId() const { return id; }

string Contenido::getNombre() const { return nombre; }

string Contenido::getDescripcion() const { return descripcion; }

int Contenido::getDuracion() const { return duracion; }

string Contenido::getGenero() const { return genero; }

string Contenido::getPortada() const { return portada; }

string Contenido::getVideo() const { return video; }

// Setters

void Contenido::setId(int id) { this->id = id; }

void Contenido::setNombre(string nombre) { this->nombre = nombre; }

void Contenido::setDescripcion(string descripcion) {
  this->descripcion = descripcion;
}

void Contenido::setDuracion(int duracion) { this->duracion = duracion; }

void Contenido::setDuracion(int horas, int minutos, int segundos) {
  duracion = horas * 3600 + minutos * 60 + segundos;
}

void Contenido::setGenero(string genero) { this->genero = genero; }

void Contenido::setPortada(string portada) { this->portada = portada; }

void Contenido::setVideo(string video) { this->video = video; }

bool Contenido::operator>(double valor) { return getCalificacion() > valor; }
bool Contenido::operator>=(double valor) { return getCalificacion() >= valor; }
bool Contenido::operator<(double valor) { return getCalificacion() < valor; }
bool Contenido::operator<=(double valor) { return getCalificacion() <= valor; }

double Contenido::getCalificacion() { return calificacion; }

string Contenido::toString() {
  stringstream ss;
  ss << "===============================" << endl;
  ss << "ID: " << getId() << endl;
  ss << "Nombre: " << getNombre() << endl;
  ss << "Descripcion: " << getDescripcion() << endl;
  ss << "Duracion: " << getDuracion() << " minutos" << endl;
  ss << "Calificacion: " << getCalificacion() << endl;
  ss << "Genero: " << getGenero() << endl;
  ss << "===============================" << endl;
  return ss.str();
}
