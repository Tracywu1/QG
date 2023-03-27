#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"calculator.h"

/*
   ��ʼ��
*/
//��ʼ������ջ
Status initLSNum(LinkStackNum* s_num) {
	s_num->top = (NumNode*)malloc(sizeof(NumNode));
	if (!s_num->top)
		return ERROR;
	s_num->count = 0;
	s_num->top->next = NULL;
	return SUCCESS;
}
//��ʼ������ջ
Status initLSChar(LinkStackChar* s_ch) {
	s_ch->top = (CharNode*)malloc(sizeof(CharNode));
	if (!s_ch->top)
		return ERROR;
	s_ch->count = 0;
	s_ch->top->next = NULL;
	return SUCCESS;
}



/*
   ��ջ
*/
//���������ƽ�������ջ��
Status pushLSNum(LinkStackNum* s_num, ElemType1 num) {
	NumNode* p = NULL;
	if (!s_num->top)
		return ERROR;
	p = (NumNode*)malloc(sizeof(NumNode));
	p->num = num;
	p->next = s_num->top->next;
	s_num->top->next = p;
	s_num->count++;
	return SUCCESS;
}
//�������ƽ�����ջ��
Status pushLSChar(LinkStackChar* s_ch, ElemType2 ch) {
	CharNode* p = NULL;
	if (!s_ch->top)
		return ERROR;
	p = (CharNode*)malloc(sizeof(CharNode));
	p->ch = ch;
	p->next = s_ch->top->next;
	s_ch->top->next = p;
	s_ch->count++;
	return SUCCESS;
}



/*
   ��ջ
*/
//�Ӳ�����ջ��ȡ������
Status popLSNum(LinkStackNum* s_num, ElemType1* num) {
	LinkStackPtr_NumNode temp, p = s_num->top->next;
	if (!s_num->top || isEmptyLSNum(s_num))
		return ERROR;
	*num = p->num;						
	temp = p->next;
	free(p);
	s_num->top->next = temp;
	s_num->count--;
	return SUCCESS;
}
//�ӷ���ջ��ȡ������
Status popLSChar(LinkStackChar* s_ch, ElemType2* ch) {
	LinkStackPtr_CharNode temp, p = s_ch->top->next;
	if (!s_ch->top || isEmptyLSChar(s_ch))
		return ERROR;
	*ch = p->ch;
	temp = p->next;
	free(p);
	s_ch->top->next = temp;
	s_ch->count--;
	return SUCCESS;
}



/*
   �ж�ջ�Ƿ�Ϊ��
*/
//�жϲ�����ջ�Ƿ�Ϊ��
Status isEmptyLSNum(LinkStackNum* s_num) {
	return s_num->count == 0;
}
//�жϷ���ջ�Ƿ�Ϊ��
Status isEmptyLSChar(LinkStackChar* s_ch) {
	return s_ch->count == 0;
}

