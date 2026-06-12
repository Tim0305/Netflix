# Base de Datos y CRUD

El manejo de almacenamiento a largo plazo usa el encapsulamiento de dependencias en el sistema de componentes `crud/` para garantizar la viabilidad y seguridad de la información interactuada.

## Tecnología de Base de Datos
Se utiliza **SQLite** para el guardado local, por su alta portabilidad y carencia de un servicio o servidor de conexión externo. En código del proyecto se implementa un ORM (Object-Relational Mapping) a través de la librería `sqlite_orm`, la cual interpreta las sentencias C++ a consultas SQL sin tener que escribir la llamada literal en strings.

## ¿Qué archivos manejan la persistencia?
La integración C++ hacia SQLite se gestiona bajo los siguientes archivos dentro de la carpeta `crud/`:
1. `entities.h`: Guarda los `struct` encargados de interpretar lo proveniente a la base de datos (Ej: `UsuarioEntity`, `PeliculaEntity`).
2. `repository.h`: El motor logístico central y conector principal con SQLite, usando la clase `Repositorio`. Aquí yacen los métodos para inserción, búsqueda, actualización y borrado.
3. `database.h` y `appdb.h`: Ayudantes para instanciar el uso de `Repositorio` a lo largo de los includes globales o buscar la ubicación y nombre en el que se localiza el banco de memoria SQLite (ej. creando un objeto `.sqlite` en base a perfiles a tu PC a través de rutas relacionales directas).

## Operaciones CRUD

A nivel de Repositorio, las famosas operaciones **CRUD** (Create, Read, Update, Delete) están construidas y expuestas en métodos directos del ORM.

**Explicación sencilla de qué es a nivel sistema:**
- **[C] Create:** Almacena nuevos registros por primera vez (`registrarUsuario`, `registrarPelicula`). 
- **[R] Read:** Efectúa búsquedas e impresiones de listas estáticas y sin cambios (`listarUsuarios`, `listarPeliculas`, `buscarUsuario`, `buscarUsuarioPorNombre`).
- **[U] Update:** Reescribe bajo el mismo bloque un registro ya previamente existente y devuelto (`actualizarUsuario`, `actualizarPelicula`).
- **[D] Delete:** Desintegra su existencia basándose en su llave única ID (`eliminarUsuario`, `eliminarPelicula`).

### Tablas Confirmadas Analizadas
Revisando `entities.h` y `repository.h`, existen y se guardan formalmente como mínimo estas **Tablas/Entidades** en la base de datos local predefinida:
1. `UsuarioEntity`: Almacena información de personas registradas, incluyendo su `id`, `nombre`, `password`, y `rol`.
2. `PeliculaEntity`: Almacena el repositorio predefinido de películas de la plataforma, incluyendo `id`, `nombre`, `genero`, `descripcion`, `duracion`, y `calificacion`.

*Pendiente de confirmar*: Por el momento no se encuentra explicitado en el CRUD el trato de guardado para la estructura de `Serie`, `Temporada` o `Episodio`. Se considera "Pendiente de confirmar" la persistencia de las mismas.

### Consultas SQL
Debido al uso de un esquema nativo a C++ mediante la arquitectura **ORM**, no se encuentra código explícito bajo formato texto (SQL estricto) inyectado; un ejemplo equivalente al `SELECT * FROM Usuarios WHERE rol = 'Admin'` presente en `repository.h` se declara nativamente así:
```cpp
storage.get_all<UsuarioEntity>(where(c(&UsuarioEntity::rol) == rol));
```