
## Paso 0 — Descargar la ORM (solo una vez)

`sqlite_orm.h` es un único header. Si no está presente, descárgalo dentro de
esta carpeta `crud/`:

```bash
cd crud
curl -sSL -o sqlite_orm.h \
  https://raw.githubusercontent.com/fnc12/sqlite_orm/master/include/sqlite_orm/sqlite_orm.h
```

## Paso 1 — Compilar

```bash
cd crud
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Paso 2 — Ejecutar

```bash
./build/netflix_crud
```
