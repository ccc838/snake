#ifndef GAME_HPP
#define GAME_HPP

#include "Snake.hpp"
#include "Food.hpp"
#include "Exception.hpp"
#include <vector>

// La classe Game représente la logique et l'état du jeu Game类表示游戏的逻辑和状态
class Game {
private:
    const int m_width ; // Largeur de l'écran 屏幕宽度
    const int m_height; // Hauteur de l'écran 屏幕高度
    const int m_casesize ; // Taille de la case 格子尺寸
    vector<int> m_moveInterval; // 移动间隔档位
    Snake m_snake; // Objet Snake 蛇对象
    Food m_food; // Objet Food 食物对象
    bool m_gameOver; // Est-ce que le jeu est terminé 游戏是否结束
    bool m_pause; // Est-ce que le jeu est en pause 游戏是否暂停
    
    

public:
    // Constructeur, initialise le jeu 构造函数，初始化游戏
    Game(int size, int width, int height);

    // Ajouter une méthode get qui retourne une référence à l'objet Snake 添加一个返回Snake对象引用的get方法
    Snake& getSnake();

    //  Ajouter une méthode pour gérer la pause 添加处理暂停的方法
    void handlePause(SDL_Event& e); 

    // Ajouter une méthode pour gérer les événements 添加处理事件的方法
    void handleEvent(SDL_Event& e); 

    // Mettre à jour l'état du jeu 更新游戏状态
    void update();

    // Obtenir la liste des intervalles de déplacement 获取移动间隔列表
    vector<int> getm_moveInterval();

    // Afficher la jeu 渲染游戏
    void render(SDL_Renderer* renderer);

    // Vérifier si le jeu est en pause 检查游戏是否暂停
    bool isPause();

    // Vérifier si le jeu est terminé 检查游戏是否结束
    bool isGameOver();


};

#endif // GAME_HPP