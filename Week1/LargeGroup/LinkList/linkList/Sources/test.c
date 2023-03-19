#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"
LinkedList L = NULL;
LNode* in = NULL;
void visit(ElemType e);
void TraverseList(LinkedList L, void (*visit)(ElemType e));
LNode* SearchEle(LinkedList L);

int ListLength(LinkedList L) {
	LNode* p = L->next; // ָ��p ָ����Ԫ���
	int i = 0; //
	while (p) { // ��ǰ��㲻Ϊ��
		p = p->next;
		i++; // ���� +1
	}
	return i;
}

LinkedList CreateList( ) { 
	printf("��������Ҫ�����������Ԫ�صĸ�����");
	int n;
	scanf("%d", &n);
	LNode* s;
	LNode* p;
	Status status = InitList(&L);
	p = L; 
	for (int j = 0; j < n; j++) {
	    s = (LNode*)malloc(sizeof(LNode));// �����½��
		printf("\ninput -> element: ");
		scanf("%d", &s->data);
		s->next = p->next; 
		p->next = s;
		p = p->next;
		if (j == n - 1)
		{
			p->next = NULL;
		}
	}
	return L;
}

void JudgeLoop(L) {
	if (IsLoopList(L))
		printf("��������ѭ������");
	else
		printf("��������ѭ������");
}

void DeleteEle(LinkedList*L) {
	printf("������������Ҫɾ����Ԫ��֮ǰ��Ԫ�أ�\n");
	while (1) {
		int ele;
		scanf("%d", &ele);
		LNode* before = SearchEle(*L,ele);
		if (before==NULL) {
			printf("�������Ԫ�ز��ڸ������У����������룡");
			continue;
		}
		else {
			int e = 0;
			if (DeleteList(before, &e)) {
				printf("��ϲ�㣡����ɾ���ɹ���\n");
				break;
			}
			else {
				printf("�Բ���,ɾ��ʧ�ܣ�");
				break;
			}
		}
	}

}

void InsertEle(LinkedList* L) {
	printf("������������Ҫ�����Ԫ�أ�\n");
	int ele;
	scanf("%d", &ele);
	LNode* in = (LNode*)malloc(sizeof(LNode));
	in->data = ele;
	in->next = NULL;
	printf("�������뽫������ĸ�Ԫ��֮��\n");
	while (1) {
		int ele1;
		scanf("%d", &ele1);
		if (!(SearchList(*L, ele1))) {
			printf("�������Ԫ�ز��ڸ������У����������룡");
			continue;
		}
		LNode* before = SearchEle(*L,ele1);
		if (InsertList(before, in))
			printf("��ϲ�������Ѳ���ɹ���\n");
		break;
	}
	TraverseList(*L, visit);
}

LNode* SearchEle(LinkedList L,int ele) {
	LNode* p = L->next;
	while (p->data != ele && p != NULL) {
		p = p->next;
	}
	if (p == NULL) {
		printf("�������в����ڸ�Ԫ��\n");
		return NULL;
	}
	else {
		printf("��������ڸ�Ԫ��\n");
		return p;
	}
}

void FindMid(LinkedList L) {
	LNode* mid=FindMidNode( &L);
	printf("��Ԫ��Ϊ��%d\n", mid->data);
}

	void DisplayMenu() {
		printf("************************************************************\n");
		printf("   a.����������                           b.��ӡ����\n");
		printf("************************************************************\n");
		printf("   c.ɾ��ĳһԪ��֮���Ԫ��               d.����ĳһԪ��\n");
		printf("************************************************************\n");
		printf("   e.��ת����                             f.Ԫ����ż����\n");
		printf("************************************************************\n");
		printf("   g.�ж��Ƿ�Ϊѭ������                   h.��ѯ�Ƿ����ĳһԪ��\n");
		printf("************************************************************\n");
		printf("   i.��ѯ��������м�Ԫ��                 j.exit\n");
		printf(" -------------------------------------------------------------\n");
	}

	
	int main() {
		DisplayMenu();
		while (1) {
			char select;
			scanf(" %c", &select);
			if (!((select >= 'a') && (select <= 'j')))
			{
				printf("����������ٴ����룡\n");
				continue;
			}
			switch (select)
			{
			case 'a':
				CreateList(5);
				break;
			case 'b':
				TraverseList(L, visit);
				break;
			case 'c':
				DeleteEle(&L);
				break;
			case 'd':
				InsertEle(&L);
				break;
			case 'e':
				ReverseList(&L);
				TraverseList(L, visit);
				break;
			case 'f':
				ReverseEvenList(&L);
				break;
			case 'g':
				JudgeLoop(L);
				break;
			case 'h':
				printf("������������Ҫ��ѯ��Ԫ�أ�\n");
				int ele;
				scanf("%d", &ele);
				SearchEle(L,ele);
				break;
			case 'i':
				FindMid(L);
				break;
			case 'j':
				return 0;
			}
		
	}
}
