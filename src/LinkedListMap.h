#include "util.h"
#include <stdlib.h>

	LLMNode new_LLMNode() {
		LLMNode result = (LLMNode) malloc(sizeof(struct llmnode_t));
		result->next = NULL;
		result->previous = NULL;
		result->value = NULL;
		return result;
	}

	void LLMNode_setNext(LLMNode this, LLMNode next){
		if(this == NULL) return;
		this->next = next;
	}

	void LLMNode_setPrevious(LLMNode this, LLMNode previous) {
		if(this == NULL) return;
		this->previous = previous;
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


	LinkedListMap new_LinkedListMap() {
		LinkedListMap result = (LinkedListMap) malloc(sizeof(struct linkedlistmap_t));
		result->root = NULL;
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

	void LinkedListMap_add(LinkedListMap list, void* key, void* value) {

	}

