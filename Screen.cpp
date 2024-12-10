#include "Screen.hpp"

// Constructeur, initialise la fenêtre et le renderer 构造函数，初始化窗口和渲染器
Screen::Screen(const char* title, int width, int height) {
    SDL_Init(SDL_INIT_VIDEO);  // Initialisation du sous-système vidéo SDL 初始化SDL视频子系统
    m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);  // Création de la fenêtre 创建窗口
    if (m_window == nullptr) {
        // Si la création de la fenêtre échoue, afficher un message d'erreur et quitter le programme 如果窗口创建失败，输出错误信息并退出程序
        SDL_Log("Unable to create window: %s", SDL_GetError());
        exit(1);
    }
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);  // Création du renderer 创建渲染器
    if (m_renderer == nullptr) {
        // Si la création du renderer échoue, afficher un message d'erreur et quitter le programme 如果渲染器创建失败，输出错误信息并退出程序
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(m_window);
        exit(1);
    }
}

// Destructeur, libère les ressources 析构函数，释放资源
Screen::~Screen() {
    SDL_DestroyRenderer(m_renderer);  // Destruction du renderer 销毁渲染器
    SDL_DestroyWindow(m_window);  // Destruction de la fenêtre 销毁窗口
    SDL_Quit();  // Quitter SDL 退出SDL
}