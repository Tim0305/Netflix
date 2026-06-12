#pragma once
#include "repository.h"
#include <QDir>
#include <string>

inline Repositorio& appDb() {
    static std::string ruta =
        (QDir::homePath() + "/netflix.sqlite").toStdString();
    static Repositorio repo(ruta);
    return repo;
}
