#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <vector>
#include "Case.hpp"

class Obstacle {
private:
    std::vector<Case> m_parts; // Liste des cases qui composent l'obstacle
    int m_lifetime;            // Durée de vie de l'obstacle en mises à jour

public:
    // Constructeur : initialise un obstacle
    Obstacle(int size, int x, int y, int length, bool horizontal, int lifetime);

    // Accéder aux parties de l'obstacle
    const std::vector<Case>& getParts() const;

    // Réduire la durée de vie de l'obstacle
    void decreaseLifetime();

    // Vérifier si l'obstacle a expiré
    bool isExpired() const;

    // Afficher l'obstacle
    void render(SDL_Renderer* renderer) const;
};

#endif // OBSTACLE_HPP
