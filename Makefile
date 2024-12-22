CXX = g++
CXXFLAGS = `sdl2-config --cflags --libs`


all: main clean

# Compilation principale
main:main.o Screen.o Case.o Food.o Snake.o Game.o Obstacle.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

main.o: main.cpp Screen.hpp Case.hpp Food.hpp Snake.hpp Game.hpp Obstacle.hpp
	$(CXX) -c $< $(CXXFLAGS)

Game.o: Game.cpp Game.hpp Snake.hpp Food.hpp Case.hpp Obstacle.hpp
	$(CXX) -c $< $(CXXFLAGS)

Snake.o: Snake.cpp Snake.hpp Case.hpp
	$(CXX) -c $< $(CXXFLAGS)	

Food.o: Food.cpp Food.hpp Case.hpp
	$(CXX) -c $< $(CXXFLAGS)

Screen.o: Screen.cpp Screen.hpp
	$(CXX) -c $< $(CXXFLAGS)


Obstacle.o: Obstacle.cpp Obstacle.hpp Case.hpp
	$(CXX) -c $< $(CXXFLAGS)


Case.o: Case.cpp Case.hpp
	$(CXX) -c $< $(CXXFLAGS)


clean:
	rm -f *.o 
