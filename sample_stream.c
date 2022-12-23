/*
 * [1] R. C. H. Cheng, "Generating Beta Variates with Nonintegral Shape Parameters",
 * Univ. of Wales Institute of Science and Technology, Management Science/Operations Research, 1978
 *
 * BA Algorithm Implementation: Stream of samples
 *
 * Hit Ctrl-C to stop the program
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "libbeta.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: sample_stream 1.0 2.0\n");
        return -1;
    }

    float a = atof(argv[1]);
    float b = atof(argv[2]);

	srand(time(NULL));

    while(1) {
        float p = beta_sample_BA(a, b);
        printf("%f\n", p);
    }

	return 0;
}


