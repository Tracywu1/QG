#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"LQueue.h"
void get_type();
void show();
void get_int(void** data);
void get_float(void** data);
void get_char(void** data);

int main()
{
	get_type();
	show();
	return 0;
}


void get_type()
{
	while (1)
	{
		type = '\0';
		printf("请告诉我你要使用什么样的数据:\n");
		printf("'i' 指 int, 'f' 指 float ，'c' 指 char!\n");
		scanf("%c", &type);
		while (getchar() != '\n');
		if (type == 'i' || type == 'f' || type == 'c')
			break;
		else
		{
			system("cls");
			printf("Please don't give me others!\n");
		}
	}
}

void show()
{
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	void* data = NULL;
	if (type == 'i'){
		data = (void*)malloc(sizeof(int));
		datatype[0] = 'i';
	}
	else if (type == 'f'){ 
		data = (void*)malloc(sizeof(float));
		datatype[0] = 'f';
	}	
	else if (type == 'c') {
		data = (void*)malloc(sizeof(char));
		datatype[0] = 'c';
	}
	void* addData;
	int flag;
	InitLQueue(Q);
	while (1)
	{
		while (1)
		{
			flag = 0;
			printf("你可以做以下操作:\n");
			printf("1.检查该队列是否为空;\n");
			printf("2.获取该队列的队首元素;\n");
			printf("3.让一个元素入列;\n");
			printf("4.让一个元素出列;\n");
			printf("5.遍历队列中的所有元素;\n");
			printf("6.获得该队列的长度;\n");
			printf("7.销毁该队列并退出系统.\n");
			printf("请输入操作码（1~7）:\n");
			scanf("%d", &flag);
			while (getchar() != '\n');
			if (flag < 1 || flag>7)
			{
				system("cls");
				printf("请输入正确的操作码（1~7）：");
			}
			else
				break;
		}
		switch (flag)
		{
		case(1)://查空
			if (IsEmptyLQueue(Q) == TRUE)
				printf("该队列现在是空的，应该向里面加入一些元素\n");
			else
				printf("该队列目前非空\n");
			break;
		case(2)://获取队首元素
			if (GetHeadLQueue(Q, data) == TRUE)
			{
				LPrint(data);
				printf("\n");
			}
			else
				printf("该队列现在是空的，应该向里面加入一些元素\n");
			printf("\n");
			break;
		case(3)://入列
			if (type == 'i')
				get_int(&addData);
			else if (type == 'f')
				get_float(&addData);
			else
				get_char(&addData);
			if (EnLQueue(Q, addData) == TRUE)
				printf("恭喜您，您已成功向队列中添加元素！\n");
			else
			{
				printf("空间已满!!!\n");
				exit(-1);
			}
			break;
		case(4)://出列
			if (DeLQueue(Q) == TRUE)
				printf("恭喜您，您已成功让一个元素出列！\n");
			else
				printf("该队列现在已经为空\n");
		case(5)://遍历队列
			TraverseLQueue(Q, LPrint);
			break;
		case(6)://获取队列的长度
		{
			int length = LengthLQueue(Q);
			if (length!=-1)
				printf("该队列的长度为：%d.\n", length);
			else
			{
				printf("队列中出现了某些问题!!!\n");
				exit(-1);
			}
			break;
		}
		case(7)://销毁队列并退出
			DestoryLQueue(Q);
			return;
		}
	}

}

void get_int(void** data)
{
	printf("Please give me a int number:\n");
	int* p = (int*)malloc(sizeof(int));
	char s[50];
	int flag = 1;
	while (1)
	{
		gets_s( s,49);
		if (*s == '-')
		{
			if (strlen(s) < 6)
			{
				int i;
				for (i = 1; i < 6 && s[i] != '\0'; i++)
					if (s[i] < '0' || s[i]>'9');
				{
					flag = 0;
					break;
				}
				if (flag == 1)
				{
					*p = 0;
					for (i = 1; i < 6 && s[i] != '\0'; i++)
						*p = (*p) * 10 + s[i] - '0';
					(*p) *= -1;
					*data = (void*)p;
					return;
				}
			}
		}
		else if (strlen(s) < 5)
		{
			int i;
			for (i = 0; i < 5 && s[i] != '\0'; i++)
				if (s[i] < '0' || s[i]>'9')
				{
					flag = 0;
					break;
				}
			if (flag == 1)
			{
				*p = 0;
				for (i = 0; i < 5 && s[i] != '\0'; i++)
					*p = (*p) * 10 + s[i] - '0';
				*data = (void*)p;
				break;
			}
		}
		printf("Please give me a right int number which is bigger than -10000 and smaller than 10000;\n");
	}
}

void get_float(void** data)
{
	printf("Please give me a float number:\n");
	float* p = (float*)malloc(sizeof(float));
	*p = 0.0;
	/* 此处可以用类比于上面那个函数和计算器中那个写，但是太长了，所以......靠用户诚实  */
	scanf("%f", p);
	while (getchar() != '\n');
	*data = (void*)p;
}

void get_char(void** data)
{
	printf("Please give me a char:\n");
	char* p = (char*)malloc(sizeof(char));
	*p = '0';
	scanf("%c", p);
	while (getchar() != '\n');
	*data = (void*)(p);
}

