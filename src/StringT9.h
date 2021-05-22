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

int StringT9_equals(StringT9 a, StringT9 b) {		// return non-zero int if the value of the StringT9´s *are* the same

    return ! StringT9_compare(a, b);

}

