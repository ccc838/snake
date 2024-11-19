#include "Screen.hpp"

Screen::Screen() {
    m_window = nullptr;
    m_renderer = nullptr;
}

bool Screen::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Erreur lors de l'initialisation de SDL" << std::endl;
        return false;
    }

    // Création de la fenêtre
    m_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (m_window == nullptr) {
        std::cout << "Problème avec la création de la fenêtre" << std::endl;
        SDL_Quit();
        return false;
    }

    // Création du renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (m_renderer == nullptr) {
        std::cout << "Erreur lors de la création du renderer" << std::endl;
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    return true;
}

void Screen::close() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Screen::clear() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255); // Couleur de fond noire
    SDL_RenderClear(m_renderer);
}

bool Screen::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

void Screen::render() {
    SDL_RenderPresent(m_renderer); // Affiche le contenu du renderer à l'écran
}
