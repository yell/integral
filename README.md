# Gaussian quadrature

This application created for numerical integration using [Gaussian quadrature](http://en.wikipedia.org/wiki/Gaussian_quadrature).  
Parser and integration parts are written in C  
Interface created in Qt 5.2.1  
Application is optimized for Windows 7 1366x768. There aren't any other tests yet.

### Parser

#### operations  `+  -  *  /  ^`  
#### variables  `p q r s t u v w x y z`  
#### math constants  `e pi`  
#### functions

 - **sin x**  
 - **cos x**  
 - **tg x** or **tan x**  
 - **ctg x** or **cot x**  
 - **sec x**  
 - **cosec x** or **csc x**  
 - **arcsin x** or **asin x**  
 - **arccos x** or **acos x**  
 - **arctg x** or **arctan x** or **atan x**  
 - **arcctg x** or **arccot x** or **acot x**  
 - **sh x** or **sinh x**  
 - **ch x** or **cosh x**  
 - **th x** or **tanh x**  
 - **cth x** or **coth x**  
 - **arsh x** or **arsinh x**  
 - **arch x** or **arcosh x**  
 - **arth x** or **artanh x**  
 - **arcth x** or **arcoth x**  
 - **exp x**  
 - **ln x** or **log x**  
 - **sqrt x**  
 - **cbrt x** // cubic root, **x** any  
 - **abs x** or **|x|**  
 - **floor x** // integer part of **x**  
 - **sign x** or **sgn x**  
 - **min(x; y)**  
 - **max(x; y)**  
 - **pow(x; y)** = **x ^ y** 
 - **gamma x** // Euler's gamma function, **x** > 0  
 - **lgamma x** = **ln( gamma x )**  
 - **erf x** // error function  
 - **bessel_j(n; x)** // Bessel's function of the first kind, **n** - integer  
 - **jO x** or **j_O x** // Bessel's function of the first kind (**n** = 0)  
 - **bessel_y(n; x)** // Bessel's function of the second kind, **n** - integer, **x** > 0  
 - **yO x** or **y_O x** // Bessel's function of the second kind (**n** = 0), **x** > 0  

#### specifications

 * Default max expression length is **128** characters  
 * Default max token length is **45** characters  
 * If |**value**| > **10 ^ 45**, **value** considered as *infinity*  
 * You can omit * (multiplication sign), where it is possible:    
     **2e** , **2 e** , **x x** , **2(5 - 6)pi** , **(2 + e)(1 - 2)** , **x sin1** will be parsed successfully    
     **ee** , **xx** , **xsin1**, **|1 - 2||2 - 1|** will cause an error (try not to omit * with abs brackets)  
 * **[ ]** brackets are understood as **( )** brackets  
 * You can omit brackets, where it is possible:  
     **sin x** , **sin1** , **ln sin x - exp-x** will be understood as **sin( x)** , **sin(1)** and **ln( sin( x)) - exp(-x)**  

### Integration
    
* Improper integrals (**-inf** ; **+inf**) are computed using 1024- and 2048-nodes [Gauss-Hermite quadrature](http://en.wikipedia.org/wiki/Gauss-Hermite_quadrature). Integral value considering as 2048-nodes quadrature value and computing error as difference between quadrature values.
* Improper integrals (**a** ; **+inf**) and (**-inf** ; **a**) are computed using 512- and 1024-nodes [Gauss-Laguerre quadrature](http://en.wikipedia.org/wiki/Gauss-Laguerre_quadrature). Integral value considering as 1024-nodes quadrature value and computing error as difference between quadrature values. 
* Finite domain integrals (**a** ; **b**) are computed using G25 K51 [Gauss-Kronrod quadrature](http://en.wikipedia.org/wiki/Gauss-Kronrod_quadrature) with interval subdivision. Computation finishes, when **|G - K|** < **max(1.0e-6 ; 1.0e-8 * |G|)**, where **G** - Gauss quadrature value and **K** - Kronrod quadrature value. Integral value considering as **K**. In this app you can choose computation time between **3**, **15** and **90** seconds.

### How to get

Compile files as a Qt project using QtCreator or download application  [here](https://downloads.sourceforge.net/project/gaussianquadrature/GQ%20Setup.rar?r=https%3A%2F%2Fsourceforge.net%2Fprojects%2Fgaussianquadrature%2F%3Fsource%3Dnavbar&ts=1404579639&use_mirror=cznic).

### Usage

You can also use parser and integrator in your C/C++ programs:  
```
#include "ldparser.c"
```
- `void parse(char *expression, int var, long double *const_value, int *error)`  
parses `*expression` assuming the variable is `var`. If `*expression` is constant, it's value is stored in `*const_value`.
- `char* parse_error_msg(int code)` returns message by the code of the parsing error/message
- after successful parsing of expression you can computate it in different variable values by  
`long double computate(long double x, int *error)` (`x` - variable of expression)
```
#include "integration.c"
```
- integration can be performed by `void integrate(char *A, char *B, char *f, char var, long double abs_eps, long double rel_eps, int max_intervals, int max_delay, IntResult *result, int *error)`. (`*A` ; `*B`) - domain; `*f` - function; `var` - variable;
```
typedef struct {
    long double value;
    long double eps;
    int mode;
} IntResult;
```
- `char* error_msg(int code)` returns message by the code of the parsing/integration error/message  
  
Note that parser and integrator are using `long double`. And if you use MinGW gcc and have problems with them, try inserting this line in top of your program: 
```
#define __USE_MINGW_ANSI_STDIO 1
```

### Screenshots
--
![1](https://github.com/monstaHD/integral/raw/desktop/screens/1.png)
--
![2](https://github.com/monstaHD/integral/raw/desktop/screens/2.png)
--
![3](https://github.com/monstaHD/integral/raw/desktop/screens/3.png)
--
![4](https://github.com/monstaHD/integral/raw/desktop/screens/4.png)
--
![5](https://github.com/monstaHD/integral/raw/desktop/screens/5.png)
--
 
Finally, all of your computations will be stored in **C:\gq_log.txt**:
```
1 dz, z from 0 to +inf
	Message      : success
	Elapsed Time : 0 (3000) ms
	Value = +Infinity
----------------------------------------------------------------
1/Gamma[z] dz, z from 0 to +oo
	Message      : success
	Elapsed Time : 73 (3000) ms
	Value    = 2.80777024202851936576612323914759
	Abs. Eps = 0.00000000000000000065052130349130
----------------------------------------------------------------
ln sin t dt, t from 0 to Pi
	Message      : computation timed out
	Elapsed Time : 3001 (3000) ms
	Value    = -2.17758252981168809025297461445803
	Abs. Eps = 0.00002027770699960227719638172772
----------------------------------------------------------------
arcsin 2 dz, z from 0 to 1
	Message : domain error
----------------------------------------------------------------
ln sin t dt, t from 0 to Pi
	Message      : success
	Elapsed Time : 62131 (90000) ms
	Value    = -2.17758597903822972096342380776690
	Abs. Eps = 0.00000063367834371918715929972166
```
