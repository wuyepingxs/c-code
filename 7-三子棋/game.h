#define _CRT_SECURE_NO_WARNINGS 
#define ROW 3 //行3
#define COL 3 //列3	

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//头文件中 需要 声明函数，否则警报，然后在game.c里编辑函数
void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComputerMove(char board[ROW][COL], int row, int col);

char IsWin(char board[ROW][COL], int row, int col);

int IsFull(char board[ROW][COL], int row, int col);
