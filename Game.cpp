#include "Game.hpp"

// Constructeur, initialise le jeu 构造函数，初始化游戏
Game::Game(int size, int width, int height) : m_width(width), m_height(height), m_casesize(size), m_moveInterval({150,125,100,75,50}), m_snake(size, width/size/2 *size , height/size/2 *size , m_moveInterval[0]), m_food(size, width, height), m_pause(false), m_gameOver(false) {
}

// Obtenir l'objet Snake 获取蛇对象
Snake& Game::getSnake() {
    return m_snake;
}


// Gérer la pause 处理暂停
void Game::handlePause(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_SPACE:
                m_pause = !m_pause; // Lancer une exception de pause 抛出暂停异常
                break;
        }
    }
}


// Mettre à jour le traitement des événements du jeu 更新游戏事件处理
void Game::handleEvent(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_UP:
                m_snake.setDirection(0, -m_casesize);  // Se déplacer vers le haut 向上移动
                break;
            case SDLK_DOWN:
                m_snake.setDirection(0, m_casesize);   // Se déplacer vers le bas 向下移动
                break;
            case SDLK_LEFT:
                m_snake.setDirection(-m_casesize, 0);  // Se déplacer à gauche 向左移动
                break;
            case SDLK_RIGHT:
                m_snake.setDirection(m_casesize, 0);  // Se déplacer à droite 向右移动
                break;

        }
    }
}


// Mettre à jour l'état du jeu 更新游戏状态
void Game::update() {
    m_snake.update();

    // Vérifier si le serpent a mangé la nourriture 检查蛇是否吃到食物
    if (m_snake.getHeadPosition() == m_food.getPosition()) {
        m_snake.grow(); // Faire grandir le serpent 使蛇变长
        bool isOccupied = true;
        while (isOccupied == true) { // Régénérer la nourriture 重新生成食物
            m_food.spawn(m_food.getPosition().getSize(), m_width, m_height); 
            isOccupied = false;
            for (Case part : m_snake.getBody()) {
                if (m_food.getPosition().getX() == part.getX() && m_food.getPosition().getY() == part.getY()) {
                    isOccupied = true;
                    break; 
                }
            }
        }
    }

    // Gérer le cas où la tête du serpent touche les boards 处理蛇头碰到墙壁的情况
    if (m_snake.getHeadPosition().getX() < 0) {
        m_snake.getHeadPosition().setPosition(m_width - m_casesize, m_snake.getHeadPosition().getY());
    } else if (m_snake.getHeadPosition().getX() >= m_width) {
        m_snake.getHeadPosition().setPosition(0, m_snake.getHeadPosition().getY());
    }
    if (m_snake.getHeadPosition().getY() < 0) {
        m_snake.getHeadPosition().setPosition(m_snake.getHeadPosition().getX(), m_height - m_casesize) ;
    } else if (m_snake.getHeadPosition().getY() >= m_height) {
        m_snake.getHeadPosition().setPosition(m_snake.getHeadPosition().getX(), 0 );
    }
    
    // Vérifier si le serpent se mord la queue 检查蛇是否咬到自己
    if (m_snake.getBodyLength() > 1) {
        for (size_t i = 1; i < m_snake.getBodyLength(); ++i) {
            if (m_snake.getHeadPosition() == m_snake.getBody()[i]) {
                m_gameOver = true;
                throw ExceptioneatBody();  // Si le serpent se mord la queue, alors une erreur est générée 若蛇咬到自己，则产生报错信息
            }
        }
    }

    // Augmenter la vitesse du serpent 增加蛇的速度
    if (m_snake.getBodyLength() == 6) {
        getSnake().setMoveInterval(m_moveInterval[1]);
    }else if (m_snake.getBodyLength() == 10) {
        getSnake().setMoveInterval(m_moveInterval[2]);
    }else if (m_snake.getBodyLength() == 15) {
        getSnake().setMoveInterval(m_moveInterval[3]);
    }else if (m_snake.getBodyLength() == 25) {
        getSnake().setMoveInterval(m_moveInterval[4]);
    }
}

// Obtenir la liste des intervalles de déplacement 获取移动间隔列表
vector<int> Game::getm_moveInterval(){
    return m_moveInterval;
};

// Afficher le jeu 渲染游戏
void Game::render(SDL_Renderer* renderer) {
    m_snake.render(renderer);
    m_food.render(renderer);
}

// Vérifier si le jeu est terminé 检查游戏是否结束
bool Game::isPause() { 
    return m_pause; 
}

// Vérifier si le jeu est terminé 检查游戏是否结束
bool Game::isGameOver() { 
    return m_gameOver; 
}




