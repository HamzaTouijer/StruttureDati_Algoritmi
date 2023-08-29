
static int ProdottoRec(int a, int b) {
	if (b == 0) {
		return 0;
	}
	return ProdottoRec(a, b - 1) + a;
}


int Prodotto(int a, int b) {
	if (a < 0 || b < 0) {
		return -1;
	}
	return ProdottoRec(a, b);
}


/*
int main(void) {
	int r;
	r = Prodotto(-1 ,2);
	r = Prodotto(1, -2);
	r = Prodotto(0, 0);
	r = Prodotto(7, 6);
	return 0;
}
*/