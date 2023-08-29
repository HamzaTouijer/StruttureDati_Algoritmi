#include <limits.h>
#include <math.h>

static int DivisioneNegativiResNeg(int a, int b, int r) {	//ottengo risultato negativo
	if (abs(a) < abs(b)) {
			return 0;
		}
	r += 1;
	return DivisioneNegativiResNeg(a + b, b, r) - 1;
}
static int DivisioneNegativiResPos(int a, int b, int r){	//ottengo risultato positivo
	if (abs(a) < abs(b)) {
		return 0;
	}
	r += 1;
	return DivisioneNegativiResPos(a - b, b, r) + 1;
}

int DivisioneNegativi(int a, int b) {
	if (b == 0) {
		return INT_MAX;
	}
	if (a == 0) {
		return 0;
	}
	int r = 0;
	if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
		return DivisioneNegativiResNeg(a, b, r);
	} else {
		return DivisioneNegativiResPos(a, b, r);
	}
}