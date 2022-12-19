//扫雷
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include"game.h"


void menu()
{
	printf("**********************************\n");
	printf("***********   1.play  ************\n");
	printf("***********   0.exit  ************\n");
	printf("**********************************\n");
}

void game() 
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的 雷 的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的 雷 的信息
	//初始化棋盘
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');

	//打印棋盘
	//DisplayBoard(mine, ROW, COL);//玩家玩的时候不打印这个，现在打印是为了测试验证
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);//玩家玩的时候不打印这个，现在打印是为了测试验证


	//排查雷-关键函数，好好写，好好理解其中的逻辑
	FindMine(mine, show, ROW, COL);//9行9列，mine的信息放到 show里面，
	                               //同时可以嵌套，开挂打印mine
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)//switch后面 不要加 分号，否则报错
		{case 0:
			printf("退出游戏\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;

	//真正
}





