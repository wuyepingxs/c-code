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



//   assert const帮助调式
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<assert.h>

//void my_strcpy(char*dest, char*src)
//{
//	while (*src !='\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;//最后一步 把 \0 拷贝过去
//
//}


//老司机 代码
void my_strcpy(char*dest, const char*src)//如果传过来 空指针 NULL，这是非法的
                                        //上一行括号里面 加const ，可报错 防止写反了
{
	assert(src != NULL);//断言    不符合条件 就会断言失败 就会报错 line21 有问题
	assert(dest != NULL);//          第一个断言处 停止
	while (*dest++ = *src++) //既拷贝了 \0 ，又停下了循环。\0为假， 字符串里没有0.
	{             
		;//先 *dest=*src,再 *dest++,*src++.
	}
	*dest = *src;//最后一步 把 \0 拷贝过去

}

int main()
{
	char arr1[10] = "xxx";
	char arr2[] = "hello";
	//strcpy(arr1, arr2);
	my_strcpy(arr1, arr2);
	printf("%s", arr1);
	return 0;
}
