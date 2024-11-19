#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SDL2/SDL.h>
#include <iostream>

class Screen {
private:
    SDL_Window* m_window;
protected:
    SDL_Renderer* m_renderer;
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

    Screen();
    bool init();
    void close();
    void clear();
    bool processEvents();
    void render();

    // Méthode pour obtenir le renderer
    SDL_Renderer* getRenderer() {
        return m_renderer;
    }
};

class SnakeHead {
private:
    SDL_Rect m_rect;  // Représentation de la tête du serpent
    int m_vx, m_vy;   // Vitesse en x et y (déplacement)
    Uint32 m_lastMoveTime; // Dernier temps de mouvement
    const int m_moveInterval = 100; // Intervalle en millisecondes entre chaque déplacement

public:
    SnakeHead(int startX, int startY) {
        m_rect.x = startX;
        m_rect.y = startY;
        m_rect.w = 20;  // Taille de la tête du serpent
        m_rect.h = 20;
        m_vx = 0;  // Déplacement horizontal initial
        m_vy = 0;  // Déplacement vertical initial
        m_lastMoveTime = SDL_GetTicks(); // Initialisation du temps de mouvement
    }

    void setDirection(int vx, int vy) {
        m_vx = vx;
        m_vy = vy;
    }

    void update() {
        // Vérifier si l'intervalle de mouvement est écoulé
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - m_lastMoveTime >= m_moveInterval) {
            m_rect.x += m_vx * 5; // Déplacer horizontalement
            m_rect.y += m_vy * 5; // Déplacer verticalement
            m_lastMoveTime = currentTime; // Mettre à jour le dernier temps de mouvement
        }
    }

    void render(SDL_Renderer* renderer) {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Couleur verte pour la tête
        SDL_RenderFillRect(renderer, &m_rect);
    }
};

#endif // SCREEN_HPP
