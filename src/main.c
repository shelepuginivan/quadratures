#include <math.h>
#include <stdio.h>

#include "newton_cotes.h"

double singular_func(double x) {
    return sin(x) / sqrt(x);
}

int main() {
    double a = 0.0, b = 1.0;

    double res = quad_nc_open_composite(singular_func, QUAD_NC_OPEN_METHOD_N_3, a, b, 20000000);

    printf("%.21f\n", res);

    return 0;
}
