#include "Screen.hpp"
#include "Snake.hpp"
#include "Food.hpp"
#include <SDL2/SDL.h>

int main() {
    Screen screen;
    if (!screen.init()) {
        return -1;
    }

    Snake snake(100, 100); // Le serpent commence à (100, 100)
    Food food;             // Création de la nourriture
    food.spawn(640, 480);  // Positionnement initial de la nourriture

    bool running = true;
    SDL_Event event;

    // Boucle principale du jeu
    while (running) {
        // Gérer les événements (entrées clavier et autres)
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false; // Fermer le jeu si l'utilisateur quitte
            }

            // Passer l'événement au serpent pour gérer les touches
            snake.handleInput(event);
        }

        // Effacer l'écran
        screen.clear();

        // Déplacer le serpent
        snake.move();

        // Vérifier si le serpent mange la nourriture
        if (snake.eatFood(food)) {
            // La nourriture a été mangée, générer une nouvelle nourriture
            food.spawn(640, 480);  // Remplacer la position de la nourriture
        }

        // Vérifier les collisions (si le serpent se mord la queue)
        if (snake.checkCollision()) {
            running = true; // Fin du jeu si collision
        }

        // Afficher le serpent et la nourriture
        snake.render(screen.getRenderer());
        food.render(screen.getRenderer());

        // Afficher à l'écran
        screen.render();

        // Délai pour ralentir le jeu et avoir une animation fluide
        SDL_Delay(100);
    }

    // Fermer SDL et nettoyer
    screen.close();
    return 0;
}
