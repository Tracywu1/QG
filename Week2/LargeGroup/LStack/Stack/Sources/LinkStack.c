#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

//��ջ

//��ʼ��ջ
Status initLStack(LinkStack* s) {
	s->top = (StackNode*)malloc(sizeof(StackNode));
	if (!s->top)
		return ERROR;
	s->count = 0;
	s->top->next = NULL;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	return s->count == 0;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (!s->top || s->count == 0)
		return ERROR;
	*e = s->top->next->data;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack* s) {
	LinkStackPtr temp, p = s->top->next;			//pָ��ջ��Ԫ��
	if (!s->top)
		return ERROR;
	while (p) {
		temp = p->next;             //����ջ��Ԫ�ص���һ��Ԫ��
		free(p);					//freeջ��Ԫ��
		p = temp;
		s->count--;
	}
	s->top->next = NULL;
	if (isEmptyLStack)
		return SUCCESS;
	else
		return ERROR;
}

//����ջ
Status destroyLStack(LinkStack* s) {
	//д��һ
	LinkStackPtr tempt, p = s->top->next;
	if (!s->top)
		return ERROR;
	while (p) {
		tempt = p->next;
		free(p);
		p = tempt;
		s->count--;
	}
	s->top->next = NULL;
	s->top = NULL;
	free(s->top);
	if (!s->top)
		return SUCCESS;
	else
		return ERROR;

	//д����
	/*if (clearLStack(s)) {
		free(s->top);
		return SUCCESS;
	} else {
		return ERROR;
	}*/
}

//���ջ����
Status LStackLength(LinkStack* s, int* length) {
	if (!s->top)
		return ERROR;
	*length = s->count;
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType data) {
	StackNode* p = NULL;
	if (!s->top)
		return ERROR;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top->next;
	s->top->next = p;
	s->count++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack* s, ElemType* data) {
	LinkStackPtr temp, p = s->top->next;
	if (!s->top || isEmptyLStack(s))
		return ERROR;
	*data = p->data;						//��ջ��Ԫ�ش洢�� data
	temp = p->next;
	free(p);
	s->top->next = temp;
	s->count--;
	return SUCCESS;
}

//��ջ����ʼ������ջ
Status traverseLStack(LinkStack* s, void (*visit)(ElemType e)) {
	if (!s->top || s->count == 0)
		return ERROR;
	printf("����ջ����Ϊ��\n");
	LinkStackPtr p = s->top->next;
	while (p) {
		visit(p->data);//�Ѻ���Ӧ�����������
		p = p->next;//ǰ������һ��
	}
	return SUCCESS;
}
void visit(ElemType e) {
	printf("%d\t", e);
}
