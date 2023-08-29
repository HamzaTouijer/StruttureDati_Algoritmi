//Se n è minore di zero la funzione deve ritornare 0.

static unsigned long long FattorialeRec(int n) {
	if (n == 1 || n == 0) {
		return 1;
	}
	return n * FattorialeRec(n - 1);
}

unsigned long long Fattoriale(int n) {
	//Se n è minore di zero la funzione deve ritornare 0.
	if (n < 0) {
		return 0;
	}
	return FattorialeRec(n);
}
/*
int main(void) {

	unsigned long long a = Fattoriale(0);
	unsigned long long b = Fattoriale(5);
	unsigned long long c = Fattoriale(10);

	return 0;
}
*/