#include <math.h>

#include "newton_cotes.h"
#include "newton_cotes_tbl.h"
#include "utils.h"

double quad_nc_closed(double (*f)(double), QuadNCClosedMethod n, double a, double b) {
    if (!QUAD_TBL_CHECK_NC_CLOSED(n)) {
        return NAN;
    }

    double sum = 0.0;
    double c = 0.0;
    double b_minus_a = b - a;
    double h = b_minus_a / n;
    double denom = (double)quad_newton_cotes_closed_denom[n];
    int tbl_s = QUAD_TBL_OFFSET_NC_CLOSED(n);

    for (int i = 0; i <= (int)n; i++) {
        double xi = fma((double)i, h, a);
        double t = f(xi) * quad_newton_cotes_closed_coef[tbl_s + i] / denom;
        quad_kahan_sum(&sum, &c, t);
    }

    return fma(b_minus_a, sum, b_minus_a * c);
}

double quad_nc_closed_composite(double (*f)(double), QuadNCClosedMethod n, double a, double b,
                                unsigned long m) {
    if (!QUAD_TBL_CHECK_NC_CLOSED(n)) {
        return NAN;
    }

    double h = (b - a) / m;
    double sum = 0.0;
    double c = 0.0;

    for (unsigned long i = 0; i < m; i++) {
        double left = fma((double)i, h, a);
        double right = left + h;
        double sub = quad_nc_closed(f, n, left, right);
        quad_kahan_sum(&sum, &c, sub);
    }

    return sum + c;
}

double quad_nc_open(double (*f)(double), QuadNCOpenMethod n, double a, double b) {
    if (!QUAD_TBL_CHECK_NC_OPEN(n)) {
        return NAN;
    }

    double sum = 0.0;
    double c = 0.0;
    double b_minus_a = b - a;
    double h = b_minus_a / (n + 1);
    double denom = (double)quad_newton_cotes_open_denom[n];
    int tbl_s = QUAD_TBL_OFFSET_NC_OPEN(n);

    for (int i = 0; i < (int)n; i++) {
        double xi = fma((double)(i + 1), h, a);
        double t = f(xi) * quad_newton_cotes_open_coef[tbl_s + i] / denom;
        quad_kahan_sum(&sum, &c, t);
    }

    return fma(b_minus_a, sum, b_minus_a * c);
}

double quad_nc_open_composite(double (*f)(double), QuadNCOpenMethod n, double a, double b,
                              unsigned long m) {
    if (!QUAD_TBL_CHECK_NC_OPEN(n)) {
        return NAN;
    }

    double h = (b - a) / m;
    double sum = 0.0;
    double c = 0.0;

    for (unsigned long i = 0; i < m; i++) {
        double left = fma((double)i, h, a);
        double right = left + h;
        double sub = quad_nc_open(f, n, left, right);
        quad_kahan_sum(&sum, &c, sub);
    }

    return sum + c;
}
