#include "util.h"

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