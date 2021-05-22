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

	if(value->length <= 5)
		return (LinkedListMap) BSTreeMap_find(smallWords, value);

	int position = StringT9_getIntHead(value);
	BSTreeMap bstm = HashMap(bigWords, &position);

	return (LinkedListMap) BSTreeMap_find(bstm, value);
}

void Dictionary_insert(Dictionary dict, String value) {
	if(dict == NULL || value == NULL)
		return;

	StringT9 valueT9 = String_toStringT9(value);
	if(valueT9 == NULL) return;

	LinkedListMap llm;

	if(value->length <= 5) {
		llm = (LinkedListMap) BSTreeMap_find(smallWords, valueT9);

		if(llm != NULL) {
			LinkedListMap_getNodeByValue(llm, value);


		if(llm == NULL) {
			llm = new_LinkedListMap();
			Integer newCount = new_Integer();
			*newCount = 1;

			LinkedListMap_add(llm, newCount, value);
			BSTreeMap_insert(smallWords, valueT9, llm);
		}

	} else {
		int position = StringT9_getIntHead(valueT9);
		BSTreeMap bstm = HashMap(bigWords, &position);
		llm = (LinkedListMap) BSTreeMap_find(bstm, value);
	}

}

