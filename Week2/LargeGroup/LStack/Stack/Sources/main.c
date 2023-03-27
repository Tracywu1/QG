#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"
LinkStack* s = NULL;
void DisplayMenu();
LinkStack* CreateLStack(LinkStack* s);
int JudgeInput();
void visit(ElemType e);

int main() {
	s = (LinkStack*)malloc(sizeof(LinkStack));
	s->top = NULL;
	while (1) {
		DisplayMenu();
		short choice;
		while ((scanf("%hd", &choice) != 1) || choice < 1 || choice > 10) {
			while (getchar() != '\n');//清空输入缓冲区
			printf("请输入合法操作码。\n");
			printf("请输入操作码(1~10): ");
		}
		if (choice == 10)
		{
			printf("欢迎您再次使用, 再见!\n");
			break;
		}
		if (s->top && choice == 1)
		{
			/* 企图重复创建链栈 */
			/* 拦截该行为 */
			printf("请不要重复创建链栈。\n");
			continue;
		}
		else if (!s->top && choice !=1 )
		{
			/* 企图不创建链栈就开始访问链栈 */
			/* 拦截该行为 */
			printf("请先创建链栈再对其进行操作.\n");
			continue;
		}
		switch (choice)
		{
		case 1:
			CreateLStack(s);
			traverseLStack(s, visit);
			break;
		case 2:
			traverseLStack(s, visit);
			break;
		case 3:
		{
			if (clearLStack(s))
				printf("您已清空该链栈\n");
			else
				printf("清空链栈失败\n");
				break;
		}
		case 4:
		{
			if (destroyLStack(s))
				printf("您已销毁该链栈\n");
			else
				printf("销毁链栈失败\n");
			break;
		}
		case 5:
		{
			ElemType ele = 0;
			getTopLStack(s, &ele);
			printf("栈顶元素为：%d\n", ele);
		    break;
		}
		case 6:
		{
			int data = 0;
			if (popLStack(s, &data))
				printf("恭喜您，出栈成功！出栈的元素为：%d\n", data);
			else
				printf("对不起，出栈失败,该链栈已经为空！\n");
			break;
		}
		case 7:
		{
			printf("\ninput -> element: ");
			int data = JudgeInput();
			if (pushLStack(s, data))
				printf("恭喜您，入栈成功！\n");
			else
				printf("对不起，入栈失败！\n");
			break;
		}
		case 8:
		{
			int length = 0;
			if (LStackLength(s, &length))
				printf("查询成功，该链栈的长度为：%d\n", length);
			else
				printf("对不起，查询失败！\n");
			break;
		}
		case 9:
		{
			if (isEmptyLStack(s))
				printf("该链栈为空\n");
			else
				printf("该链栈非空\n");
			break;
		}
		case 10:
			return 0;
		}
	}
}

int JudgeInput() {
	int ele;
	while (scanf("%d", &ele) != 1)
	{
		while (getchar() != '\n');
		printf("\n请输入整数.\n");
	}
	return ele;
}

LinkStack* CreateLStack(LinkStack* s) {
	if (initLStack(s));
	else printf("链栈初始化失败！\n");
	int data = 0;
	printf("请输入您要创建的链栈的元素的个数：");
	int n;
	while (scanf("%d", &n) != 1 || n < 0) {
		while (getchar() != '\n');
		printf("\n请输入正整数:\n");
	}
	for (int i = 0; i < n; i++) {
		printf("\ninput -> element: ");
		data = JudgeInput();
		Status status = pushLStack(s, data);
	}
	printf("恭喜您！链栈已成功创建！\n");
	return s;
}

void DisplayMenu() {
	printf("\n");
	printf("**********************************************************************\n");
	printf("   1.创建链栈                                 2.从栈顶开始遍历输出链栈\n");
	printf("**********************************************************************\n");
	printf("   3.清空链栈                                 4.销毁链栈\n");
	printf("**********************************************************************\n");
	printf("   5.获取栈顶元素                             6.出栈\n");
	printf("**********************************************************************\n");
	printf("   7.入栈                                     8.获取链栈长度\n");
	printf("**********************************************************************\n");
	printf("   9.判断该链栈是否为空                      10.退出系统\n");
	printf("--------------------------------------------------------------\n");
	printf("请选择您需要的操作(1~10)：\n");
}