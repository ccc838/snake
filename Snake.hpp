#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include <SDL2/SDL.h>
#include "Food.hpp"  // Ajouter cette ligne pour inclure la classe Food
struct Case {
    int x, y;
};

class Snake {
public:
    Snake(int startX, int startY);
    void move();
    void render(SDL_Renderer* renderer);
    bool eatFood(Food& food);
    bool checkCollision();
    void handleInput(SDL_Event& event);
    void grow(); // Méthode pour grandir

    void setDirection(int dx, int dy) { m_dx = dx; m_dy = dy; }

private:
    std::vector<Case> m_body; // Corps du serpent
    int m_dx, m_dy;  // Direction actuelle
};

#endif
