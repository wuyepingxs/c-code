#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int i = 1;
	while (10 >= i)
	{
		printf("%d", i);
		i++;
	}
	return 0;
}
//在屏幕打印1-10的数字


#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int i = 1;
	while (10 >= i)
	{
		if (i == 5)
			continue;
		printf("%d", i);
		i++;
	}
	return 0;
}//结果是 1234+闪动的光标（无限循环continue 之前的内容， 终止本次循环，跳到下一次循环入口）



#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	char ch = 0；//此处一般用char，int能用但不推荐。 之所以赋值0，是为了让机器觉得里面有东西，不然第一个输入的字符会
	            //给ch，而不是放在缓冲区。以后其他所有东西都必须赋初始值。
	while ((ch = getchar()) != EOF)  //ctrl+z 输入后 终止
	{
		putchar(ch);
	}

	
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	char ret = '\0';
	char ch = 0;//用'\0'更准确
	char password[20] = { 0 };
	printf("请输入密码>:");
		scanf("%s", password);//输入密码并存放在password数组中。密码：123456 ABCD
		                      //scanf只读空格之前的东西
		                     //因为是字符串 所以不用 %d 配合&
		while ((ch = getchar()) != '\n')
		{
			;//当getchar读取到\n时，跳出循环.修改之前这里是getchar（）
			//免得下面的ret=getchar，读到A 导致不给等待输入的机会
			//所以用这个循环清空缓冲区。此处密码ABCD部分 没有读进去
			//所以密码不能有空格
		}
		printf("请确认（Y/N）:>");

		ret = getchar();//Y/N
		if (ret == 'Y')
			printf("确认成功\n");
		else
			printf("放弃确认\n");

	
	return 0;
}
