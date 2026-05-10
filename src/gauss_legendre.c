#include "gauss_legendre.h"
#include "gauss_legendre_tbl.h"

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

double quad_gl_composite(double (*f)(double), int n, double a, double b, unsigned long m) {
    double sum = 0.0;
    double h = (b - a) / m;

    for (unsigned long i = 0; i < m; i++) {
        double left = a + i * h;
        double right = left + h;
        sum += quad_gl(f, n, left, right);
    }

    return sum;
}
