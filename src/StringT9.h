#include <stdlib.h>
#include <string.h>
#include "util.h"

StringT9 new_StringT9(int length, byte* value) {		// create a new StringT9 object

	StringT9 result = (StringT9) malloc(sizeof(struct stringt9_t));

	result->value = value;
	result->length = length;

	return result;
}

int StringT9_compare(StringT9 a, StringT9 b) {	// compare StringT9 objects
	if(a == b)
		return 0;
	if(a == NULL)
		return 1;
	if(b == NULL)
		return -1;

	int i;
	for(i = 0; i < a->length && i < b->length; i++) {
		if(a->value[i] == b->value[i])
			continue;
		if(a->value[i] < b->value[i])
			return -1;
		return 1;
	}
	return (a->length - b->length);
}

int StringT9_equals(StringT9 a, StringT9 b) {		// return non-zero int if the value of the StringT9´s *are* the same

	return ! StringT9_compare(a, b);

}

int StringT9_getIntHead(StringT9 a) {
	if (a->length <= 5) return 0;
	int result = 0;
	for (int i = 0; i < 5; i++) {
		switch(a->value[i]) {
			case '1' : result = result * 10 + 1; break;
			case '2' : result = result * 10 + 2;break;
			case '3' : result = result * 10 + 3;break;
			case '4' : result = result * 10 + 4;break;
			case '5' : result = result * 10 + 5;break;
			case '6' : result = result * 10 + 6;break;
			case '7' : result = result * 10 + 7;break;
			case '8' : result = result * 10 + 8;break;
			case '9' : result = result * 10 + 9;break;
			default: break;
		}
	}
	return result;
}

