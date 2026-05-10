#ifndef QUAD_RUNNER_H
#define QUAD_RUNNER_H

#include "newton_cotes.h"

typedef enum {
    QUAD_RUNNER_METHOD_NEWTON_COTES_CLOSED,
    QUAD_RUNNER_METHOD_NEWTON_COTES_OPEN,
    QUAD_RUNNER_METHOD_GAUSS_LEGENDRE,
} QuadRunnerMethod;

typedef struct {
    QuadRunnerMethod method;
    unsigned long n;
    unsigned long composite;
    double a;
    double b;
    double (*f)(double x);
} QuadRunner;

void quad_runner_load_defaults(QuadRunner *r);
void quad_runner_load_from_env(QuadRunner *r);

double quad_runner_run(QuadRunner *r);

#endif /* QUAD_RUNNER_H */
