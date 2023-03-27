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
	printf("请输入您要创建的链表的元素的个数：");
    int n;
	while (scanf("%d", &n)!=1 || n<0 ) {
			while (getchar() != '\n');
			printf("\n请输入正整数:\n");
	}
	LNode* s;
	LNode* p;
	p = *L;
	for (int j = 0; j < n; j++) {
		s = (LNode*)malloc(sizeof(LNode));// 生成新结点
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
	printf("恭喜您！链表已成功创建！\n");
	return *L;
}

void JudgeLoop(LinkedList L) {
	if (IsLoopList(L))
		printf("该链表是循环链表");
	else
		printf("该链表不是循环链表");
}

void DeleteEle(LinkedList* L) {
	if ((*L)->next == NULL) {
		printf("请先创建链表再尝试删除链表中的元素。\n");
		return;
	}
	printf("请您输入您想要删除的元素之前的元素：\n");
	while (1) {
		int ele = JudgeInput();
		LNode* before = SearchEle(*L, ele);
		if (before == NULL) {
			printf("您输入的元素不在该链表中，请重新输入！\n");
			continue;
		}
		else {
			int e = 0;
			if (DeleteList(before, &e)) {
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

void InsertEle(LinkedList* L) {
	printf("请您输入您想要插入的元素：\n");
	int ele = JudgeInput();
	LNode* in = (LNode*)malloc(sizeof(LNode));
	in->data = ele;
	in->next = NULL;
	printf("请问您想将其插入哪个元素之后？\n");
	while (1) {
		int ele1 = JudgeInput();
		if (SearchList(*L, ele1)==0) {
			printf("您输入的元素不在该链表中，请重新输入！");
			continue;
		}
		else {
			LNode* before = SearchEle(*L, ele1);
			if (InsertList(before, in))
				printf("恭喜您，您已插入成功！\n");
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
	printf("该链表的中间元素为：%d\n", mid->data);
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

void DisplayMenu() {
	printf("\n");
	printf("************************************************************\n");
	printf("   1.创建单链表                           2.打印链表\n");
	printf("************************************************************\n");
	printf("   3.删除某一元素之后的元素               4.插入某一元素\n");
	printf("************************************************************\n");
	printf("   5.反转链表                             6.元素奇偶调换\n");
	printf("************************************************************\n");
	printf("   7.判断是否为循环链表                   8.查询是否存在某一元素\n");
	printf("************************************************************\n");
	printf("   9.查询该链表的中间元素                 10.销毁链表\n");
	printf("************************************************************\n");
	printf("                            11.exit\n");
	printf(" -------------------------------------------------------------\n");
	printf("请选择您需要的操作(1~11)：\n");
}


int main() {
	while (1) {
		DisplayMenu();
		short choice;
		while ((scanf("%hd", &choice) != 1) || choice < 1 || choice > 11) {
			while (getchar() != '\n');//清空输入缓冲区
			printf("请输入合法操作码。\n");
			printf("请输入操作码(1~11): ");
		}
		if (choice == 11)
		{
			printf("欢迎您再次使用, 再见!\n");
			break;
		}
		if ( L != NULL && choice == 1)
		{
			/* 企图重复创建链表 */
		    /* 拦截该行为 */
			printf("请不要重复创建链表。\n");
			continue;
		}
		else if (L== NULL && choice != 1)
		{
			/* 企图不创建链表就开始访问链表 */
			/* 拦截该行为 */
			printf("请先创建链表再对其进行操作.\n");
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
			printf("请您输入您想要查询的元素：\n");
			int ele = JudgeInput();
			LNode* se = SearchEle(L, ele);
			if (se)
				printf("该链表存在该元素\n");
			else
				printf("该链表中不存在该元素\n");
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
