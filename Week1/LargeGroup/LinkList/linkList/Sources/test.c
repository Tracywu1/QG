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
	LNode* p = L->next; // 指针p 指向首元结点
	int i = 0; //
	while (p) { // 当前结点不为空
		p = p->next;
		i++; // 长度 +1
	}
	return i;
}

LinkedList CreateList( ) { 
	printf("请输入您要创建的链表的元素的个数：");
	int n;
	scanf("%d", &n);
	LNode* s;
	LNode* p;
	Status status = InitList(&L);
	p = L; 
	for (int j = 0; j < n; j++) {
	    s = (LNode*)malloc(sizeof(LNode));// 生成新结点
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
		printf("该链表是循环链表");
	else
		printf("该链表不是循环链表");
}

void DeleteEle(LinkedList*L) {
	printf("请您输入您想要删除的元素之前的元素：\n");
	while (1) {
		int ele;
		scanf("%d", &ele);
		LNode* before = SearchEle(*L,ele);
		if (before==NULL) {
			printf("您输入的元素不在该链表中，请重新输入！");
			continue;
		}
		else {
			int e = 0;
			if (DeleteList(before, &e)) {
				printf("恭喜你！您已删除成功！\n");
				break;
			}
			else {
				printf("对不起,删除失败！");
				break;
			}
		}
	}

}

void InsertEle(LinkedList* L) {
	printf("请您输入您想要插入的元素：\n");
	int ele;
	scanf("%d", &ele);
	LNode* in = (LNode*)malloc(sizeof(LNode));
	in->data = ele;
	in->next = NULL;
	printf("请问您想将其插入哪个元素之后？\n");
	while (1) {
		int ele1;
		scanf("%d", &ele1);
		if (!(SearchList(*L, ele1))) {
			printf("您输入的元素不在该链表中，请重新输入！");
			continue;
		}
		LNode* before = SearchEle(*L,ele1);
		if (InsertList(before, in))
			printf("恭喜您，您已插入成功！\n");
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
		printf("该链表中不存在该元素\n");
		return NULL;
	}
	else {
		printf("该链表存在该元素\n");
		return p;
	}
}

void FindMid(LinkedList L) {
	LNode* mid=FindMidNode( &L);
	printf("该元素为：%d\n", mid->data);
}

	void DisplayMenu() {
		printf("************************************************************\n");
		printf("   a.创建单链表                           b.打印链表\n");
		printf("************************************************************\n");
		printf("   c.删除某一元素之后的元素               d.插入某一元素\n");
		printf("************************************************************\n");
		printf("   e.反转链表                             f.元素奇偶调换\n");
		printf("************************************************************\n");
		printf("   g.判断是否为循环链表                   h.查询是否存在某一元素\n");
		printf("************************************************************\n");
		printf("   i.查询该链表的中间元素                 j.exit\n");
		printf(" -------------------------------------------------------------\n");
	}

	
	int main() {
		DisplayMenu();
		while (1) {
			char select;
			scanf(" %c", &select);
			if (!((select >= 'a') && (select <= 'j')))
			{
				printf("输入错误！请再次输入！\n");
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
				printf("请您输入您想要查询的元素：\n");
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
