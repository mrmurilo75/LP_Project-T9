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

	int minLenght = a->length;
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

