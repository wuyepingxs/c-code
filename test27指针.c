
#define _CRT_SECURE_NO_WARNINGS 
int main()
{
	/*char ch = 'q';
	char*pc = &ch; */
	//字符指针不仅可以指向一个字符，还可以指向一个字符串；

	char*ps = "hello bit";// 本质上 "hello bit"字符串首字符地址 存储到指针变量ps中
	char arr[] = "hello bit";//访问形式一样的，但是字符串放进了数组
	//*ps = 'w';//err
	//打印字符数组
	//printf("%c\n", *ps);//h
	//printf("%s\n", ps);//   打印字符串，直接用指针就行，指针就是地址，不能用 解引用操作 ，否则出错
 //   printf("%s", arr);
	return 0;
}

int main()
{
	char str1[] = "hello bit";
	char str2[] = "hello bit";
	const char* str3 = "hello bit";//常量字符串不能改 ，否则err
	const char* str4 = "hello bit";

	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");

	return 0;
}

//指针数组         数组中存放的是指针
int main()
{
	////arr是一个存放整形指针的数组
	//int a = 10;
	//int b = 20;
	//int c = 30;

	//int * arr[3] = {&a,&b,&c};
	//int i = 0;
	//for (i = 0; i < 3; i++)
	//{
	//	printf("%d ", *(arr[i]));
	//} //老土 愚蠢的写法


	int a[5] = { 1, 2, 3, 4, 5 };
	int b[] = { 2, 3, 4, 5, 6 };
	int c[] = { 3, 4, 5, 6, 7 };
	int*arr[3] = { a, b, c };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			//printf("%d ", *(arr[i] + j));
			printf("%d ", arr[i][j]); 
			//[j] == *(+j)
			//模拟了一个二维数组，但不是， 二维数组是连续存放，此处看起来连续存放
		}
		printf("\n");
	}
	return 0;
}



//数组指针 
int main()
{
	int a = 10;
	int*pa = &a;
	char ch = 'w';
	char*pc = &ch;

	double*d[5] ;
	int arr[10] = { 1, 2, 3, 4, 5 };
	//  int*parr[10]= &arr; //成为指针数组了，parr先和方块结合


	int(*parr)[10] = &arr;
	//parr就是一个数组指针---存放数组的地址

	double*(*pd)[5] = &d;
	// 数组元素类型+指针名+数组元素个数

	//arr 数组首元素地址
	//&arr 取出数组的地址
	//parr存放 数组的地址 10个地址 
	return 0;
}

int main()
{
	float f = 9.0f;
	int *p = (int*)&f;
	printf("%d\n", *p);
	return 0;
}
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);
	printf("%p\n", &arr);
	printf("%p\n", arr + 1);
	printf("%p\n", &arr + 1);
	//打印结果一样 但是类型不一样
	//数组名是首元素地址，2个例外
	//1.sizeof(数组名)---     计算整个数组 占内存大小
	//2. &数组名      ---     取出整个数组的地址

return 0;
}

不好的写法 ，用了 数组指针，一半不这么写
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11 };
	int(*pa)[10] = &arr;//数组指针
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *((*pa) + i));//此时*pa相当于数组名，因为pa是数组指针
		                          //对pa解引用操作，不是第一个元素； 而是拿到了整个数组=相当于数组名=相当于首元素地址
		                            //这中写法 很别扭
	}
	printf("%d", *(*pa+9));
	return 0;
}

//方便的写法 
void print1(int arr[3][5], int r, int c)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//p是一个 数组指针
void print2(int(*p)[5], int r, int c)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", *(*(p + i) + j));
			//*(p + i) 在 i=0,1,2时   相当于 arr[0], arr[1], arr[2]， 即数组名，即一行内首元素地址!!!
		}
		printf("\n");
	}
}
int main()
{
	//类似 int a[5]; &a  用 int（*p)[5] 接收 
	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6, }, { 3, 4, 5, 6, 7 } };
	//print1(arr, 3, 5);
	print2(arr, 3, 5); //arr数组名 表示数组首元素地址,但 二维数组首元素是 第一行！！！（一维数组的五个地址）

	return 0;
}

void test(int(*arr1)[5])
{}
int main()
{
	int arr[3][5] = { 0 };
	test(arr);
	return 0;
}


int i;//全局变量，不初始化，默认是0
int main()
{

     i--;//-1
	 //1. sizeof这个操作符，算出的结果类型是unsigned int
	if (i > sizeof(i))//-1>4    2. 有符号整数型 和 无符号整形 比较大小
		                    //    会把 有符号数当作无符号数处理，即超级大的正数，全1
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}
	return 0;
}


求Sn=a+aa+aaa+aaaa+aaaaa前五项之和，其中a是一个数字
例如2+22+222+2222+22222
#include<stdio.h>
int main()
{
	//由a组成前N项之和--不考虑溢出
	int a = 0;
	int n = 0;
	scanf("%d %d", &a, &n);
	int i = 0;
	int sum = 0;
	int ret = 0;//一项
	for (i = 0; i < n; i++)
	{
		ret = ret * 10 + n;  //算出一项
		sum = sum + ret;     //求和
	}
	printf("sum=%d\n", sum);
	return 0;
}

#include<stdio.h>
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int*p = arr;
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int*pend = arr + sz - 1;                //设定指针的限制条件
	while (p <=pend)
	{
		printf("%d ", *p);
		p++;//+到 等于限制条件为止
	}
	/*for (i = 0; i < sz; i++)
	{
		printf("%d ", *p);
		p++;
		
	}*/
	return 0;
}

//n位数的 每一位数的n次方之和 是n位数本身的值，则是自幂数
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//判断i是否会自幂数
		//1.计算i的位数-n
		int n = 1;
		int tmp = i;
		while (tmp / 10)
		{
			n++;
			tmp = tmp / 10;
		}
		//2.计算i的每一位n次方之和
		tmp = i;        //tmp已经变了，让tmp的值恢复
		int sum = 0;
		while (tmp)
		{
			sum+=pow(tmp % 10, n);
			tmp = tmp / 10;
		}
		//3.判断
		if (sum == i)
		{
			printf("%d ", i);
		}
	}
	return 0;
}

#include<stdio.h>

int main()
{

	return 0;
}

