#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void BabboNataleRec(const int *pacchi, size_t pacchi_size, int p, unsigned int i, bool *vcurr, bool *vbest, int *max, int cnt, int sum) {
	if (i == pacchi_size) {
		for (size_t j = 0; j < pacchi_size; ++j) {
			if (vcurr[j] == 1) {
				sum += pacchi[j];
			}
		}
		if (sum <= p) {
			if (cnt >= *max) {
				for (size_t j = 0; j < pacchi_size; ++j) {
					vbest[j] = vcurr[j];
				}
				*max = cnt;
			}
		}
		return;
	}
	vcurr[i] = 1;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt + 1, 0);
	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt, 0);
	vcurr[i] = 1;
}

void BabboNatale(const int *pacchi, size_t pacchi_size, int p) {
	bool *vcurr = calloc(pacchi_size, sizeof(bool));
	bool *vbest = calloc(pacchi_size, sizeof(bool));

	int max = 0;
	BabboNataleRec(pacchi, pacchi_size, p, 0, vcurr, vbest, &max, 0, 0);
		free(vcurr);
	for (size_t j = 0; j < pacchi_size; ++j) {
		printf("%i ", vbest[j]);
	}
	free(vbest);
}