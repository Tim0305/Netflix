#ifndef CONTENIDO_H
#define CONTENIDO_H

#include <string>

using namespace std;

class Contenido {

protected:

    int id;
    string nombre;
    string descripcion;
    int duracion;

    double calificacion;
    int numeroCalificaciones;

    string genero;
    string portada;
    string video;

public:

    Contenido();

    Contenido(
        int id,
        string nombre,
        string descripcion,
        int duracion,
        string genero,
        string portada,
        string video
    );

    virtual ~Contenido();

    // Getters
    int getId() const;
    string getNombre() const;
    string getDescripcion() const;
    int getDuracion() const;
    string getGenero() const;
    string getPortada() const;
    string getVideo() const;

    virtual double getCalificacion() const = 0;

    // Setters
    void setId(int id);
    void setNombre(string nombre);
    void setDescripcion(string descripcion);

    void setDuracion(int duracion);
    void setDuracion(
        int horas,
        int minutos,
        int segundos
    );

    void setGenero(string genero);
    void setPortada(string portada);
    void setVideo(string video);

    void addCalificacion(double valor);

    bool operator>(double valor);
};

#endif