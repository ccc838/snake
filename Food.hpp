#ifndef FOOD_HPP
#define FOOD_HPP

#include "Case.hpp"
#include <SDL.h>
#include <vector>

// La classe Food représente la nourriture dans le jeu Food类表示游戏中的食物
class Food {
private:
    Case m_position;  // Position de la nourriture 食物的位置

public:
    // Constructeur, initialise l'état de la nourriture 构造函数，初始化食物状态
    Food(int size, int width, int height);

    // Génère de la nourriture 生成食物
    void spawn(int size, int width, int height);

    // Obtenir la position de la nourriture 获取食物的位置
    Case getPosition();

    // Afficher la food 渲染食物
    void render(SDL_Renderer* renderer);

};

#endif // FOOD_HPP