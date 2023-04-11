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
	if (!bst) return failed; // ��ָ�룬����ʧ��
	NodePtr stack[100]; // ����ջ
	int top = -1; // ��ʼ��ջ��ָ��
	NodePtr p = bst->root; // �Ӹ��ڵ㿪ʼ����
	while (p || top != -1) { // ջ��Ϊ�ջ�ǰ�ڵ㲻Ϊ��ʱѭ��
		if (p) { // ��ǰ�ڵ㲻Ϊ��
			visit(p); // ���ʵ�ǰ�ڵ�
			if (p->right) stack[++top] = p->right; // ���ӽڵ���ջ
			p = p->left; // �ƶ������ӽڵ�
		}
		else { // ��ǰ�ڵ�Ϊ�գ�����ջ���ڵ�
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
	if (!bst) return failed; // ��ָ�룬����ʧ��
	NodePtr stack[100]; // ����ջ
	int top = -1; // ��ʼ��ջ��ָ��
	NodePtr p = bst->root; // �Ӹ��ڵ㿪ʼ����
	while (p || top != -1) { // ջ��Ϊ�ջ�ǰ�ڵ㲻Ϊ��ʱѭ��
		if (p) { // ��ǰ�ڵ㲻Ϊ��
			stack[++top] = p; // ��ǰ�ڵ���ջ
			p = p->left; // �ƶ������ӽڵ�
		}
		else { // ��ǰ�ڵ�Ϊ�գ�����ջ���ڵ�
			p = stack[top--];
			visit(p); // ���ʵ�ǰ�ڵ�
			p = p->right; // �ƶ������ӽڵ�
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
	if (!bst) return failed; // ��ָ�룬����ʧ��
	NodePtr stack[100]; // ����ջ
	int top = -1; // ��ʼ��ջ��ָ��
	NodePtr p = bst->root; // �Ӹ��ڵ㿪ʼ����
	NodePtr last_visited = NULL; // ��ʼ����һ�����ʵĽڵ�
	while (p || top != -1) { // ջ��Ϊ�ջ�ǰ�ڵ㲻Ϊ��ʱѭ��
		if (p) { // ��ǰ�ڵ㲻Ϊ��
			stack[++top] = p; // ��ǰ�ڵ���ջ
			p = p->left; // �ƶ������ӽڵ�
		}
		else { // ��ǰ�ڵ�Ϊ�գ��鿴ջ���ڵ�����ӽڵ�
			NodePtr peek = stack[top];
			if (peek->right && last_visited != peek->right) { // ������ӽڵ������û�б����ʹ�
				p = peek->right; // �ƶ������ӽڵ�
			}
			else { // ���ӽڵ㲻���ڻ��Ѿ������ʹ�
				visit(peek); // ����ջ���ڵ�
				last_visited = peek; // ������һ�����ʵĽڵ�
				top--; // ����ջ���ڵ�
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
		clearBinaryTree(node->left);  // �ݹ����������
		clearBinaryTree(node->right);  // �ݹ����������
		free(node);  // �ͷŵ�ǰ�ڵ�
	}
}

Status clearBST(BinarySortTreePtr bst) {
	if (bst != NULL && bst->root != NULL) {
		clearBinaryTree(bst->root);  // ��ն����������нڵ���ڴ�ռ�
		bst->root = NULL;
		return succeed;// �����ڵ�ָ������Ϊ NULL
	}
	return failed;
}
