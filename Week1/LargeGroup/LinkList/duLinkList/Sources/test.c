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
			while (getchar() != '\n');//清空输入缓冲区
			printf("请输入合法操作码。\n");
			printf("请输入操作码(1~8): ");
		}
		if (choice == 8)
		{
			printf("欢迎您再次使用, 再见!\n");
			break;
		}
		if (L != NULL && choice == 1)
		{
			/* 企图重复创建链表 */
			/* 拦截该行为 */
			printf("请不要重复创建链表。\n");
			continue;
		}
		else if (L == NULL && choice != 1)
		{
			/* 企图不创建链表就开始访问链表 */
			/* 拦截该行为 */
			printf("请先创建链表再对其进行操作.\n");
			continue;
		}
		switch (choice)
		{
		case 1://创建链表
			CreateList(&L);
			TraverseList_DuL(L, visit);
			break;
		case 2://遍历打印链表
			TraverseList_DuL(L, visit);
			break;
		case 3://删除链表中的元素
			DeleteEle(&L);
			TraverseList_DuL(L, visit);
			break;
		case 4://前插
			InsertEle_Before(&L);
			break;
		case 5://后插
			InsertEle_After(&L);
			break;
		case 6://查询元素
			printf("请您输入您想要查询的元素：\n");
			int ele = JudgeInput();
			DuLNode* se = SearchEle(L, ele);
			if (se)
				printf("该链表存在该元素\n");
			else
				printf("该链表中不存在该元素\n");
			break;
		case 7://销毁链表
			DestroyList_DuL(&L);
			break;
		case 8://退出系统
			return 0;
		}
	}
}

void DisplayMenu() {
	printf("\n");
	printf("************************************************************\n");
	printf("   1.创建双向链表                         2.打印链表\n");
	printf("************************************************************\n");
	printf("   3.删除某一元素之后的元素               4.插入某一元素（前插）\n");
	printf("************************************************************\n");
	printf("   5.插入某一元素（后插）                 6.查询是否存在某一元素\n");
	printf("************************************************************\n");
	printf("   7.销毁链表                             8.exit\n");
	printf(" -------------------------------------------------------------\n");
	printf("请选择您需要的操作(1~8)：\n");
}

DuLinkedList CreateList(DuLinkedList* L) {
	InitList_DuL(L);
	printf("请输入您要创建的链表的元素的个数：");
	int n = JudgeInput();
	DuLNode* s;
	DuLNode* p;
	p = (*L);
	for (int j = 0; j < n; j++) {
		s = (DuLNode*)malloc(sizeof(DuLNode));// 生成新结点
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
	printf("恭喜您！链表已成功创建！\n");
	return *L;
}

void DeleteEle(DuLinkedList* L) {
	if ((*L)->prior == NULL) {
		printf("请先创建链表再尝试删除链表中的元素。\n");
		return;
	}
	printf("请您输入您想要删除的元素之前的元素：\n");
	while (1) {
		int ele = JudgeInput();
		DuLNode* before = SearchEle(*L, ele);
		if (before == NULL) {
			printf("您输入的元素不在该链表中，请重新输入！\n");
			continue;
		}
		else {
			int e = 0;
			if (DeleteList_DuL(before, &e)) {
				printf("恭喜你！您已删除成功！\n");
				break;
			}
			else {
				printf("对不起,删除失败！\n");
				break;
			}
		}
	}

}

void InsertEle_After(DuLinkedList* L) {
	printf("请您输入您想要插入的元素：\n");
	int ele = JudgeInput();
	DuLNode* in = (DuLNode*)malloc(sizeof(DuLNode));
	in->data = ele;
	in->next = NULL;
	in->prior = NULL;
	printf("请问您想将其插入哪个元素之后？\n");
	while (1) {
		int ele1 = JudgeInput();
		if (SearchEle(*L, ele1) == NULL) {
			printf("您输入的元素不在该链表中，请重新输入！");
			continue;
		}
		else {
			DuLNode* before = SearchEle(*L, ele1);
			if (InsertAfterList_DuL(before, in))
				printf("恭喜您，您已插入成功！\n");
			break;
		}
	}
	TraverseList_DuL(*L, visit);
}

void InsertEle_Before(DuLinkedList* L) {
	printf("请您输入您想要插入的元素：\n");
	int ele = JudgeInput();
	DuLNode* in = (DuLNode*)malloc(sizeof(DuLNode));
	in->data = ele;
	in->next = NULL;
	in->prior = NULL;
	printf("请问您想将其插入哪个元素之前？\n");
	while (1) {
		int ele1 = JudgeInput();
		if (SearchEle(*L, ele1) == NULL) {
			printf("您输入的元素不在该链表中，请重新输入！");
			continue;
		}
		else {
			DuLNode* before = SearchEle(*L, ele1);
			if (InsertBeforeList_DuL(before, in))
				printf("恭喜您，您已插入成功！\n");
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
		printf("\n请输入整数.\n");
	}
	return ele;
}
