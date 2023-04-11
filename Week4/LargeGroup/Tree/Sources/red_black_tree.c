#include <stdio.h>
#include <stdlib.h>
#include "red_black_tree.h"

int isEmpty(StackPtr);
void insert_fixup(RedBlackTreePtr, RBNodePtr);
RBNodePtr get_uncle(RBNodePtr);
int is_left(RBNodePtr);
int is_right(RBNodePtr);
void delete_fixup(RedBlackTreePtr, RBNodePtr);



typedef struct QueueNode {
	RBNodePtr node;
	struct QueueNode* next;
} QueueNode, * QueueNodePtr;

typedef struct Queue {
	QueueNodePtr head, tail;
} Queue, * QueuePtr;

QueueNodePtr createQueueNode_RB(RBNodePtr node) {
	QueueNodePtr qn = (QueueNodePtr)malloc(sizeof(QueueNode));
	if (!qn) {
		return NULL;
	}
	qn->node = node;
	qn->next = NULL;
	return qn;
}

int isEmptyQueue_RB(Queue queue) {
	return queue.head == NULL;
}

void enqueue_RB(QueuePtr queue, RBNodePtr node) {
	QueueNodePtr qn = createQueueNode_RB(node);
	if (!qn) {
		return;
	}
	if (isEmptyQueue_RB(*queue)) {
		queue->head = queue->tail = qn;
	}
	else {
		queue->tail->next = qn;
		queue->tail = qn;
	}
}

QueueNodePtr dequeue_RB(QueuePtr queue) {
	if (isEmptyQueue_RB(*queue)) {
		return NULL;
	}
	QueueNodePtr qn = queue->head;
	queue->head = queue->head->next;
	if (!queue->head) {
		queue->tail = NULL;
	}
	return qn;
}

typedef struct StackNode {
	RBNodePtr data;
	struct StackNode* next;
} StackNode, * StackNodePtr;

typedef struct Stack {
	StackNodePtr top;
} Stack, * StackPtr;

StackPtr createStack() {
	StackPtr stack = (StackPtr)malloc(sizeof(Stack));
	stack->top = NULL;
	return stack;
}

void push(StackPtr stack, RBNodePtr data) {
	StackNodePtr node = (StackNodePtr)malloc(sizeof(StackNode));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

RBNodePtr pop(StackPtr stack) {
	if (isEmpty(stack)) {
		return NULL;
	}
	RBNodePtr data = stack->top->data;
	StackNodePtr node = stack->top;
	stack->top = stack->top->next;
	free(node);
	return data;
}

int isEmpty(StackPtr stack) {
	return stack->top == NULL;
}

void destroyStack(StackPtr stack) {
	while (!isEmpty(stack)) {
		pop(stack);
	}
	free(stack);
}

//��ʼ�������
Status init(RedBlackTreePtr tree) {
	tree->nil = (RBNodePtr)malloc(sizeof(RBNode));
	tree->nil->color = BLACK;
	tree->nil->left = NULL;
	tree->nil->right = NULL;
	tree->nil->parent = NULL;
	tree->root = tree->nil;
	return succeed;
}

// �����ڵ�
RBNodePtr create_node(ElemType value, RBNodePtr nil) {
	RBNodePtr node = (RBNodePtr)malloc(sizeof(RBNode));
	if (node == NULL) {
		printf("create_node error: out of memory!\n");
		exit(1);
	}
	node->value = value;
	node->left = nil;
	node->right = nil;
	node->parent = nil;
	node->color = RED; // �½ڵ���ɫΪ��ɫ
	return node;
}

//����
void left_rotate(RedBlackTreePtr tree, RBNodePtr node) {
	RBNodePtr right = node->right;
	node->right = right->left;
	if (right->left != tree->nil) {
		right->left->parent = node;
	}
	right->parent = node->parent;
	if (node->parent == tree->nil) {
		tree->root = right;
	}
	else if (node == node->parent->left) {
		node->parent->left = right;
	}
	else {
		node->parent->right = right;
	}
	right->left = node;
	node->parent = right;
}

//����
void right_rotate(RedBlackTreePtr tree, RBNodePtr node) {
	RBNodePtr left = node->left;
	node->left = left->right;
	if (left->right != tree->nil) {
		left->right->parent = node;
	}
	left->parent = node->parent;
	if (node->parent == tree->nil) {
		tree->root = left;
	}
	else if (node == node->parent->left) {
		node->parent->left = left;
	}
	else {
		node->parent->right = left;
	}
	left->right = node;
	node->parent = left;
}

// ����ڵ�
Status insert(RedBlackTreePtr tree, ElemType value) {
	// BST����ڵ�
	RBNodePtr y = NULL;
	RBNodePtr x = tree->root;
	while (x != tree->nil) { // �����ҵ����ʵĲ���λ��
		y = x;
		if (value < x->value) {
			x = x->left;
		}
		else if (value > x->value) {
			x = x->right;
		}
		else {
			return succeed; // ��������ֵ�Ѿ����ڣ�����Բ������
		}
	}
	RBNodePtr node = create_node(value, tree->nil); // �����½ڵ�

	node->parent = y;
	if (y == NULL) { // ��Ϊ�գ�������Ǹ��ڵ�
		tree->root = node;
		node->parent = tree->nil; // ���ø��ڵ�ĸ��ڵ�ָ��
	}
	else if (value < y->value) {
		y->left = node;
	}
	else {
		y->right = node;
	}

	// �������������
	insert_fixup(tree, node);
	return succeed;
}
//��������
void insert_fixup(RedBlackTreePtr tree, RBNodePtr node) {
	while (node != tree->root && node->parent->color == RED) {
		if (is_left(node->parent)) {
			RBNodePtr uncle = node->parent->parent->right;
			if (uncle != tree->nil && uncle->color == RED) {
				// Case 1: ����ڵ��Ǻ�ɫ
				node->parent->color = BLACK;
				uncle->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
			else {
				if (is_right(node)) {
					// Case 2: ����ڵ��Ǻ�ɫ���ҵ�ǰ�ڵ������ӽڵ�
					node = node->parent;
					left_rotate(tree, node);
				}
				// Case 3: ����ڵ��Ǻ�ɫ���ҵ�ǰ�ڵ������ӽڵ�
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				right_rotate(tree, node->parent->parent);
				// ������ɫ
				node->parent->parent->color = RED;
				node->parent->color = BLACK;
			}
		}
		else {
			RBNodePtr uncle = node->parent->parent->left;
			if (uncle != tree->nil && uncle->color == RED) {
				// Case 1: ����ڵ��Ǻ�ɫ
				node->parent->color = BLACK;
				uncle->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
			else {
				if (is_left(node)) {
					// Case 2: ����ڵ��Ǻ�ɫ���ҵ�ǰ�ڵ������ӽڵ�
					node = node->parent;
					right_rotate(tree, node);
				}
				// Case 3: ����ڵ��Ǻ�ɫ���ҵ�ǰ�ڵ������ӽڵ�
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				left_rotate(tree, node->parent->parent);
				// ������ɫ
				node->parent->parent->color = RED;
				node->parent->color = BLACK;
			}
		}
	}
	tree->root->color = BLACK;
}

//��ȡ�ڵ���常�ڵ�
RBNodePtr get_uncle(RBNodePtr node) {
	RBNodePtr grandparent = node->parent->parent;
	if (grandparent == NULL) {
		return NULL;
	}
	if (node->parent == grandparent->left) {
		return grandparent->right;
	}
	else {
		return grandparent->left;
	}
}

//�ж��ڵ��Ƿ��Ǹ��ڵ�����ӽڵ�
int is_left(RBNodePtr node) { return node == node->parent->left; }

//�ж��ڵ��Ƿ��Ǹ��ڵ�����ӽڵ� 
int is_right(RBNodePtr node) { return node == node->parent->right; }

//��ѯ�ڵ�
Status search(RedBlackTreePtr rbt, ElemType value) {
	if (!rbt || !rbt->root) {
		return failed;
	}
	RBNodePtr cur = rbt->root;
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

//��ȡ�ڵ�ĺ����ڵ� 
RBNodePtr get_successor(RBNodePtr node) {
	if (node->right != NULL) {
		node = node->right;
		while (node->left != NULL) {
			node = node->left;
		}
		return node;
	}
	RBNodePtr parent = node->parent;
	while (parent != NULL && node == parent->right) {
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

//ɾ���ڵ�
Status delete_node(RedBlackTreePtr rbt, int value) {
	if (!rbt || !rbt->root) {
		return failed;
	}
	RBNodePtr node = rbt->root;
	while (node != rbt->nil && node->value != value) {
		if (value < node->value) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}
	if (node == rbt->nil) {
		return failed;
	}
	RBNodePtr x, y;
	// �ҵ���ɾ���Ľڵ� y
	if (node->left == rbt->nil || node->right == rbt->nil) {
		y = node;
	}
	else {
		y = get_successor(node);
	}
	// �ҵ� y �ĺ��ӽڵ� x
	if (y->left != rbt->nil) {
		x = y->left;
	}
	else {
		x = y->right;
	}
	x->parent = y->parent;
	if (y->parent == rbt->nil) {
		// y Ϊ���ڵ�
		rbt->root = x;
	}
	else if (y == y->parent->left) {
		y->parent->left = x;
	}
	else {
		y->parent->right = x;
	}
	if (y != node) {
		// ��� y ���Ǵ�ɾ���ڵ㣬�� y ��ֵ������ɾ���ڵ�
		node->value = y->value;
	}
	if (y->color == BLACK) {
		// ɾ���ڵ��Ӱ�����������ʣ���Ҫ�����޸�
		delete_fixup(rbt, x);
	}
	free(y);
	return succeed;
}

//ɾ���޸�
void delete_fixup(RedBlackTreePtr rbt, RBNodePtr node) {
	while (node != rbt->root && node->color == BLACK) {
		if (node == node->parent->left) {
			RBNodePtr brother = node->parent->right;
			if (brother->color == RED) {
				brother->color = BLACK;
				node->parent->color = RED;
				left_rotate(rbt, node->parent);
				brother = node->parent->right;
			}
			if (brother->left->color == BLACK && brother->right->color == BLACK) {
				brother->color = RED;
				node = node->parent;
			}
			else {
				if (brother->right->color == BLACK) {
					brother->left->color = BLACK;
					brother->color = RED;
					right_rotate(rbt, brother);
					brother = node->parent->right;
				}
				brother->color = node->parent->color;
				node->parent->color = BLACK;
				brother->right->color = BLACK;
				left_rotate(rbt, node->parent);
				node = rbt->root;
			}
		}
		else {
			RBNodePtr brother = node->parent->left;
			if (brother->color == RED) {
				brother->color = BLACK;
				node->parent->color = RED;
				right_rotate(rbt, node->parent);
				brother = node->parent->left;
			}
			if (brother->right->color == BLACK && brother->left->color == BLACK) {
				brother->color = RED;
				node = node->parent;
			}
			else {
				if (brother->left->color == BLACK) {
					brother->right->color = BLACK;
					brother->color = RED;
					left_rotate(rbt, brother);
					brother = node->parent->left;
				}
				brother->color = node->parent->color;
				node->parent->color = BLACK;
				brother->left->color = BLACK;
				right_rotate(rbt, node->parent);
				node = rbt->root;
			}
		}
	}
	node->color = BLACK;
}

void preorderTraversalRecursiveHelper(RBNodePtr node, RBNodePtr nil, void (*visit_RB)(RBNodePtr)) {
	if (node != nil) {
		visit_RB(node);
		preorderTraversalRecursiveHelper(node->left, nil, visit_RB);
		preorderTraversalRecursiveHelper(node->right, nil, visit_RB);
	}
}

Status preorderTraversalRecursive(RedBlackTreePtr rbt, void (*visit_RB)(RBNodePtr)) {
	if (rbt->root == rbt->nil) {
		return failed;
	}
		preorderTraversalRecursiveHelper(rbt->root, rbt->nil, visit_RB);
		return succeed;
}

Status preorderTraversalIterative(RedBlackTreePtr rbt) {
	if (rbt == NULL) return failed;
	RBNodePtr root = rbt->root;
	if (root == rbt->nil) {
		return failed;
	}
	//��ʼ��ջ
	StackPtr stack = createStack();
	push(stack, root);
	while (!isEmpty(stack)) {
		RBNodePtr node = pop(stack);
		printf("%d ", node->value);
		//�Ƚ����ӽڵ���ջ
		if (node->right != rbt->nil) {
			push(stack, node->right);
		}
		//�ٽ����ӽڵ���ջ���Ա�֤�ȷ������ӽڵ�
		if (node->left != rbt->nil) {
			push(stack, node->left);
		}
	}
	//����ջ
	destroyStack(stack);
	return succeed;
}

void inorderTraversalRecursiveHelper(RBNodePtr node, RBNodePtr nil, void (*visit_RB)(RBNodePtr)) {
	if (node != nil) {
		preorderTraversalRecursiveHelper(node->left, nil, visit_RB);
		visit_RB(node);
		preorderTraversalRecursiveHelper(node->right, nil, visit_RB);
	}
}

Status inorderTraversalRecursive(RedBlackTreePtr rbt, void (*visit_RB)(RBNodePtr)) {
	if (rbt->root == rbt->nil) {
		return failed;
	}
	preorderTraversalRecursiveHelper(rbt->root, rbt->nil, visit_RB);
	return succeed;
}

Status inorderTraversalIterative(RedBlackTreePtr rbt) {
	if (rbt == NULL) return failed;
	StackPtr stack = createStack();
	RBNodePtr node = rbt->root;
	while (node != rbt->nil || !isEmpty(stack)) {
		while (node != rbt->nil) {
			push(stack, node);
			node = node->left;
		}
		node = pop(stack);
		printf("%d ", node->value);
		node = node->right;
	}
	destroyStack(stack);
	return succeed;
}

void postorderTraversalRecursiveHelper(RBNodePtr node, RBNodePtr nil, void (*visit_RB)(RBNodePtr)) {
	if (node != nil) {
		preorderTraversalRecursiveHelper(node->left, nil, visit_RB);
		preorderTraversalRecursiveHelper(node->right, nil, visit_RB);
		visit_RB(node);
	}
}

Status postorderTraversalRecursive(RedBlackTreePtr rbt, void (*visit_RB)(RBNodePtr)) {
	if (rbt->root == rbt->nil) {
		return failed;
	}
	preorderTraversalRecursiveHelper(rbt->root, rbt->nil, visit_RB);
	return succeed;
}

Status postorderTraversalIterative(RedBlackTreePtr rbt) {
	if (rbt == NULL) return failed;
	StackPtr stack1 = createStack();
	StackPtr stack2 = createStack();
	push(stack1, rbt->root);
	while (!isEmpty(stack1)) {
		RBNodePtr node = pop(stack1);
		push(stack2, node);
		if (node->left != rbt->nil) {
			push(stack1, node->left);
		}
		if (node->right != rbt->nil) {
			push(stack1, node->right);
		}
	}
	while (!isEmpty(stack2)) {
		RBNodePtr node = pop(stack2);
		printf("%d ", node->value);
	}
	destroyStack(stack1);
	destroyStack(stack2);
	return succeed;
}

Status levelOrderTraversal(RedBlackTreePtr rbt) {
	if (!rbt || !rbt->root) {
		return failed;
	}
	Queue queue;
	queue.head = queue.tail = NULL;
	enqueue_RB(&queue, rbt->root);
	while (!isEmptyQueue_RB(queue)) {
		QueueNodePtr qn = dequeue_RB(&queue);
		RBNodePtr node = qn->node;
		printf("%d ", node->value);
		if (node->left != rbt->nil) {
			enqueue_RB(&queue, node->left);
		}
		if (node->right != rbt->nil) {
			enqueue_RB(&queue, node->right);
		}
		free(qn);
	}
	return succeed;
}

void clearRedBlackTreeHelper(RBNodePtr node, RBNodePtr nil) {
	if (node == nil) {
		return;
	}
	clearRedBlackTreeHelper(node->left, nil);
	clearRedBlackTreeHelper(node->right, nil);
	free(node);
}

Status clearRedBlackTree(RedBlackTreePtr rbt) {
	if (rbt == NULL) return failed;
	clearRedBlackTreeHelper(rbt->root, rbt->nil);
	rbt->root = rbt->nil;
	return succeed;
}