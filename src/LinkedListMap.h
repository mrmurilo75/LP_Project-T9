#include "util.h"
#include <stdlib.h>

LLMNode new_LLMNode() {
	LLMNode result = (LLMNode) malloc(sizeof(struct llmnode_t));
	result->next = NULL;
	result->previous = NULL;
	result->value = NULL;
	int* key = malloc(sizeof(int));
	*key = 0;
	result->key = (void*) key;

	return result;
}

void LLMNode_setNext(LLMNode this, LLMNode next){
	if(this == NULL || this == next) return;

	this->next = next;

	if(next != NULL && LLMNode_getPrevious(next) != this)
		LLMNode_setPrevious(next, this);
}

void LLMNode_setPrevious(LLMNode this, LLMNode previous) {
	if(this == NULL || this == previous) return;

	this->previous = previous;

	if(previous != NULL && LLMNode_getNext(previous) != this)
		LLMNode_setNext(previous, this);
}

void LLMNode_setKey(LLMNode this, void* key) {
	if(this == NULL) return;
	this->key = key;
}

void LLMNode_setValue(LLMNode this, void* value) {
	if(this == NULL) return;
	this->value = value;
}

LLMNode LLMNode_getNext(LLMNode this) {
	if(this == NULL) return NULL;
	return this->next;
}

LLMNode LLMNode_getPrevious(LLMNode this) {
	if(this == NULL) return NULL;
	return this->previous;
}

void*  LLMNode_getKey(LLMNode this) {
	if(this == NULL) return NULL;
	return this->key;
}

void* LLMNode_getValue(LLMNode this) {
	if(this == NULL) return NULL;
	return this->value;
}
void LLMNode_print(LLMNode node) {
	printf("t= %p\t", node);
	printf("k= %d\t", *((int*)(node->key)));
	printf("v= %s\t", ((String)(node->value))->value);
	printf("n= %p\t", node->next);
	printf("p= %p\t", node->previous);
	printf("\n");

	return;
}


LinkedListMap new_LinkedListMap() {
	LinkedListMap result = (LinkedListMap) malloc(sizeof(struct linkedlistmap_t));
	
	result->root = NULL;
	result->current = NULL;

	return result;
}

void LinkedListMap_setRoot(LinkedListMap list, LLMNode node) {
	if(list == NULL) return;
	list->root = node;
}

LLMNode LinkedListMap_getRoot(LinkedListMap list) {
	if(list == NULL) return NULL;
	return list->root;
}

// !! Defined for a <int> key
void* LinkedListMap_find(LinkedListMap list, void* key) {
	if(list == NULL) return NULL;

	int keyValue = *( (int*) key );
	for(LLMNode current = LinkedListMap_getRoot(list); 
			current != NULL;
			current = LLMNode_getNext(current) 
	) {
		int* currentKey = (int*) LLMNode_getKey(current);

		if(*currentKey == keyValue)
			return currentKey;
	}

	return NULL;
}

/*private*/ void LinkedListMap_addNode(LinkedListMap list, LLMNode newNode) {
	if(list == NULL || newNode == NULL) return;

	void *key = LLMNode_getKey(newNode);

	if(LinkedListMap_getRoot(list) == NULL) {
		LinkedListMap_setRoot(list, newNode);

		return;
	}
	prin tf("@LLLM : this function is possibly only going as far as setting the root, then a mistake happens in this following block athat prevents other node from being added");

	int keyValue = *( (int*) key ), currentKeyValue;
	LLMNode current, next;
	for(current = LinkedListMap_getRoot(list), 
			next = LLMNode_getNext(current), 
			currentKeyValue = *( (int*) LLMNode_getKey(current) );
		next != NULL
			&& currentKeyValue <= keyValue;
		current = LLMNode_getNext(current), 
			next = LLMNode_getNext(current), 
			     currentKeyValue = *( (int*) LLMNode_getKey(current) ));

	if(currentKeyValue <= keyValue) {
		if(next == NULL) {
			LLMNode_setNext(current, newNode);

			return;
		}
		LLMNode_setPrevious(next, newNode);
		LLMNode_setNext(current, newNode);

		return;
	}

	LLMNode previous = LLMNode_getPrevious(current);

	if(previous == NULL) {
		LLMNode_setPrevious(current, newNode);

		return;
	}
	LLMNode_setNext(previous, newNode);
	LLMNode_setPrevious(current, newNode);

	return;
}

void LinkedListMap_print(LinkedListMap list) {
	for(LLMNode current = LinkedListMap_getRoot(list); 
			current != NULL;
			current = LLMNode_getNext(current) 
	) {
		printf("%p\t", list);
		LLMNode_print(current);
	}

	return;
}

void LinkedListMap_add(LinkedListMap list, void* key, void* value) {
	if(list == NULL || key == NULL) return;

	LLMNode newNode = new_LLMNode();
	LLMNode_setKey(newNode, key);
	LLMNode_setValue(newNode, value);

	LinkedListMap_addNode(list, newNode);

	LinkedListMap_print(list);

	return;
}

LLMNode LinkedListMap_getNodeByValue(LinkedListMap list, void* value) {
	if(list == NULL) return NULL;

	String valueStr = (String) value, currentValueStr;
	LLMNode current;
	int comparison;
	for(current = LinkedListMap_getRoot(list), 
			currentValueStr = (String) LLMNode_getValue(current);
		current != NULL
			&& (comparison = String_compare(valueStr, currentValueStr)) > 0;
		current = LLMNode_getNext(current),
			currentValueStr = (String) LLMNode_getValue(current) );

	if(current != NULL && comparison == 0)
		return current;

	return NULL;
}

void LinkedListMap_updateNode(LinkedListMap list, LLMNode node) {
	if(list == NULL || node == NULL) return;

// simply remove and add again (can be done better by simply going foward or backwards)

	LLMNode previous = LLMNode_getPrevious(node),
		next = LLMNode_getNext(node);
	LLMNode_setNext(previous, next);
	LLMNode_setPrevious(node, NULL);
	LLMNode_setNext(node, NULL);

	LinkedListMap_addNode(list, node);

	return;
}

void* LinkedListMap_current(LinkedListMap list) {
	if(list == NULL) return NULL;

	if(list->current == NULL)
		list->current = LinkedListMap_getRoot(list);

	return LLMNode_getValue(list->current);
}

void* LinkedListMap_next(LinkedListMap list) {
	if(list == NULL) return NULL;

	printf("HERE\n");
	if(list->current != NULL)
		list->current = LLMNode_getNext(list->current);
	if(list->current == NULL)
		list->current = LinkedListMap_getRoot(list);

	return LLMNode_getValue(list->current);
}

