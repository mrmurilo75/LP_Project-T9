#include "util.h"


Dictionary new_Dictionary() {
	Dictionary result = (Dictionary) malloc(sizeof(struct dictionary_t));
	result->bigWords = new_HashMap();
	result->smallWords = new_BSTreeMap();

	return result;
}

LinkedListMap Dictionary_find(Dictionary dict, StringT9 value) {
	if(dict == NULL || value == NULL)
		return;

	StringT9 valueT9 = String_toStringT9(value);
	if(valueT9 == NULL) return;

	BSTreeMap bstm;

	if(value->length > 5) {
		int position = StringT9_getIntHead(valueT9);
		bstm = HashMap_get(bigWords, &position);

		if(bstm == NULL) {
			bstm = new_BSTreeMap();
			HashMap_insert(bigWords, &position, bstm);
		}
	} else 
		bstm = smallWords;

	return (LinkedListMap) BSTreeMap_find(bstm, valueT9);
}

void Dictionary_insert(Dictionary dict, String value) {
	if(dict == NULL || value == NULL)
		return;

	StringT9 valueT9 = String_toStringT9(value);
	if(valueT9 == NULL) return;

	LinkedListMap llm;
	BSTreeMap bstm;

	if(value->length > 5) {
		int position = StringT9_getIntHead(valueT9);
		bstm = HashMap_get(bigWords, &position);

		if(bstm == NULL) {
			bstm = new_BSTreeMap();
			HashMap_insert(bigWords, &position, bstm);
		}
	} else 
		bstm = smallWords;

	llm = (LinkedListMap) BSTreeMap_find(bstm, valueT9);
	LLMNode node;

	if(llm == NULL) {
		llm = new_LinkedListMap();
		BSTreeMap_insert(bstm, valueT9, llm);
		node = NULL;
	} else 
		node = LinkedListMap_getNodeByValue(llm, value);

	if(node == NULL) {
		Integer newCount = new_Integer();
		*newCount = 1;

		LinkedListMap_add(llm, newCount, value);

	} else {
		Integer count = (Integer) LLMNode_getKey(node);

		(*count)++;
		LinkedListMap_updateNode(llm, node);
	}

	return;
}

