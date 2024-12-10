# 指定编译器
CXX = g++
# SDL库的路径
SDLDIR = SDL2-2.26.5-mingw32/x86_64-w64-mingw32
# 编译器标志
CXXFLAGS = -I $(SDLDIR)/include -L $(SDLDIR)/lib -lmingw32 -lSDL2main -lSDL2 -O2


# 默认目标
all: main clean

# 主程序的依赖和链接
main: main.o Screen.o Case.o Food.o Snake.o Game.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

# 各个对象文件的编译规则
main.o: main.cpp Screen.hpp Case.hpp Food.hpp Snake.hpp Game.hpp
	$(CXX) -c $< $(CXXFLAGS)

Game.o: Game.cpp Game.hpp Snake.hpp Food.hpp Case.hpp
	$(CXX) -c $< $(CXXFLAGS)

Snake.o: Snake.cpp Snake.hpp Case.hpp
	$(CXX) -c $< $(CXXFLAGS)	

Food.o: Food.cpp Food.hpp Case.hpp
	$(CXX) -c $< $(CXXFLAGS)

Screen.o: Screen.cpp Screen.hpp
	$(CXX) -c $< $(CXXFLAGS)

Case.o: Case.cpp Case.hpp
	$(CXX) -c $< $(CXXFLAGS)



# 清理生成的文件
clean:
	del /F *.o
