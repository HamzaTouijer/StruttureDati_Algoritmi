static int ProdottoNegativiRec(int a, int b) {
	if (b == 0) {
		return 0;
	}
	return ProdottoNegativiRec(a, b + 1) - a;
}

static int ProdottoNegativiRec2(int a, int b) {
	if (b == 0) {
		return 0;
	}
	return ProdottoNegativiRec2(a, b - 1) + a;
}
int ProdottoNegativi(int a, int b) {
	if (b < 0) {
		return ProdottoNegativiRec(a, b);
	}
	return ProdottoNegativiRec2(a, b);
}
