# Clases del Sistema

En esta sección se documentan principalmente las clases pertenecientes a la capa del "Dominio", fundamentales para estructurar la información manejada por el sistema.

## `Contenido`
**Archivos:** `Contenido.h`, `Contenido.cpp`

Es la clase padre en la clasificación de contenido audiovisual dentro de la plataforma. Ha sido estructurada como una clase **Abstracta**.

- **Responsabilidad:** Agrupar y proporcionar características y funcionalidades genéricas y redundantes tanto de series como de películas (ID, duración, nombre, género).
- **Atributos Importantes:**
  - `int id`, `duracion`, `numcalificaciones`
  - `double calificacion`
  - `string nombre`, `genero`, `descripcion`, `portada`, `src`
- **Métodos Importantes:**
  - `double getCalificacion()`, `string getGenero()`, `string getNombre()`
  - `void setCalificacion(double calificacion)`
  - `virtual void mostrar() = 0` *(Método virtual puro que obliga a las subclases a sobreescribirlo).*
- **Relación con otras clases:** Padre de las clases `Pelicula` y `Serie`.

---

## `Pelicula`
**Archivos:** `Pelicula.h`, `Pelicula.cpp`

- **Responsabilidad:** Representar una entidad de largometraje, es decir, un archivo y consumo audiovisual de bloque único.
- **Atributos Importantes:** 
  - Hereda los atributos del padre `Contenido`.
- **Métodos Importantes:**
  - `void mostrar() override;` (Implementación obligada del método abstracto del padre).
- **Relación con otras clases:** Hereda directamente de `Contenido`.
- **Observaciones:** Para la persistencia se suele mapear usando un struct adicional llamado `PeliculaEntity` ubicado en el directorio `crud/`.

---

## `Serie`
**Archivos:** `Serie.h`, `Serie.cpp`

- **Responsabilidad:** Representar al conjunto macro de una producción seriada, subdividida por temporadas.
- **Atributos Importantes:**
  - `vector<Temporada> temporadas;` (Arreglo con la lógica o el objeto de sub-agrupamiento).
  - Adquiere los atributos heredados de `Contenido`.
- **Métodos Importantes:**
  - `void agregarTemporada(Temporada temporada);`
  - `double getCalificacion();`
  - `void mostrar() override;`
- **Relación con otras clases:** Hereda de `Contenido`. Posee una relación de Composición/Agregación directa integrando de ceros a muchas variables del tipo `Temporada` dentro de su vector.

---

## `Temporada`
**Archivos:** `Temporada.h`, `Temporada.cpp`

- **Responsabilidad:** Actuar como puente y agrupación modular de capítulos bajo un mismo lapso productivo del proyecto seriado.
- **Atributos Importantes:**
  - `int numero;` (Número de la temporada)
  - `vector<Episodio> episodios;`
- **Métodos Importantes:**
  - `void agregarEpisodio(Episodio episodio);`
  - `double getCalificacion();`
  - `void mostrar();`
- **Relación con otras clases:** Componente subordinado de `Serie` y elemento raíz manejador del objeto `Episodio`.

---

## `Episodio`
**Archivos:** `Episodio.h`, `Episodio.cpp`

- **Responsabilidad:** Constituir la unidad base visualizada al final de toda la ramificación temporal de la Serie.
- **Atributos Importantes:**
  - `int id`, `duracion`, `temporada;`
  - `string titulo`, `descripcion`, `src;`
  - `double calificacion;`
- **Métodos Importantes:**
  - `double getCalificacion();`
  - `void setCalificacion(double calificacion);`
  - `void mostrar();`
- **Relación con otras clases:** Pieza íntegra y contenido subalterno de forma obligada hacia un struct del tipo `Temporada`.

---

## `Usuario`
**Archivos:** `Usuario.h`, `Usuario.cpp`

- **Responsabilidad:** Manejar los permisos y acreditación de uso para personas interactuando y abriendo nuestro aplicativo.
- **Atributos Importantes:**
  - `int id;`
  - `string nombre`, `password`, `rol;`
- **Métodos Importantes:**
  - `void mostrar();`
- **Relación con otras clases:** Puede instanciarse a lo largo del sistema a la hora de determinar comportamientos a través del `rol`.
- **Observaciones:** El manejo para lectura SQL está envuelto en `UsuarioEntity`.