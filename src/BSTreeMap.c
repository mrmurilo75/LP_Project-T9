#include "util.h"
#include <stdlib.h>

BSTMNode new_BSTMNode() {
	BSTMNode result = (BSTMNode) malloc(sizeof(struct bstmnode_t));
	rightNode = NULL;
	leftNode = NULL;
	value = NULL;
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

BSTreeMap new_BSTreeMap() {
    BSTreeMap result = (BSTreeMap) malloc(sizeof(struct bstreemap_t));
    result->root = NULL;
}

void* BSTreeMap_find(BSTreeMap tree, void* key);
/*
    link STsearch(link h, int v) {
        int t;
        if (h == NULL) return NULL;
            t = h->chave;
        if (v == t) return h;
        if (v < t)
            return STsearch(h->l, v);
        else
            return STsearch(h->r, v);
    }
 */

void BSTreeMap_insert(BSTreeMap tree, void* key, void* value);
/*
    link STinsertR(link h, int v)
    {
        if (h == NULL) {
            link x = malloc(sizeof *x);
            x->chave = v;
            x->l = x->r = NULL;
            return x;
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

