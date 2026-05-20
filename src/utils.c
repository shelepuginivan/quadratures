#include <math.h>

#include "utils.h"

double quad_kahan_sum(double *sum, double *c, double input) {
    double t = *sum + input;
    if (fabs(*sum) >= fabs(input)) {
        *c += (*sum - t) + input;
    } else {
        *c += (input - t) + *sum;
    }
    *sum = t;
    return *sum;
}
