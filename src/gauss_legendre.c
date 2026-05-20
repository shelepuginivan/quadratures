#include <math.h>

#include "gauss_legendre.h"
#include "gauss_legendre_tbl.h"
#include "utils.h"

double quad_gl(double (*f)(double), int n, double a, double b) {
    if (!QUAD_TBL_CHECK_LEGENDRE(n)) {
        return NAN;
    }

    double sum = 0.0;
    double c = 0.0;
    double h_a_plus_b = (a + b) / 2;
    double h_b_minus_a = (b - a) / 2;

    int tbl_s = QUAD_TBL_OFFSET_LEGENDRE(n);
    int tbl_e = tbl_s + 2 * n;

    for (int i = tbl_s; i < tbl_e; i += 2) {
        double wi = quad_roots_legendre[i];
        double xi = quad_roots_legendre[i + 1];
        double xi_norm = fma(xi, h_b_minus_a, h_a_plus_b);

        double term = wi * f(xi_norm);
        quad_kahan_sum(&sum, &c, term);
    }

    return fma(h_b_minus_a, sum, h_b_minus_a * c);
}

double quad_gl_composite(double (*f)(double), int n, double a, double b, unsigned long m) {
    if (!QUAD_TBL_CHECK_LEGENDRE(n)) {
        return NAN;
    }

    double sum = 0.0;
    double c = 0.0;
    double h = (b - a) / m;

    for (unsigned long i = 0; i < m; i++) {
        double left = fma(h, i, a);
        double right = left + h;
        double sub = quad_gl(f, n, left, right);
        quad_kahan_sum(&sum, &c, sub);
    }

    return sum + c;
}
