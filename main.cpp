/*******************************************************
			�ļ����ƣ�main.cpp
			�ļ�������ʵ��һ��̰���ߵ���Ϸ
			���뻷����VS 2015
			����޸ģ�<2017-12-21> <��������> <���ػ�>
*******************************************************/
#include"snake.h"

int main()
{
	GameInit();
	DrawSnake();
	while (1)
	{
		while (!kbhit())   //�����������İ���
		{
			if (food.flag == 0) {
				CoorFood();
			}
			DrawSnake();//�ߵ��ƶ�������һ��ѭ��
			SnakeMove();//�ߵ��ƶ�-���ı䷽��-���ƶ�
			EatFood();
			Sleep(150);
		}
		ChangeCh();
	}
	return 0;
}

//��Ϸ�ĳ�ʼ��
void GameInit()
{
	initgraph(640, 480);

	srand((unsigned int)time(NULL));

	//setbkcolor(RGB(248, 120, 152));
	setbkcolor(RGB(255, 160, 160));
	cleardevice();//����õ���ɫ��ˢ�±���

	mciSendString(L"open ˦�и�.mp3 alias music", 0, 0, 0);	//MIC send ����  string �ַ���
	mciSendString(L"play music", 0, 0, 0);

	rectangle(0,0,10,10);     //��ʼ��һ����
	snake.n = 1;
	snake.sCoor[0].x = 0;
	snake.sCoor[0].y = 0;
	snake.ch = right;//��������
	food.flag = 0;//ʳ�ﱻ�Ե����ܲ����µ�ʳ��
}

//n����!!!!!!����
void DrawSnake()
{
	BeginBatchDraw();
	cleardevice();
	roundrect(food.x, food.y, food.x + 10, food.y + 10, 10, 10);
	for (int i = snake.n - 1; i >= 0; i--) //n����   0--n-1
	{
		//setcolor(RGB(snake.sCoor[i].x / 2, snake.sCoor[i].y / 2, i * 20));
		rectangle(snake.sCoor[i].x, snake.sCoor[i].y, snake.sCoor[i].x+10, snake.sCoor[i].y+10);
	}
	EndBatchDraw();
}

//ÿһ�������x+10
void SnakeMove()
{
	for (int i = snake.n - 1; i > 0; i--)
	{
		snake.sCoor[i].x = snake.sCoor[i - 1].x;
		snake.sCoor[i].y=snake.sCoor[i - 1].y;
		//setcolor(RGB(snake.sCoor[i].x/2, snake.sCoor[i].y/2, i*10));
	}
	//���ݲ�ͬ�ķ������ı䲻ͬ
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

//�ı䷽��
void ChangeCh()
{
	int move;//����
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

//����ʳ�������
void CoorFood()
{
	food.x = rand() % 64 * 10;
	food.y = rand() % 48 * 10;
	food.flag = 1;
}

//��ʳ��
	void EatFood()
	{
	if (snake.sCoor[0].x == food.x&&snake.sCoor[0].y == food.y) {
		snake.n++;
		//setcolor(RGB(220, 120, 156));
		food.flag = 0;
	}
}