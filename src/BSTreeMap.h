#include "util.h"
#include <stdlib.h>

BSTMNode new_BSTMNode(void* key, void* value) {
	BSTMNode result = (BSTMNode) malloc(sizeof(struct bstmnode_t));
	result->rightNode = NULL;
	result->leftNode = NULL;

	result->key = key;
	result->value = value;

	return result;
}

void* BSTMNode_getRightNode(BSTMNode node) {
    if(node->rightNode == NULL) return NULL;
	return node->rightNode;
}

void BSTMNode_setRightNode(BSTMNode node, BSTMNode right) {
	node->rightNode = right;
}

void* BSTMNode_getLeftNode(BSTMNode node) {
    if(node->leftNode == NULL) return NULL;
	return node->leftNode;
}

void BSTMNode_setLeftNode(BSTMNode node, BSTMNode left) {
	node->leftNode = left;
}

void* BSTMNode_getValue(BSTMNode node) {
    if(node->value == NULL) return NULL;
	return node->value;
}

void BSTMNode_setValue(BSTMNode node, void* value) {
	node->value = value;
}

void* BSTMNode_getKey(BSTMNode node){
    if(node->key == NULL) return NULL;
	return node->key;
}


int BSTMNode_compareKey(BSTMNode node, void* key){		// !! Defined for key of type StringT9
	void* nodeKey = BSTMNode_getKey(node);
	return StringT9_compare(nodeKey, key);
}

BSTreeMap new_BSTreeMap() {
	BSTreeMap result = (BSTreeMap) malloc(sizeof(struct bstreemap_t));
	result->root = NULL;

	return result;
}


void* BSTreeMap_find(BSTreeMap tree, void* key) {
	if(tree == NULL || key == NULL) return NULL;

	BSTMNode node = tree->root;
	while(node != NULL) {
		int comparison = BSTMNode_compareKey(node, key);

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

	return NULL;
}

/*private*/ BSTMNode BSTMNode_insert(BSTMNode node, void* key, void* value);
		// node: aka subtree in which to search
		// key: to find
		// value: which we want the key to be mapped to
		// returns NULL if no new node was created
		// otherwise returns the node created (or parent) for balacing

/*private*/ BSTMNode BSTMNode_rotateRight(BSTMNode node);

/*private*/ BSTMNode BSTMNode_rotateLeft(BSTMNode node);

void BSTreeMap_insert(BSTreeMap tree, void* key, void* value) {
	if(tree == NULL || key == NULL) return;

	void* root = tree->root;
	if(root == NULL) {
		tree->root = new_BSTMNode(key, value);
		return;
	}

	root = BSTMNode_insert(root, key, value);
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

		if(left == NULL) {
			left = new_BSTMNode(key, value);
			BSTMNode_setLeftNode(node, left);
			return BSTMNode_rotateRight(node);		// return the result of the rotation to be set as new left by the parent
		}

		BSTMNode newLeft = BSTMNode_insert(left, key, value);

		if(newLeft == NULL)
			return NULL;

		BSTMNode_setLeftNode(node, newLeft);
		return BSTMNode_rotateRight(node);		// return the result of the rotation to be set as new left by the parent
	}
	if(comparison > 0) {
		BSTMNode right = BSTMNode_getRightNode(node);

		if(right == NULL) {
			right = new_BSTMNode(key, value);
			BSTMNode_setRightNode(node, right);
			return BSTMNode_rotateLeft(node);		// return the result of the rotation to be set as new left by the parent
		}

		BSTMNode newRight = BSTMNode_insert(right, key, value);

		if(newRight == NULL)
			return NULL;

		BSTMNode_setRightNode(node, newRight);
		return BSTMNode_rotateLeft(node);		// return the result of the rotation to be set as new right by the parent
	}

	return NULL; // should never reach
}

/*private*/ BSTMNode BSTMNode_rotateRight(BSTMNode node) {
    BSTMNode left = BSTMNode_getLeftNode(node);
    BSTMNode_setRightNode(left, node);
    BSTMNode_setLeftNode(node, BSTMNode_getRightNode(left));
    return left;
}


/*private*/ BSTMNode BSTMNode_rotateLeft(BSTMNode node) {
    BSTMNode temp = BSTMNode_getRightNode(node);
    BSTMNode_setRightNode(node, BSTMNode_getLeftNode(temp));
    BSTMNode_setLeftNode(temp, node);
    return temp;
}



