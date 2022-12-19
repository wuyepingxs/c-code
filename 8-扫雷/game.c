//
#define _CRT_SECURE_NO_WARNINGS 
#include"game.h"


//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;//set接收参数，无论传过来是啥，都用来初始化
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{//此处应该用ROWS COLS，传mine过来，11*11 应给也是11*11接收

	int i = 0;
	int j = 0;
	printf("------扫雷游戏------\n");
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}

	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);//加个空格
		}
		printf("\n");
	}
	printf("------扫雷游戏------\n\n");
}


//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col)
{//布置10个雷
	int count = EASY_COUNT;
	while (count)
	{
		//生成随机下标
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}


static int get_mine_count(char mine[ROWS][COLS],int x,int y)//加static仅仅是在game.c里面使用
{//假设要排查x,y坐标周围 8个位置，其实只要统计一下周围8个坐标的信息即可
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			if (mine[x + i][y + j] == '1')
			{
				count++;
			}
		}
	}
	return count;

}





//排查雷 
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1.输入排查雷的坐标
	//2.检查坐标处是不是雷
	//（1）是雷 -很遗憾炸死了，游戏结束
	//（2）不是雷-统计坐标周围有几个雷-存储排查雷的信息到show数组,游戏继续
	int win = 0;
	while (win < row*col-EASY_COUNT)//9*9-10=71,排雷71次未炸，说明赢了
	{
		int x = 0;
		int y = 0;
		printf("请输入要排查的坐标:>");
		scanf("%d %d", &x, &y);//x--(1-9)  y--（1-9）

		//判断坐标合法性
		if (x >= 1 && x <=row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);//展示一下棋盘 ，让玩家输的心服口服
				break;
			}
			else
			{
				//不是雷的话，统计x,y坐标周围有几个雷
				int count =get_mine_count(mine, x, y);//此处假设count得到的是数字3
				show[x][y] = count+'0';//而show要装的是字符3，因此要转换一下,加48，也就是字符'0'.
				//显示排查出的信息
				DisplayBoard(show, row, col);
				win++;
				DisplayBoard(mine, ROW, COL);//测试人员开挂做参考
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}
	if (win == row*col - EASY_COUNT)//win=9*9-10=71
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, row, col);
	}

}
