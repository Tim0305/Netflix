#pragma once
#include "database.h"
#include <vector>
#include <memory>
using namespace sqlite_orm;

class Repositorio {
public:
    explicit Repositorio(const string& archivo)
        : storage(initStorage(archivo)) {
        storage.sync_schema();
    }    

    int registrarUsuario(const string& nombre, const string& password, const string& rol) {
        UsuarioEntity u;
        u.nombre = nombre; u.password = password; u.rol = rol;
        return storage.insert(u);   
    }
    std::vector<UsuarioEntity> listarUsuarios() { return storage.get_all<UsuarioEntity>(); }
    std::unique_ptr<UsuarioEntity> buscarUsuario(int id) { return storage.get_pointer<UsuarioEntity>(id); }
    void eliminarUsuario(int id) { storage.remove<UsuarioEntity>(id); }

    int agregarCalificacion(const string& tipo_contenido, int contenido_id, double valor) {
        CalificacionEntity c;
        c.contenido_id = contenido_id;
        c.valor = valor;
        return storage.insert(c);
    }

    std::vector<double> obtenerVectorCalificaciones(const string& tipo_contenido, int contenido_id) {
        auto entidades = storage.get_all<CalificacionEntity>(
        where(c(&CalificacionEntity::contenido_id) == contenido_id)
        );
        std::vector<double> valores;
        for (const auto& entidad : entidades) {
            valores.push_back(entidad.valor);
        }
        return valores;
    }

    int registrarPelicula(const string& nombre, const string& descripcion, double duracion, double calificacion, int numCalificaciones, const string& genero, const string& portada, const string& video) {
        PeliculaEntity p;
        p.nombre = nombre; p.descripcion = descripcion; p.duracion = duracion;
        p.genero = genero; p.portada = portada; p.video = video;
        return storage.insert(p);
    }
    std::vector<PeliculaEntity> listarPeliculas() { return storage.get_all<PeliculaEntity>(); }
    std::unique_ptr<PeliculaEntity> buscarPelicula(int id) { return storage.get_pointer<PeliculaEntity>(id); }
    void eliminarPelicula(int id) { storage.remove<PeliculaEntity>(id); }

    int registrarSerie(const string& nombre, const string& descripcion, double duracion, double calificacion, int numCalificaciones, const string& genero, const string& portada, const string& video) {
        SerieEntity s;
        s.nombre = nombre; s.descripcion = descripcion; s.duracion = duracion;
        s.genero = genero; s.portada = portada; s.video = video;
        return storage.insert(s);
    }
    std::vector<SerieEntity> listarSeries() { return storage.get_all<SerieEntity>(); }
    std::unique_ptr<SerieEntity> buscarSerie(int id) { return storage.get_pointer<SerieEntity>(id); }
    void eliminarSerie(int id) { storage.remove<SerieEntity>(id); }

    int registrarEpisodio(int serie_id, int temporada, const string& nombre, const string& descripcion, double duracion, double calificacion, int numCalificaciones, const string& genero, const string& portada, const string& video) {
        EpisodioEntity e;
        e.serie_id = serie_id; e.temporada = temporada; e.nombre = nombre;
        e.descripcion = descripcion; e.duracion = duracion; e.calificacion = calificacion;
        e.numeroCalificaciones = numCalificaciones; e.genero = genero;
        e.portada = portada; e.video = video;
        return storage.insert(e);
    }
    std::vector<EpisodioEntity> listarEpisodios() { return storage.get_all<EpisodioEntity>(); }
    std::unique_ptr<EpisodioEntity> buscarEpisodio(int id) { return storage.get_pointer<EpisodioEntity>(id); }
    
    std::vector<EpisodioEntity> episodiosPorSerie(int serie_id) {
        using namespace sqlite_orm;
        return storage.get_all<EpisodioEntity>(
            where(c(&EpisodioEntity::serie_id) == serie_id)
        );
    }
    void eliminarEpisodio(int id) { storage.remove<EpisodioEntity>(id); }

private:
    Storage storage;
};