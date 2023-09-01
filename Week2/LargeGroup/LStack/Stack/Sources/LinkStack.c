#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

//链栈

//初始化栈
Status initLStack(LinkStack* s) {
	s->top = (StackNode*)malloc(sizeof(StackNode));
	if (!s->top)
		return ERROR;
	s->count = 0;
	s->top->next = NULL;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s) {
	return s->count == 0;
}

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (!s->top || s->count == 0)
		return ERROR;
	*e = s->top->next->data;
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack* s) {
	LinkStackPtr temp, p = s->top->next;			//p指向栈顶元素
	if (!s->top)
		return ERROR;
	while (p) {
		temp = p->next;             //保留栈顶元素的下一个元素
		free(p);					//free栈顶元素
		p = temp;
		s->count--;
	}
	s->top->next = NULL;
	if (isEmptyLStack)
		return SUCCESS;
	else
		return ERROR;
}

//销毁栈
Status destroyLStack(LinkStack* s) {
	//写法一
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

	//写法二
	/*if (clearLStack(s)) {
		free(s->top);
		return SUCCESS;
	} else {
		return ERROR;
	}*/
}

//检测栈长度
Status LStackLength(LinkStack* s, int* length) {
	if (!s->top)
		return ERROR;
	*length = s->count;
	return SUCCESS;
}

//入栈(注意参数与出栈的不同)
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

//出栈
Status popLStack(LinkStack* s, ElemType* data) {
	LinkStackPtr temp, p = s->top->next;
	if (!s->top || isEmptyLStack(s))
		return ERROR;
	*data = p->data;						//出栈的元素存储到 data
	temp = p->next;
	free(p);
	s->top->next = temp;
	s->count--;
	return SUCCESS;
}

//从栈顶开始遍历链栈
Status traverseLStack(LinkStack* s, void (*visit)(ElemType e)) {
	if (!s->top || s->count == 0)
		return ERROR;
	printf("该链栈序列为：\n");
	LinkStackPtr p = s->top->next;
	while (p) {
		visit(p->data);//把函数应用于链表的项
		p = p->next;//前进到下一项
	}
	return SUCCESS;
}
void visit(ElemType e) {
	printf("%d\t", e);
}
