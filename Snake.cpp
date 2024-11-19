#include "Snake.hpp"

Snake::Snake(int size, int startX, int startY) {
    m_head.x = startX;
    m_head.y = startY;
    m_head.w = size;
    m_head.h = size;

    m_vx = 0;
    m_vy = 0;
}

void Snake::setDirection(int vx, int vy) {
    m_vx = vx;
    m_vy = vy;
}

void Snake::update(int deltaTime) {
    m_head.x += m_vx * deltaTime / 10; // Mettre à jour la position en X
    m_head.y += m_vy * deltaTime / 10; // Mettre à jour la position en Y
}

void Snake::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Vert pour la tête du serpent
    SDL_RenderFillRect(renderer, &m_head);  // Affiche la tête du serpent
}
