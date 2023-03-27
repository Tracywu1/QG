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

Status initLSNum(LinkStackNum* s_num);//��ʼ������ջ
Status initLSChar(LinkStackChar* s_ch);//��ʼ������ջ

Status pushLSNum(LinkStackNum* s_num, ElemType1 num);//���������ƽ�������ջ��
Status pushLSChar(LinkStackChar* s_ch, ElemType2 ch);//�������ƽ�����ջ��

Status popLSNum(LinkStackNum* s_num, ElemType1* num);//�Ӳ�����ջ��ȡ������
Status popLSChar(LinkStackChar* s_ch, ElemType2* ch);//�ӷ���ջ��ȡ������

Status isEmptyLSNum(LinkStackNum* s);//�жϲ�����ջ�Ƿ�Ϊ��
Status isEmptyLSChar(LinkStackChar* s);//�жϷ���ջ�Ƿ�Ϊ��

#endif

