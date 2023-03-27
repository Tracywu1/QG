#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculator.h"
LinkStackNum* s_num = NULL;
LinkStackChar* s_ch = NULL;
Status judgeChar(ElemType2 ch);
char opCompare(char t1, char t2);
float calcMain();
float calculate(float num1, char op, float num2);
void DisplayMenu();


int main()
{
	while (1) {
		DisplayMenu();
		short choice;
		while ((scanf("%hd", &choice) != 1) || choice < 1 || choice > 10) {
			while (getchar() != '\n');//清空输入缓冲区
			printf("请输入合法操作码。\n");
			printf("请输入操作码(1~2): ");
		}
		if (choice == 2){
			printf("欢迎您再次使用, 再见!\n");
			break;
		}
		switch (choice) {
		case 1:
		{
			while (getchar() != '\n');
			printf("请您输入算术表达式(自加等号):\n");
			ElemType1 result = 0.0;
			result = calcMain();
			printf("%g\n", result);
			while (getchar() != '\n');
			break;
		}
		case 2:
			return 0;
		}
	}
}

/*
用于获取用户输入，并且进行计算
*/
float calcMain()
{
	s_num = (LinkStackNum*)malloc(sizeof(NumNode));
	s_num->top = NULL;
	s_ch = (LinkStackChar*)malloc(sizeof(CharNode));
	s_ch->top = NULL;

	ElemType1 num1, num2, pnum1, pnum2, result, num;
	result = 0.0;
	char ch, ch1, ch2, sign;
	char* str = NULL;
	int count = 0;

	//初始化
	initLSNum(s_num);
	initLSChar(s_ch);

	////将'='计算在运算符栈中
	pushLSChar(s_ch, '=');
	ch = getchar();                                  //从键盘读取字符
	while ((ch != '=') || s_ch->top->next->ch != '=')//两者都不是等于号时
	{
		if (judgeChar(ch) == 0)//输入的是数字
		{
			str = (char*)malloc(sizeof(char) * 10);
			do
			{
				*str = ch;                           //数字放一块           
				str++;
				count++;
				ch = getchar();
			} while (judgeChar(ch) == 0);
			*str = '\0';
			str = str - count;                       //指针指回字符串的首地址
			num = (float)atof(str);                         //将字符串转换为浮点数
			pushLSNum(s_num, num);                   //将数推进操作数栈中
			str = NULL;
			count = 0;
		}
		else//输入的是运算符
		{
			switch (opCompare(s_ch->top->next->ch, ch))
			{
				//当前运算符优先级高于栈顶运算符
			case '<':
			{
				pushLSChar(s_ch, ch);
				ch = getchar();
				break;
			}
			//当前运算符优先级等于栈顶运算符
			case '=':
			{
				popLSChar(s_ch, &ch1);
				sign = ch1;
				ch = getchar();
				break;
			}
			//当前运算符优先级低于栈顶运算符
			case '>':
			{
				popLSChar(s_ch, &ch2);
				sign = ch2;
				popLSNum(s_num, &pnum1);
				num2 = pnum1;
				popLSNum(s_num, &pnum2);
				num1 = pnum2;
				result = calculate(num1, sign, num2);
				pushLSNum(s_num, result);
				break;
			}
			}
		}
	}
	result = s_num->top->next->num;
	return result;
}

/*
   判断运算符数否输入正确
*/
Status judgeChar(ElemType2 ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '=' || ch == '\n')
		return SUCCESS;
	else
		return ERROR;
}



/*
	  判断栈顶运算符与当前运算符的优先级
	  t1为栈顶运算符，t2为与栈顶比较的运算符
*/
char opCompare(char t1, char t2)
{
	char ch = 0;
	switch (t2)
	{
	case '+':
	case '-':
	{
		ch = (t1 == '(' || t1 == '=') ? '<' : '>';
		break;
	}
	case '*':
	case '/':
	{
		ch = (t1 == '*' || t1 == '/' || t1 == ')') ? '>' : '<';
		break;
	}
	case '(':
	{
		if (t1 == ')')
		{
			printf("ERROR INPUT\n");
			exit(-1);
		}
		else
		{
			ch = '<';
		}
		break;
	}
	case ')':
	{
		switch (t1)
		{
		case '(':
		{
			ch = '=';
			break;
		}
		case '=':
		{
			printf("ERROR INPUT\n");
			exit(-1);
		}
		default:ch = '>';
		}
		break;
	}
	case '=':
	{
		switch (t1)
		{
		case '=':
		{
			ch = '=';
			break;
		}
		case '(':
		{
			printf("ERROR INPUT!\n");
			exit(-1);
		}
		default:ch = '>';
		}
	}
	}
	return ch;
}



/*
   简单的计算功能
*/
float calculate(float num1, char op, float num2)
{
	float result = 0.0;
	switch (op)
	{
	case '+':
	{
		result = num1 + num2;
		break;
	}
	case '-':
	{
		result = num1 - num2;
		break;
	}
	case '*':
	{
		result = num1 * num2;
		break;
	}
	case '/':
	{
		if (num2 == 0)
		{
			printf("error input!\n");
			return -1;
		}
		else
		{
			result = num1 / num2;
		}
	}
	}
	return result;
}



/*
   菜单
*/
void DisplayMenu() {
	printf("------------------------------------------\n");
	printf("|      (        |       )      |    +    |\n");
	printf("------------------------------------------\n");
	printf("|    7     |    8    |    9    |    -    |\n");
	printf("------------------------------------------\n");
	printf("|    4     |    5    |    6    |    *    |\n");
	printf("------------------------------------------\n");
	printf("|    1     |    2    |    3    |    /    |\n");
	printf("------------------------------------------\n");
	printf("|       0       |       .      |  enter  |\n");
	printf("------------------------------------------\n");
	printf("1.进行正整数或浮点数四则运算（抱歉，负数还未实现）\n");
	printf("2.退出\n");
}