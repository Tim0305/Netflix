#include <cctype>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Contenido.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"

using namespace std;

const string DATOS_FILEPATH = "datos.txt";

void mostrarPeliculas(vector<Contenido *>);
void mostrarSeries(vector<Contenido *>);
Serie *buscarSerie(int, vector<Contenido *>);
Pelicula *buscarPelicula(int, vector<Contenido *>);
string leerLinea();
int leerEntero();
double leerDouble();
char leerChar();
void opcionMostrarCatalogo(vector<Contenido *> contenidos);
void opcionRegistrarContenido(vector<Contenido *> &contenidos);
void opcionModificarContenido(vector<Contenido *> &contenidos);
void opcionEliminarContenido(vector<Contenido *> &contenidos);
void opcionCalificarContenido(vector<Contenido *> &contenidos);
vector<Contenido *> cargarContenidos(string filepath);
void guardarDatos(string path, const vector<Contenido *> &lista);
void opcionReproducirContenido(vector<Contenido *> contenidos);


int main() {
  vector<Contenido *> contenidos; // El catálogo inicia vacío

  // Obtener los datos del .txt
  contenidos = cargarContenidos(DATOS_FILEPATH);

  bool ejecutando = true;
  while (ejecutando) {
    int opcion = -1;
    do {
      cout << "\n================ MENU ================" << endl;
      cout << "[1] Mostrar catalogo" << endl;
      cout << "[2] Registrar contenido" << endl;
      cout << "[3] Modificar contenido" << endl;
      cout << "[4] Eliminar contenido" << endl;
      cout << "[5] Calificar contenido" << endl;
      cout << "[6] Reproducir contenido" << endl;
      cout << "[0] Salir" << endl;
      cout << "> ";
      opcion = leerEntero();

      if (opcion < 0 || opcion > 6) {
        cout << endl << "Opcion incorrecta. Intenta de nuevo." << endl;
      }
    } while (opcion < 0 || opcion > 6);

    switch (opcion) {
    case 1: {
      opcionMostrarCatalogo(contenidos);
      break;
    }
    case 2: {
      opcionRegistrarContenido(contenidos);
      break;
    }
    case 3: {
      opcionModificarContenido(contenidos);
      break;
    }
    case 4: {
      opcionEliminarContenido(contenidos);
      break;
    }
    case 5: {
      opcionCalificarContenido(contenidos);
      break;
    }
    case 6: {
      opcionReproducirContenido(contenidos);
      break;
    }
    case 0: {
      guardarDatos(DATOS_FILEPATH, contenidos);
      ejecutando = false;
      break;
    }
    }
  }

  // Liberación correcta de memoria (Incluyendo los Episodios* de cada Serie*)
  for (Contenido *c : contenidos) {
    Serie *s = dynamic_cast<Serie *>(c);
    if (s != nullptr) {
      for (Episodio *ep : s->getEpisodios()) {
        delete ep;
      }
    }
    delete c;
  }
  return 0;
}

void mostrarPeliculas(vector<Contenido *> contenidos) {
  for (Contenido *c : contenidos) {
    if (dynamic_cast<Pelicula *>(c)) {
      cout << "ID: " << c->getId() << " - " << c->getNombre() << endl;
    }
  }
}

void mostrarSeries(vector<Contenido *> contenidos) {
  for (Contenido *c : contenidos) {
    if (dynamic_cast<Serie *>(c)) {
      cout << "ID: " << c->getId() << " - " << c->getNombre() << endl;
    }
  }
}

Pelicula *buscarPelicula(int id, vector<Contenido *> contenidos) {
  for (Contenido *c : contenidos) {
    if (c->getId() == id) {
      Pelicula *p = dynamic_cast<Pelicula *>(c);
      return p;
    }
  }
  return nullptr;
}

Serie *buscarSerie(int id, vector<Contenido *> contenidos) {
  for (Contenido *c : contenidos) {
    if (c->getId() == id) {
      Serie *s = dynamic_cast<Serie *>(c);
      return s;
    }
  }
  return nullptr;
}

void opcionMostrarCatalogo(vector<Contenido *> contenidos) {
  if (contenidos.empty()) {
    cout << endl
         << "No existen datos registrados en el catalogo actualmente." << endl;
    return;
  }

  char subOpcion;
  do {
    cout << "\n--- MOSTRAR CATÁLOGO ---" << endl;
    cout << "  [a] Ver Peliculas" << endl;
    cout << "  [b] Ver Series" << endl;
    cout << "  [c] Ver Todos" << endl;
    cout << "  [d] Filtros" << endl;
    cout << "  [e] Volver al menu principal" << endl;
    cout << "  > ";
    string entrada = leerLinea();
    subOpcion = (!entrada.empty()) ? tolower(entrada[0]) : ' ';

    if (subOpcion < 'a' || subOpcion > 'e') {
      cout << "Opcion incorrecta. Elija de [a] a [e]." << endl;
    }
  } while (subOpcion < 'a' || subOpcion > 'e');

  switch (subOpcion) {
  case 'a': {
    cout << endl;
    cout << "===============================" << endl;
    cout << "            Peliculas" << endl;
    cout << "===============================" << endl;
    for (Contenido *c : contenidos) {
      if (dynamic_cast<Pelicula *>(c)) {
        cout << c->toString() << endl << endl;
      }
    }
    break;
  }
  case 'b': {
    cout << endl;
    cout << "===============================" << endl;
    cout << "             Series" << endl;
    cout << "===============================" << endl;
    for (Contenido *c : contenidos) {
      if (dynamic_cast<Serie *>(c)) {
        cout << c->toString() << endl << endl;
      }
    }
    break;
  }
  case 'c': {
    cout << endl;
    cout << "===============================" << endl;
    cout << "            Catalogo" << endl;
    cout << "===============================" << endl;
    for (Contenido *c : contenidos) {
      cout << c->toString() << endl << endl;
    }
    break;
  }
  case 'd': {
    char opcionFiltro;
    do {
      cout << "===============================" << endl;
      cout << "            Filtros" << endl;
      cout << "===============================" << endl;
      cout << "  [1] Filtrar por Calificacion" << endl;
      cout << "  [2] Filtrar por Genero" << endl;
      cout << "  [3] Mostrar episodios de una serie con una calificacion "
              "determinada"
           << endl;
      cout << "  [4] Mostrar las películas con cierta calificacion" << endl;
      cout << "  [5] Regresar" << endl;
      cout << "  > ";
      opcionFiltro = leerEntero();

      if (opcionFiltro < 1 || opcionFiltro > 5) {
        cout << endl << "Opcion invalida. Intente de nuevo" << endl;
      }
    } while (opcionFiltro < 1 || opcionFiltro > 5);

    switch (opcionFiltro) {
    case 1: {
      cout << "Calificacion minima: ";
      double targetCal = leerDouble();
      cout << "\n--- Videos con calificacion >= " << targetCal << " ---"
           << endl;
      for (Contenido *c : contenidos) {
        if (c->getCalificacion() >= targetCal) {
          cout << c->toString() << endl << endl;
        }
      }
      break;
    }
    case 2: {
      cout << "Digita el genero exacto: ";
      string targetGen = leerLinea();
      cout << "\n--- Videos del genero: " << targetGen << " ---" << endl;
      for (Contenido *c : contenidos) {
        if (c->getGenero() == targetGen) {
          cout << c->toString() << endl << endl;
        }
      }
      break;
    }
    case 3: {
      mostrarSeries(contenidos);
      cout << endl << "ID de la Serie: ";
      int id = leerEntero();

      Serie *serie = buscarSerie(id, contenidos);
      if (serie == nullptr) {
        cout << endl
             << "No se encontraron series con el ID (" << id << ")" << endl;
        break;
      }

      cout << "Calificacion minima: ";
      double targetCal = leerDouble();
      cout << "\n--- Episodios de la serie '" << serie->getNombre()
           << "' con calificacion >= " << targetCal << " ---" << endl;

      bool existeEpisodio = false;
      for (Episodio *ep : serie->getEpisodios()) {
        if (ep->getCalificacion() >= targetCal) {
          existeEpisodio = true;
          cout << ep->toString() << endl << endl;
        }
      }
      if (!existeEpisodio)
        cout << endl << "No se encontraron episodios para el filtro" << endl;
      break;
    }
    case 4: {
      cout << "Calificacion minima: ";
      double targetCal = leerDouble();
      cout << "\n--- Peliculas con calificacion >= " << targetCal << " ---"
           << endl;

      bool existePelicula = false;
      for (Contenido *c : contenidos) {
        if (dynamic_cast<Pelicula *>(c) && c->getCalificacion() >= targetCal) {
          existePelicula = true;
          cout << c->toString() << endl << endl;
        }
      }
      if (!existePelicula)
        cout << endl << "No se encontraron peliculas para el filtro" << endl;
      break;
    }
    }
    break;
  }
  case 'e':
    return;
  }
}

void opcionRegistrarContenido(vector<Contenido *> &contenidos) {
  char subOpcion;
  do {
    cout << "\n--- REGISTRAR NUEVO CONTENIDO ---" << endl;
    cout << "  [a] Pelicula" << endl;
    cout << "  [b] Serie" << endl;
    cout << "  [c] Episodio" << endl;
    cout << "  [d] Regresar" << endl;
    cout << "   > ";
    subOpcion = leerChar();
    subOpcion = tolower(subOpcion);

    if (subOpcion < 'a' || subOpcion > 'd')
      cout << endl << "Opcion incorrecta. Intenta de nuevo." << endl;
  } while (subOpcion < 'a' || subOpcion > 'd');

  int idAutoincrementable = 1;
  for (Contenido *c : contenidos) {
    if (c->getId() >= idAutoincrementable) {
      idAutoincrementable = c->getId() + 1;
    }
  }

  switch (subOpcion) {
  case 'a': {
    cout << "Nombre: ";
    string nombre = leerLinea();
    cout << "Descripcion: ";
    string desc = leerLinea();
    cout << "Duracion: ";
    int dur = leerEntero();
    cout << "Genero: ";
    string gen = leerLinea();
    cout << "Archivo Portada: ";
    string port = leerLinea();
    cout << "Archivo Video: ";
    string vid = leerLinea();
    Pelicula *p =
        new Pelicula(idAutoincrementable, nombre, desc, dur, gen, port, vid);
    contenidos.push_back(p);
    cout << endl << "Pelicula registrada" << endl;
    break;
  }

  case 'b': {
    cout << "Nombre: ";
    string nombre = leerLinea();
    cout << "Descripcion: ";
    string desc = leerLinea();
    cout << "Duracion: ";
    int dur = leerEntero();
    cout << "Genero: ";
    string gen = leerLinea();
    cout << "Archivo Portada: ";
    string port = leerLinea();
    Serie *s = new Serie(idAutoincrementable, nombre, desc, dur, gen, port);
    contenidos.push_back(s);
    cout << endl << "Serie registrada" << endl;
    break;
  }

  case 'c': {
    int series = 0;
    for (auto c : contenidos) {
      if (dynamic_cast<Serie *>(c))
        series++;
    }

    if (series == 0) {
      cout << endl << "No hay series en el sistema." << endl;
      return;
    }

    cout << endl << "Series: " << endl;
    mostrarSeries(contenidos);
    cout << endl << "ID de la Serie a asignar: ";
    int idSerie = leerEntero();
    Serie *serie = buscarSerie(idSerie, contenidos);
    if (!serie) {
      cout << endl << "Serie no encontrada." << endl;
      return;
    }

    int idEpAutoincrementable = 1;
    for (Episodio *ep : serie->getEpisodios()) {
      if (ep->getId() >= idEpAutoincrementable)
        idEpAutoincrementable = ep->getId() + 1;
    }

    cout << "Nombre: ";
    string nombre = leerLinea();
    cout << "Descripcion: ";
    string desc = leerLinea();
    cout << "Duracion: ";
    int dur = leerEntero();
    cout << "Genero: ";
    string gen = leerLinea();
    cout << "Archivo Video: ";
    string vid = leerLinea();
    cout << "Temporada: ";
    int temp = leerEntero();
    Episodio *ep = new Episodio(idEpAutoincrementable, nombre, desc, dur, gen,
                                vid, temp, serie);
    serie->addEpisodio(ep);
    cout << endl << "Episodio registrado" << endl;
    break;
  }

  case 'd': {
    return;
  }
  }
}

void opcionModificarContenido(vector<Contenido *> &contenidos) {
  char subOpcion;
  do {
    cout << "\n--- MODIFICAR CONTENIDO ---" << endl;
    cout << "  [a] Pelicula" << endl;
    cout << "  [b] Serie" << endl;
    cout << "  [c] Episodio" << endl;
    cout << "  [d] Regresar" << endl;
    cout << "   > ";
    subOpcion = leerChar();
    subOpcion = tolower(subOpcion);

    if (subOpcion < 'a' || subOpcion > 'd')
      cout << endl << "Opcion incorrecta. Intenta de nuevo." << endl;
  } while (subOpcion < 'a' || subOpcion > 'd');

  switch (subOpcion) {
  case 'a': {
    mostrarPeliculas(contenidos);
    cout << endl << "ID de la Pelicula a modificar: ";
    int id = leerEntero();
    Pelicula *p = buscarPelicula(id, contenidos);
    if (!p) {
      cout << endl << "No encontrada." << endl;
      return;
    }

    cout << "Nuevo Nombre [" << p->getNombre() << "]: ";
    string n = leerLinea();
    if (!n.empty())
      p->setNombre(n);
    cout << "Nueva Descripcion: ";
    string d = leerLinea();
    if (!d.empty())
      p->setDescripcion(d);
    cout << "Duracion (minutos): ";
    int duracion;
    cin >> duracion;
    p->setDuracion(duracion);
    cout << "Nuevo Genero: ";
    string g = leerLinea();
    if (!g.empty())
      p->setGenero(g);
    cout << "Nueva Portada: ";
    string port = leerLinea();
    if (!port.empty())
      p->setPortada(port);
    cout << "Nuevo Video: ";
    string vid = leerLinea();
    if (!vid.empty())
      p->setVideo(vid);
    break;
  }

  case 'b': {
    mostrarSeries(contenidos);
    cout << endl << "ID de la Serie a modificar: ";
    int id = leerEntero();
    Serie *s = buscarSerie(id, contenidos);
    if (!s) {
      cout << endl << "No encontrada." << endl;
      return;
    }

    cout << "Nuevo Nombre [" << s->getNombre() << "]: ";
    string n = leerLinea();
    if (!n.empty())
      s->setNombre(n);
    cout << "Nueva Descripcion: ";
    string d = leerLinea();
    if (!d.empty())
      s->setDescripcion(d);
    cout << "Duracion (minutos): ";
    int duracion;
    cin >> duracion;
    s->setDuracion(duracion);
    cout << "Nuevo Genero: ";
    string g = leerLinea();
    if (!g.empty())
      s->setGenero(g);
    cout << "Nueva Portada: ";
    string port = leerLinea();
    if (!port.empty())
      s->setPortada(port);
    break;
  }
  case 'c': {
    mostrarSeries(contenidos);
    cout << endl << "ID de la Serie dueña del episodio: ";
    int idS = leerEntero();
    Serie *s = buscarSerie(idS, contenidos);
    if (!s) {
      cout << endl << "Serie no encontrada." << endl;
      return;
    }

    if (s->getEpisodios().empty()) {
      cout << endl << "Esta serie no tiene episodios." << endl;
      return;
    }
    for (Episodio *ep : s->getEpisodios()) {
      cout << "  ID Episodio: " << ep->getId() << " - " << ep->getNombre()
           << endl;
    }
    cout << endl << "ID del Episodio a modificar: ";
    int idEp = leerEntero();

    Episodio *targetEp = nullptr;
    for (Episodio *ep : s->getEpisodios()) {
      if (ep->getId() == idEp) {
        targetEp = ep;
        break;
      }
    }
    if (!targetEp) {
      cout << endl << "Episodio no encontrado." << endl;
      return;
    }

    cout << "Nuevo Nombre [" << targetEp->getNombre() << "]: ";
    string n = leerLinea();
    if (!n.empty())
      targetEp->setNombre(n);
    cout << "Nueva Descripcion: ";
    string d = leerLinea();
    if (!d.empty())
      targetEp->setDescripcion(d);
    cout << "Duracion (minutos): ";
    int duracion;
    cin >> duracion;
    targetEp->setDuracion(duracion);
    cout << "Nuevo Video: ";
    string vid = leerLinea();
    if (!vid.empty())
      targetEp->setVideo(vid);
    cout << "Nueva Temporada: ";
    string temp_s = leerLinea();
    if (!temp_s.empty())
      targetEp->setTemporada(stoi(temp_s));
    break;
  }
  case 'd': {
    return;
  }
  }

  cout << endl << "Modificacion realizada exitosamente." << endl;
}

void opcionEliminarContenido(vector<Contenido *> &contenidos) {
  char subOpcion;
  do {
    cout << "\n--- ELIMINAR CONTENIDO ---" << endl;
    cout << "  [a] Pelicula" << endl;
    cout << "  [b] Serie" << endl;
    cout << "  [c] Episodio" << endl;
    cout << "  [d] Regresar" << endl;
    cout << "  > ";
    subOpcion = leerChar();
    subOpcion = tolower(subOpcion);

    if (subOpcion < 'a' || subOpcion > 'd')
      cout << endl << "Opcion incorrecta. Intenta de nuevo." << endl;
  } while (subOpcion < 'a' || subOpcion > 'd');

  switch (subOpcion) {
  case 'a': {
    mostrarPeliculas(contenidos);
    cout << endl << "ID de la pelicula a eliminar: ";
    int id = leerEntero();
    for (auto it = contenidos.begin(); it != contenidos.end(); ++it) {
      if ((*it)->getId() == id) {
        delete *it;
        contenidos.erase(it);
        cout << endl << "Pelicula eliminada exitosamente." << endl;
        return;
      }
    }
    break;
  }

  case 'b': {
    mostrarSeries(contenidos);
    cout << endl << "ID de la pelicula a eliminar: ";
    int id = leerEntero();

    for (auto it = contenidos.begin(); it != contenidos.end(); ++it) {
      if ((*it)->getId() == id) {
        Serie *s = dynamic_cast<Serie *>(*it);
        for (Episodio *ep : s->getEpisodios())
          delete ep;
        delete *it;
        contenidos.erase(it);
        cout << endl << "Serie eliminada exitosamente." << endl;
        return;
      }
    }
    cout << "ID no encontrado." << endl;
    break;
  }
  case 'c': {
    mostrarSeries(contenidos);
    cout << endl << "ID de la Serie: ";
    int idSerie = leerEntero();
    Serie *s = buscarSerie(idSerie, contenidos);
    if (!s) {
      cout << "Serie no encontrada." << endl;
      return;
    }

    vector<Episodio *> episodios = s->getEpisodios();
    for (Episodio *ep : episodios) {
      cout << "  ID Episodio: " << ep->getId() << " - " << ep->getNombre()
           << endl;
    }
    cout << endl << "ID del Episodio a borrar: ";
    int idEpisodio = leerEntero();

    bool borrado = false;
    for (Episodio *ep : s->getEpisodios()) {
      if (ep->getId() == idEpisodio) {
        delete ep;
        borrado = true;
        break;
      }
    }
    if (borrado) {
      cout << endl << "Episodio eliminado exitosamente." << endl;
    } else {
      cout << endl << "Episodio no encontrado." << endl;
    }
    break;
  }
  case 'd': {
    return;
  }
  }
}

void opcionCalificarContenido(vector<Contenido *> &contenidos) {
  char subOpcion;
  do {
    cout << "\n--- CALIFICAR CONTENIDO ---" << endl;
    cout << "  [a] Pelicula o Serie" << endl;
    cout << "  [b] Episodio especifico" << endl;
    cout << "  [c] Regresar" << endl;
    cout << "  > ";
    subOpcion = leerChar();
    subOpcion = tolower(subOpcion);

    if (subOpcion < 'a' || subOpcion > 'c')
      cout << endl << "Opcion incorrecta. Intenta de nuevo." << endl;
  } while (subOpcion < 'a' || subOpcion > 'c');

  switch (subOpcion) {
  case 'a': {
    cout << endl << "--- Videos disponibles en el catalogo ---" << endl;
    for (Contenido *c : contenidos) {
      string tipo = dynamic_cast<Pelicula *>(c) ? "Pelicula" : "Serie";
      cout << "ID: " << c->getId() << " [" << tipo << "] -> " << c->getNombre()
           << " (Calif: " << c->getCalificacion() << ")" << endl;
    }
    cout << endl << "ID a calificar: ";

    int id = leerEntero();
    cout << "Calificacion (1 a 5): ";
    double valor = leerDouble();
    if (valor < 1 || valor > 5) {
      cout << endl << "Invalida." << endl;
      return;
    }

    for (Contenido *c : contenidos) {
      if (c->getId() == id) {
        c->addCalificacion(valor);
        cout << endl << "¡Calificacion añadida!" << endl;
        return;
      }
    }
    cout << endl << "No encontrado." << endl;

    break;
  }
  case 'b': {
    mostrarSeries(contenidos);
    cout << "ID de la Serie: ";
    int idS = leerEntero();
    Serie *s = buscarSerie(idS, contenidos);
    if (!s) {
      cout << endl << "Serie no encontrada." << endl;
      return;
    }

    for (Episodio *ep : s->getEpisodios()) {
      cout << "  ID Ep: " << ep->getId() << " - " << ep->getNombre()
           << " (Calif: " << ep->getCalificacion() << ")" << endl;
    }
    cout << "ID del Episodio a calificar: ";
    int idEp = leerEntero();
    cout << "Calificacion (1 a 5): ";
    double valor = leerDouble();
    if (valor < 1 || valor > 5) {
      cout << endl << "Invalida." << endl;
      return;
    }

    for (Episodio *ep : s->getEpisodios()) {
      if (ep->getId() == idEp) {
        ep->addCalificacion(valor);
        cout << endl << "¡Calificacion añadida al episodio!" << endl;
        return;
      }
    }
    cout << endl << "Episodio no encontrado." << endl;
    break;
  }
  case 'c': {
    return;
  }
  }
}

string leerLinea() {
  string entrada;
  getline(cin, entrada);
  return entrada;
}

int leerEntero() {
  int valor;
  cin >> valor;
  cin.ignore(); // Limpiar el buffer para el siguiente getline
  return valor;
}

double leerDouble() {
  double valor;
  cin >> valor;
  cin.ignore(); // Limpiar el buffer
  return valor;
}

char leerChar() {
  char valor;
  cin >> valor;
  cin.ignore();
  return valor;
}

vector<Contenido *> cargarContenidos(string filepath) {
  vector<Contenido *> lista;
  ifstream archivo(filepath);

  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo: " << filepath
         << ". Se iniciara con catalogo vacio." << endl;
    return lista;
  }

  string linea;
  Serie *ultimaSerie = nullptr;

  while (getline(archivo, linea)) {
    if (linea.empty())
      continue;

    stringstream ss(linea);
    string tipo;
    getline(ss, tipo, ',');

    if (tipo == "P") {
      // Pelicula
      string id_s, nombre, descripcion, duracion_s, genero, portada, video;
      getline(ss, id_s, ',');
      getline(ss, nombre, ',');
      getline(ss, descripcion, ',');
      getline(ss, duracion_s, ',');
      getline(ss, genero, ',');
      getline(ss, portada, ',');
      getline(ss, video, ',');

      Pelicula *p = new Pelicula(stoi(id_s), nombre, descripcion,
                                 stoi(duracion_s), genero, portada, video);
      lista.push_back(p);

    } else if (tipo == "S") {
      // Serie
      string id_s, nombre, descripcion, duracion_s, genero, portada;
      getline(ss, id_s, ',');
      getline(ss, nombre, ',');
      getline(ss, descripcion, ',');
      getline(ss, duracion_s, ',');
      getline(ss, genero, ',');
      getline(ss, portada, ','); // Último parámetro de Serie

      Serie *s = new Serie(stoi(id_s), nombre, descripcion, stoi(duracion_s),
                           genero, portada);
      lista.push_back(s);
      ultimaSerie = s;

    } else if (tipo == "E") {
      // Episodio
      string id_s, nombre, descripcion, duracion_s, genero, video, temporada_s;
      getline(ss, id_s, ',');
      getline(ss, nombre, ',');
      getline(ss, descripcion, ',');
      getline(ss, duracion_s, ',');
      getline(ss, genero, ',');
      getline(ss, video,
              ','); // Se salta la lectura de portada directamente a video
      getline(ss, temporada_s, ',');

      Episodio *ep =
          new Episodio(stoi(id_s), nombre, descripcion, stoi(duracion_s),
                       genero, video, stoi(temporada_s), nullptr);

      if (ultimaSerie != nullptr) {
        ultimaSerie->addEpisodio(ep);
      }
    }
  }
  archivo.close();
  cout << "Datos cargados exitosamente desde " << filepath << endl;
  return lista;
}

void guardarDatos(string path, const vector<Contenido *> &lista) {
  if (path.empty()) {
    cout << "Ruta vacia. No se pudieron guardar los datos." << endl;
    return;
  }

  ofstream archivo(path, ios::out | ios::trunc);
  if (!archivo.is_open()) {
    cout << "Error: No se pudo abrir el archivo para guardar los datos."
         << endl;
    return;
  }

  for (Contenido *c : lista) {
    Pelicula *p = dynamic_cast<Pelicula *>(c);
    if (p != nullptr) {
      archivo << "P," << p->getId() << "," << p->getNombre() << ","
              << p->getDescripcion() << "," << p->getDuracion() << ","
              << p->getGenero() << "," << p->getPortada() << ","
              << p->getVideo() << "\n";
      continue;
    }

    Serie *s = dynamic_cast<Serie *>(c);
    if (s != nullptr) {
      // Serie omite video
      archivo << "S," << s->getId() << "," << s->getNombre() << ","
              << s->getDescripcion() << "," << s->getDuracion() << ","
              << s->getGenero() << "," << s->getPortada() << "\n";

      for (Episodio *ep : s->getEpisodios()) {
        // Episodio omite portada
        archivo << "E," << ep->getId() << "," << ep->getNombre() << ","
                << ep->getDescripcion() << "," << ep->getDuracion() << ","
                << ep->getGenero() << "," << ep->getVideo() << ","
                << ep->getTemporada() << "\n";
      }
    }
  }

  archivo.close();
  cout << "Datos guardados con exito en: " << path << endl;
}

void opcionReproducirContenido(vector<Contenido *> contenidos) {
  char subOpcion;
  do {
    cout << "\n--- REPRODUCIR CONTENIDO ---" << endl;
    cout << "  [a] Reproducir Pelicula" << endl;
    cout << "  [b] Reproducir Episodio de una Serie" << endl;
    cout << "  [c] Regresar" << endl;
    cout << "  > ";
    subOpcion = leerChar();
    subOpcion = tolower(subOpcion);

    if (subOpcion < 'a' || subOpcion > 'c')
      cout << endl << "Opcion incorrecta. Intenta de nuevo." << endl;
  } while (subOpcion < 'a' || subOpcion > 'c');

  switch (subOpcion) {
    case 'a': {
      mostrarPeliculas(contenidos);
      cout << endl << "ID de la Pelicula a reproducir: ";
      int id = leerEntero();
      Pelicula *p = buscarPelicula(id, contenidos);
      
      if (!p) {
        cout << endl << "Pelicula no encontrada." << endl;
        return;
      }
      
      p->reproducir();
      break;
    }
    case 'b': {
      mostrarSeries(contenidos);
      cout << endl << "ID de la Serie: ";
      int idSerie = leerEntero();
      Serie *s = buscarSerie(idSerie, contenidos);
      
      if (!s) {
        cout << endl << "Serie no encontrada." << endl;
        return;
      }

      cout << endl << "Episodios disponibles:" << endl;
      for (Episodio *ep : s->getEpisodios()) {
        cout << "  ID: " << ep->getId() << " - " << ep->getNombre() << endl;
      }
      
      cout << "ID del Episodio a reproducir: ";
      int idEpisodio = leerEntero();

      Episodio *targetEp = nullptr;
      for (Episodio *ep : s->getEpisodios()) {
        if (ep->getId() == idEpisodio) {
          targetEp = ep;
          break;
        }
      }

      if (!targetEp) {
        cout << endl << "Episodio no encontrado." << endl;
        return;
      }

      targetEp->reproducir();
      break;
    }
    case 'c': {
      return;
    }
  }
}