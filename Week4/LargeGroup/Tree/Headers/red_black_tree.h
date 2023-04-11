#ifndef REDBLACKTREE_RED_BLACK_TREE_H
#define REDBLACKTREE_RED_BLACK_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef enum Color {
	RED,
	BLACK
} Color;

Color color; // 节点颜色，RED表示红色，BLACK表示黑色

typedef int ElemType;

typedef struct RBNode {
	ElemType value;
	struct RBNode* left, * right, * parent;
	int color;
} RBNode, * RBNodePtr;

typedef struct RedBlackTree {
	RBNodePtr root;
	RBNodePtr nil;
} RedBlackTree, * RedBlackTreePtr;

Status init(RedBlackTreePtr);
RBNodePtr create_node(ElemType, RBNodePtr);
Status insert(RedBlackTreePtr, ElemType);
Status search(RedBlackTreePtr, ElemType);
Status delete_node(RedBlackTreePtr, int);
Status preorderTraversalRecursive(RedBlackTreePtr, void (*visit_RB)(RBNodePtr));
Status inorderTraversalRecursive(RedBlackTreePtr, void(*visit_RB)(RBNodePtr));
Status postorderTraversalRecursive(RedBlackTreePtr, void(*visit_RB)(RBNodePtr));
Status preorderTraversalIterative(RedBlackTreePtr);
Status inorderTraversalIterative(RedBlackTreePtr);
Status postorderTraversalIterative(RedBlackTreePtr);
Status levelOrderTraversal(RedBlackTreePtr);
Status clearRedBlackTree(RedBlackTreePtr);

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H