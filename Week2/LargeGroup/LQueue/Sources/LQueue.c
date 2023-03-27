#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "LQueue.h" 


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {
	return (Q->front == Q->rear ? TRUE : FALSE);
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
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
	Q->rear->next = p;//ȷ��p��βָ��֮ǰ��ָ�Ľڵ�����
	Q->rear = p;
	return TRUE;

}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q �������͵��ֽ���

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

