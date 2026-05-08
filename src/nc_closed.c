#include "nc_closed.h"

void quad_nc_closed_method_weights(QuadNCClosedMethod n, double *w) {
    switch (n) {
    case QUAD_NC_CLOSED_METHOD_TRAPEZOIDAL:
        w[0] = 1.0 / 2.0;
        w[1] = 1.0 / 2.0;
        break;
    case QUAD_NC_CLOSED_METHOD_SIMPSON:
        w[0] = 1.0 / 6.0;
        w[1] = 4.0 / 6.0;
        w[2] = 1.0 / 6.0;
        break;
    case QUAD_NC_CLOSED_METHOD_SIMPSON_3_8:
        w[0] = 1.0 / 8.0;
        w[1] = 3.0 / 8.0;
        w[2] = 3.0 / 8.0;
        w[3] = 1.0 / 8.0;
        break;
    case QUAD_NC_CLOSED_METHOD_BOOLE:
        w[0] = 7.0 / 90.0;
        w[1] = 32.0 / 90.0;
        w[2] = 12.0 / 90.0;
        w[3] = 32.0 / 90.0;
        w[4] = 7.0 / 90.0;
        break;
    case QUAD_NC_CLOSED_METHOD_N_5:
        w[0] = 19.0 / 288.0;
        w[1] = 75.0 / 288.0;
        w[2] = 50.0 / 288.0;
        w[3] = 50.0 / 288.0;
        w[4] = 75.0 / 288.0;
        w[5] = 19.0 / 288.0;
        break;
    case QUAD_NC_CLOSED_METHOD_WEDDLE:
        w[0] = 41.0 / 840.0;
        w[1] = 216.0 / 840.0;
        w[2] = 27.0 / 840.0;
        w[3] = 272.0 / 840.0;
        w[4] = 27.0 / 840.0;
        w[5] = 216.0 / 840.0;
        w[6] = 41.0 / 840.0;
        break;
    default:
        for (int i = 0; i < QUAD_NC_CLOSED_METHOD_ENTRY_NUMBER; i++) {
            w[i] = 0.0;
        }
        break;
    }
}

double quad_nc_closed(double (*f)(double), QuadNCClosedMethod n, double a, double b) {
    double w[QUAD_NC_CLOSED_METHOD_ENTRY_NUMBER];
    double h = (b - a) / n;
    double sum = 0.0;

    quad_nc_closed_method_weights(n, w);

    for (int i = 0; i <= n; i++) {
        sum += w[i] * f(a + i * h);
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
