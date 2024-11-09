
#define MAXLEN 1600             //max length of snake
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
	int dirt;					//direction
	int length;					//length
	SnakeNode node[MAXLEN];		//node of snake    
};
