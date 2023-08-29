
static int DivisioneRec(int a, int b, int r) {
	if ((a-b)<0) {
		return 0;
	}
	r += 1;
	return DivisioneRec(a - b, b, r) + 1;
}

int Divisione(int a, int b) {
	if (a < 0 || b <= 0) {
		return -1;
	}
	if (a == 0) {
		return 0;
	}
	int r = 0;
	return DivisioneRec(a, b, r);
}