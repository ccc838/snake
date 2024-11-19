#include "Screen.hpp"

int main() {
    // Créer l'écran et initialiser le jeu
    Screen screen;
    if (!screen.init()) {
        std::cout << "Erreur d'initialisation SDL" << std::endl;
        return 1;
    }

    SnakeHead snake(00, 00); // Position initiale de la tête du serpent
    bool quit = false;

    // Boucle principale du jeu
    while (!quit) {
        // Traiter les événements
        quit = !screen.processEvents();

        // Gérer les directions avec les touches du clavier
        const Uint8* keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_UP]) {
            snake.setDirection(0, -1); // Déplacement vers le haut
        } else if (keystate[SDL_SCANCODE_DOWN]) {
            snake.setDirection(0, 1); // Déplacement vers le bas
        } else if (keystate[SDL_SCANCODE_LEFT]) {
            snake.setDirection(-1, 0); // Déplacement vers la gauche
        } else if (keystate[SDL_SCANCODE_RIGHT]) {
            snake.setDirection(1, 0); // Déplacement vers la droite
        }

        // Mettre à jour la position de la tête du serpent
        snake.update(); // Utilisation de la méthode update avec le contrôle du temps

        // Effacer l'écran et rendre les nouvelles positions
        screen.clear();
        snake.render(screen.getRenderer());
        screen.render();

        SDL_Delay(10); // Délai pour limiter l'utilisation du CPU
    }

    // Fermer le jeu et libérer les ressources
    screen.close();
    return 0;
}
