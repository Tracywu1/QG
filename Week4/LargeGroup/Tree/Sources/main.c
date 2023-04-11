#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"
#include "red_black_tree.h"

BinarySortTreePtr bst = NULL;
RedBlackTreePtr rbt = NULL;
NodePtr createNode(ElemType value);

void visit(NodePtr node) {
	printf("%d ", node->value);
}

void visit_RB(RBNodePtr node) {
	printf("%d ", node->value);
}


short JudgeChoice(int n) {
	short choice;
	while ((scanf("%hd", &choice) != 1) || choice < 1 || choice > n) {
		while (getchar() != '\n');//������뻺����
		printf("������Ϸ�������~~\n");
		printf("�����������(1~%d): ", n);
	}
	return choice;
}

int JudgeInput() {
	int ele;
	while (scanf("%d", &ele) !=1||ele<=0)
	{
		while (getchar() != '\n');
		printf("\n������������.\n");
	}
	return ele;
}

void DisplayMenu() {
	printf("\n");
	printf("***********************************************************************************\n");
	printf("   1.��ͨ������                               2.�����\n");
	printf("***********************************************************************************\n");
	printf("   3.exit\n");
	printf(" ----------------------------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~3)��\n");
}

void BinarySortTreeMenu() {
	printf("\n");
	printf("***********************************************************************************\n");
	printf("   1.����������                           2.����\n");
	printf("***********************************************************************************\n");
	printf("   3.����                                 4.ɾ��\n");
	printf("***********************************************************************************\n");
	printf("   5.����                                 6.���\n");
	printf("***********************************************************************************\n");
	printf("   7.���ٲ��˳�\n");
	printf(" ----------------------------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~7)��\n");
}

void TraverseMenu() {
	printf("\n");
	printf("***********************************************************************************\n");
	printf("   1.����������ݹ�棩                   2.����������ǵݹ�棩\n");
	printf("***********************************************************************************\n");
	printf("   3.����������ݹ�棩                   4.����������ǵݹ�棩\n");
	printf("***********************************************************************************\n");
	printf("   5.����������ݹ�棩                   6.����������ǵݹ�棩\n");
	printf("***********************************************************************************\n");
	printf("   7.�������                             8.exit\n");
	printf(" ----------------------------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~8)��\n");
}

void createBinaryTree(BinarySortTreePtr bst, int n) {
	int value = 0;
	for (int i = 0; i < n; i++) {
		printf("\ninput -> element: ");
		value = JudgeInput();
		Node* node = createNode(value);
		if (bst->root == NULL) {
			bst->root = node;
		}
		else {
			Node* current = bst->root;
			Node* parent = NULL;
			while (current != NULL) {
				parent = current;
				if (value < current->value) {
					current = current->left;
				}
				else if (value > current->value) {
					current = current->right;
				}
				else {
					printf("�ڵ��Ѿ����ڣ����������룺\n");
					free(node);
					node = NULL;
					value = JudgeInput();
					node = createNode(value);
					current = bst->root;  // ���´Ӹ��ڵ㿪ʼ����
					parent = NULL;
				}
			}
			if (parent != NULL) {
				if (value < parent->value) {
					parent->left = node;
				}
				else {
					parent->right = node;
				}
			}
		}
	}
}

void BinaryTraverse_main(BinarySortTreePtr bst) {
	while (1) {
		TraverseMenu();
		short choice = JudgeChoice(8);
		switch (choice) {
		case 1:
			if (!BST_preorderR(bst, visit))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 2:
			if (!BST_preorderI(bst, visit))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 3:
			if (!BST_inorderR(bst, visit))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 4:
			if (!BST_inorderI(bst, visit))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 5:
			if (!BST_postorderR(bst, visit))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 6:
			if (!BST_postorderI(bst, visit))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 7:
			if (!BST_levelOrder(bst, visit))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 8:
			return;
		}
	}
}

void RedBlackTreeTraverse_main(RedBlackTreePtr rbt) {
	while (1) {
		TraverseMenu();
		short choice = JudgeChoice(8);
		switch (choice) {
		case 1:
			if (!preorderTraversalRecursive(rbt,visit_RB))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 2:
			if (!preorderTraversalIterative(rbt))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 3:
			if (!inorderTraversalRecursive(rbt, visit_RB))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 4:
			if (!inorderTraversalIterative(rbt))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 5:
			if (!postorderTraversalRecursive(rbt, visit_RB))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 6:
			if (!postorderTraversalIterative(rbt))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 7:
			if (!levelOrderTraversal(rbt))printf("�Բ��𣬱���ʧ�ܣ����ܳ�����һЩ����");
			break;
		case 8:
			return;
		}
	}
}

void BinarySortTree_main() {
	bst = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	if (!BST_init(bst)) {
		printf("��������ʼ��ʧ�ܣ�\n");
		return;
	}
	while (1) {
		BinarySortTreeMenu();
		short choice = JudgeChoice(7);
		if (bst->root && choice == 1)
		{
			printf("�벻Ҫ�ظ�����������\n");
			continue;
		}
		else if (!bst->root && choice != 1&& choice != 7)
		{
			printf("���ȴ����������ٶ�����в���\n");
			continue;
		}
		switch (choice) {
		case 1:
		{
			printf("��������Ҫ�����Ķ�������Ԫ�صĸ�����");
			int n = JudgeInput();
			createBinaryTree(bst,n);
			printf("��ϲ�����������ѳɹ�������\n");
			BST_preorderR(bst,visit);
			break;
		}
		case 2:
		{
			printf("������������Ҫ��ѯ������(ֻ����������)��");
			int value = JudgeInput();
			if (BST_search(bst,value)) {
				printf("�ö�������������Ҫ��ѯ������\n");
			}
			else {
				printf("�Բ��𣬸ö�������û������Ҫ��ѯ������\n");
			}
			break;
		}
		case 3:
		{
			printf("����������Ҫ���������(ֻ����������)��");
			int value = JudgeInput();
			if (BST_insert(bst, value)) {
				printf("��ϲ�������Գɹ���������ݣ�\n");
				BST_preorderR(bst, visit);
			}else {
				printf("�Բ��������������ʧ�ܣ������ǳ�����һЩ����\n");
			}
			break;
		}
		case 4:
		{
			printf("������������Ҫɾ��������(ֻ����������)��");
			int value = JudgeInput();
			if (BST_delete(bst, value)) {
				printf("��ϲ�������Գɹ�ɾ�������ݣ�\n");
				BST_preorderR(bst, visit);
			}else {
				printf("�Բ�����ɾ��������ʧ�ܣ������ǳ�����һЩ����\n");
			}
			break;
		}
		case 5:
			BinaryTraverse_main(bst);
			break;
		case 6:
			if (clearBST(bst)) printf("��ϲ�������ѳɹ���ոö�������");
			else printf("�Բ������ʧ�ܣ����ܳ�����ĳЩ����");
			break;
		case 7:
			if (bst->root)clearBST(bst);
			free(bst);
			return;
		}
	}
}

void createRedBlackTree(RedBlackTreePtr rbt, int n) {
	int value = 0;
	RBNodePtr node = NULL;
	for (int i = 0; i < n; i++) {
		printf("\ninput -> element: ");
		value = JudgeInput();
		if (i!=0 && search(rbt, value)) {
			printf("�Բ�������������ͬ����ֵ������������\n");
			i--;
			continue;
		}
		insert(rbt, value);
	}
}

void RedBlackTree_main() {
	rbt = (RedBlackTreePtr)malloc(sizeof(RedBlackTree));
	if (!init(rbt)) {
		printf("�������ʼ��ʧ�ܣ�\n");
		return;
	}
	while (1) {
		BinarySortTreeMenu();
		short choice = JudgeChoice(7);
		if (!(rbt->root== rbt->nil) && choice == 1)
		{
			printf("�벻Ҫ�ظ�����������\n");
			continue;
		}
		else if ((rbt->root == rbt->nil) && choice != 1 && choice != 7)
		{
			printf("���ȴ����������ٶ�����в���\n");
			continue;
		}
		switch (choice) {
		case 1:
		{
			printf("��������Ҫ�����ĺ������Ԫ�صĸ�����");
			int n = JudgeInput();
			createRedBlackTree(rbt, n);
			printf("��ϲ����������ѳɹ�������\n");
			preorderTraversalRecursive(rbt, visit_RB);
			break;
		}
		case 2:
		{
			printf("������������Ҫ��ѯ������(ֻ������������)��");
			int value = JudgeInput();
			if (search(rbt, value)) {
				printf("�ú������������Ҫ��ѯ������\n");
			}
			else {
				printf("�Բ��𣬸ú������û������Ҫ��ѯ������\n");
			}
			break;
		}
		case 3:
		{
			printf("����������Ҫ���������(ֻ����������)��");
			int value = JudgeInput();
			if (insert(rbt, value)) {
				printf("��ϲ�������Գɹ���������ݣ�\n");
				preorderTraversalRecursive(rbt, visit_RB);
			}
			else {
				printf("�Բ��������������ʧ�ܣ������ǳ�����һЩ����\n");
			}
			break;
		}
		case 4:
		{
			printf("������������Ҫɾ��������(ֻ����������)��");
			int value = JudgeInput();
			if (delete_node(rbt, value)) {
				printf("��ϲ�������Գɹ�ɾ�������ݣ�\n");
				preorderTraversalRecursive(rbt, visit_RB);
			}
			else {
				printf("�Բ�����ɾ��������ʧ�ܣ������ǳ�����һЩ����\n");
			}
			break;
		}
		case 5:
			RedBlackTreeTraverse_main(rbt);
			break;
		case 6:
			if (clearRedBlackTree(rbt)) printf("��ϲ�������ѳɹ���ոö�������");
			else printf("�Բ������ʧ�ܣ����ܳ�����ĳЩ����");
			break;
		case 7:
			if (rbt)clearRedBlackTree(rbt);
			free(rbt->nil);
			free(rbt);
			return;
		}
	}
}

int main(){
	while (1) {
		DisplayMenu();
		short choice = JudgeChoice(3);
		if (choice == 3){
			printf("��ӭ���ٴ�ʹ��, �ټ�!\n");
			break;
		}
		switch (choice) {
		case 1:
			BinarySortTree_main();
			break;
		case 2:
			RedBlackTree_main();
			break;
		case 3:
			return;
		}
	}
}
