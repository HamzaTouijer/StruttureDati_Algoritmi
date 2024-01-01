#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include "elemtype.h"
#include <stdio.h>
#include <stdlib.h>

Item *ListLoad(const char *filename) {
	FILE *f = fopen(filename, "r");
	Item *List = ListCreateEmpty();
	if (f == NULL) {
		return List;
	}
	int tmp = 0;
	while (fscanf(f, "%d", &tmp) == 1) {
		List = ListInsertHead(&tmp, List);
	}

	fclose(f);
	return List;
}