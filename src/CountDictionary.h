#include "util.h"


void* new_CountDictionary() {
	CountDictionary result = malloc(sizeof(countdictionary_t));
	result->bigWords = new_HashMap();
	result->smallWords = new_BSTreeMap();

	return result;
}

int* CountDictionary_find(CountDictionary dict, void* string) {
}

void* CountDictionary_findLLM(CountDictionary dict, void* stringT9) {
}

void CountDictionary_insert(CountDictionary dict, void* string) {
	if(dict == NULL || string == NULL)
		return;

	StringT9 stringT9 = String_toStringT9(string);

	LinkedListMap llm = CountDictionary_findLLM(dict, stringT9);

	if(llm != NULL){
		
		return;
	}

	
	if(valueT9 == NULL)
		return;

	if(value->length <= 5) {	// is smallWord
		BSTreeMap_insert(smallWord, 1, new

		int vHead = StringT9_getIntHead(valueT9);





}

