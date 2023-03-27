#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef float ElemType1;
typedef char ElemType2;

typedef  struct StackNode1
{
	ElemType1 num;
	struct StackNode1* next;
}NumNode, * LinkStackPtr_NumNode;

typedef  struct  LinkStack1
{
	LinkStackPtr_NumNode top;
	int	count;
}LinkStackNum;

typedef  struct StackNode2
{
	ElemType2 ch;
	struct StackNode2* next;
}CharNode, * LinkStackPtr_CharNode;

typedef  struct  LinkStack2
{
	LinkStackPtr_CharNode top;
	int	count;
}LinkStackChar;

Status initLSNum(LinkStackNum* s_num);//初始化数据栈
Status initLSChar(LinkStackChar* s_ch);//初始化符号栈

Status pushLSNum(LinkStackNum* s_num, ElemType1 num);//将操作数推进操作数栈中
Status pushLSChar(LinkStackChar* s_ch, ElemType2 ch);//将符号推进符号栈中

Status popLSNum(LinkStackNum* s_num, ElemType1* num);//从操作数栈中取出数据
Status popLSChar(LinkStackChar* s_ch, ElemType2* ch);//从符号栈中取出数据

Status isEmptyLSNum(LinkStackNum* s);//判断操作数栈是否为空
Status isEmptyLSChar(LinkStackChar* s);//判断符号栈是否为空

#endif

