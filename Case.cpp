#include "Case.hpp"
#include <SDL2/SDL.h>



//Constructeur, initialise la position et la taille de la case 构造函数，初始化格子的位置和大小
Case::Case(int size, int startX, int startY)
 : CELL_SIZE(size), m_case{startX, startY, size, size} {
 }

//Obtenir la coordonnée X de la case 获取格子的X坐标
int Case::getX() { return m_case.x; }

//Obtenir la coordonnée Y de la case 获取格子的Y坐标
int Case::getY() { return m_case.y; }

//Obtenir la taille de la case 获取格子的大小
int Case::getSize() { return CELL_SIZE; }

//Définir une nouvelle position pour la case 设置格子的新位置
void Case::setPosition(int x, int y) {
    m_case.x = x;
    m_case.y = y;
}

//Méthode de rendu, utilisée pour dessiner la case sur le renderer SDL 渲染方法，用于在SDL渲染器上绘制格子
void Case::render(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //Définir la couleur de rendu en blanc 设置渲染颜色为白色
    SDL_RenderFillRect(renderer, &m_case); //Remplir le rectangle avec le renderer SDL et les données de la case 使用SDL渲染器和格子的矩形数据填充矩形
}
