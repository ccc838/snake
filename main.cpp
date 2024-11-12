
#define MAXLEN 1600             //max length of snake //   cases pour le snake et les pommes
typedef struct {
	int x;
	int y;
}SnakeNode;

//class of snake
class Snake
{
	friend class Food;          //food is friend function of snake
public:
	Snake();					//initialization
	void Move();				//move
	void Draw();				//draw the snake
	bool Eat(Food food);	    //eat
	bool Defeat();				//judgement of fail
private:
	int dirtx;					//direction suivant x
	int dirty                   //direction suivant y
	int length;					//length
	SnakeNode node[MAXLEN];		//node of snake    
};


//class of food
class Food
{
	friend class Snake;         //snake is friend function of food
public:
	Food(Snake snake);			//initialization
	void Draw();				//draw the food
private:
	int x, y;					//coordinate of food
	int score;					//score
};




