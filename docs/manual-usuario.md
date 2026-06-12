# Manual de Usuario

Bienvenido a la prueba de concepto *Netflix* (Timflix), este manual te guiará bajo el entendimiento logístico y práctico al abrir nuestro aplicativo a fin de gozar un catálogo virtual inmersivo.

## Cómo Abrir la Aplicación
1. Tras compilar y correr (`build/Netflix`), verás la primera pantalla del sistema conformando en un inicio o ventana principal a modo puente.
2. Si es tu primera vez usando el sistema debes proceder interactuando en las herramientas visuales en los espacios pautados de logueo.

## Cómo Registrarse
1. Desde la primera ventana, en caso de no contar con un perfil para acceder, haz clic en el botón dispuesto de **Registrarse** (redirigiendo a visualización desde el entorno de *SignupWindow*).
2. Completa los requisitos en sus debidos formularios e insertando credenciales estipuladas.
3. El sistema verificará de forma interna con la base de datos la creación e integración de los mismos.

## Cómo Iniciar Sesión / Autenticación
1. Desde el gestor primordial, busca presionar en **Iniciar Sesión**.
2. Concede tu Nombre de Identidad de Cuenta o tu Nombre de Usuario explícito.
3. Ingresa la contraseña alfanumérica registrada. 
4. Si las credenciales logran entrelazarse y verificarse dentro la base SQLite incrustada, serás dirigido a las capacidades del flujo básico dependiendo única y rigurosamente del **Rol pre-establecido**.

## Qué puede hacer un usuario Normal (Estándar)
- Todo usuario cuenta con la navegación global por la aplicación base, incluyendo observar el catálogo visual y navegar mediante filtros visuales de listados y búsquedas categorizadas.
- Visualizar elementos como Series o Películas para leer sus datos técnicos, sinopsis y calificación. *(En Desarrollo).*

## Perfil del Administrador (`Admin`)
Es la entidad del más profundo espectro superior; una vez entra goza de su redirección natural del sistema al "Tablero General" o *Panel Administrativo*, las atribuciones y capacidades permiten gestionar enteramente las partes vitalizadas conectadas. 

**Qué puede hacer un Administrador:**
- Gestionar (Aprobar Creación/Observación/Actualizar/Destrucción) de listines desde **Base de Datos** orientados hacia:
  - Usuarios del entorno en la ventana de **Usuarios**.
  - Registro interno de listados de catálogos cinemáticos en la ventana de **Películas**.
  - Segmentaciones y visualizaciones organizacionales mediante herramientas CRUD hacia **Géneros**.