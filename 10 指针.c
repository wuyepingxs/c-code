//利用指针 打印一个数组的元素
#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *p = arr;
	int*pend = arr + 9;
	while (p <= pend)//不要 *p<=*pend, 这是两个指针 的元素比较，本来的目的是指针比较大小
	{
		printf("%d\n", *p);
		p++;
	}
	return 0;
}


//字符串计数器
#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<string.h>

int my_strlen(char*str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int main()
{
	//strlen( )求字符串长度
	//递归

	int len = my_strlen("abc");//字符串传参，传a的地址，即首字符地址。
	printf("%d\n", len);
	return 0;
}




//字符串长度，用指针和指针相减 实现
#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<string.h>


my_strlen(char* str)
{
	char*start = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - start;//'\0'的指针 减去 a 的指针
}
int main()
{
	int len = my_strlen("abcdef");//字符串传参，传即首字符地址。
	printf("%d\n", len);
	return 0;
} 
