#include <stdlib.h>
#include <string.h>

String new_String(int* value) {		// create a new String object

	String result = (String) malloc(sizeof(string_t));

	result->value = value;
	result->length = strlen(value);

	return result;
}

int String_compare(String a, String b) {	// compare String objects

	int minLenght = a->length;
	if(b->length < minLenght) 
		minLenght = b->length;

	int i = 0;
	while(i < minLenght && a->value[i] == b->value[i])
		i++;

	return a->value[i] - b->value[i];
}


int String_equals(String a, String b) {		// return non-zero int if the value of the Strings *are* the same

	return ! String_compare(a, b);

}

