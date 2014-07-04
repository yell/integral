# Gaussian quadrature

This application created for numerical integration using [Gaussian quadrature](http://en.wikipedia.org/wiki/Gaussian_quadrature) rule.  
Parser and integration parts are written in C  
Interface created in Qt 5.2.1  

## Parser

#### operations  `+  -  *  /  ^`  
#### variables `p q r s t u v w x y z`  
#### math constants `e pi`  
#### functions:

  **sin x**  
  **cos x**  
  **tg x** or **tan x**  
  **ctg x** or **cot x**  
  **sec x**  
  **cosec x** or **csc x**  
  
  **arcsin x** or **asin x**  
  **arccos x** or **acos x**  
  **arctg x** or **arctan x** or **atan x**  
  **arcctg x** or **arccot x** or **acot x**  
    
  **sh x** or **sinh x**  
  **ch x** or **cosh x**  
  **th x** or **tanh x**  
  **cth x** or **coth x**  
    
  **arsh x** or **arsinh x**  
  **arch x** or **arcosh x**  
  **arth x** or **artanh x**  
  **arcth x** or **arcoth x**  
    
  **exp x**  
  **ln x** or **log x**  
  **sqrt x**  
  **cbrt x** // cubic root, **x** any  
  **abs x** or **|x|**  
  **floor x** // integer part of **x**  
  **sign x** or **sgn x**  
  **min(x; y)**  
  **max(x; y)**  
  **pow(x; y)** = **x ^ y** 
    
  **gamma x** // Euler's gamma function, **x** > 0  
  **lgamma x** = **ln( gamma x )**  
  **erf x** // error function  
  **bessel_j(n; x)** // Bessel's function of the first kind, **n** - integer  
  **jO x** or **j_O x** // Bessel's function of the first kind (**n** = 0)  
  **bessel_y(n; x)** // Bessel's function of the second kind, **n** - integer, **x** > 0  
  **yO x** or **y_O x** // Bessel's function of the second kind (**n** = 0), **x** > 0  

###specifications

* Default max expression length is **128** characters
* Default max token length is **45** characters
* If |*value*| > 10^45, *value* considered as *infinity*
* You can omit * (multiplication sign), where it is possible:  
    **2e** , **2 e** , **x x** , **2(5 - 6)pi** , **(2 + e)(1 - 2)** , **x sin1** will be parsed successfully  
    **ee** , **xx** , **xsin1**, **|1 - 2||2 - 1|** will cause an error (try not to omit * with abs brackets) 
* **[ ]** brackets are understood as **( )** brackets
* You can omit brackets, where it is possible:  
    **sin x** , **sin1** , **ln sin x - exp-x** will be understood as **sin( x)** , **sin(1)** and **ln( sin( x)) - exp(-x)**
  

    



