#include "nc_open.h"

void quad_nc_open_method_weights(QuadNCOpenMethod n, double *w) {
    switch (n) {
    case QUAD_NC_OPEN_METHOD_RECTANGULAR:
        w[0] = 1.0;
        break;
    case QUAD_NC_OPEN_METHOD_N_1:
        w[0] = 1.0 / 2.0;
        w[1] = 1.0 / 2.0;
        break;
    case QUAD_NC_OPEN_METHOD_MILNE:
        w[0] = 2.0 / 3.0;
        w[1] = -1.0 / 3.0;
        w[2] = 2.0 / 3.0;
        break;
    case QUAD_NC_OPEN_METHOD_N_3:
        w[0] = 11.0 / 24.0;
        w[1] = 1.0 / 24.0;
        w[2] = 1.0 / 24.0;
        w[3] = 11.0 / 24.0;
        break;
    default:
        for (int i = 0; i < QUAD_NC_OPEN_METHOD_ENTRY_NUMBER; i++) {
            w[i] = 0.0;
        }
        break;
    }
}

double quad_nc_open(double (*f)(double), QuadNCOpenMethod n, double a, double b) {
    double w[QUAD_NC_OPEN_METHOD_ENTRY_NUMBER];
    double h = (b - a) / (n + 2);
    double sum = 0.0;

    quad_nc_open_method_weights(n, w);

    for (int i = 0; i <= n; i++) {
        sum += w[i] * f(a + (i + 1) * h);
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
