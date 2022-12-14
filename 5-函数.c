// 自定义函数
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int get_max(int x, int y)
//返回类型 函数名 函数参数
{
	if (x > y)
		return x;
	else
		return y;
}
int main()
{
	int a = 10;
	int b = 20;
	int max = get_max(a, b);
	printf("max=%d\n", max);

	max = get_max(100, 400);
	printf("max=%d\n", max);
	return 0;
}

// 通过指针交换实参的值
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

//void Swap1(int x, int y)
////返回类型 函数名 函数参数
//{
//	int temp = 0;
//	temp = x;
//	x = y;
//	y = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap1(a, b);
//	printf("a=%d,b=%d\n", a,b);
//
//	
//	return 0;
//}
void Swap2(int*pa,int*pb)
{
	int tmp = 0;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
int main()
{
	int a = 10;
	int b = 20;
	Swap2(&a, &b);
	printf("a=%d,b=%d\n",a,b);

	return 0;
}

// 写一个函数,判断一个数是否是素数，并且求100-200内的素数
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>

int is_prime(int n)
{
	int x = 0;
		for (x = 2; x < sqrt(n); x++)//试除 2到（n-1）,sqrt减少一半运算量
		{

			if (n%x == 0)
			{
				return 0;
				break;
			}

		}
			return 1;//只要返回了0,函数就结束了。不用怕for结束后，每次执行return 1.

}


int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (is_prime(i) == 1)
		printf("%d是素数\n",i);
	}
	return 0;
}

// 写一个函数,判断某年是否是闰年，打印1000-2000的闰年。
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int is_leap_year(int n)//功能要单一独立，别打印
{
	if ((n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0))
		return 1;
	else
		return 0;
}


// 写一个函数,实现整形有序数组二分查找
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
                     //arr这里本质是一个指针 ，不输入任何东西，就是第一个元素，输入下标，就是对数组里元素进行操作
int binary_search(int arr[],int k,int sz)
{
	//算法的实现
	
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid]>k)
		{
			right = mid - 1;
		}
		else//此时只剩下等于
		{
			return mid;
		}
		
	}
	return -1;
}


int main()
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k = 17;
	int ret=binary_search(arr, k,sz);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，下标是:%d\n", ret);
	}
	return 0;
}

int main()
{
	int i = 0;
	for (i = 1000; i <= 2000; i++)
	{
		if (1==is_leap_year(i))
			printf("%d ", i);
	}
	printf("是闰年\n");
	return 0;
}

//写一个函数，每调用一次，num值加1.
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

void ADD(int* p)//p指针变量
{
	(*p)++;
}
int main()
{
	int num = 0;
	ADD(&num);
	printf("num=%d\n",num);
	ADD(&num);
	printf("num=%d\n", num);
	ADD(&num);
	printf("num=%d\n", num);
	ADD(&num);
	printf("num=%d\n", num);
	return 0;
}

//结果是
//num = 1
//num = 2
//num = 3
//num = 4


//链式访问
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	printf("%d", (printf("%d", printf("%d", 43))));
	return 0;
}
//printf()返回值是 ()内字符个数。
//结果4321



//递归
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);

}
int main()
{

		int num = 1234567;
		print(num);
		return 0;
	
}//打印结果 1 2 3 4 5 6 7 


//不允许创建临时变量，求字符串长度。(此处创建了临时变量)
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>

int my_strlen(char* str) //str是指针变量，存放地址。计算字符串长度，应该返回一个int
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
	char arr[] = { "bit^^^^^^^^^" };
	int len = my_strlen(arr);
	//数组传参 传过去的不是整个数组
	//而是 第一个元素的 地址  
	printf("%d", len);
	
		return 0;
	
}



//重要 @@@@@@@@不允许创建临时变量，求字符串长度，用递归，大事化小。
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>

//int my_strlen(char* str) //str是指针变量，存放地址。计算字符串长度，应该返回一个int
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

int my_strlen(char* str)
{
	if (*str != '\0')
		return 1 + my_strlen(str+1);//用+号 ，让每次的返回值 加起来。指针变量标号不能用++
	else
	    return 0;
}
int main()
{
	char arr[] = { "bit#######" };
	int len = my_strlen(arr);
	//数组传参 传过去的不是整个数组
	//而是 第一个元素的 地址  
	printf("%d", len);
	
		return 0;
	
}


//重要@@@@@@@@     用递归，求阶乘 
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int fac(int n)//n每次都会-1，所以每次递归都有-1，放参数里更合适
               //由于是阶乘，所以相邻的返回值要相乘。
			    //由于是递归，每次收回一个函数时，这个函数充当了中转值。1充当了条件
				//递归和循环 某些时候可以互相转换。
{
	if (n <= 1)
		return 1;
	else
		return n*fac(n - 1);

}

int fac2(int n)
{
	int i = 0;
	int ret = 1;
	for (i = 1; i <= n; i++)
	{
		ret = ret*i;
	}
	return ret;
}
int main()
{

	int n = 10;
	scanf("%d", &n);
	printf("%d", fac2(n));//此处可修改 fac 加或者不加 2 ，切换函数
	
		return 0;
	
}


//重要@@@@@@@@     用递归，斐波那契数，效率低，要高 往下看
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int count = 3;
int fib(int n)
{
	if (n == 3);//测试第三个斐波那契数 计算次数
	{count++; }
	if (n <=2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n = 0;
	scanf("%d", &n);
	printf("%d\n", fib(n));
	printf("%d\n", count);
    return 0;
	
}
//40
//102334155
//204668312 fib（3）计算次数


//重要@@@@@@@@   斐波那契数，用循环更简单
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int fib(int n)
{
	int i = 0;
	int a = 1;
	int b = 1;
	int c = 0;
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		while (n>2)//循环次数是n-2，优化后的结果。用for更容易理解。
		{
			c = a + b;
			a = b;
			b = c;
			n--;
		}
		return c;
	}
}
int main()
{
    int n = 0;
	scanf("%d", &n);
	printf("%d\n", fib(n));
	
    return 0;
	
}
