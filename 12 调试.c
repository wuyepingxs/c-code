//每一个函数的 调用 都会在栈区上开辟一定的空间！
//局部变量 存储在 栈区
//栈区内存的使用是 从高地址 到低地址
//数组 下标增长，地址增加，
//
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
void test()
{
	int a = 10;
	int b = 20;
	int c = a + b;
}

int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i + 1;
	}
	for (i = 0; i < sz; i++)
	{

		printf("%d\n", arr[i]);
	}

	return 0;
}


void test2()
{
	printf("hehe\n");
}
void test1()
{
	test2();
}

void test()
{
	test1();
}


int main()
{
	test();
	return 0;
}

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i = 0;
	//永远碰不到i，死循环
	
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 0;
		printf("hehe\n");
	}

	return 0;
}
