#pragma once
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>     //srand
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define MAXSIZE 100  //最多可以有100节蛇

//枚举方向
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

//蛇的结构体
typedef struct Snake
{
	int n;//当前节数
	CH ch;//方向
	COOR sCoor[MAXSIZE];//每一节蛇的坐标

}SNAKE;

//几个实物  1个食物一个变量   坐标（int x，int y）  食物是否被吃掉
//设计类
typedef struct Food
{
	int x;
	int y;
	int flag;
}FOOD;

FOOD food;//定义食物
SNAKE snake;//定义蛇

void GameInit();
void DrawSnake();
void SnakeMove();
void ChangeCh();
void EatFood();
void CoorFood();
