#include "Screen.hpp"
#include "Game.hpp"
#include "Food.hpp"
#include "Snake.hpp"
#include "Case.hpp"

int main(int argc, char* args[]) {
    const int SCREEN_WIDTH = 640;  // Largeur de l'écran 屏幕宽度
    const int SCREEN_HEIGHT = 480;  // Hauteur de l'écran 屏幕高度
    const int CELL_SIZE = 20;  // Taille de chaque case 每个格子的大小
    const int moveInterval = 100; // Fréquence de mise à jour(vitesse de déplacement) 更新频率（移动速度）

    // Créer un objet écran 创建屏幕对象
    Screen screen("Game Snake", SCREEN_WIDTH, SCREEN_HEIGHT);

    // Créer un objet jeu 创建游戏对象
    Game game(CELL_SIZE, SCREEN_WIDTH , SCREEN_HEIGHT , moveInterval);

    bool quit = false;  // Indicateur de sortie 退出标志
    SDL_Event e;  // Objet événement 事件对象
    game.getSnake().setDirection(CELL_SIZE , 0); // Définir la direction de déplacement initiale 设置初始移动方向

    // Boucle principale du jeu 游戏主循环
    while (!quit) {
        // Gérer les événements 处理事件
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;  // Gérer l'événement de sortie 处理退出事件
            } else {
                game.handleEvent(e);  // Gérer les autres événements 处理其他事件
            }
        }

        // Mettre à jour l'état du jeu 更新游戏状态
        game.update();


        // Afficher le jeu 渲染游戏
        SDL_SetRenderDrawColor(screen.getRenderer(), 0, 0, 0, 255);  // Définir la couleur de rendu noire 设置渲染颜色为黑色
        SDL_RenderClear(screen.getRenderer());  // Nettoyer l'écran 清除屏幕
        game.render(screen.getRenderer());  // Afficher les objets du jeu 渲染游戏对象
        SDL_RenderPresent(screen.getRenderer());  // Montrer le résultat du rendu 显示渲染结果

        
        // Déterminer si le jeu est terminé par méthode exception 通过exception方法判断游戏是否结束
        try {
        if (game.isGameOver()) {
            throw exception();
        }
        } catch (exception& e) {
        // Afficher un message de fin de jeu 显示游戏结束的消息
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Game Over", "Game Over!", screen.getWindow());
        quit = true;
        }
    
    }

    return 0;
}