#ifndef QUAD_NEWTON_COTES_TBL_H
#define QUAD_NEWTON_COTES_TBL_H

#define QUAD_TBL_OFFSET_NC_CLOSED(n) ((n) * ((n) + 1) / 2 - 1)
#define QUAD_TBL_OFFSET_NC_OPEN(n) ((n) * ((n) + 1) / 2)

// clang-format off

// https://en.wikipedia.org/wiki/Newton%E2%80%93Cotes_formulas
static const double quad_newton_cotes_closed[] = {
    // n = 1 (Trapezoidal)
    1.0 / 2.0,
    1.0 / 2.0,
    // n = 2 (Simpson)
    1.0 / 6.0,
    4.0 / 6.0,
    1.0 / 6.0,
    // n = 3 (Simpson 3/8)
    1.0 / 8.0,
    3.0 / 8.0,
    3.0 / 8.0,
    1.0 / 8.0,
    // n = 4 (Boole)
     7.0 / 90.0,
    32.0 / 90.0,
    12.0 / 90.0,
    32.0 / 90.0,
     7.0 / 90.0,
    // n = 5
    19.0 / 288.0,
    75.0 / 288.0,
    50.0 / 288.0,
    50.0 / 288.0,
    75.0 / 288.0,
    19.0 / 288.0,
    // n = 6 (Weddle)
     41.0 / 840.0,
    216.0 / 840.0,
     27.0 / 840.0,
    272.0 / 840.0,
     27.0 / 840.0,
    216.0 / 840.0,
     41.0 / 840.0,
};

static const double quad_newton_cotes_open[] = {
    // n = 0 (Rectangular / midpoint)
    1.0,
    // n = 1
    1.0 / 2.0,
    1.0 / 2.0,
    // n = 2 (Milne)
     2.0 / 3.0,
    -1.0 / 3.0,
     2.0 / 3.0,
    // n = 3
    11.0 / 24.0,
     1.0 / 24.0,
     1.0 / 24.0,
    11.0 / 24.0,
};

// clang-format on

#endif /* QUAD_NEWTON_COTES_TBL_H */
