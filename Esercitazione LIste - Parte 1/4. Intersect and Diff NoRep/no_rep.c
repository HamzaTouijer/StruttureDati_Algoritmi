#include "elemtype.h"
#include "list.h"

//Per non avere ripetizioni controllo se l'elemento di tmp1 è gia nella soluzione
Item *IntersectNoRep(const Item *i1, const Item *i2) {
	Item *Sol = ListCreateEmpty();
	Item *tmpSol = ListCreateEmpty();
	for (const Item *tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		//check
		int check = 0;
		for (tmpSol = Sol; !ListIsEmpty(tmpSol); tmpSol = ListGetTail(tmpSol)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmpSol)) == 0) {
				check = 1;
				break;
			}
		}
		if (check == 0) {
			for (const Item *tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
				if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
					Sol = ListInsertBack(Sol, ListGetHeadValue(tmp1));
					break;
				}
			}
		}
	}
	return Sol;
}

Item *DiffNoRep(const Item *i1, const Item *i2) {
	Item *Sol = ListCreateEmpty();
	Item *tmpSol = ListCreateEmpty();
	for (const Item *tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		//check
		int check = 0;
		for(tmpSol = Sol; !ListIsEmpty(tmpSol); tmpSol = ListGetTail(tmpSol)){
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmpSol)) == 0) {
				check = 1;
				break;
			}
		}
		if (check == 0) {
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
	}
	return Sol;
}