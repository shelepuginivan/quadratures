#include <math.h>

#include "functions.h"

double quad_fn_sin_x_over_sqrt_x(double x) {
    return sin(x) / sqrt(x);
}

double quad_fn_sqr(double x) {
    return x * x;
}

double quad_fn_cub(double x) {
    return pow(x, 3.0);
}

double quad_fn_x4(double x) {
    return pow(x, 4.0);
}
