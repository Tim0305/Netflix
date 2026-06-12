#pragma once
#include "entities.h"
#include "sqlite_orm.h"
#include <string>

inline auto initStorage(const string& archivo) {
    using namespace sqlite_orm;
    return make_storage(
        archivo,
        make_table("usuarios",
            make_column("id",       &UsuarioEntity::id, primary_key().autoincrement()),
            make_column("nombre",   &UsuarioEntity::nombre),
            make_column("password", &UsuarioEntity::password),
            make_column("rol",      &UsuarioEntity::rol)),

        make_table("calificaciones",
            make_column("id",             &CalificacionEntity::id, primary_key().autoincrement()),
            make_column("contenido_id",   &CalificacionEntity::contenido_id),
            make_column("valor",          &CalificacionEntity::valor)),
            
        make_table("peliculas",
            make_column("id",                   &PeliculaEntity::id, primary_key().autoincrement()),
            make_column("nombre",               &PeliculaEntity::nombre),
            make_column("descripcion",          &PeliculaEntity::descripcion),
            make_column("duracion",             &PeliculaEntity::duracion),
            make_column("numeroCalificaciones", &PeliculaEntity::numeroCalificaciones),
            make_column("genero",               &PeliculaEntity::genero),
            make_column("portada",              &PeliculaEntity::portada),
            make_column("video",                &PeliculaEntity::video)),
            
        make_table("series",
            make_column("id",                   &SerieEntity::id, primary_key().autoincrement()),
            make_column("nombre",               &SerieEntity::nombre),
            make_column("descripcion",          &SerieEntity::descripcion),
            make_column("duracion",             &SerieEntity::duracion),
            make_column("numeroCalificaciones", &SerieEntity::numeroCalificaciones),
            make_column("genero",               &SerieEntity::genero),
            make_column("portada",              &SerieEntity::portada),
            make_column("video",                &SerieEntity::video)),
            
        make_table("episodios",
            make_column("id",                   &EpisodioEntity::id, primary_key().autoincrement()),
            make_column("serie_id",             &EpisodioEntity::serie_id),
            make_column("temporada",            &EpisodioEntity::temporada),
            make_column("nombre",               &EpisodioEntity::nombre),
            make_column("descripcion",          &EpisodioEntity::descripcion),
            make_column("duracion",             &EpisodioEntity::duracion),
            make_column("calificacion",         &EpisodioEntity::calificacion),
            make_column("numeroCalificaciones", &EpisodioEntity::numeroCalificaciones),
            make_column("genero",               &EpisodioEntity::genero),
            make_column("portada",              &EpisodioEntity::portada),
            make_column("video",                &EpisodioEntity::video),
            foreign_key(&EpisodioEntity::serie_id).references(&SerieEntity::id))
    );
}

using Storage = decltype(initStorage(std::string{}));