#include <float.h>
#include <stdio.h>

#include "runner.h"

int main() {
    QuadRunner r;
    quad_runner_load_defaults(&r);
    quad_runner_load_from_env(&r);

    double res = quad_runner_run(&r);
    printf("%.*g\n", DBL_DECIMAL_DIG, res);

    return 0;
}
