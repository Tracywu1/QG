#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"
LinkedList L=NULL;
LNode* in = NULL;
void visit(ElemType e);
void TraverseList(LinkedList L, void (*visit)(ElemType e));
LNode* SearchEle(LinkedList L, int ele);
int JudgeInput();

LinkedList CreateList(LinkedList* L) {
	InitList(L);
	printf("��������Ҫ�����������Ԫ�صĸ�����");
    int n;
	while (scanf("%d", &n)!=1 || n<0 ) {
			while (getchar() != '\n');
			printf("\n������������:\n");
	}
	LNode* s;
	LNode* p;
	p = *L;
	for (int j = 0; j < n; j++) {
		s = (LNode*)malloc(sizeof(LNode));// �����½��
		printf("\ninput -> element: ");
		s->data = JudgeInput();
		s->next = p->next;
		p->next = s;
		p = p->next;
		if (j == n - 1)
		{
			p->next = *L;
		}
	}
	printf("��ϲ���������ѳɹ�������\n");
	return *L;
}

void JudgeLoop(LinkedList L) {
	if (IsLoopList(L))
		printf("��������ѭ������");
	else
		printf("��������ѭ������");
}

void DeleteEle(LinkedList* L) {
	if ((*L)->next == NULL) {
		printf("���ȴ��������ٳ���ɾ�������е�Ԫ�ء�\n");
		return;
	}
	printf("������������Ҫɾ����Ԫ��֮ǰ��Ԫ�أ�\n");
	while (1) {
		int ele = JudgeInput();
		LNode* before = SearchEle(*L, ele);
		if (before == NULL) {
			printf("�������Ԫ�ز��ڸ������У����������룡\n");
			continue;
		}
		else {
			int e = 0;
			if (DeleteList(before, &e)) {
				printf("��ϲ�㣡����ɾ���ɹ���\n");
				break;
			}
			else {
				printf("�Բ���,ɾ��ʧ�ܣ�\n");
				break;
			}
		}
	}

}

void InsertEle(LinkedList* L) {
	printf("������������Ҫ�����Ԫ�أ�\n");
	int ele = JudgeInput();
	LNode* in = (LNode*)malloc(sizeof(LNode));
	in->data = ele;
	in->next = NULL;
	printf("�������뽫������ĸ�Ԫ��֮��\n");
	while (1) {
		int ele1 = JudgeInput();
		if (SearchList(*L, ele1)==0) {
			printf("�������Ԫ�ز��ڸ������У����������룡");
			continue;
		}
		else {
			LNode* before = SearchEle(*L, ele1);
			if (InsertList(before, in))
				printf("��ϲ�������Ѳ���ɹ���\n");
			break;
		}
	}
	TraverseList(*L, visit);
}

LNode* SearchEle(LinkedList L, int ele) {
	LNode* p = L->next;
	while ((p != L) && (p->data != ele)) {
		p = p->next;
	}
	if (p == L) {

		return NULL;
	}
	else {
		return p;
	}
}

void FindMid(LinkedList L) {
	LNode* mid = FindMidNode(&L);
	printf("��������м�Ԫ��Ϊ��%d\n", mid->data);
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

void DisplayMenu() {
	printf("\n");
	printf("************************************************************\n");
	printf("   1.����������                           2.��ӡ����\n");
	printf("************************************************************\n");
	printf("   3.ɾ��ĳһԪ��֮���Ԫ��               4.����ĳһԪ��\n");
	printf("************************************************************\n");
	printf("   5.��ת����                             6.Ԫ����ż����\n");
	printf("************************************************************\n");
	printf("   7.�ж��Ƿ�Ϊѭ������                   8.��ѯ�Ƿ����ĳһԪ��\n");
	printf("************************************************************\n");
	printf("   9.��ѯ��������м�Ԫ��                 10.��������\n");
	printf("************************************************************\n");
	printf("                            11.exit\n");
	printf(" -------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~11)��\n");
}


int main() {
	while (1) {
		DisplayMenu();
		short choice;
		while ((scanf("%hd", &choice) != 1) || choice < 1 || choice > 11) {
			while (getchar() != '\n');//������뻺����
			printf("������Ϸ������롣\n");
			printf("�����������(1~11): ");
		}
		if (choice == 11)
		{
			printf("��ӭ���ٴ�ʹ��, �ټ�!\n");
			break;
		}
		if ( L != NULL && choice == 1)
		{
			/* ��ͼ�ظ��������� */
		    /* ���ظ���Ϊ */
			printf("�벻Ҫ�ظ���������\n");
			continue;
		}
		else if (L== NULL && choice != 1)
		{
			/* ��ͼ����������Ϳ�ʼ�������� */
			/* ���ظ���Ϊ */
			printf("���ȴ��������ٶ�����в���.\n");
			continue;
		}
		switch (choice)
		{
		case 1:
			CreateList(&L);
			TraverseList(L, visit);
			break;
		case 2:
			TraverseList(L, visit);
			break;
		case 3:
			DeleteEle(&L);
			TraverseList(L, visit);
			break;
		case 4:
			InsertEle(&L);
			break;
		case 5:
			ReverseList(&L);
			TraverseList(L, visit);
			break;
		case 6:
			ReverseEvenList(&L);
			TraverseList(L, visit);
			break;
		case 7:
			JudgeLoop(L);
			break;
		case 8:
			printf("������������Ҫ��ѯ��Ԫ�أ�\n");
			int ele = JudgeInput();
			LNode* se = SearchEle(L, ele);
			if (se)
				printf("��������ڸ�Ԫ��\n");
			else
				printf("�������в����ڸ�Ԫ��\n");
			break;
		case 9:
			FindMid(L);
			break;
		case 10:
			DestroyList(&L);
			break;
		case 11:
			return 0;
		}
	}
}
