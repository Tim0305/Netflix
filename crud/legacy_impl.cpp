#include "Usuario.h"
#include "Contenido.h"
#include "Pelicula.h"
#include <iostream>

Usuario::Usuario() {}
Contenido::Contenido() {}
Pelicula::Pelicula() {}
void Pelicula::mostrar() {
    std::cout << "[Pelicula] " << nombre
              << " | genero: " << genero << std::endl;
}
