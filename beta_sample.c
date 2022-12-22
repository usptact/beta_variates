/*
 * [1] R. C. H. Cheng, "Generating Beta Variates with Nonintegral Shape Paramters",
 * Univ. of Wales Institute of Science and Technology, Management Science/Operations Research, 1978
 *
 * BA Algorithm Implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float randfrac();
float min(float a, float b);
float max(float a, float b);
float beta_sample_BA(float a, float b);

int main() {
	srand(time(NULL));

	// set these
	float a = 2.0;
	float b = 5.0;

	int counts[10];
	for (int i = 0; i < 10; ++i) {
		counts[i] = 0;
	}

	for (int i = 0; i < 10000; ++i) {
		float p = next_sample(a, b);

		if (p > 0.9) {
			//printf("Hit #10\n");
			counts[9]++;
		} else if (p > 0.8) {
			//printf("Hit #9\n");
			counts[8]++;
		} else if (p > 0.7) {
			//printf("Hit #8\n");
			counts[7]++;
		} else if (p > 0.6) {
			//printf("Hit #7\n");
			counts[6]++;
		} else if (p > 0.5) {
			//printf("Hit #6\n");
			counts[5]++;
		} else if (p > 0.4) {
			//printf("Hit #5\n");
			counts[4]++;
		} else if (p > 0.3) {
			//printf("Hit #4\n");
			counts[3]++;
		} else if (p > 0.2) {
			//printf("Hit #3\n");
			counts[2]++;
		} else if (p > 0.1) {
			//printf("Hit #2\n");
			counts[1]++;
		} else {
			//printf("Hit #1\n");
			counts[0]++;
		}
	}

	for (int i = 0 ; i < 10; ++i) {
		printf("%d ", counts[i]);
	}
	printf("\n");

	return 0;
}

float randfrac() {
	return (rand() % RAND_MAX) / (float) RAND_MAX;
}

float min(float a, float b) {
	return (a > b) ? b : a;
}

float max(float a, float b) {
	return (a > b) ? a : b;
}

float beta_sample_BA(float a, float b) {
	float alpha = a + b;
	float beta = 0.0;
	float u1 = 0.0, u2 = 0.0, w = 0.0, v = 0.0;

	if (min(a, b) <= 1.0) {
		beta = max(1.0 / a, 1.0 / b);
	} else {
		beta = sqrt((alpha - 2.0) / (2 * a * b - alpha));
	}

	float gamma = a + 1.0 / beta;

	while (1) {
		u1 = randfrac();
		u2 = randfrac();
		v = beta * log(u1 / (1 - u1));
		w = a * exp(v);
		float tmp = log(alpha / (b + w));
		if (alpha * tmp + (gamma * v) - 1.3862944 >= log(u1 * u1 * u2)) {
			break;
		}
	}

	float x = w / (b + w);
	return x;
}

