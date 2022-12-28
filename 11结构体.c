//结构体
#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<string.h>


struct B
{
	char c;
	int a;
	float d;
};

struct Stu
{
	//成员变量
	struct B sb;// 成员可以是 另外一个结构体
	char name[20];//名字
	int age;//年龄 
	char id[20];//学号
}s1,s2;//创建2个结构体变量 ，且是全局变量，因为在{}外部的变量。



void print1(struct Stu t)
{
	printf("%c %d %lf    %s %d %s\n", t.sb.c, t.sb.a, t.sb.d, t.name, t.age, t.id);
}
void print2(struct Stu *ps)
{
	printf("%c %d %lf    %s %d %s\n", ps->sb.c, ps->sb.a, ps->sb.d, ps->name, ps->age, ps->id);
}

int main()
{
	//s是局部变量
	struct Stu s = {   {'w',20,3.1}  ,  "张三",30,"2020-1234" };//创建结构体s，同时初始化


	//printf("%c\n", s.sb.c);//打印出来是 'w'
	//printf("%s\n", s.id);
	//struct Stu*ps = &s;
	//printf("%c\n", (*ps).sb.c);
	//printf("%c\n", ps->sb.c);//指针指向的s里的 sb

	//写一个函数打印s的值
	print1(s);   //传值调用  ，也就需要开辟空间，形参t 用来接收 s 的 实参。 对t的改变不影响s，看用途。

	print2(&s);  //传址调用  无需开辟多余空间，也省了 传值时间，避免 空间 时间 双重浪费，效率高。

	return 0;
}

//不想改 可以加 const
