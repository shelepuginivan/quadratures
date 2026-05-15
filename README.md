# quadratures

Numerical integration using Newton-Cotes and Gauss-Legendre quadrature rules.


## Building

```sh
make
```

The compiled binary is written to `./build/quadratures`.


## Configuration

Runner is configured via environment variables.

| Variable         | Description                                       | Value                        | Default       |
| ---------------- | ------------------------------------------------- | ---------------------------- | ------------- |
| `QUAD_N`         | Order of the quadrature method                    | _unsigned long_              | `2`           |
| `QUAD_METHOD`    | Quadrature method to use                          | "nc_closed", "nc_open", "gl" | `"nc_closed"` |
| `QUAD_COMPOSITE` | Split `[a, b]` into subintervals (composite rule) | _unsigned long_              | `1`           |
| `QUAD_A`         | Lower bound of integration                        | _double_                     | `0.0`         |
| `QUAD_B`         | Upper bound of integration                        | _double_                     | `1.0`         |
| `QUAD_FN`        | Function to integrate                             | _see below_                  | `"x^2"`       |

`QUAD_METHOD` and `QUAD_N` set a specific quadrature formula to be used. Supported methods and their orders are as follows.

- `QUAD_METHOD=nc_closed`, [closed Newton-Cotes rules](https://en.wikipedia.org/wiki/Newton%E2%80%93Cotes_formulas#Closed_Newton%E2%80%93Cotes_formulas):
  |  N  | Formula     |
  | --- | ----------- |
  | `1` | Trapezoidal |
  | `2` | Simpson     |
  | `3` | Simpson 3/8 |
  | `4` | Boole       |
  | `5` | -           |
  | `6` | Weddle      |

- `QUAD_METHOD=nc_open`, [open Newton-Cotes rules](https://en.wikipedia.org/wiki/Newton%E2%80%93Cotes_formulas#Open_Newton%E2%80%93Cotes_formulas):
  |  N  | Formula                |
  | --- | ---------------------- |
  | `0` | Rectangle, or midpoint |
  | `1` | -                      |
  | `2` | Milne                  |
  | `3` | -                      |

- `QUAD_METHOD=gl`, [Gauss-Legendre rules](https://en.wikipedia.org/wiki/Gauss%E2%80%93Legendre_quadrature): 2, 3, 4, 5, 6.

`QUAD_FN` defines a function to integrate. The following functions are supported:
| Value      | Function                   |
| ---------- | -------------------------- |
| `sin`      | $\sin{x}$                  |
| `tan`      | $\tan{x}$                  |
| `sqrt`     | $\sqrt{x}$                 |
| `sin/sqrt` | $\frac{\sin{x}}{\sqrt{x}}$ |
| `x^2`      | $x^2$                      |
| `x^3`      | $x^3$                      |
| `x^4`      | $x^4$                      |

`QUAD_A` and `QUAD_B` additionally support string literals `pi`, `pi/2`, and `e`.

## Examples

1.  $\int_0^1 x^2 dx$, using Simpson's rule:
    ```sh
    QUAD_N=2 QUAD_METHOD=nc_closed QUAD_FN="x^2" QUAD_A=0 QUAD_B=1 ./build/quadratures
    ```

2.  $\int_0^1 \frac{\sin{x}}{\sqrt{x}} dx$, using open Newton-Cotes formula of order 3:
    ```sh
    QUAD_N=3 QUAD_METHOD=nc_open QUAD_FN="sin/sqrt" QUAD_A=0 QUAD_B=1 ./build/quadratures
    ```

3.  $\int_0^{\pi} x^3 dx$, using Gauss-Legendre formula of order 6, applying composite rule with 10 subintervals:
    ```sh
    QUAD_COMPOSITE=10 QUAD_N=6 QUAD_METHOD=gl QUAD_FN="x^3" QUAD_A=0 QUAD_B=pi ./build/quadratures
    ```
