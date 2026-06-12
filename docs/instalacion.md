# Guía de Instalación

Esta guía te ayudará a preparar tu entorno, clonar, compilar y ejecutar el proyecto de Netflix en tu computadora local.

## Requisitos Previos
Para poder trabajar con este proyecto, tu equipo necesita el siguiente software:

- **Git** (Para descargar el código y colaborar).
- **Compilador C++** compatible con el estándar C++17. (MinGW en Windows, GCC/Clang en Linux, o Apple Clang en macOS).
- **CMake** (Versión 3.5 o superior) para generar el sistema de construcción de la aplicación.
- **SQLite3** (Suele estar incluido o ser fácilmente instalable, el proyecto usa la librería `sqlite_orm`).
- **Librerías de Qt 5 o Qt 6**.
- **IDE Recomendado:** VS Code (con las extensiones *C/C++*, *CMake Tools*, y *Qt para CMake*) o **Qt Creator**.

## 1. Clonar el repositorio
Abre una terminal y ejecuta el siguiente comando donde deseas guardar los archivos:
```bash
git clone <URL_DEL_REPOSITORIO>
cd Netflix
```

## 2. Abrir y Compilar

### Opción A: Usando Qt Creator
1. Abre Qt Creator.
2. Ve a `Archivo` -> `Abrir Archivo o Proyecto...`
3. Navega hacia la carpeta `Netflix/` y selecciona el archivo `CMakeLists.txt`.
4. Qt Creator te mostrará una pantalla para realizar la configuración del proyecto (kits de compilación). Selecciona tu kit (ej. Desktop Qt 6) y presiona "Configurar Proyecto".
5. Usa el botón verde de "Reproducir" (o `Ctrl + R` / `Cmd + R`) en la esquina inferior izquierda para compilar y ejecutar automáticamente.

### Opción B: Usando Visual Studio Code (VS Code)
1. Abre VS Code en la carpeta del repositorio.
2. Instala la extensión **CMake Tools** y **C/C++** si aún no las tienes.
3. Se te debería preguntar un *Kit* de CMake y usar buscar tu compilador disponible (GCC, Clang, MSVC). También asegúrate de que CMake Tools pueda encontrar tu instalación de Qt, puede que necesites definir la variable de entorno `CMAKE_PREFIX_PATH` apuntando a tu instalación de Qt (ej. `C:/Qt/6.x.x/mingw.../lib/cmake`).
4. Haz clic en **"Build"** (Compilar) en la barra inferior o presiona la tecla `F7`.
5. Una vez compilado con éxito, presiona el botón de **"Run"** (o en la Terminal, ejecuta el binario generado, comúnmente ubicado en `build/Netflix.exe`).

## Problemas Comunes y Soluciones

- **Error al encontrar Qt a través de CMake:**
  *Mensaje referencial: "Could NOT find Qt6..."*
  - **Solución:** Asegúrate de configurar en tu entorno la variable `CMAKE_PREFIX_PATH` indicando la ruta hacia la carpeta de `cmake` de tu versión de Qt descargada.

- **Faltan librerías o dependencias de compilador:**
  - **Solución:** Revisa que el compilador elegido soporte la misma arquitectura (32 bits o 64 bits) en la que Qt fue instalado.

- **La aplicación inicia, pero muestra errores en terminal relacionados con archivos base de datos (.sqlite):**
  - **Solución:** Revisa que tu usuario tenga permisos de escritura en la carpeta especificada en `QDir::homePath()` o la carpeta raíz del proyecto, puesto que allí se alojará el archivo `.sqlite`.