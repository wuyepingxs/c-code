#include"game.h"
//   |   |  
//---|---|---
//   |   |  
//---|---|---
//   |   |


//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' '; // 把board里面的 元素 统统替换成' '，即 不可打印的空格
		}
	}
}



//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//从0到 row-1 大行，每行有2 个 分行，分别是 数据 和分隔符
	{	                     //最后一大行 分隔符行不要


		//打印 数据行== 多列
		int j = 0;//每行最后一列，第二个组成部分不要
		for (j = 0; j < col; j++)//每一列 有2 个 组成部分
		{

			printf(" %c ", board[i][j]);
			if (j < col - 1)//最后一列 不要"|"
				printf("|");
		}
		printf("\n");//换行



		if (i < row - 1)//最后一大行，分隔符行不要，打印 0 -- row-2 下标的，即 前面 row-1行的
		{//打印 分割符行 == 多列
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");//最后一列 不要 "|"
			}
			printf("\n");//换行
		}
	}
	printf("\n");
}


//玩家走
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>");

	while (1)
	{
		printf("请输入下棋的坐标:>");
		scanf("%d %d", &x, &y);
		//1.判断坐标合法性
		if (x >= 1 && y >= 1 && x <= row && y <= col)

		{
			if (board[x - 1][y - 1] == ' ')//2.判断坐标是否被占用
			{
				board[x - 1][y - 1] = '*';//3.玩家下棋 放*
				break;//4.直到下了，才退出循环。
			}
			else
			{
				printf("坐标被占用,请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");

		}
	}
}


//电脑走
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走:>\n");

	while (1)
	{
		int x = rand() % row;//值为0-2
		int y = rand() % col;//值为0-2，即 0 --（3-1）
		//此时 x y本来都是0-2，无需看是否合法，只看是否被占用，不用-1，可直接作为下标
		//每次进来重新随机，直到找到能符合规则的x y。
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;//电脑会一直重复到能下 为止
		}//没有else 提示，然后重来
	}
}



//棋盘满了没
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//每行每列都查找有没有 NULL，有的话就 return 0
			}
		}
	}
	return 1;//以上循环走完了，一个空格都没有，说明棋盘满了，平局，返回1.
}



//谁赢了
//判断游戏状态（本函数写死了，仅仅针对三子棋）

//1.玩家赢     *
//2.电脑赢     #
//3.平局       Q
//4.游戏未结束 C
char IsWin(char board[ROW][COL], int row, int col)
{
	//判断三行，此处写死了
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];//第i行 任意一个都行 ，用 * # 作为返回值，
			//免得判断 里面是否为* #，来确定返回值，多一道判断的工序
		}
	}

	//判断三列,此处写死了
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];//第i列 任意一个都行
		}
	}

	//判断对角线，此处写死了
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] !=' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//判断平局
	//IsFull 如果棋盘满了返回1，不满返回0；
	if(1==IsFull(board,row,col))//IsWin嵌套了IsFull，输入1 1，iswin返回Q，说明isfull返回1	                       
	{                           //此处千万不要＋ 分号;  不然if就失效，直接执行if里面的语句
		return 'Q';
	}



	//游戏继续
	return 'C';
}
