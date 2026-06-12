# Ejecutable
TARGET = main 

# Compilador
CXX = g++

# Flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Todos los .cpp de la carpeta
SRC = $(wildcard *.cpp)

# Objetos
OBJ = $(SRC:.cpp=.o)

# Regla principal
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)
	rm -f $(OBJ)

# Compilar .cpp -> .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar
clean:
	rm -f $(OBJ) $(TARGET)
