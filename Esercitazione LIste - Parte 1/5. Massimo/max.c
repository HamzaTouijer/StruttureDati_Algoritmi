#include "elemtype.h"
#include "list.h"
#include <stdlib.h>

const ElemType *MaxElement(const Item *i) {
	if (ListIsEmpty(i) == 1) {
		return NULL;
	}
	 const ElemType *A = ListGetHeadValue(i);
	for (const Item *tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (*ListGetHeadValue(tmp) > *A) {
			A = ListGetHeadValue(tmp);
		}
	}
	return A;
}