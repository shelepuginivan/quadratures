#include <math.h>
#include <stdio.h>

#include "nc_closed.h"

int main() {
    double a = 0.0, b = M_PI;
    QuadNCClosedMethod n = QUAD_CLOSED_METHOD_BOOLE;

    double res = quad_nc_closed_composite(sin, n, a, b, 2);

    printf("%f\n", res);

    return 0;
}
