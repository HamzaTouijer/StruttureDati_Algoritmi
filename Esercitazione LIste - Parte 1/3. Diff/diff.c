#include "elemtype.h"
#include "list.h"

Item *Diff(const Item *i1, const Item *i2) {
	//coonfronta agni elelmento della prima lista con la seconda se arriva alla fine, questo elemento non c'è
	Item *Sol = ListCreateEmpty();
	for (const Item *tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		for (const Item *tmp2 = i2; ; tmp2 = ListGetTail(tmp2)) {
			if (ListIsEmpty(tmp2) == 1) {
				 Sol = ListInsertBack(Sol, ListGetHeadValue(tmp1));
				break;
			}
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
				break;
			}
		}
	}
	return Sol;
}