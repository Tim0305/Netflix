# Flujo de Trabajo en Git

Este documento es una guía sencilla para que todos los integrantes del proyecto puedan colaborar y evitar problemas a la hora de manipular el repositorio alojado. Está redactado pensando en las personas más novatas a la plataforma **Git**.

### Introducción Básica
Asegúrate de nunca trabajar de forma insegura en el punto final central ("rama `main`"). El flujo normal de Git se basa en aislar las cosas para que si se introducen problemas formales, la matriz superior no sufra fallos o el entorno C++ deje de compilar antes de la unión completa.

## 1. Actualizar tu código (Ir a la par del equipo)
Siempre antes de comenzar con alguna tarea de trabajo por la mañana, es buena idea actualizar tus avances basados con lo último aprobado en línea del servidor principal. Para hacer esto y traerte tu rama madre, teclea:

```bash
git switch main
git pull origin main
```

## 2. Empezar a trabajar: Crear una nueva Rama
Nunca manipules código en `main`. Crea una **Rama (*Branch*)** en base a lo que irás hacer, bajo una nomenclatura coherente y en minúsculas. 

```bash
git switch -c crear-ventana-catalogo
```
*Tip: El `-c` significa Create, y a su vez, te moverá automáticamente hacia esa rama nueva una vez se registre en el sistema de manera efectiva.*

## 3. Revisar qué componentes has tocado (Status)
A lo largo de las horas programando o añadiendo archivos, si deseas revisar cuál es el daño o avance exacto que Git considera modificado temporalmente y sin sellar, ejecuta:

```bash
git status
```
Aquí te mostrará en **rojo** todo lo nuevo y que Git ha registrado visualmente.

## 4. Agregar tus archivos
Se recomienda encarecidamente utilizar el atajo de captura de *todo*. Para que el sistema asimile y decida apilar en un borrador (*Staging Area*) todos los archivos que has tocado para prepararse a formar parte de una confirmación usa:

```bash
git add .
```

*Nota: Ignora la preocupación por carpetas de compilación ya que tenemos preparado un archivo que prohíbe explícitamente subir carpetas como `build/`.*

## 5. Hacer `Commit`
El "Commit" es ponerle el sello de seguridad y tu nombre a ese fragmento y apilamiento puntual del avance capturado en el paso anterior.
Debes colocar un texto ("Mensaje") altamente descriptivo referente a los cambios hechos.

```bash
git commit -m "Añadido CRUD completo de películas a la AdminWindow"
```

## 6. Subir tus cambios
Cuando desees que lo que realizaste abandone tu computadora local y pase a figurar en el repositorio real colaborativo hospedado online, usa `push` llamando al nombre de la rama actual que creaste en el Paso 2:

```bash
git push origin crear-ventana-catalogo
```

## 7. Abrir un 'Pull Request' (PR)
1. Dirígete a la ventana del proyecto principal de nuestro repositorio remoto (ej. en *GitHub*).
2. Debería saltarte una alerta verde o dorada pidiendote un "Compare & Pull Request".
3. Llénalo poniendo un título y documentado el cambio. Pide a un de tus pares en el proyecto que le de un vistazo.

## Buenas Prácticas
1. **Haz `commits` pequeños y constantes**, un gran error a veces da en hacer commit con mensajes como "Cambios de lunes y martes". 
2. Realiza siempre un `pull` con previedad cada mes largo de inactividad, evitando los "*Merge Conflicts*" pesados.
3. Sé asertivo en tus mensajes `commit`.

## Qué NO hacer
Hay comandos que en el contexto general que estamos, nunca debes usar para no borrar componentes fundamentales a nivel de tu ambiente local o del servidor:

- **`git reset --hard`**: Devuelve todas tus cosas que hayas tecleado y se borrarán sin piedad sin recuperación. 
- **`git push --force` (`-f`)**: Machaca en crudo sin piedad por encima reescribiendo la historia colaborativa obligada de la matriz si tienes choques.
- **`git clean -fd`**: Purgará los directorios y código nuevo de Qt que aún no metiste al `add .`