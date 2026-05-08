#ifndef QUAD_NC_CLOSED_H
#define QUAD_NC_CLOSED_H

typedef enum {
    QUAD_CLOSED_METHOD_TRAPEZOIDAL = 1,
    QUAD_CLOSED_METHOD_SIMPSON = 2,
    QUAD_CLOSED_METHOD_SIMPSON_3_8 = 3,
    QUAD_CLOSED_METHOD_BOOLE = 4,

    QUAD_CLOSED_METHOD_ENTRY_NUMBER,
} QuadNCClosedMethod;

void quad_nc_closed_method_weights(QuadNCClosedMethod n, double *w);
double quad_nc_closed(double (*f)(double), QuadNCClosedMethod n, double a, double b);
double quad_nc_closed_composite(double (*f)(double), QuadNCClosedMethod n, double a, double b,
                                int m);

#endif /* QUAD_NC_CLOSED_H */
