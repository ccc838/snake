# Spécifier le compilateur 指定编译器
CXX = g++
# Chemin de la bibliothèque SDL SDL库的路径
SDLDIR = SDL2-2.26.5-mingw32/x86_64-w64-mingw32
# Drapeau du compilateur 编译器标志
CXXFLAGS = -I $(SDLDIR)/include/SDL2  -L $(SDLDIR)/lib  -lmingw32 -lSDL2main -lSDL2  -O2


# Cible par défaut 默认目标
all: snake clean

# Dépendances et liens du programme principal 主程序的依赖和链接
Snake: main.o Screen.o Case.o Food.o Snake.o Game.o Exception.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

Test: Test.o Case.o Food.o Snake.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

# Règles de compilation pour chaque fichier objet 各个对象文件的编译规则
main.o: main.cpp Screen.hpp Case.hpp Food.hpp Snake.hpp Game.hpp Exception.hpp
	$(CXX) -c $< $(CXXFLAGS)

Test.o: Test.cpp TestFunc.cpp Case.hpp Food.hpp Snake.hpp
	$(CXX) -c $< $(CXXFLAGS)

Game.o: Game.cpp Game.hpp Snake.hpp Food.hpp Case.hpp Exception.hpp
	$(CXX) -c $< $(CXXFLAGS)

Snake.o: Snake.cpp Snake.hpp Case.hpp
	$(CXX) -c $< $(CXXFLAGS)	

Food.o: Food.cpp Food.hpp Case.hpp
	$(CXX) -c $< $(CXXFLAGS)

Exception.o: Exception.cpp Exception.hpp
	$(CXX) -c $< $(CXXFLAGS)

Screen.o: Screen.cpp Screen.hpp
	$(CXX) -c $< $(CXXFLAGS)

Case.o: Case.cpp Case.hpp
	$(CXX) -c $< $(CXXFLAGS)



# Nettoyer les fichiers générés 清理生成的文件
clean:
	rm -f *.o 
