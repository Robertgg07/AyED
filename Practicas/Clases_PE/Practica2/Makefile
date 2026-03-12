# Nombre del ejecutable final
programa = main_p2

# Busca todos los .cc del directorio actual
codigos = $(wildcard *.cpp)

# Genera la lista de objetos correspondientes (.o)
objetos = $(codigos:.cpp=.o)

# Reglas del compilador
CXX = g++
CXXFLAGS = -std=c++17 -Wall 

# Compila el ejecutable
all: $(programa)
 
# Crea un ejecutable a partir de los .o
$(programa): $(objetos)
	$(CXX) $(CXXFLAGS) -o $@ $(objetos)

# Crea los .o a partir de los .cc
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Indica que el objetivo "clean y all" no son archivos:
.PHONY: clean all

# Borra los .o y los ejecutable en caso de ser necesario con make clean
clean:
	rm -f $(programa).exe $(objetos)