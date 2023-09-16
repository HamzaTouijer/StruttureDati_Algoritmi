#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>


void OmbrelloniRec(int k, int n, int i, bool *vcurr, int cnt, int *nsol) {

	if (cnt == k) {		//foglia
		(*nsol)++;
		printf("    %i) ", *nsol);
		for (int j = 0; j < n - 1; ++j) {
				printf("%i ", vcurr[j]);
		}
		printf("%i\n", vcurr[n - 1]);
		return;
	}
	if (i == n) {
		return;
	}

	vcurr[i] = 0;
	OmbrelloniRec(k, n, i + 1 , vcurr, cnt, nsol);
	if (i == 0 || vcurr[i - 1] != 1) {
		vcurr[i] = 1;
		OmbrelloniRec(k, n, i + 1, vcurr, cnt + 1, nsol);
		vcurr[i] = 0;
	}

}

int Ombrelloni(int k, int n) {
	if (k < 0 || n < 0) {
		return 0;
	}
	bool *vcurr = calloc(n, sizeof(bool));
	int nsol = 0;

	OmbrelloniRec(k, n, 0, vcurr, 0, &nsol);
	
	free(vcurr);
	return nsol;
}

/*
int main(void) {
	int s;
	s = Ombrelloni(5, 10);
	return 0;
}
*/