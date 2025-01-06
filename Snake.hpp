#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Case.hpp"
#include <vector>
using namespace std;

class Snake {
private:
    int m_vx, m_vy; // Direction du mouvement du serpent, m_vx représente l'axe horizontal, m_vy représente l'axe vertical 蛇的移动方向，m_vx表示水平方向，m_vy表示垂直方向
    Uint32 m_lastMoveTime; // Heure du dernier mouvement 上次移动的时间
    int m_moveInterval; // Intervalle de mouvement du serpent 蛇的移动间隔
    vector<Case> m_body; // Utilisation d'un vector de la classe Case pour stocker chaque segment du corps du serpent 使用Case类的vector存储蛇的每一节身体

public:

    // Constructeur, initialise la position et la vitesse du serpent 构造函数，初始化蛇的位置和速度
    Snake(int size, int startX, int startY, int moveInterval);

    // Définit la direction de déplacement du serpent 设置蛇的移动方向
    void setDirection(int vx, int vy);

    // Met à jour la position du serpent 更新蛇的位置
    void update();

    // Afficher le serpent 渲染蛇
    void render(SDL_Renderer* renderer);

    // Obtenir le corps du serpent 获取蛇的身体
    vector<Case> getBody() ;

    // Obtenir la position de la tête du serpent 获取蛇头的位置
    Case& getHeadPosition() ;

    // Obtenir la longueur du corps du serpent 获取蛇的身体长度
    int getBodyLength() const;

    // Faire grandir le serpent 使蛇变长
    void grow();

    // Obtenir la vitesse du serpent 获得蛇的速度
    int getMoveInterval();

    // Modifier la vitesse du serpent 修改蛇的速度
    void setMoveInterval(int moveInterval);
};

#endif // SNAKE_HPP