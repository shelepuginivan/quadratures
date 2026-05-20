// https://en.wikipedia.org/wiki/Newton%E2%80%93Cotes_formulas

#ifndef QUAD_NEWTON_COTES_TBL_H
#define QUAD_NEWTON_COTES_TBL_H

#define QUAD_TBL_CHECK_NC_CLOSED(n) ((n) >= 1 && (n) <= 6)
#define QUAD_TBL_CHECK_NC_OPEN(n) ((n) >= 1 && (n) <= 4)
#define QUAD_TBL_OFFSET_NC_CLOSED(n) ((n) * ((n) + 1) / 2 - 1)
#define QUAD_TBL_OFFSET_NC_OPEN(n) ((n) * ((n) - 1) / 2)

// clang-format off

static const int quad_newton_cotes_closed_coef[] = {
    1,  1,                         // n=1 (Trapezoidal)
    1,  4,   1,                    // n=2 (Simpson)
    1,  3,   3,  1,                // n=3 (Simpson 3/8)
    7,  32,  12, 32,  7,           // n=4 (Boole)
    19, 75,  50, 50,  75, 19,      // n=5
    41, 216, 27, 272, 27, 216, 41, // n=6 (Weddle)
};
static const int quad_newton_cotes_closed_denom[] = {0, 2, 6, 8, 90, 288, 840};

static const int quad_newton_cotes_open_coef[] = {
    1,             // n=1 (Rectangular / midpoint)
    1,   1,        // n=2
    2,  -1, 2,     // n=3 (Milne)
    11,  1, 1, 11, // n=4
};
static const int quad_newton_cotes_open_denom[] = {0, 1, 2, 3, 24};

// clang-format on

#endif /* QUAD_NEWTON_COTES_TBL_H */
