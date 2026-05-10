#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "gauss_legendre.h"
#include "newton_cotes.h"
#include "runner.h"

void env_load_double_(const char *name, double *dst);
void env_load_ulong_(const char *name, unsigned long *dst);
void env_load_method_(const char *name, QuadRunnerMethod *dst);
void env_load_f_(const char *name, double (**dst)(double x));

void quad_runner_load_defaults(QuadRunner *r) {
    r->method = QUAD_RUNNER_METHOD_NEWTON_COTES_CLOSED;
    r->f = quad_fn_sin_x_over_sqrt_x;
    r->n = 2;
    r->composite = 1;
    r->a = 0.0;
    r->b = 1.0;
}

void quad_runner_load_from_env(QuadRunner *cfg) {
    env_load_ulong_("QUAD_N", &cfg->n);
    env_load_ulong_("QUAD_COMPOSITE", &cfg->composite);
    env_load_double_("QUAD_A", &cfg->a);
    env_load_double_("QUAD_B", &cfg->b);
    env_load_method_("QUAD_METHOD", &cfg->method);
    env_load_f_("QUAD_FN", &cfg->f);
}

double quad_runner_run(QuadRunner *r) {
    switch (r->method) {
    case QUAD_RUNNER_METHOD_NEWTON_COTES_CLOSED:
        return quad_nc_closed_composite(r->f, r->n, r->a, r->b, r->composite);
    case QUAD_RUNNER_METHOD_NEWTON_COTES_OPEN:
        return quad_nc_open_composite(r->f, r->n, r->a, r->b, r->composite);
    case QUAD_RUNNER_METHOD_GAUSS_LEGENDRE:
        return quad_gl_composite(r->f, r->n, r->a, r->b, r->composite);
    default:
        return NAN;
    }
}

void env_load_double_(const char *name, double *dst) {
    char *envvar = getenv(name);
    if (envvar == NULL) {
        return;
    }

    char *endptr;
    double value = strtod(envvar, &endptr);
    if (endptr == envvar) {
        return;
    }

    *dst = value;
}

void env_load_ulong_(const char *name, unsigned long *dst) {
    char *envvar = getenv(name);
    if (envvar == NULL) {
        return;
    }

    char *endptr;
    unsigned long value = strtoul(envvar, &endptr, 0);
    if (endptr == envvar) {
        return;
    }

    *dst = value;
}

void env_load_method_(const char *name, QuadRunnerMethod *dst) {
    char *m = getenv(name);
    if (m == NULL) {
        return;
    }

    if (strcmp(m, "nc_closed") == 0) {
        *dst = QUAD_RUNNER_METHOD_NEWTON_COTES_CLOSED;
        return;
    }

    if (strcmp(m, "nc_open") == 0) {
        *dst = QUAD_RUNNER_METHOD_NEWTON_COTES_OPEN;
        return;
    }

    if (strcmp(m, "gl") == 0) {
        *dst = QUAD_RUNNER_METHOD_GAUSS_LEGENDRE;
        return;
    }
}

void env_load_f_(const char *name, double (**dst)(double x)) {
    char *v = getenv(name);
    if (v == NULL) {
        return;
    }

    if (strcmp(v, "sin(x)/sqrt(x)") == 0) {
        *dst = quad_fn_sin_x_over_sqrt_x;
    }
}
