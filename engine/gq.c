/********************

    File: gq.c
    Authror: Yell Bond
    2014

********************/

#ifndef GQ_C
#define GQ_C

#define __USE_MINGW_ANSI_STDIO 1 /* Provides correct work with long double in MinGW gcc */

// #include <time.h>
#include <ctime>
#include "ldparser.c"
#include "nodes.c"

/* Messages / Errors */
#define SUCCESS             2
#define INTEGRAL_INF      -13
#define INCORRECT_N       -14
#define MAX_INTERVALS_ERR -15
#define MAX_DELAY_ERR     -16

/* integral_error_msg: returns message/error of integration by it's code */
char* integral_error_msg(int code){

    static char *temp;

    switch(code){

        case SUCCESS           : temp = "success";                            break;
        case INTEGRAL_INF      : temp = "integral is too big";                break;
        case INCORRECT_N       : temp = "incorrect n in Laguerre or Hermite"; break;
        case MAX_INTERVALS_ERR : temp = "max interval subdivision";           break;
        case MAX_DELAY_ERR     : temp = "computation timed out";              break;

        default : temp = "";
    }

    return temp;
}

/* gq_kronrod: computes integreal on finite domain (A; B) until:
               - |G-K| < max(abs_eps; rel_eps * |K|) or
               - computation time reached max_delay or
               - amount of intervals subdivision reached max_intervals
               and gives corresponding message */
long double gq_kronrod(long double A, long double B, long double abs_eps, long double rel_eps, int max_intervals, int max_delay, int *error, long double *real_eps){

    long double G = 0.0L; /* Gauss value*/
    long double K = 0.0L; /* Gauss-Kronrod value */
    long double a, b, temp1, temp2, h, G_prev, K_prev;
    register int i, j;
    int n = 1;  /* amount of intervals */

    clock_t index = clock();
    *real_eps = 0.0L;

    do{

        G_prev = G;
        K_prev = K;

        G = K = 0.0L;

        for(j = 0, h = (B - A)/n; j < n; j++){

            a = A + h * j;
            b = A + h * (j + 1);

            temp1 = computate( (a + b)/2.0L, error);

            if(*error != CORRECT_SYNTAX)
                    return 0.0L;

            K = K + temp1 * GK[0].wk;
            G = G + temp1 * GK[0].wg;

            for(i = 1; i < 26; i++){

                temp1 = computate(-GK[i].x * (b - a)/2.0L + (a + b)/2.0L, error);

                if(*error != CORRECT_SYNTAX)
                    return 0.0L;

                temp2 = computate(GK[i].x * (b - a)/2.0L + (a + b)/2.0L, error);

                if(*error != CORRECT_SYNTAX)
                    return 0.0L;

                K = K + (temp1 + temp2) * GK[i].wk;

                if(i % 2 == 0)
                    G = G + (temp1 + temp2) * GK[i].wg;

                if(isinf(G) || isinf(K)){

                    *error = INTEGRAL_INF;
                    return 0.0L;
                }

                if((int)(clock() - index) > max_delay){

                    *error = MAX_DELAY_ERR;
                    *real_eps = fabsl(K_prev - G_prev);
                    return K_prev;
                }    
            }
        }

        K *= (b - a) / 2.0L;
        G *= (b - a) / 2.0L;

        if(isinf(G) || isinf(K)){

            *error = INTEGRAL_INF;
            return 0.0L;
        }

        n *= 2;

    }while(fabsl(G - K) >= fmaxl(abs_eps, rel_eps * fabsl(K)) && n/2 < max_intervals);

    n = n/2;

    *error = ((n >= max_intervals) ? MAX_INTERVALS_ERR : SUCCESS);

    *real_eps = fabsl(K - G);
    
    return K;
}


/* gq_laguerre: computes improper integral of the first kind
                direct:  1 <=> (   A; +inf) 
                        -1 <=> (-inf;    A)
                n is 512 or 1024  */
long double gq_laguerre(long double A, int direct, int n, int *error){

    long double sum = 0.0L;
    long double temp;
    register int i;

    switch(n){

        case 512 : {
                        for(i = 0; i < 512; i++){

                            temp = computate(A + (long double)direct * L[i].x, error);

                            if(*error != CORRECT_SYNTAX)
                                return 0.0L;

                            sum = sum + temp * L[i].w;

                            if(isinf(sum)){

                                *error = INTEGRAL_INF;
                                return 0.0L;
                            }
                        }

                        *error = SUCCESS;
                        return sum;
        }

        case 1024 : {
                        for(i = 0; i < 1024; i++){

                            temp = computate(A + (long double)direct * LL[i].x, error);

                            if(*error != CORRECT_SYNTAX)
                                return 0.0L;

                            sum = sum + temp * LL[i].w;

                            if(isinf(sum)){

                                *error = INTEGRAL_INF;
                                return 0.0L;
                            }
                        }

                        *error = SUCCESS;
                        return sum;
        }

        default : {

            *error = INCORRECT_N;
            return 0.0L;
        }
    }
}

/* gq_hermite: computes (-inf; +inf) integral;
               n is 1024 or 2048 */
long double gq_hermite(int n, int *error){

    long double sum = 0.0L;
    long double temp1, temp2;
    register int i;

    switch(n){

        case 1024 : {
                        for(i = 0; i < 512; i++){

                            temp1 = computate(H[i].x, error);
                            
                            if(*error != CORRECT_SYNTAX)
                                return 0.0L;

                            temp2 = computate(-H[i].x, error);
                            
                            if(*error != CORRECT_SYNTAX)
                                return 0.0L;

                            sum = sum + ( temp1 + temp2 ) * H[i].w;

                            if(isinf(sum)){

                                *error = INTEGRAL_INF;
                                return 0.0L;
                            }
                        }

                        *error = SUCCESS;
                        return sum;
        }

        case 2048 : {
                        for(i = 0; i < 1024; i++){

                            temp1 = computate(HH[i].x, error);
                            
                            if(*error != CORRECT_SYNTAX)
                                return 0.0L;

                            temp2 = computate(-HH[i].x, error);
                            
                            if(*error != CORRECT_SYNTAX)
                                return 0.0L;

                            sum = sum + ( temp1 + temp2 ) * HH[i].w;

                            if(isinf(sum)){

                                *error = INTEGRAL_INF;
                                return 0.0L;
                            }
                        }

                        *error = SUCCESS;
                        return sum;
        }

        default : {
            
            *error = INCORRECT_N;
            return 0.0L;
        }
    }
}

#endif