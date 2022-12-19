//测试 三子棋游戏
#define _CRT_SECURE_NO_WARNINGS 
#include"game.h"//引用自己写的 头文件
void menu()
{
	printf("##########################\n");
	printf("####  1.paly  0.exit  ####\n");
	printf("##########################\n");
}

//游戏算法实现
void game()
{
	char board[ROW][COL] = { 0 };

	//初始化棋盘，使里面全是空格。即初始化数组(游戏模块相关代码，应放在game.c)
	InitBoard(board, ROW, COL);

	//打印棋盘
	DisplayBoard(board, ROW, COL);

	//玩家走，电脑走
	char ret = 0;
	while (1)//一直循环到 ret 不是 C，是不是C由 IsWin决定
	{
		PlayerMove(board, ROW, COL);//玩家下棋
		DisplayBoard(board, ROW, COL);//打印棋盘
        ret = IsWin(board, ROW, COL);//判断： 赢 输 平 继续
		if (ret!='C')
		{
			break;
		}//一直循环到不是C才break, 即C就一直循环，直到变成 *#Q,then  break，


		ComputerMove(board, ROW, COL);//电脑下棋
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret = IsWin(board, ROW, COL);//判断： 赢 输 平 继续
		if (ret != 'C')
		{
			break;
		}//一直循环到不是C才break, 即C就一直循环，直到变成 *#Q,then  break，
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret== '#')
	{
		printf("电脑赢了\n");
	}
	else //(剩下的就是Q了，不可能是C)
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);//说明谁赢了以后，还要打印棋盘给玩家看
}

//主函数
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}

	} while (input);//显示菜单后，input为0,假，退出循环，退出游戏了
	// 1 玩游戏 ，结束后break；1 结果为真，循环再来；显示菜单
	//输入其他的，选择错误； 结果为真，循环再来；显示菜单
	//0，break；结果为假，跳出循环
	
	return 0;
}

// bug：  ret!=C，break了，结果是 1打印 2平局 3打印
