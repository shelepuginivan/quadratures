#ifndef QUAD_NC_OPEN_H
#define QUAD_NC_OPEN_H

typedef enum {
    QUAD_NC_OPEN_METHOD_RECTANGULAR = 0,
    QUAD_NC_OPEN_METHOD_N_1 = 1,
    QUAD_NC_OPEN_METHOD_MILNE = 2,
    QUAD_NC_OPEN_METHOD_N_3 = 3,

    QUAD_NC_OPEN_METHOD_ENTRY_NUMBER,
} QuadNCOpenMethod;

void quad_nc_open_method_weights(QuadNCOpenMethod n, double *w);
double quad_nc_open(double (*f)(double), QuadNCOpenMethod n, double a, double b);
double quad_nc_open_composite(double (*f)(double), QuadNCOpenMethod n, double a, double b, int m);

#endif /* QUAD_NC_OPEN_H */
