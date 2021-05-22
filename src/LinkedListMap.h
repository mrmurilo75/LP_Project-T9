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
        this->next = next;
    }

    void LLMNode_setPrevious(LLMNode this, LLMNode previous) {
        this->previous = previous;
    }

    void LLMNode_setValue(LLMNode this, void* value) {
        this->value = value;
    }

    LLMNode LLMNode_getNext(LLMNode this) {
        return this->next;
    }

    LLMNode LLMNode_getPrevious(LLMNode this) {
        return this->previous;
    }

    void* LLMNode_getValue(LLMNode this) {
        return this->value;
    }


    LinkedListMap new_LinkedListMap() {
        LinkedListMap result = (LinkedListMap) malloc(sizeof(struct linkedlistmap_t));
        result->root = NULL;
        return result;
    }

    void LinkedListMap_setRoot(LinkedListMap list, LLMNode node) {
        list->root = node;
    }

    void LinkedListMap_search(LLMNode root, void* value, LLMNode *prev, LLMNode *atual) {
        *prev = root;
        *atual = root->next;
        while ((*atual) != NULL && (*atual)->value != value) {
            *prev = *atual;
            *atual = (*atual)->next;
        }
        if ((*atual) != NULL && (*atual)->value != value)
            *atual = NULL; //In case we dont find the value
    }


    void* LinkedListMap_find(LinkedListMap list, void* key) {
        LLMNode prev = new_LLMNode();
        LLMNode atual = new_LLMNode();

        LinkedListMap_search(list->root,key,*prev,*atual);

        return LLMNode_getValue(atual);
    }

    void LinkedListMap_add(LinkedListMap list, void* key, void* value);

