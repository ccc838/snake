#include "Snake.hpp"



// Constructeur, initialise la position de la tête du serpent, sa vitesse et sa longueur 构造函数，初始化蛇的头部位置,速度和身体长度
Snake::Snake(int size, int startX, int startY, int moveInterval)
    : m_vx(0), m_vy(0), m_lastMoveTime(SDL_GetTicks()), m_moveInterval(moveInterval) {
    // Initialisation du corps du serpent, longueur initiale de 3 初始化蛇的身体，初始长度为3
    m_body.push_back(Case(size, startX, startY, {rand() % (256) , rand() % (256), rand() % (256), rand() % (256)})); // Tête 头部
    m_body.push_back(Case(size, startX - size, startY, {rand() % (256) , rand() % (256), rand() % (256), rand() % (256)})); // Second segment 第二节身体
    m_body.push_back(Case(size, startX - 2 * size, startY, {rand() % (256) , rand() % (256), rand() % (256), rand() % (256)})); // Troisième segment 第三节身体
}

// Définit la direction de déplacement du serpent 设置蛇的移动方向
void Snake::setDirection(int vx, int vy) {
    // Limitation : le serpent ne peut pas faire un mouvement direct dans l'inverse 限制蛇不能直接反向移动
    if ((m_vx == 0 && vy == 0) || (m_vy == 0 && vx == 0)) {
        m_vx = vx;
        m_vy = vy;
    }
}

// Met à jour la position du serpent 更新蛇的位置
void Snake::update() {
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - m_lastMoveTime >= m_moveInterval) {
        // Calcul de la nouvelle position de la tête 计算新头部的位置
        int newHeadX = m_body.front().getX() + m_vx;
        int newHeadY = m_body.front().getY() + m_vy;

        // Création d'un nouvel objet Case pour la tête 创建新的头部Case对象
        Case newHead(m_body.front().getSize(), newHeadX, newHeadY, {rand() % (256) , rand() % (256), rand() % (256), rand() % (256)});
        // Suppression de la dernière partie du corps, conservant la longueur du corps invariable 将新头部插入到身体的开始位置
        m_body.insert(m_body.begin(), newHead);

        // Supprimer la dernière partie du corps tout en maintenant la longueur du corps inchangée 移除身体的最后部分，保持身体长度不变
        m_body.pop_back();

        // Mise à jour de l'heure du dernier mouvement 更新上次移动时间
        m_lastMoveTime = currentTime;
    }
}

// Afficher le serpent 渲染蛇
void Snake::render(SDL_Renderer* renderer) {
    for (Case part : m_body) {
        part.render(renderer);
    }
}

// Obtenir le corps du serpent 获取蛇的身体
vector<Case> Snake::getBody() {
    return m_body;
}

// Obtenir la position de la tête du serpent 获取蛇头的位置
Case& Snake::getHeadPosition() {
    return m_body.front();
}

// Obtenir la longueur du corps du serpent 获取蛇的身体长度
int Snake::getBodyLength() const {
    return static_cast<int>(m_body.size());
}

// Faire grandir le serpent 使蛇变长
void Snake::grow() {
    // Obtenir la position de la queue du serpent 获取蛇尾的位置
    Case tail = m_body.back();
    // Ajouter un nouveau segment à la queue du serpent 在蛇的尾部添加一个新的部分
    m_body.push_back(tail);
}

// Obtenir la vitesse du serpent 获得蛇的速度
int Snake::getMoveInterval(){
    return m_moveInterval;
}

// Définir la vitesse du serpent 设置蛇的速度
void Snake::setMoveInterval(int moveInterval){
    m_moveInterval = moveInterval;
}
