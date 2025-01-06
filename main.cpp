#include "Screen.hpp"
#include "Game.hpp"
#include "Food.hpp"
#include "Snake.hpp"
#include "Case.hpp"
#include "Exception.hpp"
#include <cstdio>

int main() {
    const int SCREEN_WIDTH = 640;  // Largeur de l'écran 屏幕宽度
    const int SCREEN_HEIGHT = 480;  // Hauteur de l'écran 屏幕高度
    const int CELL_SIZE = 20;  // Taille de chaque case 每个格子的大小

    // Créer un objet écran 创建屏幕对象
    Screen screen("Game Snake", SCREEN_WIDTH, SCREEN_HEIGHT);

    // Créer un objet jeu 创建游戏对象
    Game game(CELL_SIZE, SCREEN_WIDTH , SCREEN_HEIGHT);

    bool quit = false;  // Indicateur de sortie 退出标志
    bool pause = false;  // Indicateur de pause 暂停标志
    int pausetime = 0;
    SDL_Event e;  // Objet événement 事件对象
    game.getSnake().setDirection(CELL_SIZE , 0); // Définir la direction de déplacement initiale 设置初始移动方向

    // Boucle principale du jeu 游戏主循环
    while (!quit) {
        // Gérer les événements 处理事件
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;  // Gérer l'événement de sortie 处理退出事件
            } else if (pause == true) {
                game.handlePause(e);
            } else if (pause == false) {
                game.handlePause(e);
                game.handleEvent(e);  // Gérer les autres événements 处理其他事件
            }
        }

        // Mettre à jour l'état du jeu 更新游戏状态
        if (pause == false){
            try {
                game.update();
            } catch (const ExceptioneatBody& e){
            char messageGameOver[100];
            if (game.getSnake().getMoveInterval() == game.getm_moveInterval()[0]){
            sprintf(messageGameOver, "The snake eats its body! \n Your final length is %i. \n Your final speed level is 1.", game.getSnake().getBodyLength());
            } else if (game.getSnake().getMoveInterval() == game.getm_moveInterval()[1]){
            sprintf(messageGameOver, "The snake eats its body! \n Your final length is %i. \n Your final speed level is 2.", game.getSnake().getBodyLength());
            } else if (game.getSnake().getMoveInterval() == game.getm_moveInterval()[2]){
            sprintf(messageGameOver, "The snake eats its body! \n Your final length is %i. \n Your final speed level is 3.", game.getSnake().getBodyLength());
            } else if (game.getSnake().getMoveInterval() == game.getm_moveInterval()[3]){
            sprintf(messageGameOver, "The snake eats its body! \n Your final length is %i. \n Your final speed level is 4.", game.getSnake().getBodyLength());
            } else if (game.getSnake().getMoveInterval() == game.getm_moveInterval()[4]){
            sprintf(messageGameOver, "The snake eats its body! \n Your final length is %i. \n Your final speed level is 5(max speed).", game.getSnake().getBodyLength());
            }
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Game Over", messageGameOver, screen.getWindow());
            quit = true;
            } 
        }


        // Afficher le jeu 渲染游戏
        SDL_SetRenderDrawColor(screen.getRenderer(), 0, 0, 0, 255);  // Définir la couleur de rendu noire 设置渲染颜色为黑色
        SDL_RenderClear(screen.getRenderer());  // Nettoyer l'écran 清除屏幕
        game.render(screen.getRenderer());  // Afficher les objets du jeu 渲染游戏对象
        SDL_RenderPresent(screen.getRenderer());  // Montrer le résultat du rendu 显示渲染结果




        // Déterminer si le jeu est terminé 判断游戏是否暂停
        if(game.isPause() == true && pausetime == 0){
            char messagePause[100];
            if (game.getSnake().getMoveInterval() == game.getm_moveInterval()[0]){
            sprintf(messagePause, "The game is paused. \n Your length now is %i. \n Your speed level now is 1.", game.getSnake().getBodyLength());
            } else if (game.getSnake().getMoveInterval() == game.getm_moveInterval()[1]){
            sprintf(messagePause, "The game is paused. \n Your length now is %i. \n Your speed level now is 2.", game.getSnake().getBodyLength());
            } else if (game.getSnake().getMoveInterval() == game.getm_moveInterval()[2]){
            sprintf(messagePause, "The game is paused. \n Your length now is %i. \n Your speed level now is 3.", game.getSnake().getBodyLength());
            } else if (game.getSnake().getMoveInterval() == game.getm_moveInterval()[3]){
            sprintf(messagePause, "The game is paused. \n Your length now is %i. \n Your speed level now is 4.", game.getSnake().getBodyLength());
            } else if (game.getSnake().getMoveInterval() == game.getm_moveInterval()[4]){
            sprintf(messagePause, "The game is paused. \n Your length now is %i. \n Your speed level now is 5(max speed).", game.getSnake().getBodyLength());
            }
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Pause", messagePause, screen.getWindow());
            pause = true;
            pausetime += 1;
        }else if(game.isPause() == false){
            pause = false;
            pausetime = 0;
        }
        
        // Déterminer si le jeu est terminé 判断游戏是否结束
        if(game.isGameOver() == true){
            quit = true;
        }
    }
    return 0;
}