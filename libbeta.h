#include <stdlib.h>
#include <math.h>

#ifndef BETA_SAMPLE_LIBBETA_H
#define BETA_SAMPLE_LIBBETA_H

float beta_sample_BA(float a, float b);
float randfrac();
float min(float a, float b);
float max(float a, float b);

/*
 * Simple algorithm BA from [1]
 */
float beta_sample_BA(float a, float b) {
    if (a < 0.0f || b < 0.0f ) {
        return -1;
    }

    float alpha = a + b;
    float beta = 0.0f;
    float u1 = 0.0f, u2 = 0.0f, w = 0.0f, v = 0.0f;

    if (min(a, b) <= 1.0f) {
        beta = max(1.0f / a, 1.0f / b);
    } else {
        beta = sqrtf((alpha - 2.0f) / (2 * a * b - alpha));
    }

    float gamma = a + 1.0f / beta;

    while (1) {
        u1 = randfrac();
        u2 = randfrac();
        v = beta * logf(u1 / (1 - u1));
        w = a * expf(v);
        float tmp = logf(alpha / (b + w));
        if (alpha * tmp + (gamma * v) - logf(4) >= logf(u1 * u1 * u2)) {
            break;
        }
    }

    return w / (b + w);
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

#endif //BETA_SAMPLE_LIBBETA_H
