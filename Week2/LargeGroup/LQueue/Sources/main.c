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
		printf("���������Ҫʹ��ʲô��������:\n");
		printf("'i' ָ int, 'f' ָ float ��'c' ָ char!\n");
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
			printf("����������²���:\n");
			printf("1.���ö����Ƿ�Ϊ��;\n");
			printf("2.��ȡ�ö��еĶ���Ԫ��;\n");
			printf("3.��һ��Ԫ������;\n");
			printf("4.��һ��Ԫ�س���;\n");
			printf("5.���������е�����Ԫ��;\n");
			printf("6.��øö��еĳ���;\n");
			printf("7.���ٸö��в��˳�ϵͳ.\n");
			printf("����������루1~7��:\n");
			scanf("%d", &flag);
			while (getchar() != '\n');
			if (flag < 1 || flag>7)
			{
				system("cls");
				printf("��������ȷ�Ĳ����루1~7����");
			}
			else
				break;
		}
		switch (flag)
		{
		case(1)://���
			if (IsEmptyLQueue(Q) == TRUE)
				printf("�ö��������ǿյģ�Ӧ�����������һЩԪ��\n");
			else
				printf("�ö���Ŀǰ�ǿ�\n");
			break;
		case(2)://��ȡ����Ԫ��
			if (GetHeadLQueue(Q, data) == TRUE)
			{
				LPrint(data);
				printf("\n");
			}
			else
				printf("�ö��������ǿյģ�Ӧ�����������һЩԪ��\n");
			printf("\n");
			break;
		case(3)://����
			if (type == 'i')
				get_int(&addData);
			else if (type == 'f')
				get_float(&addData);
			else
				get_char(&addData);
			if (EnLQueue(Q, addData) == TRUE)
				printf("��ϲ�������ѳɹ�����������Ԫ�أ�\n");
			else
			{
				printf("�ռ�����!!!\n");
				exit(-1);
			}
			break;
		case(4)://����
			if (DeLQueue(Q) == TRUE)
				printf("��ϲ�������ѳɹ���һ��Ԫ�س��У�\n");
			else
				printf("�ö��������Ѿ�Ϊ��\n");
		case(5)://��������
			TraverseLQueue(Q, LPrint);
			break;
		case(6)://��ȡ���еĳ���
		{
			int length = LengthLQueue(Q);
			if (length!=-1)
				printf("�ö��еĳ���Ϊ��%d.\n", length);
			else
			{
				printf("�����г�����ĳЩ����!!!\n");
				exit(-1);
			}
			break;
		}
		case(7)://���ٶ��в��˳�
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
	/* �˴�����������������Ǹ������ͼ��������Ǹ�д������̫���ˣ�����......���û���ʵ  */
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

