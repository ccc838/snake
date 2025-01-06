#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SDL.h>

// La classe Screen est responsable de la gestion de la fenêtre SDL et du renderer Screen类负责管理SDL窗口和渲染器
class Screen {
private:
    SDL_Window* m_window;  // Pointeur vers la fenêtre SDL SDL窗口指针
    SDL_Renderer* m_renderer;  // Pointeur vers le renderer SDL SDL渲染器指针

public:
    // Constructeur, initialise la fenêtre et le renderer 构造函数，初始化窗口和渲染器
    Screen(const char* title, int width, int height);

    // Destructeur, libère les ressources 析构函数，释放资源
    ~Screen();

    // Obtenir le renderer 获取渲染器
    SDL_Renderer* getRenderer() const { return m_renderer; }

    // Obtenir la fenêtre 获取窗口
    SDL_Window* getWindow() const { return m_window; }


};

#endif // SCREEN_HPP
