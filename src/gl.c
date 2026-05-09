#include "gl.h"
#include "tbl_double.h"

double quad_gl(double (*f)(double), int n, double a, double b) {
    double sum = 0.0;
    double h_a_plus_b = (a + b) / 2;
    double h_b_minus_a = (b - a) / 2;

    int tbl_s = QUAD_TBL_OFFSET_LEGENDRE(n);
    int tbl_e = tbl_s + 2 * n;

    for (int i = tbl_s; i < tbl_e; i += 2) {
        double wi = quad_roots_legendre[i];
        double xi = quad_roots_legendre[i + 1];
        double xi_norm = h_a_plus_b + h_b_minus_a * xi;

        sum += wi * f(xi_norm);
    }

    return h_b_minus_a * sum;
}
