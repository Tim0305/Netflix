# Manual para Desarrolladores

Si te estás uniendo al equipo de Timflix / Netflix para apoyarnos con futuras implementes, o si simplemente buscas integrar un nivel lógico más elevado para optimizaciones, aquí encontrarás pautas que definen las mecánicas o el status de la estructura del aplicativo bajo la manipulación de este.

## 1. Organización del Código

El proyecto posee esta matriz interna generalizada con clases atómicas esparcidas que conviven en el árbol base de la carpeta `Netflix/`:

- **Gestión de Ventanas y Widgets:** Para cada objeto gráfico verás siempre una triada inseparable conformada por un `.ui` (Diseño QT), `.h` (Definición e Instanciación Visual) y un `.cpp` (Las tripas operacionales lógicas que emiten señales bajo componentes). 
  Ej. `usuarioswindow.ui` | `usuarioswindow.h` | `usuarioswindow.cpp`
- **Gestión de Clases C++:** Orientada con OOP bajo separaciones `.h` y un `.cpp`.
- **Integración SQLite y Memoria Estructurada:** Carpeta `crud/`. Ahí subyacen todos los macros para la inyección y abstracción del CRUD del SQL interno manejado bajo el paraguas técnico de la API externa de `sqlite_orm` y C++. 

## 2. Cómo agregar una nueva Ventana

1. Abre **Qt Creator** e instálate sobre la lista de la estructura raíz del repositorio, da clic derecho -> *Agrega un Nuevo Archivo* -> *Clase de Qt Designer (Qt Designer Form Class).*
2. Elige generalmente una *QDialog* o un *Widget*.
3. Bríndale un nombre descriptivo, bajo snake_case descriptiva concatenando la palabra que describe si es widget o window `pantallasecundariawindow`. Qt completará por ti las extensiones de `cpp`, `h` y `ui`.
4. El archivo se debe añadir automáticamente al árbol de binarios manejado por tu compilador. Abre el `CMakeLists.txt` alojado, busca el bloque central y agrégalo manualmente bajo tu sintaxis del *add_executable().*

## 3. Cómo agregar una nueva Clase

De antemano se pide respetar el paradigma de encapsulamiento básico. Agrega archivos limpios de herencia para la abstracción del código (ej. un `Controlador.h` y `Controlador.cpp`).

- Si tu clase define comportamientos del catálogo audiovisual, estudia si debe heredar puramente desde el archivo de componente principal `Contenido`.
- Si requiere guardarse a la base de datos (Persistencia SQL permanente), debe crearse en paralelo un `struct NuevaclaseEntity` en el header de `crud/entities.h` que le herede.

## 4. Trabajo de Interfaz bajo Archivos `.ui`

Nunca escribas o redibujes por manipulación de código XML explícito el contenido del diseño frontal ya que perderás mucho tiempo.
Abre tu Qt Creator (O instálate una extensión oficial de editor visual integrado) frente al layout en la malla y recurre explícitamente a posicionamientos por *Drag and Drop* con apoyo del bloque organizador modular *Layouts*. 
Recuerda brindar buenos *objectNames* como `btn_aceptar` para utilizarlos luego referenciado bajo el puntero dentro de C++: `ui->btn_aceptar`. 

## 5. CMakeLists

`CMakeLists.txt` es tu gerente fundamental para indicarle a nuestro ecosistema cómo se unen al compilar las configuraciones generadas en local.

* **Requerimientos básicos de Qt**: Dentro de CMake está integrado y validado con instrucciones formales previas los comandos de `set(CMAKE_AUTOUIC ON)` que facilita el amarre que CMake procese todos tus diseños `.ui` sin que se le ordene a mano bajo las rutinas `moc`.
* Al añadir, compila los sistemas, limpia caché e incluye el ejecutable a ejecutar.

## 6. Integración Funcional con CRUD y Base de Datos

Ante eventuales tablas necesarias para las operaciones CRUD locales a lo largo del sistema: 
1. Sitúate en el archivo `crud/repository.h`, observa cómo la biblioteca llama a sus punteros mediante `sqlite_orm`.
2. Sigue el diseño estructural del código usando `storage.insert(...)` o referenciándote mediante `storage.get_all<MiStructEntity>(x)`.
3. Es fundamental invocar al inicio la validación global instanciada que expida `appDb()` desde el objeto estático pre-guardado por el ambiente global Qt en el path local para tu SO usando la referencia a su ruta.

## 7. Convenciones recomendadas

1. **Snake_Case en ventanas/clases de interfaz (Archivos locales de código):** Usa el minúsculas sin camel localizados con prefijos tipo `modificarusuariowindow.cpp` para archivos de UI.
2. **PascalCase para Clases Nativas C++**: `Pelicula.cpp`, `Temporada.cpp`.
3. Mantenimiento del español técnico y claro para nombres de variables y explicacion general en el sistema interno (ej: `getCalificacion()`, `mostrar()`).

## 8. Pendientes Técnicos
* **Verificación de tablas para series y temporadas:** Actualmente el diseño expone el ORM formalizado para *Usuarios* (`UsuarioEntity`) y *Películas* (`PeliculaEntity`) en su inserción y edición, falta comprobar una expansión e implementación final por detrás referenciada hacia elementos listados formales para `Series`, `Temporadas`, y `Episiodios` o adaptarlos en bloque con serializaciones para evitar inconsistencias relacionales SQL a la larga. 
* **Depuración UI Inicial**: Confirmar estricta interconexión y visualización sin excepciones entre las partes visuales abstractas implementadas actualmente por los menús del logeo con redirecciones hacia los menús *Estándares* versus *Admin* para evitar vulneraciones.
* Cierre final de variables y clases sin uso presentes en los repositorios de inclusión.