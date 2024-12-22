#include "Obstacle.hpp"
#include <SDL2/SDL.h>

// Constructeur
Obstacle::Obstacle(int size, int x, int y, int length, bool horizontal, int lifetime)
    : m_lifetime(lifetime) {
    for (int i = 0; i < length; ++i) {
        if (horizontal) {
            // Ajout du vecteur de couleur (par exemple rouge pour les obstacles)
            m_parts.emplace_back(size, x + i * size, y, std::vector<int>{255, 0, 0, 255}); 
        } else {
            // Ajout du vecteur de couleur (par exemple rouge pour les obstacles)
            m_parts.emplace_back(size, x, y + i * size, std::vector<int>{255, 0, 0, 255}); 
        }
    }
}

// Accéder aux parties de l'obstacle
const std::vector<Case>& Obstacle::getParts() const {
    return m_parts;
}

// Réduire la durée de vie
void Obstacle::decreaseLifetime() {
    if (m_lifetime > 0) {
        --m_lifetime;
    }
}

// Vérifier si l'obstacle a expiré
bool Obstacle::isExpired() const {
    return m_lifetime <= 0;
}

// Afficher l'obstacle
void Obstacle::render(SDL_Renderer* renderer) const {
    for (const Case& part : m_parts) {
        // Utilisation de la couleur rouge pour le rendu
        part.render(renderer, {255, 0, 0, 255}); 
    }
}
