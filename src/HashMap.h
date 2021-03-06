#include "util.h"
#include <stdlib.h>
#include <stdio.h>

// !! defined for < Integer , BSTreeMap >

HashMap new_HashMap() {
	return calloc(100000, sizeof(BSTreeMap));
}

void* HashMap_get(HashMap map, void* key) {
	BSTreeMap *lmap = (BSTreeMap*) map;
	int lkey = *( (int*) key );
	
	return lmap[lkey];
}


void HashMap_insert(HashMap map, void* key, void* value) {
	BSTreeMap *lmap = (BSTreeMap*) map;
	int lkey = *( (int*) key );

	lmap[lkey] = (BSTreeMap) value;

	return;
}

// void HashMap_remove(HashMap map, void* key);

