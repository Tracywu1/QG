/*linkedList.c--֧�ֵ���������ĺ���*/
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
LinkedList* L;

/*�ӿں���*/

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L){
	if(*L!=NULL)return OVERFLOW;
	*L = (LinkedList)malloc(sizeof (LNode));
	if (!(*L))return ERROR;
	(*L)->next = NULL;//ͷָ����ʱָ��һ���սڵ�
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LNode* psave= (*L);
		while (psave) {
			psave = psave->next;//������һ���ڵ�ĵ�ַ
			free((*L));//�ͷŵ�ǰ�ڵ�
			(*L) = psave;//ǰ������һ���ڵ�
		}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q) {
	if (p == NULL||q == NULL)return ERROR;
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
	if (p == NULL || p->next == NULL)return ERROR;
	LNode* t = p->next;
	*e = t->data;
	p->next = t->next;
	free(t);//�ͷ�t�ڵ�
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
	LNode* p=L->next;
	while (p) {
		visit(p->data);//�Ѻ���Ӧ�����������
		p = p->next;//ǰ������һ��
	}
}
void visit(ElemType e) {
	printf("%d", e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	if (L->next == NULL) return ERROR;
	LNode* p = L->next;
	while (p->data != e && p != NULL) {
		p = p->next;//����eֵѰ���������ֵΪe�Ľڵ�
	}
	return SUCCESS;
}

/**
 *  @name        : Status ReverseList(LinkedList L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LinkedList p, r, q;
	p = NULL;
	r = (*L)->next;
	q = r->next;
	if (r == NULL || q == NULL)
		return;
	while (q) {
		r->next = p;
		p = r;
		r = q;
		q = q->next;
	}
	r->next = p;
	(*L)->next = r;
	printf("\n");
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
	if ( L == NULL || L->next == NULL)return ERROR;
	LNode *fast, *slow;
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
	LNode* pre, * cur, * Next;		//����ǰ�к�ָ�룬��;�ͷ�ת����
	pre = *L;
	*L = pre->next;
	while (pre && pre->next) {
		cur = pre->next;
		Next = cur->next;
		if (cur->next && cur->next->next) {			//���cur->next�����ڣ�������Ϊż��
			pre->next = cur->next->next;			//���cur->next->next�����ڣ�������Ϊ����
		}
		else {										//��������ڣ�����δ����
			pre->next = cur->next;
		}
		cur->next = pre;							//��ż����㷴ת
		pre = Next;
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
LNode* FindMidNode(LinkedList *L) {
	if ((*L) == NULL || (*L)->next == NULL) return (*L);
	LNode *mid, *fast;
	mid = fast = (*L);
	while (fast != NULL) {
		if (fast->next == NULL)fast = fast->next;
		else fast = fast->next->next;
		mid = mid->next;
	}
	return mid;
}