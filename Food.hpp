#ifndef FOOD_HPP
#define FOOD_HPP

#include "Case.hpp"
#include <SDL2/SDL.h>

// La classe Food représente la nourriture dans le jeu Food类表示游戏中的食物
class Food {
private:
    Case m_position;  // Position de la nourriture 食物的位置
    bool m_exists;    // Indique si la nourriture existe 食物是否存在

public:
    // Constructeur, initialise l'état de la nourriture 构造函数，初始化食物状态
    Food(int size, int width, int height);

    // Génère de la nourriture 生成食物
    void spawn(int size, int width, int height);

    // Supprime la nourriture 移除食物
    void remove();

    // Obtenir la position de la nourriture 获取食物的位置
    Case getPosition();

    // Vérifie si la nourriture existe 检查食物是否存在
    bool  exists() ;

};

#endif // FOOD_HPP