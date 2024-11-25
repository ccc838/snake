#include "Food.hpp"
#include <cstdlib>  // Pour rand() et srand()
#include <ctime>    // Pour srand()

Food::Food() {
    // Initialiser la position de la nourriture
    srand(static_cast<unsigned>(time(0))); // Initialisation de rand()
}



void Food::spawn(int screenWidth, int screenHeight) {
    // Positionner la nourriture à une position aléatoire
    m_x = rand() % (screenWidth / SIZE) * SIZE;
    m_y = rand() % (screenHeight / SIZE) * SIZE;
}

void Food::render(SDL_Renderer* renderer) {
    // Dessiner la nourriture à sa position
    SDL_Rect rect = { m_x, m_y, SIZE, SIZE };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Couleur rouge pour la nourriture
    SDL_RenderFillRect(renderer, &rect);
}
