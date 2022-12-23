/*
 * [1] R. C. H. Cheng, "Generating Beta Variates with Nonintegral Shape Parameters",
 * Univ. of Wales Institute of Science and Technology, Management Science/Operations Research, 1978
 *
 * BA Algorithm Implementation: Build a histogram of counts in [0,1)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "libbeta.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: sample_hist 1.0 2.0\n");
        return -1;
    }

    float a = atof(argv[1]);
    float b = atof(argv[2]);

	srand(time(NULL));

	int counts[10];
	for (int i = 0; i < 10; ++i) {
		counts[i] = 0;
	}

	for (int i = 0; i < 10000; ++i) {
		float p = beta_sample_BA(a, b);

        if (p < 0) {
            printf("Error: parameters a and b should be larger than 0!\n");
            return -1;
        }

		if (p > 0.9) {
			counts[9]++;
		} else if (p > 0.8) {
			counts[8]++;
		} else if (p > 0.7) {
			counts[7]++;
		} else if (p > 0.6) {
			counts[6]++;
		} else if (p > 0.5) {
			counts[5]++;
		} else if (p > 0.4) {
			counts[4]++;
		} else if (p > 0.3) {
			counts[3]++;
		} else if (p > 0.2) {
			counts[2]++;
		} else if (p > 0.1) {
			counts[1]++;
		} else {
			counts[0]++;
		}
	}

	for (int i = 0 ; i < 10; ++i) {
		printf("%d ", counts[i]);
	}
	printf("\n");

	return 0;
}


