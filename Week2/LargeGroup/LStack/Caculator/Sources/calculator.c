#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"calculator.h"

/*
   初始化
*/
//初始化数据栈
Status initLSNum(LinkStackNum* s_num) {
	s_num->top = (NumNode*)malloc(sizeof(NumNode));
	if (!s_num->top)
		return ERROR;
	s_num->count = 0;
	s_num->top->next = NULL;
	return SUCCESS;
}
//初始化符号栈
Status initLSChar(LinkStackChar* s_ch) {
	s_ch->top = (CharNode*)malloc(sizeof(CharNode));
	if (!s_ch->top)
		return ERROR;
	s_ch->count = 0;
	s_ch->top->next = NULL;
	return SUCCESS;
}



/*
   入栈
*/
//将操作数推进操作数栈中
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
//将符号推进符号栈中
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
   出栈
*/
//从操作数栈中取出数据
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
//从符号栈中取出数据
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
   判断栈是否为空
*/
//判断操作数栈是否为空
Status isEmptyLSNum(LinkStackNum* s_num) {
	return s_num->count == 0;
}
//判断符号栈是否为空
Status isEmptyLSChar(LinkStackChar* s_ch) {
	return s_ch->count == 0;
}

