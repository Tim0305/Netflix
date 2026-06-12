# Netflix

![Estado](https://img.shields.io/badge/Estado-En%20Desarrollo-yellow)

## Descripción General
Este es un proyecto académico tipo "Netflix" desarrollado en **C++** que permite a los usuarios explorar y gestionar películas y series. El sistema incluye funcionalidades de autenticación (login y registro), un panel de administración para la gestión de usuarios, películas y géneros, e interactúa con una base de datos **SQLite**.

## Objetivo del Sistema
El propósito de este proyecto es aplicar los conceptos de Programación Orientada a Objetos en C++ en un entorno práctico usando **Qt** para la interfaz gráfica y **CMake** para la construcción del proyecto, aplicando operaciones CRUD para persistir datos.

## Tecnologías Utilizadas
- **Lenguaje:** C++ (compatible con C++17)
- **Interfaz Gráfica:** Qt (Qt 5 / Qt 6)
- **Construcción:** CMake
- **Base de Datos:** SQLite3 (con sqlite_orm)

## Funcionalidades Principales
- **Autenticación:** Inicio de sesión y registro de usuarios.
- **Roles:** Soporte para usuarios estándar y administradores.
- **Gestión de Usuarios (CRUD):** Los administradores pueden visualizar, crear, modificar y eliminar usuarios.
- **Gestión de Películas (CRUD):** Funciones para añadir, editar, ver y eliminar películas en el catálogo.
- **Gestión de Géneros:** Herramientas para organizar el contenido por géneros.

## Estructura General del Repositorio
```
Netflix/
├── CMakeLists.txt         # Configuración principal de compilación CMake
├── main.cpp               # Punto de entrada de la aplicación
├── *.cpp / *.h            # Implementación de las clases y ventanas del sistema
├── *.ui                   # Archivos de interfaz de usuario de Qt Designer
├── crud/                  # Lógica de base de datos y operaciones CRUD (SQLite)
├── docs/                  # Documentación del proyecto
└── build/                 # Directorio de compilación (ignorado por Git)
```

## Instrucciones Rápidas
1. Clona el repositorio:
   ```bash
   git clone <URL_DEL_REPOSITORIO>
   cd Netflix
   ```
2. Abre el proyecto en **Qt Creator** o **VS Code** (usando las extensiones CMake Tools y Qt).
3. Configura el proyecto con **CMake**.
4. Compila y ejecuta el proyecto.

*Nota:* Asegúrate de tener los componentes de Qt instalados y configurados en tu entorno. Puedes consultar en [Instalación](docs/instalacion.md) para más detalles.

## Documentación
Puedes encontrar una guía completa en la carpeta `docs/`:
- [Índice Principal de Documentación](docs/README.md)
- [Instalación](docs/instalacion.md)
- [Arquitectura](docs/arquitectura.md)
- [Clases](docs/clases.md)
- [Interfaz](docs/interfaz.md)
- [Base de Datos](docs/base-de-datos.md)
- [Flujo de Git](docs/flujo-git.md)
- [Manual de Usuario](docs/manual-usuario.md)
- [Manual de Desarrollador](docs/manual-desarrollador.md)

## Estado Actual
Nota: El proyecto se encuentra en desarrollo.

## Integrantes
- Timo
- Victor
- Karla
- Alvaro
- Alex
