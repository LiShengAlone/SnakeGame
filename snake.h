#pragma once
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>     //srand
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define MAXSIZE 100  //��������100����

//ö�ٷ���
typedef enum Ch
{
	up = 72,
	down = 80,
	left = 75,
	right = 77,
}CH;

typedef struct Coor
{
	int x;
	int y;
}COOR;

//�ߵĽṹ��
typedef struct Snake
{
	int n;//��ǰ����
	CH ch;//����
	COOR sCoor[MAXSIZE];//ÿһ���ߵ�����

}SNAKE;

//����ʵ��  1��ʳ��һ������   ���꣨int x��int y��  ʳ���Ƿ񱻳Ե�
//�����
typedef struct Food
{
	int x;
	int y;
	int flag;
}FOOD;

FOOD food;//����ʳ��
SNAKE snake;//������

void GameInit();
void DrawSnake();
void SnakeMove();
void ChangeCh();
void EatFood();
void CoorFood();
