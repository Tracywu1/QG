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
		while (getchar() != '\n');//清空输入缓冲区
		printf("请输入合法操作码~~\n");
		printf("请输入操作码(1~%d): ", n);
	}
	return choice;
}

int JudgeInput() {
	int ele;
	while (scanf("%d", &ele) !=1||ele<=0)
	{
		while (getchar() != '\n');
		printf("\n请输入正整数.\n");
	}
	return ele;
}

///*
//  AVL树
//*/
//// 计算节点的高度
//int height(NodePtr node) {
//	if (node == NULL) {
//		return -1;
//	}
//	else {
//		return 1 + max(height(node->left), height(node->right));
//	}
//}
//
//// 计算节点的平衡因子
//int balanceFactor(NodePtr node) {
//	if (node == NULL) {
//		return 0;
//	}
//	else {
//		return height(node->left) - height(node->right);
//	}
//}
//
//// 左旋转
//NodePtr rotateLeft(NodePtr node) {
//	NodePtr pivot = node->right;
//	node->right = pivot->left;
//	pivot->left = node;
//	return pivot;
//}
//
//// 右旋转
//NodePtr rotateRight(NodePtr node) {
//	NodePtr pivot = node->left;
//	node->left = pivot->right;
//	pivot->right = node;
//	return pivot;
//}
//
//// 左右双旋转
//NodePtr rotateLeftRight(NodePtr node) {
//	node->left = rotateLeft(node->left);
//	return rotateRight(node);
//}
//
//// 右左双旋转
//NodePtr rotateRightLeft(NodePtr node) {
//	node->right = rotateRight(node->right);
//	return rotateLeft(node);
//}
//
//// 插入节点
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
//// 在AVL树中查找指定值的节点
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
//// 查找AVL树中的最小节点
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
//// 删除AVL树中指定值的节点
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
//// 销毁AVL树
//void destroy(BinarySortTreePtr avl) {
//	destroyNode(avl->root);
//	free(avl);
//}
//
//// 销毁AVL树的节点
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
//  堆
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
//		max_heapify(heap, i); // 或者 min_heapify(heap, i) for 小顶堆
//	}
//	for (int i = heap->size - 1; i >= 1; i--) {
//		int temp = heap->array[0];
//		heap->array[0] = heap->array[i];
//		heap->array[i] = temp;
//		heap->size--;
//		max_heapify(heap, 0); // 或者 min_heapify(heap, 0) for 小顶堆
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
	printf("   1.普通二叉树                               2.红黑树\n");
	printf("***********************************************************************************\n");
	printf("   3.exit\n");
	printf(" ----------------------------------------------------------------------------------\n");
	printf("请选择您需要的操作(1~3)：\n");
}

void BinarySortTreeMenu() {
	printf("\n");
	printf("***********************************************************************************\n");
	printf("   1.创建二叉树                           2.查找\n");
	printf("***********************************************************************************\n");
	printf("   3.插入                                 4.删除\n");
	printf("***********************************************************************************\n");
	printf("   5.遍历                                 6.清空\n");
	printf("***********************************************************************************\n");
	printf("   7.销毁并退出\n");
	printf(" ----------------------------------------------------------------------------------\n");
	printf("请选择您需要的操作(1~7)：\n");
}

void TraverseMenu() {
	printf("\n");
	printf("***********************************************************************************\n");
	printf("   1.先序遍历（递归版）                   2.先序遍历（非递归版）\n");
	printf("***********************************************************************************\n");
	printf("   3.中序遍历（递归版）                   4.中序遍历（非递归版）\n");
	printf("***********************************************************************************\n");
	printf("   5.后序遍历（递归版）                   6.后序遍历（非递归版）\n");
	printf("***********************************************************************************\n");
	printf("   7.层序遍历                             8.exit\n");
	printf(" ----------------------------------------------------------------------------------\n");
	printf("请选择您需要的操作(1~8)：\n");
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
					printf("节点已经存在，请重新输入：\n");
					free(node);
					node = NULL;
					value = JudgeInput();
					node = createNode(value);
					current = bst->root;  // 重新从根节点开始查找
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
			if (!BST_preorderR(bst, visit))printf("对不起，遍历失败，可能出现了一些问题");
			break;
		case 2:
			if (!BST_preorderI(bst, visit))printf("对不起，遍历失败，可能出现了一些问题");
			break;
		case 3:
			if (!BST_inorderR(bst, visit))printf("对不起，遍历失败，可能出现了一些问题");
			break;
		case 4:
			if (!BST_inorderI(bst, visit))printf("对不起，遍历失败，可能出现了一些问题");
			break;
		case 5:
			if (!BST_postorderR(bst, visit))printf("对不起，遍历失败，可能出现了一些问题");
			break;
		case 6:
			if (!BST_postorderI(bst, visit))printf("对不起，遍历失败，可能出现了一些问题");
			break;
		case 7:
			if (!BST_levelOrder(bst, visit))printf("对不起，遍历失败，可能出现了一些问题");
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
			if (!preorderTraversalRecursive(rbt,visit_RB))printf("对不起，遍历失败，可能出现了一些问题");
			break;
		case 2:
			if (!preorderTraversalIterative(rbt))printf("对不起，遍历失败，可能出现了一些问题");
			break;
		case 3:
			if (!inorderTraversalRecursive(rbt, visit_RB))printf("对不起，遍历失败，可能出现了一些问题");
			break;
		case 4:
			if (!inorderTraversalIterative(rbt))printf("对不起，遍历失败，可能出现了一些问题");
			break;
		case 5:
			if (!postorderTraversalRecursive(rbt, visit_RB))printf("对不起，遍历失败，可能出现了一些问题");
			break;
		case 6:
			if (!postorderTraversalIterative(rbt))printf("对不起，遍历失败，可能出现了一些问题");
			break;
		case 7:
			if (!levelOrderTraversal(rbt))printf("对不起，遍历失败，可能出现了一些问题");
			break;
		case 8:
			return;
		}
	}
}

void BinarySortTree_main() {
	bst = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	if (!BST_init(bst)) {
		printf("二叉树初始化失败！\n");
		return;
	}
	while (1) {
		BinarySortTreeMenu();
		short choice = JudgeChoice(7);
		if (bst->root && choice == 1)
		{
			printf("请不要重复创建二叉树\n");
			continue;
		}
		else if (!bst->root && choice != 1&& choice != 7)
		{
			printf("请先创建二叉树再对其进行操作\n");
			continue;
		}
		switch (choice) {
		case 1:
		{
			printf("请输入您要创建的二叉树的元素的个数：");
			int n = JudgeInput();
			createBinaryTree(bst,n);
			printf("恭喜您！二叉树已成功创建！\n");
			BST_preorderR(bst,visit);
			break;
		}
		case 2:
		{
			printf("请您输入您想要查询的数据(只能输入整数)：");
			int value = JudgeInput();
			if (BST_search(bst,value)) {
				printf("该二叉树上有你想要查询的数据\n");
			}
			else {
				printf("对不起，该二叉树上没有您想要查询的数据\n");
			}
			break;
		}
		case 3:
		{
			printf("请输入您想要插入的数据(只能输入整数)：");
			int value = JudgeInput();
			if (BST_insert(bst, value)) {
				printf("恭喜您，您以成功插入该数据！\n");
				BST_preorderR(bst, visit);
			}else {
				printf("对不起，您插入该数据失败，可能是出现了一些问题\n");
			}
			break;
		}
		case 4:
		{
			printf("请您输入您想要删除的数据(只能输入整数)：");
			int value = JudgeInput();
			if (BST_delete(bst, value)) {
				printf("恭喜您，您以成功删除该数据！\n");
				BST_preorderR(bst, visit);
			}else {
				printf("对不起，您删除该数据失败，可能是出现了一些问题\n");
			}
			break;
		}
		case 5:
			BinaryTraverse_main(bst);
			break;
		case 6:
			if (clearBST(bst)) printf("恭喜您，您已成功清空该二叉树！");
			else printf("对不起，清空失败，可能出现了某些问题");
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
			printf("对不起，您输入了相同的数值，请重新输入\n");
			i--;
			continue;
		}
		insert(rbt, value);
	}
}

void RedBlackTree_main() {
	rbt = (RedBlackTreePtr)malloc(sizeof(RedBlackTree));
	if (!init(rbt)) {
		printf("红黑树初始化失败！\n");
		return;
	}
	while (1) {
		BinarySortTreeMenu();
		short choice = JudgeChoice(7);
		if (!(rbt->root== rbt->nil) && choice == 1)
		{
			printf("请不要重复创建二叉树\n");
			continue;
		}
		else if ((rbt->root == rbt->nil) && choice != 1 && choice != 7)
		{
			printf("请先创建二叉树再对其进行操作\n");
			continue;
		}
		switch (choice) {
		case 1:
		{
			printf("请输入您要创建的红黑树的元素的个数：");
			int n = JudgeInput();
			createRedBlackTree(rbt, n);
			printf("恭喜您，红黑树已成功创建！\n");
			preorderTraversalRecursive(rbt, visit_RB);
			break;
		}
		case 2:
		{
			printf("请您输入您想要查询的数据(只能输入正整数)：");
			int value = JudgeInput();
			if (search(rbt, value)) {
				printf("该红黑树上有你想要查询的数据\n");
			}
			else {
				printf("对不起，该红黑树上没有您想要查询的数据\n");
			}
			break;
		}
		case 3:
		{
			printf("请输入您想要插入的数据(只能输入整数)：");
			int value = JudgeInput();
			if (insert(rbt, value)) {
				printf("恭喜您，您以成功插入该数据！\n");
				preorderTraversalRecursive(rbt, visit_RB);
			}
			else {
				printf("对不起，您插入该数据失败，可能是出现了一些问题\n");
			}
			break;
		}
		case 4:
		{
			printf("请您输入您想要删除的数据(只能输入整数)：");
			int value = JudgeInput();
			if (delete_node(rbt, value)) {
				printf("恭喜您，您以成功删除该数据！\n");
				preorderTraversalRecursive(rbt, visit_RB);
			}
			else {
				printf("对不起，您删除该数据失败，可能是出现了一些问题\n");
			}
			break;
		}
		case 5:
			RedBlackTreeTraverse_main(rbt);
			break;
		case 6:
			if (clearRedBlackTree(rbt)) printf("恭喜您，您已成功清空该二叉树！");
			else printf("对不起，清空失败，可能出现了某些问题");
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
			printf("欢迎您再次使用, 再见!\n");
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
