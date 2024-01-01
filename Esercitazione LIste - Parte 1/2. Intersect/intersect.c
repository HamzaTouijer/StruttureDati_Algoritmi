 #include "elemtype.h"
 #include "list.h"

Item *Intersect(const Item *i1, const Item *i2) {
	//logica: scorrere nella lista i1 e confrontarla con i2
	Item *Sol = ListCreateEmpty();
	for (const Item *tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		for (const Item *tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2))==0) {
				Sol = ListInsertBack(Sol, ListGetHeadValue(tmp1));
				break;
			}
		}
	}
	return Sol;
}