#include "Contenido.h"
#include <iostream>
#include <array>
#include <memory>
#include <opencv2/opencv.hpp>

using namespace cv;

namespace {
    string exec(const char* cmd) {
        array<char, 128> buffer;
        string result;
        unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe) {
            throw runtime_error("popen() falló!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        result.erase(result.find_last_not_of(" \n\r\t") + 1);
        return result;
    }
}

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

bool Contenido::operator>(double valor)
{
    return getCalificacion() > valor;
}

void Contenido::reproducir() const {
    if (this->video.empty()) {
        cout << "Error: No hay un enlace de video asignado a '" << this->nombre << "'." << endl;
        return;
    }
    cout << "Cargando video de: " << this->nombre << "..." << endl;
    string cmd = "yt-dlp -f \"best[height<=720]\" --get-url \"" + this->video + "\"";
    string direct_url = exec(cmd.c_str());
    if (direct_url.empty()) {
        cerr << "Error: No se pudo resolver la URL del video de YouTube." << endl;
        return;
    }
    VideoCapture cap(direct_url);
    if (!cap.isOpened()) {
        cerr << "Error: OpenCV no pudo abrir el stream de video." << endl;
        return;
    }
    string window_name = "Reproduciendo: " + this->nombre;
    namedWindow(window_name, WINDOW_NORMAL);
    resizeWindow(window_name, 854, 480);
    Mat frame;
    cout << "Reproduciendo... (Presiona 'q' o 'ESC' en la ventana para cerrarla)" << endl;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;
        imshow(window_name, frame);
        char key = (char)waitKey(30);
        if (key == 'q' || key == 27) {
            break;
        }
    }
    destroyWindow(window_name);
    cap.release();
}
