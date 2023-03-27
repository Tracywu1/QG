#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"
LinkStack* s = NULL;
void DisplayMenu();
LinkStack* CreateLStack(LinkStack* s);
int JudgeInput();
void visit(ElemType e);

int main() {
	s = (LinkStack*)malloc(sizeof(LinkStack));
	s->top = NULL;
	while (1) {
		DisplayMenu();
		short choice;
		while ((scanf("%hd", &choice) != 1) || choice < 1 || choice > 10) {
			while (getchar() != '\n');//������뻺����
			printf("������Ϸ������롣\n");
			printf("�����������(1~10): ");
		}
		if (choice == 10)
		{
			printf("��ӭ���ٴ�ʹ��, �ټ�!\n");
			break;
		}
		if (s->top && choice == 1)
		{
			/* ��ͼ�ظ�������ջ */
			/* ���ظ���Ϊ */
			printf("�벻Ҫ�ظ�������ջ��\n");
			continue;
		}
		else if (!s->top && choice !=1 )
		{
			/* ��ͼ��������ջ�Ϳ�ʼ������ջ */
			/* ���ظ���Ϊ */
			printf("���ȴ�����ջ�ٶ�����в���.\n");
			continue;
		}
		switch (choice)
		{
		case 1:
			CreateLStack(s);
			traverseLStack(s, visit);
			break;
		case 2:
			traverseLStack(s, visit);
			break;
		case 3:
		{
			if (clearLStack(s))
				printf("������ո���ջ\n");
			else
				printf("�����ջʧ��\n");
				break;
		}
		case 4:
		{
			if (destroyLStack(s))
				printf("�������ٸ���ջ\n");
			else
				printf("������ջʧ��\n");
			break;
		}
		case 5:
		{
			ElemType ele = 0;
			getTopLStack(s, &ele);
			printf("ջ��Ԫ��Ϊ��%d\n", ele);
		    break;
		}
		case 6:
		{
			int data = 0;
			if (popLStack(s, &data))
				printf("��ϲ������ջ�ɹ�����ջ��Ԫ��Ϊ��%d\n", data);
			else
				printf("�Բ��𣬳�ջʧ��,����ջ�Ѿ�Ϊ�գ�\n");
			break;
		}
		case 7:
		{
			printf("\ninput -> element: ");
			int data = JudgeInput();
			if (pushLStack(s, data))
				printf("��ϲ������ջ�ɹ���\n");
			else
				printf("�Բ�����ջʧ�ܣ�\n");
			break;
		}
		case 8:
		{
			int length = 0;
			if (LStackLength(s, &length))
				printf("��ѯ�ɹ�������ջ�ĳ���Ϊ��%d\n", length);
			else
				printf("�Բ��𣬲�ѯʧ�ܣ�\n");
			break;
		}
		case 9:
		{
			if (isEmptyLStack(s))
				printf("����ջΪ��\n");
			else
				printf("����ջ�ǿ�\n");
			break;
		}
		case 10:
			return 0;
		}
	}
}

int JudgeInput() {
	int ele;
	while (scanf("%d", &ele) != 1)
	{
		while (getchar() != '\n');
		printf("\n����������.\n");
	}
	return ele;
}

LinkStack* CreateLStack(LinkStack* s) {
	if (initLStack(s));
	else printf("��ջ��ʼ��ʧ�ܣ�\n");
	int data = 0;
	printf("��������Ҫ��������ջ��Ԫ�صĸ�����");
	int n;
	while (scanf("%d", &n) != 1 || n < 0) {
		while (getchar() != '\n');
		printf("\n������������:\n");
	}
	for (int i = 0; i < n; i++) {
		printf("\ninput -> element: ");
		data = JudgeInput();
		Status status = pushLStack(s, data);
	}
	printf("��ϲ������ջ�ѳɹ�������\n");
	return s;
}

void DisplayMenu() {
	printf("\n");
	printf("**********************************************************************\n");
	printf("   1.������ջ                                 2.��ջ����ʼ���������ջ\n");
	printf("**********************************************************************\n");
	printf("   3.�����ջ                                 4.������ջ\n");
	printf("**********************************************************************\n");
	printf("   5.��ȡջ��Ԫ��                             6.��ջ\n");
	printf("**********************************************************************\n");
	printf("   7.��ջ                                     8.��ȡ��ջ����\n");
	printf("**********************************************************************\n");
	printf("   9.�жϸ���ջ�Ƿ�Ϊ��                      10.�˳�ϵͳ\n");
	printf("--------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~10)��\n");
}