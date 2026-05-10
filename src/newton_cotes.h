#ifndef QUAD_NEWTON_COTES_H
#define QUAD_NEWTON_COTES_H

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
                                unsigned long m);

typedef enum {
    QUAD_NC_OPEN_METHOD_RECTANGULAR,
    QUAD_NC_OPEN_METHOD_N_1,
    QUAD_NC_OPEN_METHOD_MILNE,
    QUAD_NC_OPEN_METHOD_N_3,
} QuadNCOpenMethod;

double quad_nc_open(double (*f)(double), QuadNCOpenMethod n, double a, double b);
double quad_nc_open_composite(double (*f)(double), QuadNCOpenMethod n, double a, double b,
                              unsigned long m);

#endif /* QUAD_NEWTON_COTES_H */
