#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SDL2/SDL.h>
#include <iostream>

class Screen {
public:
    bool init(); // Initialiser SDL et créer la fenêtre
    void close(); // Fermer SDL et nettoyer
    void clear(); // Effacer l'écran
    void render(); // Afficher à l'écran
    bool processEvents(SDL_Event& event); // Gérer les événements (comme la fermeture de la fenêtre)
    SDL_Renderer* getRenderer() { return m_renderer; } // Retourner le renderer

private:
    SDL_Window* m_window = nullptr;  // Pointeur vers la fenêtre SDL
    SDL_Renderer* m_renderer = nullptr; // Pointeur vers le renderer SDL
};

#endif
