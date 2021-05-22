#include "util.h"


void* new_Dictionary() {
	Dictionary result = (Dictionary) malloc(sizeof(struct dictionary_t));
	result->bigWords = new_HashMap();
	result->smallWords = new_BSTreeMap();

	return result;
}

int* Dictionary_find(Dictionary dict, String value) {
}

void* Dictionary_find(Dictionary dict, StringT9 value) {
	if(value->length <= 5)
		LinkedListMap BSTreeMap_find(smallWords, 
}

void Dictionary_insert(Dictionary dict, String value) {
	if(dict == NULL || value == NULL)
		return;

	StringT9 valueT9 = String_toStringT9(value);

	LinkedListMap llm = Dictionary_findLLM(dict, valueT9);

	if(llm == NULL){
		
		return;
	}

	
	if(valueT9 == NULL)
		return;

	if(value->length <= 5) {	// is smallWord
		BSTreeMap_insert(smallWord, 1, new

		int vHead = StringT9_getIntHead(valueT9);





}

