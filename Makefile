# Variables de compilation
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g -I/usr/include/SDL2 -D_REENTRANT
LDFLAGS = -lSDL2

# Fichiers sources
SRC_FILES = main.cpp Screen.cpp Snake.cpp Food.cpp

# Fichiers objets
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Nom de l'exécutable
EXEC = main

# Cible par défaut (compiler l'exécutable)
all: $(EXEC)

# Règle pour l'exécutable
$(EXEC): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(EXEC) $(LDFLAGS)

# Règle pour compiler les fichiers .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJ_FILES) $(EXEC)

# Cible pour nettoyer et reconstruire
rebuild: clean all

# Cible pour exécuter le programme après la compilation
run: $(EXEC)
	./$(EXEC)
