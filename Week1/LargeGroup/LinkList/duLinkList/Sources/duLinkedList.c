#include <stdio.h>
#include <stdlib.h>
#include "duLinkedList.h"
DuLinkedList* L;

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L) {
	if (*L!=NULL) return OVERFLOW;
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	if (!(*L))return ERROR;
	(*L)->prior = (*L)->next = (*L);
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L) {
	DuLinkedList p = NULL;
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
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
	if (p == NULL || q == NULL || p->prior == NULL) return ERROR;
	p->prior->next = q;
	q->prior = p->prior;
	p->prior = q;
	q->next = p;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
	if (p == NULL || q == NULL || p->prior == NULL) return ERROR;
	p->next->prior = q;
	q->next = p->next;
	p->next = q;
	q->prior = p;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e) {
	if (p == NULL || p->next == L) return ERROR;
	*e = p->next->data;
	DuLNode* q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLNode* p = L->next;
	printf("链表中元素的排列为：\n");
	while (p!=L) {
		visit(p->data);
		p = p->next;
	}
}
void visit(ElemType e) {
	printf("%d\t", e);
}
