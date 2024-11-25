#ifndef FOOD_HPP
#define FOOD_HPP

#include <SDL2/SDL.h>

class Food {
public:
    Food();
    void spawn(int screenWidth, int screenHeight);
    void render(SDL_Renderer* renderer);
    
    // Ajouter les méthodes pour obtenir les coordonnées de la nourriture
    int getX() const { return m_x; }
    int getY() const { return m_y; }

private:
    int m_x, m_y;  // Position de la nourriture
    const int SIZE = 10; // Taille de la nourriture
};

#endif
