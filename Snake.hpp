#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SDL2/SDL.h>

class Snake {
private:
    SDL_Rect m_head;    // Représentation de la tête du serpent
    int m_vx, m_vy;     // Direction du déplacement
    const int CELL_SIZE; // Taille d'une cellule (distance de déplacement saccadé)

public:
    // Constructeur : initialise le serpent avec sa taille et sa position
    Snake(int size, int startX, int startY);

    // Définir la direction du serpent
    void setDirection(int vx, int vy);

    // Met à jour la position du serpent (saccadé)
    void update();

    // Affiche la tête du serpent à l'écran
    void render(SDL_Renderer* renderer);

    // Obtenir la position actuelle de la tête
    SDL_Rect getHead() const;
};

#endif // SNAKE_HPP
