# Diseño de Interfaz y Ventanas

La aplicación hace un uso exhaustivo del framework **Qt** y de clases diseñadas mediante **Qt Designer** (`.ui`), unidas entre sí por lógica generada desde los `.h` y `.cpp` mediante la captura e inicialización de señales (eventos).

A continuación se documentan las ventanas principales del enrutamiento gráfico.

---

### `mainwindow`
- **Archivos relacionales:** `mainwindow.cpp`, `mainwindow.h`, `mainwindow.ui`
- **Propósito:** Actúa como la raíz del proyecto y pantalla de bienvenida.
- **Acciones que permite:** Generalmente ofrece el puente para la decisión visual principal de si se va a crear o iniciar sesión.
- **Conecta con:** Abre las sub-ventanas `loginwindow` o `signupwindow`.

### `loginwindow`
- **Archivos relacionales:** `loginwindow.cpp`, `loginwindow.h`, `loginwindow.ui`
- **Propósito:** Ventana para recopilar la verificación de las credenciales de quien intenta dar uso a la app.
- **Acciones que permite:** Ingreso de nombre de usuario y contraseña para chequear la base de datos y entrar al sistema.
- **Conecta con:** Según el rol retornado de la base de datos, conduce directamente a `adminwindow` o bien al menú de navegación principal del usuario en una interfaz común.

### `signupwindow`
- **Archivos relacionales:** `signupwindow.cpp`, `signupwindow.h`, `signupwindow.ui`
- **Propósito:** Permitir una interfaz de creación auto-asistida a personas externas para tener rol válido de usuario regular.
- **Acciones que permite:** Registro de información inicial.

### `adminwindow`
- **Archivos relacionales:** `adminwindow.cpp`, `adminwindow.h`, `adminwindow.ui`
- **Propósito:** Ofrecer el panel general o "dashboard" de opciones reservadas para cuentas con de rol `Admin`.
- **Acciones que permite:** Botones para ir al menú de administración individual de Películas, Usuarios o Géneros.
- **Conecta con:** `usuarioswindow`, `peliculasadminwindow`, o `generoswindow`.

### `usuarioswindow`
- **Archivos relacionales:** `usuarioswindow.cpp`, `usuarioswindow.h`, `usuarioswindow.ui`
- **Propósito:** Tabla o lista macro de visualización de perfiles actuales (CRUD de Usuarios).
- **Acciones que permite:** Observar los registros tabulares y accionar botones para añadir un nuevo usuario o aplicar modificaciones.
- **Conecta con:** `registrarusuariowindow`, `modificarusuariowindow`.

### `registrarusuariowindow`
- **Archivos relacionales:** `registrarusuariowindow.cpp`, `registrarusuariowindow.h`, `registrarusuariowindow.ui`
- **Propósito:** Modal o pantalla secundaria disparada desde `usuarioswindow` en contexto de administrador para pre-llenar roles más amplios.
- **Acciones que permite:** Inserción de credenciales, a diferencia del sistema regular de usuario, aquí se puede manipular el poder y rol global (ej: Asignar jerarquías).

### `modificarusuariowindow`
- **Archivos relacionales:** `modificarusuariowindow.cpp`, `modificarusuariowindow.h`, `modificarusuariowindow.ui`
- **Propósito:** Interfaz dispuesta para cargar la información cruda pasada de un registro seleccionado con intenciones de modificarlo.
- **Acciones que permite:** Edición de ID, reinicio de contraseñas, subida y caída de nivel de Roles, etc.

### `peliculasadminwindow`
- **Archivos relacionales:** `peliculasadminwindow.cpp`, `peliculasadminwindow.h`, `peliculasadminwindow.ui`
- **Propósito:** Sub-pantalla general dispuesta a la administración total del contenido de Películas de la plataforma de *Timflix / Netflix*.

### `generoswindow`
- **Archivos relacionales:** `generoswindow.cpp`, `generoswindow.h`, `generoswindow.ui`
- **Propósito:** Sub-pantalla de administración categorizada y focalizada para regular y revisar el catálogo de géneros permitidos o creados.
- **Conecta con:** `generowidget`

### Componentes Incrustables (Widgets UI)
*Son fracciones empotrables a las tablas o ventanas para estructurar celdas más complejas:*
- `generowidget`: Widget modular enlazado con la visualización repetitiva individual de un género.
- `usuariowidget`: Widget estandarizado para la pre-visualización de perfiles compactos en vistas completas de recuadros.