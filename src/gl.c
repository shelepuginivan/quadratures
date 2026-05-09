#include "gl.h"

// https://toomanydigits.online/Block4/Sem2/3.html#id2

// clang-format off
static const double roots_legendre[] = {
    // n = 2
    1.000000000, -0.577350269,
    1.000000000, +0.577350269,
    // n = 3
    0.555555556, -0.774596669,
    0.888888889, +0.000000000,
    0.555555556, +0.774596669,
    // n = 4
    0.347854845, -0.861136312,
    0.652145155, -0.339981044,
    0.652145155, +0.339981044,
    0.347854845, +0.861136312,
    // n = 5
    0.236926885, -0.906179846,
    0.478628670, -0.538469310,
    0.568888889, +0.000000000,
    0.478628670, +0.538469310,
    0.236926885, +0.906179846,
    // n = 6
    0.171324492, -0.932469514,
    0.360761573, -0.661209386,
    0.467913935, -0.238619186,
    0.467913935, +0.238619186,
    0.360761573, +0.661209386,
    0.171324492, +0.932469514,
};
// clang-format on

double quad_gl(double (*f)(double), int n, double a, double b) {
    double sum = 0.0;
    double h_a_plus_b = (a + b) / 2;
    double h_b_minus_a = (b - a) / 2;
    int tbl_offset = (n - 2) * (n + 1);

    for (int i = tbl_offset; i < tbl_offset + 2 * n; i += 2) {
        double wi = roots_legendre[i];
        double xi = roots_legendre[i + 1];
        double xi_norm = h_a_plus_b + h_b_minus_a * xi;

        sum += wi * f(xi_norm);
    }

    return h_b_minus_a * sum;
}
