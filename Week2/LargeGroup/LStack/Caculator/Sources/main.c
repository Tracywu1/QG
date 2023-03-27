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
			while (getchar() != '\n');//������뻺����
			printf("������Ϸ������롣\n");
			printf("�����������(1~2): ");
		}
		if (choice == 2){
			printf("��ӭ���ٴ�ʹ��, �ټ�!\n");
			break;
		}
		switch (choice) {
		case 1:
		{
			while (getchar() != '\n');
			printf("���������������ʽ(�ԼӵȺ�):\n");
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
���ڻ�ȡ�û����룬���ҽ��м���
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

	//��ʼ��
	initLSNum(s_num);
	initLSChar(s_ch);

	////��'='�����������ջ��
	pushLSChar(s_ch, '=');
	ch = getchar();                                  //�Ӽ��̶�ȡ�ַ�
	while ((ch != '=') || s_ch->top->next->ch != '=')//���߶����ǵ��ں�ʱ
	{
		if (judgeChar(ch) == 0)//�����������
		{
			str = (char*)malloc(sizeof(char) * 10);
			do
			{
				*str = ch;                           //���ַ�һ��           
				str++;
				count++;
				ch = getchar();
			} while (judgeChar(ch) == 0);
			*str = '\0';
			str = str - count;                       //ָ��ָ���ַ������׵�ַ
			num = (float)atof(str);                         //���ַ���ת��Ϊ������
			pushLSNum(s_num, num);                   //�����ƽ�������ջ��
			str = NULL;
			count = 0;
		}
		else//������������
		{
			switch (opCompare(s_ch->top->next->ch, ch))
			{
				//��ǰ��������ȼ�����ջ�������
			case '<':
			{
				pushLSChar(s_ch, ch);
				ch = getchar();
				break;
			}
			//��ǰ��������ȼ�����ջ�������
			case '=':
			{
				popLSChar(s_ch, &ch1);
				sign = ch1;
				ch = getchar();
				break;
			}
			//��ǰ��������ȼ�����ջ�������
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
   �ж����������������ȷ
*/
Status judgeChar(ElemType2 ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '=' || ch == '\n')
		return SUCCESS;
	else
		return ERROR;
}



/*
	  �ж�ջ��������뵱ǰ����������ȼ�
	  t1Ϊջ���������t2Ϊ��ջ���Ƚϵ������
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
   �򵥵ļ��㹦��
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
   �˵�
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
	printf("1.�����������򸡵����������㣨��Ǹ��������δʵ�֣�\n");
	printf("2.�˳�\n");
}