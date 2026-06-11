#include <iostream>

#include "Pelicula.h"
#include "Serie.h"
#include "Temporada.h"
#include "Episodio.h"
#include "Usuario.h"

using namespace std;

int main(){

    Pelicula p1(
        1,
        "Interstellar",
        169,
        "Ciencia Ficcion");

    p1.setCalificacion(9.5);

    Pelicula p2(
        2,
        "Avatar",
        162,
        "Aventura");

    p2.setCalificacion(8.8);

    Episodio e1(
        1,
        "El Principio",
        45,
        1);

    e1.setCalificacion(9.0);

    Episodio e2(
        2,
        "La Decision",
        50,
        1);

    e2.setCalificacion(8.5);

    Episodio e3(
        3,
        "El Regreso",
        48,
        2);

    e3.setCalificacion(9.5);

    Temporada t1(1);

    t1.agregarEpisodio(e1);
    t1.agregarEpisodio(e2);

    Temporada t2(2);

    t2.agregarEpisodio(e3);


    Serie s1(
        3,
        "Dark",
        0,
        "Drama");

    s1.agregarTemporada(t1);
    s1.agregarTemporada(t2);


    Usuario u1(
        1,
        "Carlos",
        "1234",
        "Administrador");


    cout << "USUARIO" << endl;
    u1.mostrar();

    cout << endl;


    Contenido *catalogo[3];

    catalogo[0] = &p1;
    catalogo[1] = &p2;
    catalogo[2] = &s1;

    cout << "CATALOGO" << endl;

    for(int i = 0; i < 3; i++){

        catalogo[i]->mostrar();

        cout << "Calificacion: "
             << catalogo[i]->getCalificacion()
             << endl;

        cout << endl;
    }

    return 0;
}