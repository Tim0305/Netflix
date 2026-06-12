#include <iostream>
#include <vector>

#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"

using namespace std;

int main()
{
    cout << "===== CREANDO PELICULAS =====" << endl;

    Pelicula p1(
        1,
        "Avengers",
        "Superheroes",
        7200,
        "Accion",
        "portada1.jpg",
        "avengers.mp4"
    );

    Pelicula p2(
        2,
        "Titanic",
        "Drama romantico",
        10800,
        "Drama",
        "portada2.jpg",
        "titanic.mp4"
    );

    p1.addCalificacion(5);
    p1.addCalificacion(4);

    p2.addCalificacion(3);
    p2.addCalificacion(4);

    cout << endl;
    cout << p1.getNombre()
         << " -> "
         << p1.getCalificacion()
         << endl;

    cout << p2.getNombre()
         << " -> "
         << p2.getCalificacion()
         << endl;

    cout << endl;

    if (p1 > 4.0)
    {
        cout << p1.getNombre()
             << " tiene calificacion mayor a 4"
             << endl;
    }

    cout << endl;

    cout << "===== CREANDO EPISODIOS =====" << endl;

    Episodio ep1(
        101,
        "Piloto",
        "Primer episodio",
        3600,
        "Drama",
        "",
        "",
        1
    );

    Episodio ep2(
        102,
        "Capitulo 2",
        "Segundo episodio",
        3600,
        "Drama",
        "",
        "",
        1
    );

    Episodio ep3(
        103,
        "Capitulo 3",
        "Tercer episodio",
        3600,
        "Drama",
        "",
        "",
        1
    );

    ep1.addCalificacion(5);
    ep2.addCalificacion(4);
    ep3.addCalificacion(3);

    cout << "Calificacion episodio 1: "
         << ep1.getCalificacion()
         << endl;

    cout << "Calificacion episodio 2: "
         << ep2.getCalificacion()
         << endl;

    cout << "Calificacion episodio 3: "
         << ep3.getCalificacion()
         << endl;

    cout << endl;

    cout << "===== CREANDO SERIE =====" << endl;

    Serie serie1(
        10,
        "Breaking Bad",
        "Serie famosa",
        0,
        "Drama",
        "",
        ""
    );

    serie1.addEpisodio(ep1);
    serie1.addEpisodio(ep2);
    serie1.addEpisodio(ep3);

    cout << "Promedio usando operador + : "
         << +serie1
         << endl;

    cout << "Promedio usando getCalificacion() : "
         << serie1.getCalificacion()
         << endl;

    cout << endl;

    cout << "===== POLIMORFISMO =====" << endl;

    vector<Contenido*> catalogo;

    catalogo.push_back(&p1);
    catalogo.push_back(&p2);
    catalogo.push_back(&serie1);

    for (Contenido* contenido : catalogo)
    {
        cout
        << contenido->getNombre()
        << " -> "
        << contenido->getCalificacion()
        << endl;
    }

    cout << endl;

    cout << "===== FILTRO > 4 =====" << endl;

    for (Contenido* contenido : catalogo)
    {
        if (*contenido > 4.0)
        {
            cout
            << contenido->getNombre()
            << " cumple"
            << endl;
        }
    }

    return 0;
}
// =======
// #include "mainwindow.h"

// #include <QApplication>

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     MainWindow w;
//     w.show();
//     return QApplication::exec();
// }
// >>>>>>> 8104912432534cf40b83ba81de74a153c021df3c
