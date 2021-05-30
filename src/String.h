#include <stdlib.h>
#include <string.h>
#include "util.h"

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
	if(b->length < minLenght) 
		minLenght = b->length;

	int i = 0;
	while(i < minLenght && a->value[i] == b->value[i])
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
	char new_value[value->length];
	char pal[value->length];
	strcpy(pal,value->value);

	for (int i = 0; i < value->length; i++) {
		pal[i] = tolower(pal[i]);
		switch (pal[i]) {
			case 'a': new_value[i] = '2';   break;
			case 'b': new_value[i] = '2';   break;
			case 'c': new_value[i] = '2';   break;
			case 'd': new_value[i] = '3';   break;
			case 'e': new_value[i] = '3';   break;
			case 'f': new_value[i] = '3';   break;
			case 'g': new_value[i] = '4';   break;
			case 'h': new_value[i] = '4';   break;
			case 'i': new_value[i] = '4';   break;
			case 'j': new_value[i] = '5';   break;
			case 'k': new_value[i] = '5';   break;
			case 'l': new_value[i] = '5';   break;
			case 'm': new_value[i] = '6';   break;
			case 'n': new_value[i] = '6';   break;
			case 'o': new_value[i] = '6';   break;
			case 'p': new_value[i] = '7';   break;
			case 'q': new_value[i] = '7';   break;
			case 'r': new_value[i] = '7';   break;
			case 's': new_value[i] = '7';   break;
			case 't': new_value[i] = '8';   break;
			case 'u': new_value[i] = '8';   break;
			case 'v': new_value[i] = '8';   break;
			case 'w': new_value[i] = '9';   break;
			case 'x': new_value[i] = '9';   break;
			case 'y': new_value[i] = '9';   break;
			case 'z': new_value[i] = '9';   break;
            case '1': new_value[i] = '1';   break;
            case '2': new_value[i] = '2';   break;
            case '3': new_value[i] = '3';   break;
            case '4': new_value[i] = '4';   break;
            case '5': new_value[i] = '5';   break;
            case '6': new_value[i] = '6';   break;
            case '7': new_value[i] = '7';   break;
            case '8': new_value[i] = '8';   break;
            case '9': new_value[i] = '9';   break;
            case '0': new_value[i] = '0';   break;
			default: new_value[i] = '.';	break;
		}
	}

	for (int i = 0; i < value->length; i++) {
		if (new_value[i] == '.') return NULL;
	}

	nova->value = new_value;
	return nova;
}

