#pragma once
#include "entities.h"
#include "sqlite_orm.h"
#include <string>

inline auto initStorage(const std::string& archivo) {
    using namespace sqlite_orm;
    return make_storage(
        archivo,
        make_table("usuarios",
            make_column("id",       &UsuarioEntity::id, primary_key().autoincrement()),
            make_column("nombre",   &UsuarioEntity::nombre),
            make_column("password", &UsuarioEntity::password),
            make_column("rol",      &UsuarioEntity::rol)),
        make_table("peliculas",
            make_column("id",           &PeliculaEntity::id, primary_key().autoincrement()),
            make_column("nombre",       &PeliculaEntity::nombre),
            make_column("genero",       &PeliculaEntity::genero),
            make_column("descripcion",  &PeliculaEntity::descripcion),
            make_column("duracion",     &PeliculaEntity::duracion),
            make_column("calificacion", &PeliculaEntity::calificacion)));
}

using Storage = decltype(initStorage(std::string{}));
