#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "util.h"
#include "StringT9.h"

String new_String(int length, char* value) {
// !! possible bug by not cpying arguments into heap (malloc-ing)

	String result = (String) malloc(sizeof(struct string_t));

	result->value = value;
	result->length = length;
	result->size = length + 1; // accounting for the null character

	return result;
}

String new_StringWithBuffer(int length, char* value, int size) {
// !! possible bug by not cpying arguments into heap (malloc-ing)

	String result = (String) malloc(sizeof(struct string_t));

	result->value = value;
	result->length = length;
	result->size = size; // accounting for the null character

	return result;
}

int String_compare(String a, String b) {	// compare String objects

	int minLength = a->length;
	if(b->length < minLength) 
		minLength = b->length;

	int i = 0;
	while(i < minLength && a->value[i] == b->value[i])
		i++;

	if (a->value[i] != b->value[i])
		return a->value[i] - b->value[i];

	if(a->length == b->length)
		return 0;
	else if (a->length > b->length)
		return 1;

	return -1;
}


int String_equals(String a, String b) {		// return non-zero int if the value of the Strings *are* the same

	return ! String_compare(a, b);

}

void* String_toStringT9(String value) {
	StringT9 nova = new_StringT9(value->length ,NULL);
	char *new_value = malloc(sizeof(char) * (value->length +1));
	char *pal = value->value;

	for (int i = 0; i < value->length; i++) {
		pal[i] = tolower(pal[i]);
		switch (pal[i]) {
			case 'a':
			case 'b':
			case 'c': 
				new_value[i] = '2';
				break;
			case 'd':
			case 'e':
			case 'f': 
				new_value[i] = '3';
				break;
			case 'g': 
			case 'h': 
			case 'i': 
				new_value[i] = '4';
				break;
			case 'j':
			case 'k':
			case 'l': 
				new_value[i] = '5';
				break;
			case 'm':
			case 'n':
			case 'o': 
				new_value[i] = '6';
				break;
			case 'p':
			case 'q':
			case 'r':
			case 's':
				new_value[i] = '7';
				break;
			case 't':
			case 'u':
			case 'v':
				new_value[i] = '8';
				break;
			case 'w':
			case 'x':
			case 'y':
			case 'z':
				new_value[i] = '9';
				break;
			default:
				return NULL;
		}
	}

	nova->value = new_value;
	return nova;
}

String String_append(String start, String end) {
	if(start == NULL) {
		char *new_value = malloc(sizeof(char) * (end->length + 1));
		strcpy(new_value, end->value);
		return new_String(end->length, new_value);
	}

	if(end == NULL) 
		return start;

	if( start->size > (start->length + end->length) ) {
		strcpy( &(start->value[start->length]), end->value );
		return start;
	}

	char *new_value = malloc(sizeof(char) * (start->length + end->length + 1));
	strcpy(new_value, start->value);
	strcpy( &(new_value[start->length]), end->value);
	return new_String(start->length + end->length, new_value);
}

void String_del(String str, int i) {
	str->value[ str->length - 1 - i ] = '\0';
	str->length = str->length - i;

	return;
}

