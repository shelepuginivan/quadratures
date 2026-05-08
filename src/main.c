#include <math.h>
#include <stdio.h>

#include "nc_closed.h"
#include "nc_open.h"

double singular_func(double x) {
    return sin(x) / sqrt(x);
}

int main() {
    double a = 0.0, b = 1.0;
    QuadNCClosedMethod n = QUAD_NC_CLOSED_METHOD_BOOLE;

    double res = quad_nc_open_composite(singular_func, QUAD_NC_OPEN_METHOD_N_3, a, b, 100);

    printf("%f\n", res);

    return 0;
}
