#ifndef QUAD_NC_CLOSED_H
#define QUAD_NC_CLOSED_H

void quad_nc_closed_weights(int n, double *w);
double quad_nc_closed(double (*f)(double), double a, double b, int n);

#endif /* QUAD_NC_CLOSED_H */
