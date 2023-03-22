#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include "duLinkedList.h"
void visit(ElemType e);
DuLinkedList L = NULL;
DuLNode* in = NULL;
DuLinkedList CreateList(DuLinkedList* L);
void DisplayMenu();
DuLinkedList CreateList(DuLinkedList* L);
void DeleteEle(DuLinkedList* L);
void InsertEle_After(DuLinkedList* L);
void InsertEle_Before(DuLinkedList* L);
DuLNode* SearchEle(DuLinkedList L, int ele);
int JudgeInput();

int main() {
	while (1) {
		DisplayMenu();
		short choice;
		while ((scanf("%hd", &choice) != 1) || choice < 1 || choice > 8) {
			while (getchar() != '\n');//������뻺����
			printf("������Ϸ������롣\n");
			printf("�����������(1~8): ");
		}
		if (choice == 8)
		{
			printf("��ӭ���ٴ�ʹ��, �ټ�!\n");
			break;
		}
		if (L != NULL && choice == 1)
		{
			/* ��ͼ�ظ��������� */
			/* ���ظ���Ϊ */
			printf("�벻Ҫ�ظ���������\n");
			continue;
		}
		else if (L == NULL && choice != 1)
		{
			/* ��ͼ����������Ϳ�ʼ�������� */
			/* ���ظ���Ϊ */
			printf("���ȴ��������ٶ�����в���.\n");
			continue;
		}
		switch (choice)
		{
		case 1://��������
			CreateList(&L);
			TraverseList_DuL(L, visit);
			break;
		case 2://������ӡ����
			TraverseList_DuL(L, visit);
			break;
		case 3://ɾ�������е�Ԫ��
			DeleteEle(&L);
			TraverseList_DuL(L, visit);
			break;
		case 4://ǰ��
			InsertEle_Before(&L);
			break;
		case 5://���
			InsertEle_After(&L);
			break;
		case 6://��ѯԪ��
			printf("������������Ҫ��ѯ��Ԫ�أ�\n");
			int ele = JudgeInput();
			DuLNode* se = SearchEle(L, ele);
			if (se)
				printf("��������ڸ�Ԫ��\n");
			else
				printf("�������в����ڸ�Ԫ��\n");
			break;
		case 7://��������
			DestroyList_DuL(&L);
			break;
		case 8://�˳�ϵͳ
			return 0;
		}
	}
}

void DisplayMenu() {
	printf("\n");
	printf("************************************************************\n");
	printf("   1.����˫������                         2.��ӡ����\n");
	printf("************************************************************\n");
	printf("   3.ɾ��ĳһԪ��֮���Ԫ��               4.����ĳһԪ�أ�ǰ�壩\n");
	printf("************************************************************\n");
	printf("   5.����ĳһԪ�أ���壩                 6.��ѯ�Ƿ����ĳһԪ��\n");
	printf("************************************************************\n");
	printf("   7.��������                             8.exit\n");
	printf(" -------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~8)��\n");
}

DuLinkedList CreateList(DuLinkedList* L) {
	InitList_DuL(L);
	printf("��������Ҫ�����������Ԫ�صĸ�����");
	int n = JudgeInput();
	DuLNode* s;
	DuLNode* p;
	p = (*L);
	for (int j = 0; j < n; j++) {
		s = (DuLNode*)malloc(sizeof(DuLNode));// �����½��
		printf("\ninput -> element: ");
		s->data = JudgeInput();
		s->next = p->next;
		s->prior = p;
		p->next = s;
		(*L)->prior = s;
		p = p->next;
		if (j == n - 1)
		{
			p->next = *L;
		}
	}
	printf("��ϲ���������ѳɹ�������\n");
	return *L;
}

void DeleteEle(DuLinkedList* L) {
	if ((*L)->prior == NULL) {
		printf("���ȴ��������ٳ���ɾ�������е�Ԫ�ء�\n");
		return;
	}
	printf("������������Ҫɾ����Ԫ��֮ǰ��Ԫ�أ�\n");
	while (1) {
		int ele = JudgeInput();
		DuLNode* before = SearchEle(*L, ele);
		if (before == NULL) {
			printf("�������Ԫ�ز��ڸ������У����������룡\n");
			continue;
		}
		else {
			int e = 0;
			if (DeleteList_DuL(before, &e)) {
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

void InsertEle_After(DuLinkedList* L) {
	printf("������������Ҫ�����Ԫ�أ�\n");
	int ele = JudgeInput();
	DuLNode* in = (DuLNode*)malloc(sizeof(DuLNode));
	in->data = ele;
	in->next = NULL;
	in->prior = NULL;
	printf("�������뽫������ĸ�Ԫ��֮��\n");
	while (1) {
		int ele1 = JudgeInput();
		if (SearchEle(*L, ele1) == NULL) {
			printf("�������Ԫ�ز��ڸ������У����������룡");
			continue;
		}
		else {
			DuLNode* before = SearchEle(*L, ele1);
			if (InsertAfterList_DuL(before, in))
				printf("��ϲ�������Ѳ���ɹ���\n");
			break;
		}
	}
	TraverseList_DuL(*L, visit);
}

void InsertEle_Before(DuLinkedList* L) {
	printf("������������Ҫ�����Ԫ�أ�\n");
	int ele = JudgeInput();
	DuLNode* in = (DuLNode*)malloc(sizeof(DuLNode));
	in->data = ele;
	in->next = NULL;
	in->prior = NULL;
	printf("�������뽫������ĸ�Ԫ��֮ǰ��\n");
	while (1) {
		int ele1 = JudgeInput();
		if (SearchEle(*L, ele1) == NULL) {
			printf("�������Ԫ�ز��ڸ������У����������룡");
			continue;
		}
		else {
			DuLNode* before = SearchEle(*L, ele1);
			if (InsertBeforeList_DuL(before, in))
				printf("��ϲ�������Ѳ���ɹ���\n");
			break;
		}
	}
	TraverseList_DuL(*L, visit);
}

DuLNode* SearchEle(DuLinkedList L, int ele) {
	DuLNode* p = L->next;
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

int JudgeInput() {
	int ele;
	while (scanf("%d", &ele) != 1)
	{
		while (getchar() != '\n');
		printf("\n����������.\n");
	}
	return ele;
}
