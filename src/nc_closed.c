#include "nc_closed.h"

void quad_nc_closed_weights(int n, double *w) {
    switch (n) {
    case 1:
        w[0] = 1.0 / 2.0;
        w[1] = 1.0 / 2.0;
        break;
    case 2:
        w[0] = 1.0 / 6.0;
        w[1] = 4.0 / 6.0;
        w[2] = 1.0 / 6.0;
        break;
    case 3:
        w[0] = 1.0 / 8.0;
        w[1] = 3.0 / 8.0;
        w[2] = 3.0 / 8.0;
        w[3] = 1.0 / 8.0;
        break;
    case 4:
        w[0] = 7.0 / 90.0;
        w[1] = 32.0 / 90.0;
        w[2] = 12.0 / 90.0;
        w[3] = 32.0 / 90.0;
        w[4] = 7.0 / 90.0;
        break;
    }
}
