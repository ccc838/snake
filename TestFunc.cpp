#include <iostream>
#include <vector>

#include "Case.hpp"
#include "Snake.hpp"
#include "Food.hpp"

using namespace std;


void TestCase() {
    // Créer un objet Case 创建一个Case对象
    vector<int> color = {255, 255, 255, 255};  // Blanc 白色
    Case cell(10, 50, 50, color);  // size, startX, startY, color

    // Tester le constructeur 测试构造函数
    if (cell.getX() != 50 || cell.getY() != 50 || cell.getSize() != 10) {
        cerr << "Test failed: Constructor should initialize position and size correctly" << endl;
    }

    // Tester le réglage d'une nouvelle position 测试设置新位置
    cell.setPosition(60, 60);
    if (cell.getX() != 60 || cell.getY() != 60) {
        cerr << "Test failed: setPosition should update the position correctly" << endl;
    }

    cout << "All tests de class case passed!" << endl;
}



void TestSnake() {
    // Créer un objet Snake 创建一个Snake对象
    Snake snake(10, 50, 50, 100);  // size, startX, startY, moveInterval

    // Tester le constructeur 测试构造函数
    if (snake.getBodyLength() != 3) {
        cerr << "Test failed: Constructor should initialize body length to 3" << endl;
    }

    // Tester la configuration de la direction de déplacement 测试移动方向设置
    snake.setDirection(10, 0);  // Déplacer à droite 向右移动
    if (snake.getBody().front().getX() != 50) {
        cerr << "Test failed: Initial head position should be (50, 50)" << endl;
    }

    SDL_Delay(1000); // Attendre 1 seconde 等待1秒

    // Mettre à jour la position du serpent 更新蛇的位置
    SDL_Delay(1000);
    snake.update();
    if (snake.getBody().front().getX() != 60 || snake.getBody().front().getY() != 50) {
        cerr << "Test failed: Head position should be updated to (60, 50)" << endl;
    }

    // Tester la croissance du serpent 测试使蛇变长
    snake.grow();
    if (snake.getBodyLength() != 4) {
        cerr << "Test failed: Snake should grow in length" << endl;
    }

    // Tester la configuration de la vitesse 测试速度设置
    snake.setMoveInterval(50);
    if (snake.getMoveInterval() != 50) {
        cerr << "Test failed: Move interval should be set to 50" << endl;
    }

    cout << "All tests de class snake passed!" << endl;
}



void TestFood() {
    // Créer un objet Food 创建一个Food对象
    Food food(10, 800, 600);  // size, width, height

    // Tester le constructeur et la génération de la position de la nourriture 测试构造函数和生成食物位置
    Case position = food.getPosition();
    if (position.getX() < 0 || position.getX() >= 800 ||
        position.getY() < 0 || position.getY() >= 600) {
        cerr << "Test failed: Food position should be within the specified width and height" << endl;
    }

    cout << "All tests de class food passed!" << endl;
}

