#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "LQueue.h" 


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (NULL == p)
		return;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q))
		return;
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {
	return (Q->front == Q->rear ? TRUE : FALSE);
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e) {
	if (IsEmptyLQueue(Q))
		return FALSE;
	long long unsigned int typeSize;
	if (datatype[0] == 'i') {
		typeSize = sizeof(int);
	}
	else if (datatype[0] == 'f') {
		typeSize = sizeof(double);
	}
	else if (datatype[0] == 'c') {
		typeSize = sizeof(char);
	}
	else {
		typeSize = sizeof(Q->front->next->data);
	}
	memcpy(e, Q->front->next->data, typeSize);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {
	int length;
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next;
	return length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data) {
	long long unsigned int typeSize;
	if (datatype[0] == 'i') {
		typeSize = sizeof(int);
	}
	else if (datatype[0] == 'f') {
		typeSize = sizeof(double);
	}
	else if (datatype[0] == 'c') {
		typeSize = sizeof(char);
	}
	else {
		typeSize = sizeof(Q->front->next->data);
	}
	Node* p = (Node*)malloc(sizeof(Node));
	if (NULL == p)
		return FALSE;
	p->data = (void*)malloc(sizeof(typeSize));
	memcpy(p->data, data,typeSize);
	p->next = NULL;
	Q->rear->next = p;//确保p与尾指针之前所指的节点相连
	Q->rear = p;
	return TRUE;

}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q))
		return FALSE;
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if (NULL == Q->front->next)
		Q->rear = Q->front;
	free(p);
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q))
		return;
	Node* p, * q;
	Q->rear = Q->front;
	p = Q->front->next;
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	if (IsEmptyLQueue(Q))
		return FALSE;
	long long unsigned int typeSize;
	if (datatype[0] == 'i') {
		typeSize = sizeof(int);
	}
	else if (datatype[0] == 'f') {
		typeSize = sizeof(double);
	}
	else if (datatype[0] == 'c') {
		typeSize = sizeof(char);
	}
	else {
		typeSize = sizeof(Q->front->next->data);
	}
	Node* p = (void*)malloc(sizeof(typeSize));
	p = Q->front->next;
	int i = 1;
	foo = LPrint;
	while (p != NULL) {
		if (i % 5 == 0) printf("\n");
		foo(p->data);
		p = p->next;
		i++;
	}
	printf("\n");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q 数据类型的字节数

 *  @notice      : None
 */
void LPrint(void* q) {
	if (datatype[0] == 'i') {
		printf("%d  ", *(int*)q);
	}
	else if (datatype[0] == 'f') {
		printf("%.2f  ", *(float*)q);
	}
	else if (datatype[0] == 'c') {
		printf("%c  ", *(char*)q);
	}
}

