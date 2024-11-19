CXX = g++
CXXFLAGS = `sdl2-config --cflags --libs`

# Programmes à générer
PROGS = main

# Compilation principale
all: $(PROGS)

main: main.o Screen.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

main.o: main.cpp Screen.hpp
	$(CXX) -c $< $(CXXFLAGS)

Screen.o: Screen.cpp Screen.hpp
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f *.o $(PROGS)
