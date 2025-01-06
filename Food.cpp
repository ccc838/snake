#include "Food.hpp"


// Constructeur de la classe Food, initialise l'état de la nourriture Food类的构造函数，初始化食物状态
Food::Food(int size, int width, int height) : m_position(Case(size, 0, 0, {255,225,225,255})) {
    spawn(size, width, height);
}

// Génère de la nourriture 生成食物
void Food::spawn(int size, int width, int height) {  
    m_position = Case(size, rand() % (width / size) * size, rand() % (height / size) * size, {255,225,225,255});
}


// Obtenir la position de la nourriture 获取食物的位置
Case Food::getPosition() {
    return m_position;
}

// Afficher la food 渲染食物
void Food::render(SDL_Renderer* renderer) {
    m_position.render(renderer);
}