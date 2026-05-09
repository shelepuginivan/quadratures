#include "nc_closed.h"
#include "tbl_double.h"

double quad_nc_closed(double (*f)(double), QuadNCClosedMethod n, double a, double b) {
    double h = (b - a) / n;
    double sum = 0.0;
    int tbl_s = QUAD_TBL_OFFSET_NC_CLOSED(n);

    for (int i = 0; i <= n; i++) {
        sum += quad_newton_cotes_closed[tbl_s + i] * f(a + i * h);
    }

    return (b - a) * sum;
}

double quad_nc_closed_composite(double (*f)(double), QuadNCClosedMethod n, double a, double b,
                                int m) {
    double h = (b - a) / m;
    double sum = 0.0;

    for (int i = 0; i < m; i++) {
        double left = a + (i * h);
        double right = left + h;
        sum += quad_nc_closed(f, n, left, right);
    }

    return sum;
}
