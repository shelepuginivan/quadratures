#ifndef QUAD_NC_CLOSED_H
#define QUAD_NC_CLOSED_H

typedef enum {
    QUAD_NC_CLOSED_METHOD_TRAPEZOIDAL = 1,
    QUAD_NC_CLOSED_METHOD_SIMPSON,
    QUAD_NC_CLOSED_METHOD_SIMPSON_3_8,
    QUAD_NC_CLOSED_METHOD_BOOLE,
    QUAD_NC_CLOSED_METHOD_N_5,
    QUAD_NC_CLOSED_METHOD_WEDDLE,
} QuadNCClosedMethod;

double quad_nc_closed(double (*f)(double), QuadNCClosedMethod n, double a, double b);
double quad_nc_closed_composite(double (*f)(double), QuadNCClosedMethod n, double a, double b,
                                int m);

#endif /* QUAD_NC_CLOSED_H */
