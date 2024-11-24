#ifndef CASE_HPP
#define CASE_HPP

#include <SDL2/SDL.h>

// La classe Case représente une case dans le jeu Case类表示游戏中的一个格子
class Case {
private:
    SDL_Rect m_case; // Utilisation de la structure SDL_Rect pour stocker la position et la taille de la case 使用SDL_Rect结构体存储格子的位置和大小
    int CELL_SIZE; // Taille de la case 格子的大小
    

public:
    // Définition de l'opérateur == pour comparer deux cases 定义case类的==
    bool operator ==(const Case& other) const {
        return m_case.x == other.m_case.x && m_case.y == other.m_case.y;
    } 

    // Constructeur, initialise la position et la taille de la case 构造函数，初始化格子的位置和大小
    Case(int size, int startX, int startY) ;

    // Obtenir la coordonnée X de la case 获取格子的X坐标
    int getX() ;

    // Obtenir la coordonnée Y de la case 获取格子的Y坐标
    int getY() ;

    // Obtenir la taille de la case 获取格子的大小
    int  getSize()  ;

    // Définir une nouvelle position pour la case 设置格子的新位置
    void setPosition(int x, int y) ;

    // Méthode de rendu, utilisée pour dessiner la case sur le renderer SDL 渲染方法，用于在SDL渲染器上绘制格子
    void render(SDL_Renderer* renderer) const;
};

#endif // CASE_HPP