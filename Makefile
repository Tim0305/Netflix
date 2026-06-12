# Ejecutable
TARGET = main 

# Compilador
CXX = g++

# Flags normales + Rutas de los headers de OpenCV (Para que encuentre los .hpp)
CXXFLAGS = -Wall -Wextra -std=c++17 `pkg-config --cflags opencv4`

# Librerias de OpenCV (Para el paso final)
LDFLAGS = `pkg-config --libs opencv4`

# Todos los .cpp de la carpeta
SRC = $(wildcard *.cpp)

# Objetos
OBJ = $(SRC:.cpp=.o)

# Regla principal
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compilar .cpp -> .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar
clean:
	rm -f $(OBJ) $(TARGET)