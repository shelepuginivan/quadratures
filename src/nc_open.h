#ifndef QUAD_NC_OPEN_H
#define QUAD_NC_OPEN_H

typedef enum {
    QUAD_NC_OPEN_METHOD_RECTANGULAR,
    QUAD_NC_OPEN_METHOD_N_1,
    QUAD_NC_OPEN_METHOD_MILNE,
    QUAD_NC_OPEN_METHOD_N_3,
} QuadNCOpenMethod;

double quad_nc_open(double (*f)(double), QuadNCOpenMethod n, double a, double b);
double quad_nc_open_composite(double (*f)(double), QuadNCOpenMethod n, double a, double b, int m);

#endif /* QUAD_NC_OPEN_H */
