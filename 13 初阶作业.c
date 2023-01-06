 运算符优先级
#define _crt_secure_no_warnings 
#include<stdio.h>

 
int main()
{
	int a, b, c;
	a = 5;//
	c = ++a;//
	b = ++c; c++; ++a; a++;//c=8;a=8;b=7
	b += a++ + c;
	// a++ 表达式，在运算完成后自增，+ 比+=优先，a+c为8+8=16，b+=16为b=7+16=23,最后a自增后为9
	printf("a=%d b=%d c=%d", a, b, c);
	return 0;
}
//答案 9 23 8



写一个代码判断一个数字二进制形式 补码 1的个数. 只有%了为1 才count++
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
 此函数 不能处理负数
int Numberof1(int n)
{
	int count = 0;
	while (n)//能进循环就一定能  进入 下面的 if
	{
		if (n % 2 == 1)//这个代码对负数 不灵，count永远无法++
		{
			count++;
		}
		n /= 2;
	}
	return count;

}


//容易理解，但代码还不够少
//int Numberof1(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) == 1)//按位与 1    等于1，说明最后一位为1。找到一次1，count++
//		{
//			count++;
//		}
//	}
//	return count;
//}

//最简单的
int Numberof1(int n)
{
	int count = 0;
	int i = 0;
	while (n)
	{
		n = n&(n - 1);//规律：n与n-1, 去掉n的一个1；直到没有1.
		count++;
	}
}
//int main()
//{
//	int n = 10;//n=10时，ret=2; n=-1时，ret=4;
//    //n=-1
//	//原码 10000000000000000000000000000001
//	//反码 11111111111111111111111111111110
//	//补码 11111111111111111111111111111111 32个1
//	int ret = Numberof1(n);
//	printf("ret=%d\n", ret);
//	return 0;
//}

//写一个代码判断一个数字是不是2的N次方
//2的N次方数字，其中只有一个1
//那么k&(k-1)==0; 一次就够了，说明是2的N次方


//输入两个整数，求两个整数二进制位 格式 有多少个 位 不同

#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int m = 0;
	int n = 0;
	int i = 0;
	int count = 0;
	scanf("%d %d", &m, &n); 

	int ret = m^n;
	//相同为0，相异为1。
	//统计一下ret的二进制中有几个1，说明m和n的二进制位中 有几个位不同。
	count = Numberof1(ret);       // 调用函数

	/*for (i = 0; i < 32; i++)
	{
		if (((m >> i) & 1) != ((n >> i) & 1))
		{
			count++;
		}
	}*/

	printf("不同位数=%d\n", count);
	return 0;
}
