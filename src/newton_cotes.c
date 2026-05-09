#include "newton_cotes.h"
#include "newton_cotes_tbl.h"

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
