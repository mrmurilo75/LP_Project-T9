#include <stdlib.h>
#include <string.h>
#include "util.h"

String new_String(int length, int* value) {		// create a new String object

	String result = (String) malloc(sizeof(struct string_t));

	result->value = value;
	result->length = length;

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
            default: new_value[i] = '.';    break;
        }
    }

    for (int i = 0; i < value->length; i++) {
        if (new_value[i] == '.') return NULL;
    }

    nova->value = new_value;
    return nova;
}

