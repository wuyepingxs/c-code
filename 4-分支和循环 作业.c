//输入三个数，输出 同样三个数 从大到小排列
#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<string.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d%d", &a, &b, &c);
	if (a < b)
		
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (a < c)
	{
		int tmp = a;
		a = c;
		c = tmp;
	}
	if (b < c)
	{
		int tmp = b;
		b = c;
		c = tmp;
	}
	printf("%d %d %d\n", a, b, c);
	return 0;
}

//作业：打印1-100以内 3的倍数
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			printf("%d ",i);
		}
	}
	return 0;
}

//作业：给定2个数，求这两个数最大公约数
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int m = 0;
    int n = 0;
	int r = 0;
	scanf("%d %d", &m, &n);
	while (r=m%n)
	{
		m = n;
		n = r;
		
	}
	printf("%d\n", n);

	return 0;
}


//任务：输出1000-2000 的闰年 方法1
#include<stdio.h>
#include<string.h>
int main()
{
	int count = 0;
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (year % 4 == 0 && year % 100 != 0)
		{
			printf("%d ", year);
			count++;
		}
		else if (year % 400 == 0)
		{
			printf("%d ", year);
			count++;
		}
	}
	printf("%d个闰年 ", count);
	return 0;
}

//任务：输出1000-2000 的闰年 方法2
#include<stdio.h>
#include<string.h>
int main()
{
	int count = 0;
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if ((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0)) //区别在这里
		{
			printf("%d ", year);
			count++;
		}
	
	}
	printf("%d个闰年 ", count);
	return 0;
}

//任务：输出100-200之间的素数
#include<stdio.h>
int main()
{
	int i = 0;
	int j  = 0;
	for (i = 100; i <= 200; i++) //还可以再优化 for (i = 101; i <= 200; i+=2)，偶数不可能是质数，继续减少一半运算量
	{
		for (j = 2; j < i; j++)//试除法：假定因数 从 2 到 i-1
		{
			if (i%j == 0)
				break;//跳出循环后，只有从2到i-1都整除失败的，最终才有i=j,否则j都比i小。
		}
		if (i == j)
			printf("%d\n ", i);
	}
	
	return 0;
}


//任务：输出100-200之间的素数 方法2，运算量减少一半
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;
	int j  = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		for (j = 2; j <= sqrt(i); j++)
			//试除法 除到一半时还没有的话，剩下一半就不会有了
			//所以用开平方 减少一半 运算量 sqrt，引用<math.h>
		{
			if (i%j == 0)
				break;
		}
		if (j > sqrt(i))     // 当j<= sqrt(i),没有取余为0，是素数，最后j++
		{
			printf("%d\n ", i);
			count++;
		}
	}
	printf("素数总数为 %d", count);
	return 0;
}//答案是 100-200 的素数，以及素数总数为21


//任务：1/1-1/2+1/3......-1/100=？
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;
	double sum = 0.0;//初始值 也要浮点数
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		sum += flag*1.0 / i;
		// 分子分母必有 浮点数 ，值才为浮点数。
		//sum储存浮点数，sum为浮点数类型double
		flag = -flag;    //变换符号
	}
	printf("%lf", sum);
	return 0;
}


//制作猜数字游戏，用时间戳生成随机初始值,
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>  //rand()
#include<time.h>    //time
void menu()        //菜单界面
{
	printf("###########################\n");
	printf("####   1.play  0.exit  ####\n");
	printf("###########################\n");
}
                           //RAND_MAX 32767，rand()取0~32767之间任意值，伪随机
void game()//游戏程序
{
	int ret = 0;
	int guess = 0;
	ret = rand()%100+1;//库函数rand()，<stdlib.h>的。
	while (1)//恒为真，只有猜对了才能退出游戏
	{
		printf("请输入数字:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if(guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n\n");
			break;//跳出while循环
		}
	}
	
}
int main()
{
	int input = 0; 
	srand((unsigned int)time(NULL));//拿时间戳设置随机数设置起点,死记
	do{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//猜数字游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
      } 
while (input);
	return 0;
}


//goto语句执行关机命令，输入我是猪停止。

#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 120");
again:
	printf("2分内关机，输 ‘我是猪’，就取消关机\n请输入：>");
		scanf("%s", &input);
	if (0 == strcmp(input, "我是猪"))
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}


//while 语句执行关机命令，输入我是猪停止。

#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 120");
	while (1)
	{
		printf("2分内关机，输 ‘我是猪’，就取消关机\n请输入：>");
		scanf("%s", &input);
		if (0 == strcmp(input, "我是猪"))
		{
			system("shutdown -a");
			break;
		}
	}
	
	return 0;
}
