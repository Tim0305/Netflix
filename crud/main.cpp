#include "repository.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

static string leerTexto(const string& etiqueta) {
    cout << etiqueta;
    string valor;
    getline(cin, valor);
    return valor;
}

static int leerEntero(const string& etiqueta) {
    cout << etiqueta;
    int valor = 0;
    while (!(cin >> valor)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valor invalido. " << etiqueta;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return valor;
}

static double leerDouble(const string& etiqueta) {
    cout << etiqueta;
    double valor = 0;
    while (!(cin >> valor)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valor invalido. " << etiqueta;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return valor;
}


static void menuUsuarios(Repositorio& repo) {
    while (true) {
        cout << "\n--- USUARIOS ---\n"
             << "1) Registrar usuario\n"
             << "2) Listar usuarios\n"
             << "3) Buscar usuario por id\n"
             << "4) Buscar usuarios por rol\n"
             << "5) Actualizar usuario\n"
             << "6) Eliminar usuario\n"
             << "0) Volver\n";
        int op = leerEntero("Opcion: ");

        if (op == 0) return;
        else if (op == 1) {
            string nombre = leerTexto("Nombre: ");
            string pass   = leerTexto("Password: ");
            string rol    = leerTexto("Rol (admin/cliente): ");
            int id = repo.registrarUsuario(nombre, pass, rol);
            cout << "Usuario creado con id " << id << "\n";
        }
        else if (op == 2) {
            auto usuarios = repo.listarUsuarios();
            cout << "Total: " << usuarios.size() << "\n";
            for (const auto& u : usuarios)
                cout << "  #" << u.id << "  " << u.nombre
                     << "  [" << u.rol << "]\n";
        }
        else if (op == 3) {
            int id = leerEntero("Id: ");
            auto u = repo.buscarUsuario(id);
            if (u) cout << "#" << u->id << "  " << u->nombre
                        << "  [" << u->rol << "]\n";
            else   cout << "No existe ese usuario.\n";
        }
        else if (op == 4) {
            string rol = leerTexto("Rol a buscar: ");
            auto usuarios = repo.usuariosPorRol(rol);
            cout << "Encontrados: " << usuarios.size() << "\n";
            for (const auto& u : usuarios)
                cout << "  #" << u.id << "  " << u.nombre << "\n";
        }
        else if (op == 5) {
            int id = leerEntero("Id a actualizar: ");
            string nombre = leerTexto("Nuevo nombre: ");
            string pass   = leerTexto("Nuevo password: ");
            string rol    = leerTexto("Nuevo rol: ");
            if (repo.actualizarUsuario(id, nombre, pass, rol))
                cout << "Actualizado.\n";
            else
                cout << "No existe ese usuario.\n";
        }
        else if (op == 6) {
            int id = leerEntero("Id a eliminar: ");
            repo.eliminarUsuario(id);
            cout << "Eliminado (si existia).\n";
        }
        else cout << "Opcion invalida.\n";
    }
}

static void menuPeliculas(Repositorio& repo) {
    while (true) {
        cout << "\n--- PELICULAS ---\n"
             << "1) Registrar pelicula\n"
             << "2) Listar peliculas\n"
             << "3) Buscar pelicula por id\n"
             << "4) Buscar peliculas por genero\n"
             << "5) Actualizar pelicula\n"
             << "6) Eliminar pelicula\n"
             << "0) Volver\n";
        int op = leerEntero("Opcion: ");

        if (op == 0) return;
        else if (op == 1) {
            string nombre = leerTexto("Nombre: ");
            string genero = leerTexto("Genero: ");
            string desc   = leerTexto("Descripcion: ");
            int dur       = leerEntero("Duracion (min): ");
            double cal    = leerDouble("Calificacion (0-10): ");
            int id = repo.registrarPelicula(nombre, genero, desc, dur, cal);
            cout << "Pelicula creada con id " << id << "\n";
        }
        else if (op == 2) {
            auto pelis = repo.listarPeliculas();
            cout << "Total: " << pelis.size() << "\n";
            for (const auto& p : pelis)
                cout << "  #" << p.id << "  " << p.nombre
                     << "  (" << p.genero << ", " << p.duracion << " min, "
                     << p.calificacion << ")\n";
        }
        else if (op == 3) {
            int id = leerEntero("Id: ");
            auto p = repo.buscarPelicula(id);
            if (p) cout << "#" << p->id << "  " << p->nombre
                        << "  (" << p->genero << ")\n  " << p->descripcion << "\n";
            else   cout << "No existe esa pelicula.\n";
        }
        else if (op == 4) {
            string genero = leerTexto("Genero a buscar: ");
            auto pelis = repo.peliculasPorGenero(genero);
            cout << "Encontradas: " << pelis.size() << "\n";
            for (const auto& p : pelis)
                cout << "  #" << p.id << "  " << p.nombre << "\n";
        }
        else if (op == 5) {
            int id = leerEntero("Id a actualizar: ");
            string nombre = leerTexto("Nuevo nombre: ");
            string genero = leerTexto("Nuevo genero: ");
            string desc   = leerTexto("Nueva descripcion: ");
            int dur       = leerEntero("Nueva duracion: ");
            double cal    = leerDouble("Nueva calificacion: ");
            if (repo.actualizarPelicula(id, nombre, genero, desc, dur, cal))
                cout << "Actualizada.\n";
            else
                cout << "No existe esa pelicula.\n";
        }
        else if (op == 6) {
            int id = leerEntero("Id a eliminar: ");
            repo.eliminarPelicula(id);
            cout << "Eliminada (si existia).\n";
        }
        else cout << "Opcion invalida.\n";
    }
}

int main() {
    Repositorio repo("netflix.sqlite");
    cout << "Base de datos 'netflix.sqlite' lista.\n";

    while (true) {
        cout << "\n===== NETFLIX CRUD =====\n"
             << "1) Usuarios\n"
             << "2) Peliculas\n"
             << "0) Salir\n";
        int op = leerEntero("Opcion: ");

        if (op == 0) { cout << "Hasta luego!\n"; break; }
        else if (op == 1) menuUsuarios(repo);
        else if (op == 2) menuPeliculas(repo);
        else cout << "Opcion invalida.\n";
    }
    return 0;
}
