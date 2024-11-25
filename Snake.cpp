#include "Snake.hpp"
#include "Food.hpp"
#include <SDL2/SDL.h>

Snake::Snake(int startX, int startY) {
    m_dx = 1; // Déplacement initial vers la droite
    m_dy = 0; // Pas de mouvement vertical
    m_body.push_back({startX, startY});  // La tête du serpent
}

void Snake::move() {
    // Déplacer la tête du serpent
    Case newHead = m_body[0];
    newHead.x += m_dx * 10;  // Déplacer en fonction de la direction
    newHead.y += m_dy * 10;

    // Déplacer le corps
    m_body.insert(m_body.begin(), newHead); // Ajouter la nouvelle tête au début

    // Supprimer la queue (le dernier segment) si le serpent n'a pas mangé
    m_body.pop_back();
}

void Snake::render(SDL_Renderer* renderer) {
    // Dessiner chaque segment du serpent
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Vert pour le serpent
    for (const Case& part : m_body) {
        SDL_Rect rect = { part.x, part.y, 10, 10 };
        SDL_RenderFillRect(renderer, &rect);
    }
}

bool Snake::eatFood(Food& food) {
    // Vérifier si la tête du serpent touche la nourriture
    if (m_body[0].x == food.getX() && m_body[0].y == food.getY()) {
        grow();  // Faire grandir le serpent
        return true;
    }
    return false;
}

bool Snake::checkCollision() {
    // Vérifier si le serpent se mord lui-même
    for (size_t i = 1; i < m_body.size(); ++i) {
        if (m_body[i].x == m_body[0].x && m_body[i].y == m_body[0].y) {
            return true;
        }
    }
    return false;
}

void Snake::handleInput(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                setDirection(0, -1);
                break;
            case SDLK_DOWN:
                setDirection(0, 1);
                break;
            case SDLK_LEFT:
                setDirection(-1, 0);
                break;
            case SDLK_RIGHT:
                setDirection(1, 0);
                break;
        }
    }
}

void Snake::grow() {
    // Ajouter un segment à la fin du serpent
    m_body.push_back(m_body.back());
}
