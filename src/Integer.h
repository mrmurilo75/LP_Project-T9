#include "util.h"
#include <stdlib.h>

Integer new_Integer() {
	return (int*) malloc(sizeof(int));
}

