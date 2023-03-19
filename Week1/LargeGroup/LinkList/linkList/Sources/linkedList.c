/*linkedList.c--支持单链表操作的函数*/
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
LinkedList* L;

/*接口函数*/

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
	(*L)->next = NULL;//头指针暂时指向一个空节点
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
			psave = psave->next;//保存下一个节点的地址
			free((*L));//释放当前节点
			(*L) = psave;//前进至下一个节点
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
	LNode* p=L->next;
	while (p) {
		visit(p->data);//把函数应用于链表的项
		p = p->next;//前进到下一项
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
		p = p->next;//根据e值寻找数据域的值为e的节点
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
	LNode* pre, * cur, * Next;		//定义前中后指针，用途和反转相似
	pre = *L;
	*L = pre->next;
	while (pre && pre->next) {
		cur = pre->next;
		Next = cur->next;
		if (cur->next && cur->next->next) {			//如果cur->next不存在，结点个数为偶数
			pre->next = cur->next->next;			//如果cur->next->next不存在，结点个数为奇数
		}
		else {										//如果都存在，遍历未结束
			pre->next = cur->next;
		}
		cur->next = pre;							//将偶数结点反转
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