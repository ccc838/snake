

#ifndef CASES_HPP
#define CASES_HPP

#include <SDL2/SDL.h>

class Cases {
private:
    SDL_Rect m_cases; // Représentation graphique de la case
    const int CELL_SIZE; // Taille de la case

public:
    // Constructeur
    Cases(int size, int startX, int startY)
        : CELL_SIZE(size) {
        m_cases.w = CELL_SIZE;
        m_cases.h = CELL_SIZE;
        m_cases.x = startX; // Initialisation des coordonnées
        m_cases.y = startY;
    }

    // Méthodes d'accès
    int getX() const { return m_cases.x; }
    int getY() const { return m_cases.y; }
    int getSize() const { return CELL_SIZE; }

    // Méthode pour définir une nouvelle position
    void setPosition(int x, int y) {
        m_cases.x = x;
        m_cases.y = y;
    }

    // Méthode de rendu pour afficher la case
    void render(SDL_Renderer* renderer) const {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Blanc
        SDL_RenderFillRect(renderer, &m_cases);
    }
};

#endif // CASES_HPP
