//
#define _CRT_SECURE_NO_WARNINGS 
#define ROW         9
#define COL         9
#define ROWS       ROW+2
#define COLS       COL+2
#define EASY_COUNT  10    //改成80，排一次就排雷成功，测试胜利是否准确

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
//声明函数

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//布置雷
void SetMine(char board[ROWS][COLS], int row, int col);
//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
