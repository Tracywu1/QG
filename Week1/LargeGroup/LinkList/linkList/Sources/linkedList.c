/*linkedList.c--支持单链表操作的函数*/
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
LinkedList *L;

/*接口函数*/

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList* L) {
	if (*L != NULL)return OVERFLOW;
	*L = (LinkedList)malloc(sizeof(LNode));
	if (!(*L))return ERROR;
	(*L)->next = *L;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L) {
	LinkedList p = NULL;
	p = (*L)->next;
	while (p != (*L))
	{
		(*L)->next = p->next;
		free(p);
		p = (*L)->next;
	}
	free(*L);
	*L = NULL;
	printf("恭喜您，您已成功销毁链表！");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q) {
	if (p == NULL || q == NULL)return ERROR;
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, ElemType* e) {
	if (p == NULL || p->next == L)return ERROR;
	LNode* t = p->next;
	*e = t->data;
	p->next = t->next;
	free(t);//释放t节点
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode* p = L->next;
	printf("链表中元素的排列为：\n");
	while (p != L) {
		visit(p->data);//把函数应用于链表的项
		p = p->next;//前进到下一项
	}
}
void visit(ElemType e) {
	printf("%d\t", e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	if (L->next == L) return ERROR;
	LNode* p = L->next;
	while (p != L && p->data != e) {
		p = p->next;//根据e值寻找数据域的值为e的节点
	}
	if (p == L)return ERROR;
	return SUCCESS;
}

/**
 *  @name        : Status ReverseList(LinkedList L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L) {
	LinkedList p1 = NULL, p2 = NULL, p3 = NULL;
	p1 = (*L)->next;
	p2 = p1->next;
	if (*L == p1)
	{
		return ERROR;
	}
	else if (*L == p2) {
		return SUCCESS;
	}
	p3 = p2->next;
	while (p3 != (*L))
	{
		p2->next = p1;//反转指针
		p1 = p2;
		p2 = p3;//p1,p2向后移动
		p3 = p3->next;//保存p3的下一个节点
	}
	p2->next = p1;
	(*L)->next->next = *L;
	(*L)->next = p2;//将p2插入链表的循环中
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	if (L == NULL || L->next == NULL)return ERROR;
	LNode* fast, * slow;
	fast = slow = L;
	fast = fast->next->next;
	slow = slow->next;
	while (1) {
		if (!fast || !slow)return ERROR;
		if (fast == slow)return SUCCESS;
		else {
			fast = fast->next->next;
			slow = slow->next;
		}
	}
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList* L) {
	LinkedList p1 = NULL, p2 = *L, p3 = (*L)->next;
	p1 = *L;
	p2 = p2->next;
	p3 = p3->next;
	while (p3!=*L) {
		if ((p3->data) % 2 == 0) {
			p2->next = p3->next;
			p3->next = p2;
			p1->next = p3;
			p1 = p1->next;
			p3 = p3->next->next;
		}else {
			p1 = p1->next;
			p2 = p2->next;
			p3 = p3->next;
		}
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList* L) {
	LNode* fast = *L, * slow = *L;
	while (fast->next != *L && fast->next->next != *L) {
		fast = fast->next->next;
		slow = slow->next;
	}
	if (fast->next->next == *L) {
		return slow->next;
	}
	return slow;
}