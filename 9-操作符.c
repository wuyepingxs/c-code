//不创建变量，交换两个变量的值。
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{//此种写法 ，倘若遇到缓存溢出，不好
  int a = 3;
  int b = 5;
  printf("a=%d,b=%d", a, b);
  a = a + b;
  b = a - b;
  a = a - b;
  printf("a=%d,b=%d", a, b);
  return 0;
}

//sizeof()中的表达式 不参与运算
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
  short s = 5;
  int a = 10;
  printf("%d\n", sizeof(s = a + 2));//sizeof()中的表达式 不参与运算
  printf("%d\n", s);
  return 0;
}//答案：2 5


//  问题代码：操作符 1优先级 2结合性 3控制求值顺序（&& ||   ？： ,）
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

	int fun()
	{
		static int count = 0;
		return count++;
	}

	int main()
	{
		int answer;
		answer = fun() - fun()*fun();//哪个fun先调用不知道，这是问题代码
		printf("%d\n", answer);
		return 0;
	}




// 1 初始化 2逆置，不是逆序
#define _CRT_SECURE_NO_WARNINGS 

void init(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}

void print(int*arr, int sz)//数组名是首元素地址，可以用指针接收:    int*arr
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[], int sz)

{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}


}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);//，打印数组各个元素，传参 数组名就是首元素地址，sz就是数组元素个数
	reverse(arr, sz);//逆置 交换 位置而已
	print(arr, sz);
	init(arr, sz);//初始化 使数组各元素为0
	print(arr, sz);//打印 初始化后的数组 各个元素
	return 0;
}
