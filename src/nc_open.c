#include "nc_open.h"
#include "tbl_double.h"

double quad_nc_open(double (*f)(double), QuadNCOpenMethod n, double a, double b) {
    double h = (b - a) / (n + 2);
    double sum = 0.0;
    int tbl_s = QUAD_TBL_OFFSET_NC_OPEN(n);

    for (int i = 0; i <= n; i++) {
        sum += quad_newton_cotes_open[tbl_s + i] * f(a + (i + 1) * h);
    }

    return (b - a) * sum;
}

double quad_nc_open_composite(double (*f)(double), QuadNCOpenMethod n, double a, double b, int m) {
    double h = (b - a) / m;
    double sum = 0.0;

    for (int i = 0; i < m; i++) {
        double left = a + (i * h);
        double right = left + h;
        sum += quad_nc_open(f, n, left, right);
    }

    return sum;
}
