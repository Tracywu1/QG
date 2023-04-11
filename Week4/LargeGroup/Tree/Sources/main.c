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

///*
//  AVL��
//*/
//// ����ڵ�ĸ߶�
//int height(NodePtr node) {
//	if (node == NULL) {
//		return -1;
//	}
//	else {
//		return 1 + max(height(node->left), height(node->right));
//	}
//}
//
//// ����ڵ��ƽ������
//int balanceFactor(NodePtr node) {
//	if (node == NULL) {
//		return 0;
//	}
//	else {
//		return height(node->left) - height(node->right);
//	}
//}
//
//// ����ת
//NodePtr rotateLeft(NodePtr node) {
//	NodePtr pivot = node->right;
//	node->right = pivot->left;
//	pivot->left = node;
//	return pivot;
//}
//
//// ����ת
//NodePtr rotateRight(NodePtr node) {
//	NodePtr pivot = node->left;
//	node->left = pivot->right;
//	pivot->right = node;
//	return pivot;
//}
//
//// ����˫��ת
//NodePtr rotateLeftRight(NodePtr node) {
//	node->left = rotateLeft(node->left);
//	return rotateRight(node);
//}
//
//// ����˫��ת
//NodePtr rotateRightLeft(NodePtr node) {
//	node->right = rotateRight(node->right);
//	return rotateLeft(node);
//}
//
//// ����ڵ�
//NodePtr insert(NodePtr node, ElemType value) {
//	if (node == NULL) {
//		node = (NodePtr)malloc(sizeof(Node));
//		node->value = value;
//		node->left = NULL;
//		node->right = NULL;
//	}
//	else if (value < node->value) {
//		node->left = insert(node->left, value);
//		if (balanceFactor(node) == 2) {
//			if (balanceFactor(node->left) == 1) {
//				node = rotateRight(node);
//			}
//			else {
//				node = rotateLeftRight(node);
//			}
//		}
//	}
//	else if (value > node->value) {
//		node->right = insert(node->right, value);
//		if (balanceFactor(node) == -2) {
//			if (balanceFactor(node->right) == -1) {
//				node = rotateLeft(node);
//			}
//			else {
//				node = rotateRightLeft(node);
//			}
//		}
//	}
//	return node;
//}
//
//// ��AVL���в���ָ��ֵ�Ľڵ�
//NodePtr search(BinarySortTreePtr avl, ElemType value) {
//	NodePtr node = avl->root;
//	while (node != NULL && node->value != value) {
//		if (value < node->value) {
//			node = node->left;
//		}
//		else {
//			node = node->right;
//		}
//	}
//	return node;
//}
//
//// ����AVL���е���С�ڵ�
//NodePtr findMin(NodePtr node) {
//	if (node == NULL) {
//		return NULL;
//	}
//	else if (node->left == NULL) {
//		return node;
//	}
//	else {
//		return findMin(node->left);
//	}
//}
//
//// ɾ��AVL����ָ��ֵ�Ľڵ�
//NodePtr deleteNode(NodePtr node, ElemType value) {
//	if (node == NULL) {
//		return NULL;
//	}
//	else if (value < node->value) {
//		node->left = deleteNode(node->left, value);
//		if (balanceFactor(node) == -2) {
//			if (balanceFactor(node->right) <= 0) {
//				node = rotateLeft(node);
//			}
//			else {
//				node = rotateRightLeft(node);
//			}
//		}
//	}
//	else if (value > node->value) {
//		node->right = deleteNode(node->right, value);
//		if (balanceFactor(node) == 2) {
//			if (balanceFactor(node->left) >= 0) {
//				node = rotateRight(node);
//			}
//			else {
//				node = rotateLeftRight(node);
//			}
//		}
//	}
//	else {
//		if (node->left == NULL && node->right == NULL) {
//			free(node);
//			node = NULL;
//		}
//		else if (node->left == NULL) {
//			NodePtr temp = node;
//			node = node->right;
//			free(temp);
//		}
//		else if (node->right == NULL) {
//			NodePtr temp = node;
//			node = node->left;
//			free(temp);
//		}
//		else {
//			NodePtr temp = findMin(node->right);
//			node->value = temp->value;
//			node->right = deleteNode(node->right, temp->value);
//			if (balanceFactor(node) == 2) {
//				if (balanceFactor(node->left) >= 0) {
//					node = rotateRight(node);
//				}
//				else {
//					node = rotateLeftRight(node);
//				}
//			}
//		}
//	}
//	return node;
//}
//
//// ����AVL��
//void destroy(BinarySortTreePtr avl) {
//	destroyNode(avl->root);
//	free(avl);
//}
//
//// ����AVL���Ľڵ�
//void destroyNode(NodePtr node) {
//	if (node != NULL) {
//		destroyNode(node->left);
//		destroyNode(node->right);
//		free(node);
//	}
//}
//
///*


/*
//  ��
//*/
//typedef struct Heap {
//	ElemType* array;
//	int size;
//} Heap, * HeapPtr;

//void max_heapify(HeapPtr heap, int i) {
//	int largest = i;
//	int left = 2 * i + 1;
//	int right = 2 * i + 2;
//
//	if (left < heap->size && heap->array[left] > heap->array[largest]) {
//		largest = left;
//	}
//	if (right < heap->size && heap->array[right] > heap->array[largest]) {
//		largest = right;
//	}
//	if (largest != i) {
//		int temp = heap->array[i];
//		heap->array[i] = heap->array[largest];
//		heap->array[largest] = temp;
//		max_heapify(heap, largest);
//	}
//}
//
//void min_heapify(HeapPtr heap, int i) {
//	int smallest = i;
//	int left = 2 * i + 1;
//	int right = 2 * i + 2;
//
//	if (left < heap->size && heap->array[left] < heap->array[smallest]) {
//		smallest = left;
//	}
//	if (right < heap->size && heap->array[right] < heap->array[smallest]) {
//		smallest = right;
//	}
//	if (smallest != i) {
//		int temp = heap->array[i];
//		heap->array[i] = heap->array[smallest];
//		heap->array[smallest] = temp;
//		min_heapify(heap, smallest);
//	}
//}
//
//void heap_sort(HeapPtr heap) {
//	for (int i = heap->size / 2 - 1; i >= 0; i--) {
//		max_heapify(heap, i); // ���� min_heapify(heap, i) for С����
//	}
//	for (int i = heap->size - 1; i >= 1; i--) {
//		int temp = heap->array[0];
//		heap->array[0] = heap->array[i];
//		heap->array[i] = temp;
//		heap->size--;
//		max_heapify(heap, 0); // ���� min_heapify(heap, 0) for С����
//	}
//}
//
//HeapPtr create_heap(int capacity) {
//	HeapPtr heap = (HeapPtr)malloc(sizeof(Heap));
//	heap->array = (ElemType*)malloc(sizeof(ElemType) * capacity);
//	heap->size = 0;
//	return heap;
//}
//
//void destroy_heap(HeapPtr heap) {
//	free(heap->array);
//	free(heap);
//}


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
