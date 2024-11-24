#include "Food.hpp"
#include <SDL2/SDL.h>

// Constructeur de la classe Food, initialise l'état de la nourriture Food类的构造函数，初始化食物状态
Food::Food(int size, int width, int height) : m_position(Case(size, 0, 0)), m_exists(false) {
    spawn(size, width, height);
}

// Génère de la nourriture 生成食物
void Food::spawn(int size, int width, int height) {
    m_position = Case(size, rand() % (width / size) * size, rand() % (height / size) * size);
    m_exists = true;
}

// Supprime la nourriture 移除食物
void Food::remove() {
    m_exists = false;
}

// Obtenir la position de la nourriture 获取食物的位置
Case Food::getPosition() {
    return m_position;
}

// Vérifier si la nourriture existe 检查食物是否存在
bool Food::exists() {
    return m_exists;
}