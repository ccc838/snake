#include "Screen.hpp"

bool Screen::init() {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Erreur lors de l'initialisation de SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    // Création de la fenêtre
    m_window = SDL_CreateWindow("Winner_Groupe_Of_Anaconda", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (m_window == nullptr) {
        std::cout << "Problème avec la création de la fenêtre: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // Création du renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (m_renderer == nullptr) {
        std::cout << "Erreur lors de la création du renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    return true;
}

void Screen::close() {
    // Nettoyer et fermer SDL
    if (m_renderer != nullptr) {
        SDL_DestroyRenderer(m_renderer);
    }
    if (m_window != nullptr) {
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}

void Screen::clear() {
    // Effacer l'écran avec une couleur noire
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255); // Noir
    SDL_RenderClear(m_renderer);
}

void Screen::render() {
    // Afficher à l'écran
    SDL_RenderPresent(m_renderer);
}

bool Screen::processEvents(SDL_Event& event) {
    // Traiter les événements (par exemple, si l'utilisateur ferme la fenêtre)
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false; // Retourne false si la fenêtre est fermée
        }
    }
    return true;
}
