#ifndef QUAD_GAUSS_LEGENDRE_H
#define QUAD_GAUSS_LEGENDRE_H

double quad_gl(double (*f)(double), int n, double a, double b);
double quad_gl_composite(double (*f)(double), int n, double a, double b, unsigned long m);

#endif /* QUAD_GAUSS_LEGENDRE_H */
