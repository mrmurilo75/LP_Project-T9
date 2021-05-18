#include "util.h"
#include <stdlib.h>

BSTMNode new_BSTMNode(void* key) {
	BSTMNode result = (BSTMNode) malloc(sizeof(struct bstmnode_t));
	result->rightNode = NULL;
	result->leftNode = NULL;

	result->key = key;
	result->value = NULL;
}

BSTMNode new_BSTMNode(void* key, void* value) {
	BSTMNode result = (BSTMNode) malloc(sizeof(struct bstmnode_t));
	result->rightNode = NULL;
	result->leftNode = NULL;

	result->key = key;
	result->value = value;
}

void* BSTMNode_getRightNode(BSTMNode node) {
	return node->rightNode;
}

void BSTMNode_setRightNode(BSTMNode node, BSTMNode right) {
	node->rightNode = right;
}

void* BSTMNode_getLeftNode(BSTMNode node) {
	return node->leftNode;
}

void BSTMNode_setLeftNode(BSTMNode node, BSTMNode left) {
	node->leftNode = left;
}

void* BSTMNode_getValue(BSTMNode node) {
	return node->value;
}

void BSTMNode_setValue(BSTMNode node, void* value) {
	node->value = value;
}

void* BSTMNode_getKey(BSTMNode node){
	return node->key;
}


int BSTMNode_compareKey(BSTMNode node, void* key){		// !! Defined for key of type StringT9
	void* nodeKey = BSTMNode_getKey(node);
	return StringT9_compare(nodeKey, key);
}

BSTreeMap new_BSTreeMap() {
	BSTreeMap result = (BSTreeMap) malloc(sizeof(struct bstreemap_t));
	result->root = NULL;
}


void* BSTreeMap_find(BSTreeMap tree, void* key) {
	if(tree == NULL || key == NULL) return NULL;

	BSTMNode node = tree->root;
	StringT9 nodeKey;
	while(node != NULL && (nodeKey = BSTMNode_getKey(node)) != NULL) {
		int comparison = BSTMNode_compareKey(nodeKey, key);

		if(comparison == 0)
			return BSTMNode_getValue(node);
		if(comparison < 0) {
			node = BSTMNode_getLeftNode(node);
			continue;
		}
		if(comparison > 0) {
			node = BSTMNode_getRightNode(node);
			continue;
		}
	}

	return NUll;
}

/*private*/ BSTMNode BSTMNode_insert(BSTMNode node, void* key, void* value);
		// node: aka subtree in which to search
		// key: to find
		// value: which we want the key to be mapped to
		// returns NULL if no new node was created
		// otherwise returns the node created (or parent) for balacing

/*private*/ BSTMNode BSTMNode_rotateRight(node);	// TODO

/*private*/ BSTMNode BSTMNode_rotateLeft(node);		// TODO

void BSTreeMap_insert(BSTreeMap tree, void* key, void* value) {
	if(key == NULL) return;

	if(tree == NULL) {
		new_BSTreeMap();
		BSTreeMap_insert(tree, key, value);
		return;
	}

	void* root = tree->root;
	if(root == NULL) {
		tree->root = new BSTMNode(key, value);
		return;
	}

	root = BSTMNode_insert(node, key, value);
	if(root == NULL) 	// inserted in an existing node
		return;

	tree->root = root;	// rotated
	return;
}

/*private*/ BSTMNode BSTMNode_insert(BSTMNode node, void* key, void* value) {
	if(node == NULL || key == NULL) return NULL;

	int comparison = BSTMNode_compareKey(node, key);

	if(comparison == 0) {
		BSTMNode_setValue(node, value);
		return NULL;		// bc we didnt insert a new node
	}
	if(comparison < 0) {
		BSTMNode left = BSTMNode_getLeftNode(node);
		BSTMNode newLeft = BSTMNode_insert(left, key, value);

		if(newLeft == NULL)
			return NULL;

		BSTMNode_setLeftNode(node, newLeft);
		return BSTMNode_rotateRight(node);		// return the result of the rotation to be set as new left by the parent
	}
	if(comparison > 0) {
		BSTMNode right = BSTMNode_getRightNode(node);
		BSTMNode newRight = BSTMNode_insert(right, key, value);

		if(newRight == NULL)
			return NULL;

		BSTMNode_setRightNode(node, newRight);
		return BSTMNode_rotateLeft(node);		// return the result of the rotation to be set as new right by the parent
	}

	return NULL; // should never reach
}

/*
	Tree STinsertR(Tree h, Key v)
	{
		if (h == NULL) {
			Tree nt = new Tree; //malloc(sizeof *x);
			nt->root->chave = v;
			nt->left = nt->right = NULL;
			return nt;
		}
		if (v < h->chave) {
			h->l = STinsertR(h->l, v);
			h = rotR(h);
		}
		else {
			h->r = STinsertR(h->r, v);
			h = rotL(h);
		}
		return h;
	}

	link rotR(link h)
	{
		link x = h->l;
		h->l = x->r;
		x->r = h;
		return x;
	}

	link rotL(link h)
	{
		link x = h->r;
		h->r = x->l;
		x->l = h;
		return x;
	}
 */

