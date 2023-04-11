#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"


/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr bst) {
	bst->root = NULL;
	return succeed;
}

NodePtr createNode(ElemType value) {
	NodePtr node = (NodePtr)malloc(sizeof(Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}


/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr bst, ElemType value) {
	NodePtr new_node = (NodePtr)malloc(sizeof(Node));
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;

	if (bst->root == NULL) {
		bst->root = new_node;
		return succeed;
	}

	NodePtr current_node = bst->root;
	NodePtr parent_node = NULL;
	while (current_node != NULL) {
		parent_node = current_node;
		if (value < current_node->value) {
			current_node = current_node->left;
		}
		else if (value > current_node->value) {
			current_node = current_node->right;
		}
		else {
			free(new_node);
			return failed;
		}
	}

	if (value < parent_node->value) {
		parent_node->left = new_node;
	}
	else {
		parent_node->right = new_node;
	}

	return succeed;

}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
NodePtr findMinNode(NodePtr node) {
	if (!node) {
		return NULL;
	}

	while (node->left) {
		node = node->left;
	}
	return node;
}

Status BST_delete(BinarySortTreePtr bst, ElemType value) {
	if (!bst || !bst->root) {
		return failed;
	}

	NodePtr cur = bst->root;
	NodePtr parent = NULL;
	while (cur && cur->value != value) {
		parent = cur;
		if (value < cur->value) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}

	if (!cur) {
		return failed;
	}

	if (!cur->left || !cur->right) {
		NodePtr child = cur->left ? cur->left : cur->right;
		if (!parent) {
			bst->root = child;
		}
		else if (cur == parent->left) {
			parent->left = child;
		}
		else {
			parent->right = child;
		}
		free(cur);
	}
	else {
		NodePtr minNode = findMinNode(cur->right);
		cur->value = minNode->value;
		BST_delete(bst, minNode->value);
	}

	return succeed;
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr bst, ElemType value) {
	if (!bst || !bst->root) {
		return failed;
	}

	NodePtr cur = bst->root;
	while (cur) {
		if (value == cur->value) {
			return succeed;
		}
		else if (value < cur->value) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}
	return failed;
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
	if (!bst) return failed; // 空指针，返回失败
	NodePtr stack[100]; // 创建栈
	int top = -1; // 初始化栈顶指针
	NodePtr p = bst->root; // 从根节点开始遍历
	while (p || top != -1) { // 栈不为空或当前节点不为空时循环
		if (p) { // 当前节点不为空
			visit(p); // 访问当前节点
			if (p->right) stack[++top] = p->right; // 右子节点入栈
			p = p->left; // 移动到左子节点
		}
		else { // 当前节点为空，弹出栈顶节点
			p = stack[top--];
		}
	}
	return succeed;
}

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_preorderR_helper(NodePtr node, void (*visit)(NodePtr)) {
	if (node == NULL) {
		return;
	}
	visit(node);
	BST_preorderR_helper(node->left, visit);
	BST_preorderR_helper(node->right, visit);
}

Status BST_preorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
	if (bst == NULL) {
		return failed;
	}
	BST_preorderR_helper(bst->root, visit);
	return succeed;
}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
	if (!bst) return failed; // 空指针，返回失败
	NodePtr stack[100]; // 创建栈
	int top = -1; // 初始化栈顶指针
	NodePtr p = bst->root; // 从根节点开始遍历
	while (p || top != -1) { // 栈不为空或当前节点不为空时循环
		if (p) { // 当前节点不为空
			stack[++top] = p; // 当前节点入栈
			p = p->left; // 移动到左子节点
		}
		else { // 当前节点为空，弹出栈顶节点
			p = stack[top--];
			visit(p); // 访问当前节点
			p = p->right; // 移动到右子节点
		}
	}
	return succeed;
}


/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */

void BST_inorderR_helper(NodePtr node, void (*visit)(NodePtr)) {
	if (node == NULL) {
		return;
	}
	BST_inorderR_helper(node->left, visit);
	visit(node);
	BST_inorderR_helper(node->right, visit);
}

Status BST_inorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
	if (bst == NULL) {
		return failed;
	}
	BST_inorderR_helper(bst->root, visit);
	return succeed;
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
	if (!bst) return failed; // 空指针，返回失败
	NodePtr stack[100]; // 创建栈
	int top = -1; // 初始化栈顶指针
	NodePtr p = bst->root; // 从根节点开始遍历
	NodePtr last_visited = NULL; // 初始化上一个访问的节点
	while (p || top != -1) { // 栈不为空或当前节点不为空时循环
		if (p) { // 当前节点不为空
			stack[++top] = p; // 当前节点入栈
			p = p->left; // 移动到左子节点
		}
		else { // 当前节点为空，查看栈顶节点的右子节点
			NodePtr peek = stack[top];
			if (peek->right && last_visited != peek->right) { // 如果右子节点存在且没有被访问过
				p = peek->right; // 移动到右子节点
			}
			else { // 右子节点不存在或已经被访问过
				visit(peek); // 访问栈顶节点
				last_visited = peek; // 更新上一个访问的节点
				top--; // 弹出栈顶节点
			}
		}
	}
	return succeed;
}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */

void BST_postorderR_helper(NodePtr node, void (*visit)(NodePtr)) {
	if (node != NULL) {
		BST_postorderR_helper(node->left, visit);
		BST_postorderR_helper(node->right, visit);
		visit(node);
	}
}
Status BST_postorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
	if (bst == NULL) {
		return failed;
	}
	BST_postorderR_helper(bst->root, visit);
	return succeed;
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
typedef struct QueueNode {
	NodePtr value;
	struct QueueNode* next;
} QueueNode, * QueueNodePtr;

typedef struct Queue {
	QueueNodePtr front, rear;
	int size, capacity;
} Queue, * QueuePtr;

QueuePtr createQueue(int capacity) {
	QueuePtr queue = (QueuePtr)malloc(sizeof(Queue));
	queue->front = queue->rear = NULL;
	queue->size = 0;
	queue->capacity = capacity;
	return queue;
}

void enqueue(QueuePtr queue, NodePtr node) {
	QueueNodePtr qnode = (QueueNodePtr)malloc(sizeof(QueueNode));
	qnode->value = node;
	qnode->next = NULL;
	if (queue->rear == NULL) {
		queue->front = queue->rear = qnode;
	}
	else {
		queue->rear->next = qnode;
		queue->rear = qnode;
	}
	queue->size++;
}

void dequeue(QueuePtr queue, NodePtr* node) {
	if (queue->front == NULL) {
		*node = NULL;
		return;
	}
	QueueNodePtr qnode = queue->front;
	queue->front = queue->front->next;
	if (queue->front == NULL) {
		queue->rear = NULL;
	}
	*node = qnode->value;
	free(qnode);
	queue->size--;
}

void destroyQueue(QueuePtr queue) {
	QueueNodePtr qnode = queue->front;
	while (qnode != NULL) {
		QueueNodePtr next = qnode->next;
		free(qnode);
		qnode = next;
	}
	free(queue);
}

Status BST_levelOrder(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
	if (bst == NULL || bst->root == NULL) {
		return failed;  
	}
	QueuePtr queue = createQueue(100);
	enqueue(queue, bst->root);
	while (queue->size > 0) {
		NodePtr node;
		dequeue(queue, &node);
		visit(node);
		if (node->left != NULL) {
			enqueue(queue, node->left);
		}
		if (node->right != NULL) {
			enqueue(queue, node->right);
		}
	}
	destroyQueue(queue);
	return succeed;
}

void clearBinaryTree(NodePtr node) {
	if (node != NULL) {
		clearBinaryTree(node->left);  // 递归清空左子树
		clearBinaryTree(node->right);  // 递归清空右子树
		free(node);  // 释放当前节点
	}
}

Status clearBST(BinarySortTreePtr bst) {
	if (bst != NULL && bst->root != NULL) {
		clearBinaryTree(bst->root);  // 清空二叉树中所有节点的内存空间
		bst->root = NULL;
		return succeed;// 将根节点指针设置为 NULL
	}
	return failed;
}
