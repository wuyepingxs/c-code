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
