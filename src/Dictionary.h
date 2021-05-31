#include "util.h"
#include "Integer.h"
#include "String.h"
#include "LinkedListMap.h"
#include "BSTreeMap.h"
#include "HashMap.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

Dictionary new_Dictionary() {
	Dictionary result = (Dictionary) malloc(sizeof(struct dictionary_t));
	result->bigWords = new_HashMap();
	result->smallWords = new_BSTreeMap();

	return result;
}

LinkedListMap Dictionary_find(Dictionary dict, StringT9 value) {
	if(dict == NULL || value == NULL)
		return NULL;

	BSTreeMap bstm;

	if(value->length > 5) {
		int position = StringT9_getIntHead(value);
		bstm = HashMap_get(dict->bigWords, &position);

		if(bstm == NULL) {
			bstm = new_BSTreeMap();
			HashMap_insert(dict->bigWords, &position, bstm);
		}
	} else 
		bstm = dict->smallWords;

	return (LinkedListMap) BSTreeMap_find(bstm, value);
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
		bstm = HashMap_get(dict->bigWords, &position);

		printf("pos= %d\t", position);

		if(bstm == NULL) {
			bstm = new_BSTreeMap();
			HashMap_insert(dict->bigWords, &position, bstm);
		}
	} else {
		printf("\t\t");
		bstm = dict->smallWords;
	}

	llm = (LinkedListMap) BSTreeMap_find(bstm, valueT9);
	printf("v=     %s\tvT9= %s\tllm= %p\n", value->value, valueT9->value, llm);
	LLMNode node;

	if(llm == NULL) {
		llm = new_LinkedListMap();
		BSTreeMap_insert(bstm, valueT9, llm);
		printf("inserted %p\n", BSTreeMap_find(bstm, valueT9));
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

/* private */ String readNextWord(FILE* file);

Dictionary Dictionary_fillFromFile(FILE* file) {
	if(file == NULL) return NULL;

	Dictionary dict = new_Dictionary();

	String word = readNextWord(file);
	while(word != NULL) {
		//printf("\tinserting word: %s\n", word->value); 
		Dictionary_insert(dict, word);
		word = readNextWord(file);
	}

	return dict;
}

/* private */ String readNextWord(FILE* file) {
	if(file == NULL) return NULL;

	int i,
		c;
	char word[64];

	while(!isalnum( c = fgetc(file) ) && c != EOF);

	for(i = 0; i < 63 && isalnum(c); i++, c = fgetc(file))
		word[i] = c;

	word[ i ] = '\0';

	if(i == 0)
		return NULL; // String is empty

	//printf("\tword: %s\n", word); 

	char *word_trimmed = malloc(sizeof(char) * (i+1));
	strcpy(word_trimmed, word);

	return new_String( i, word_trimmed );
}
