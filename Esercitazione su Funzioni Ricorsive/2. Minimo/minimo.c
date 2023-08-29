//Si assuma che v sia sempre diverso da NULL e che v_size sia sempre maggiore o uguale ad 1.

int Minimo(const int *v, int v_size) {
	--v_size;
	if (v_size == 0) {
		return v[0];
	}

	int min = Minimo(v, v_size);

	if (v[v_size] < min) {
		return v[v_size];
	} else {
		return min;
	}
}

/*
int main(void) {

	int av[] = { 9, 2, 6, 5};
	int as = 4;

	int a = Minimo(av, as);

	return 0;
}
*/