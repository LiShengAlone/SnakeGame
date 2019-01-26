/*******************************************************
			文件名称：main.cpp
			文件描述：实现一个贪吃蛇的游戏
			编译环境：VS 2015
			最后修改：<2017-12-21> <创建工程> 
*******************************************************/
#include"snake.h"

int main()
{
	GameInit();
	DrawSnake();
	while (1)
	{
		while (!kbhit())   //跳出的条件的按键
		{
			if (food.flag == 0) {
				CoorFood();
			}
			DrawSnake();//蛇的移动本身是一个循环
			SnakeMove();//蛇的移动-》改变方向-》移动
			EatFood();
			Sleep(150);
		}
		ChangeCh();
	}
	return 0;
}

//游戏的初始化
void GameInit()
{
	initgraph(640, 480);

	srand((unsigned int)time(NULL));

	//setbkcolor(RGB(248, 120, 152));
	setbkcolor(RGB(255, 160, 160));
	cleardevice();//用设好的颜色来刷新背景

	mciSendString(L"open 甩葱歌.mp3 alias music", 0, 0, 0);	//MIC send 发送  string 字符串
	mciSendString(L"play music", 0, 0, 0);

	rectangle(0,0,10,10);     //初始化一节蛇
	snake.n = 1;
	snake.sCoor[0].x = 0;
	snake.sCoor[0].y = 0;
	snake.ch = right;//上下左右
	food.flag = 0;//食物被吃掉才能产生新的食物
}

//n节蛇!!!!!!画蛇
void DrawSnake()
{
	BeginBatchDraw();
	cleardevice();
	roundrect(food.x, food.y, food.x + 10, food.y + 10, 10, 10);
	for (int i = snake.n - 1; i >= 0; i--) //n节蛇   0--n-1
	{
		//setcolor(RGB(snake.sCoor[i].x / 2, snake.sCoor[i].y / 2, i * 20));
		rectangle(snake.sCoor[i].x, snake.sCoor[i].y, snake.sCoor[i].x+10, snake.sCoor[i].y+10);
	}
	EndBatchDraw();
}

//每一个坐标的x+10
void SnakeMove()
{
	for (int i = snake.n - 1; i > 0; i--)
	{
		snake.sCoor[i].x = snake.sCoor[i - 1].x;
		snake.sCoor[i].y=snake.sCoor[i - 1].y;
		//setcolor(RGB(snake.sCoor[i].x/2, snake.sCoor[i].y/2, i*10));
	}
	//根据不同的方向来改变不同
	switch (snake.ch)
	{
	case up:
		snake.sCoor[0].y -= 10;
		break;
	case down:
		snake.sCoor[0].y += 10;
		break;
	case right:
		snake.sCoor[0].x += 10;
		break;
	case left:
		snake.sCoor[0].x -= 10;
		break;
	}
}

//改变方向
void ChangeCh()
{
	int move;//按键
	move = getch();

	switch (move) {
	case up:
		if (snake.ch != down)
			snake.ch = up;
		break;
	case down:
		if (snake.ch != up)
			snake.ch = down;
		break;
	case right:
		if (snake.ch != left)
			snake.ch = right;
		break;
	case left:
		if (snake.ch != right)
			snake.ch = left;
		break;
	}	
}

//计算食物的坐标
void CoorFood()
{
	food.x = rand() % 64 * 10;
	food.y = rand() % 48 * 10;
	food.flag = 1;
}

//吃食物
	void EatFood()
	{
	if (snake.sCoor[0].x == food.x&&snake.sCoor[0].y == food.y) {
		snake.n++;
		//setcolor(RGB(220, 120, 156));
		food.flag = 0;
	}
}
