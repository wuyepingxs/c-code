//写一个计算y的函数
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
double count_y(double x)
{

	if (x < 1 || x == 1)
	{
		return exp(x) + 5;
	}
	else if ((x>1 && x < 5) || x == 5)
	{
		return -4 * x + 5;
	}
	else if ((x>5 && x < 10) || x == 10)
	{
		return sqrt(x) - 1;
	}
	else    //x>10
	{
		return 3 * x - 11;
	}


}

int main()
{
	double y = 0;
	double x = 0;
	int cnt = 0;
	printf("为了方便自豪兄测试，本次计算y函数,循环5次\n");
	printf("请输入大于或者等于0的数:>");
	
	while (cnt <= 5)
	{
		cnt++;
		do
		{
			scanf("%lf", &x);
			if (x < 0)
			{
				printf("请重新输入\n");
			}
		} while (x < 0);

        y = count_y(x);
		printf("\n y的值为%lf\n", y);
		if (cnt <= 4)
			printf("请输入下一个测试数:>");
	}

	return 0;
}



//最小 公倍数	
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int i = 1;
	for (i = 1;; i++)
	{
		if (a*i%b == 0)
		{
			printf("%d\n", a*i);
			break;
		}
	}
	return 0;
}


//写一个函数 将 字符串 的单词倒置
void reverse(char*left, char*right)
{
//不要用空指针，交换的是指针对应的变量的值，用变量装值即可。
	
	char tmp = 0;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
//凡是 非亲历亲为 不足为知也
int main()
{
	char arr[100] = { 0 };
	//scanf("%s", arr);//做不到 遇到空格 默认结束 输入 123 456 得出 123 
	//输入进来了
	gets(arr);
	int len = strlen(arr);
	reverse(arr, arr + len - 1); //尝试 将 整个字符串倒置
	//printf("%s\n", arr);
	char*start = arr;
	while (*start)//不要忘记*字符！！！
	{
		char*end = start;

		while (*end != ' '&&*end != '\0')// ' '或者'\0'停下来
		{
			end++;
		}

		//逆序一个单词
		reverse(start, end - 1);

		if (*end == ' ')
			start = end + 1;
		else
			start = end;//相当于break：指针 相同，那么解引用时对应的（ 地址相同） 值相同
		              // 可以while（1），此处直接用break 
      }
	printf("%s", arr);
	return 0;
}
