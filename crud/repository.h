#pragma once
#include "database.h"
#include <vector>
#include <memory>

class Repositorio {
public:
    explicit Repositorio(const std::string& archivo)
        : storage(initStorage(archivo)) {
        storage.sync_schema();
    }
    
    int registrarUsuario(const std::string& nombre,
                         const std::string& password,
                         const std::string& rol) {
        UsuarioEntity u;
        u.nombre = nombre;
        u.password = password;
        u.rol = rol;
        return storage.insert(u);   
    }
    std::vector<UsuarioEntity> listarUsuarios() {
        return storage.get_all<UsuarioEntity>();
    }
    std::unique_ptr<UsuarioEntity> buscarUsuario(int id) {
        return storage.get_pointer<UsuarioEntity>(id);
    }
    std::vector<UsuarioEntity> usuariosPorRol(const std::string& rol) {
        using namespace sqlite_orm;
        return storage.get_all<UsuarioEntity>(
            where(c(&UsuarioEntity::rol) == rol));
    }
    std::unique_ptr<UsuarioEntity> buscarUsuarioPorNombre(const std::string& nombre) {
        using namespace sqlite_orm;
        auto encontrados = storage.get_all<UsuarioEntity>(
            where(c(&UsuarioEntity::nombre) == nombre), limit(1));
        if (encontrados.empty()) return nullptr;
        return std::make_unique<UsuarioEntity>(encontrados.front());
    }
    bool actualizarUsuario(int id,
                           const std::string& nombre,
                           const std::string& password,
                           const std::string& rol) {
        auto actual = storage.get_pointer<UsuarioEntity>(id);
        if (!actual) return false;
        actual->nombre = nombre;
        actual->password = password;
        actual->rol = rol;
        storage.update(*actual);
        return true;
    }
    void eliminarUsuario(int id) {
        storage.remove<UsuarioEntity>(id);
    }


    int registrarPelicula(const std::string& nombre,
                          const std::string& genero,
                          const std::string& descripcion,
                          int duracion,
                          double calificacion) {
        PeliculaEntity p;
        p.nombre = nombre;
        p.genero = genero;
        p.descripcion = descripcion;
        p.duracion = duracion;
        p.calificacion = calificacion;
        return storage.insert(p);
    }
    std::vector<PeliculaEntity> listarPeliculas() {
        return storage.get_all<PeliculaEntity>();
    }
    std::unique_ptr<PeliculaEntity> buscarPelicula(int id) {
        return storage.get_pointer<PeliculaEntity>(id);
    }
    std::vector<PeliculaEntity> peliculasPorGenero(const std::string& genero) {
        using namespace sqlite_orm;
        return storage.get_all<PeliculaEntity>(
            where(c(&PeliculaEntity::genero) == genero));
    }
    bool actualizarPelicula(int id,
                            const std::string& nombre,
                            const std::string& genero,
                            const std::string& descripcion,
                            int duracion,
                            double calificacion) {
        auto actual = storage.get_pointer<PeliculaEntity>(id);
        if (!actual) return false;
        actual->nombre = nombre;
        actual->genero = genero;
        actual->descripcion = descripcion;
        actual->duracion = duracion;
        actual->calificacion = calificacion;
        storage.update(*actual);
        return true;
    }
    void eliminarPelicula(int id) {
        storage.remove<PeliculaEntity>(id);
    }

private:
    Storage storage;
};
