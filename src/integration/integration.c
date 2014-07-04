/********************

    File: integration.c
    Authror: Yell Bond
    2014

********************/

#ifndef INTEGRATION_C
#define INTEGRATION_C

#define __USE_MINGW_ANSI_STDIO 1 /* Provides correct work with long double in MinGW gcc */

#include <string.h>
#include <ctype.h>
#include <time.h>
#include "ldparser.c"
#include "gq.c"

/* Messages / Errors */
#define VARIABLE_INTERVAL -17
#define NO_SENSE          -18

#define ABS_EPS 1.0e-6L
#define REL_EPS 1.0e-8L
#define MAX_INTERVALS 1e+6

/* Sources for pointers */
static long double a_src;
static long double b_src;
static long double cnst_src;
static int error_a_src;
static int error_b_src;
static int error_f_src;

/* mode: 'G' : integral computed by Gauss-Kronrod rule
         'L' : Gauss-Laguerre
         'H' : Gauss-Hermite
         'C' : f = const
         '+' : I = +infinity 
         '-' : I = -infinity */
typedef struct {
    long double value;
    long double eps;
    int mode;
} IntResult;

/* error_msg: returns message/error of parsing/integration by it's code */
char* error_msg(int code){
    
    static char *temp;

    if(strlen(parse_error_msg(code)) > 0)
        return parse_error_msg(code);

    else if(strlen(integral_error_msg(code)) > 0)
        return integral_error_msg(code);

    else if(code == VARIABLE_INTERVAL)
        temp = "variable interval";

    else if(code == NO_SENSE)
        temp = "integral has no sense";

    else
        temp = "";

    return temp;
}

/* is_inf: returns  1, if s is +oo, oo , +inf , inf (spaces omitted, both capitals letters or not are available in "inf")
                   -1, if s is -oo , -inf (...)
                    0 otherwise */
int is_inf(char *s){

    register int i = 0;
    int sign = 1;
    static char temp[EXPR_LNGTH];
    
    strcpy(temp, s);

    while(isspace(temp[i]))
        i++;

    if(temp[i] == '+')
        i++;

    if(temp[i] == '-'){

        sign = -1;
        i++;
    }

    while(isspace(temp[i]))
        i++;

    if(tolower(temp[i]) == 'i' && tolower(temp[i + 1]) == 'n' && tolower(temp[i + 2]) == 'f'){
    
        i += 3;
        
        while(isspace(temp[i]))
            i++;

        return temp[i] ? 0 : sign;
    }

    else if(temp[i] == 'o' && temp[i + 1] == 'o' ){
   
        i += 2;

        while(isspace(temp[i]))
            i++;

        return temp[i] ? 0 : sign;
    }

    else    
        return 0;
}

void integrate(char *A, char *B, char *f, char var, long double abs_eps, long double rel_eps, int max_intervals, int max_delay, IntResult *result, int *error){

    long double *a, *b, *cnst;
    int *error_f, *error_a, *error_b;
    int is_inf_a = is_inf(A);
    int is_inf_b = is_inf(B);
    int sign_c;

    a = &a_src;
    b = &b_src;
    cnst = &cnst_src;
    error_a = &error_a_src;
    error_b = &error_b_src;
    error_f = &error_f_src;

    result->value = result->eps = 0.0L;
    result->mode = 0;

    /* corectness of input */
    parse(f, var, cnst, error_f);

    if(*error_f != CORRECT_SYNTAX && *error_f != EXPR_IS_CONST){

        *error = *error_f;
        return;
    }

    if(is_inf_a == 0){
        
        parse(A, var, a, error_a);
        
        if(*error_a == CORRECT_SYNTAX){

            *error = VARIABLE_INTERVAL;
            return;
        }

        else if(*error_a != EXPR_IS_CONST){

            *error = *error_a;
            return;
        }
    }

    if(is_inf_b == 0){
        
        parse(B, var, b, error_b);
        
        if(*error_b == CORRECT_SYNTAX){

            *error = VARIABLE_INTERVAL;
            return;
        }

        else if(*error_b != EXPR_IS_CONST){

            *error = *error_b;
            return;
        }
    }

    if(is_inf_a * is_inf_b == 1){

        *error = NO_SENSE;
        return;
    }

    /* f = constant */
    sign_c = (*cnst > 0) ? 1 : -1;

    if(*error_f == EXPR_IS_CONST){

        if(is_inf_a == 0 && is_inf_b == 0){

            result->value = (*cnst) * ((*b) - (*a));
            result->mode = 'C';
            *error = SUCCESS;
            return;
        }

        else if(isless(fabsl(*cnst), MACHINE_EPS)){

            result->mode = 'C';
            *error = SUCCESS;
            return;
        }

        else if(is_inf_b != 0){

            result->mode = ((is_inf_b * sign_c > 0) ? '+' : '-');
            *error = SUCCESS;
            return;
        }

        else{

            result->mode = ((is_inf_a * sign_c > 0) ? '-' : '+');
            *error = SUCCESS;
            return;
        }
    }

    /* f is not constant */
    parse(f, var, cnst, error_f);

    if(is_inf_a == 0 && is_inf_b == 0){
        
        if(isgreater(*b, *a))
            result->value = gq_kronrod(*a, *b, abs_eps, rel_eps, max_intervals, max_delay, error, cnst);
        else
            result->value = -1.0L * gq_kronrod(*b, *a, abs_eps, rel_eps, max_intervals, max_delay, error, cnst);

        result->eps = *cnst;
        result->mode = 'G';
        return;
    }    

    else if(is_inf_a == 0 && is_inf_b != 0){

        result->mode = 'L';
        result->eps = (long double)is_inf_b * gq_laguerre(*a, is_inf_b, 512, error);
        
        if(*error != SUCCESS)
            return;

        result->value = (long double)is_inf_b * gq_laguerre(*a, is_inf_b, 1024, error);
        result->eps = fabsl(result->value - result->eps);
            return;
    }    

    else if(is_inf_a != 0 && is_inf_b == 0){

        result->mode = 'L';
        result->eps = -1.0L * (long double)is_inf_a * gq_laguerre(*a, is_inf_a, 512, error);
        
        if(*error != SUCCESS)
            return;

        result->value = -1.0L * (long double)is_inf_a * gq_laguerre(*a, is_inf_a, 1024, error);
        result->eps = fabsl(result->value - result->eps);
            return;
    }
    
    else{

        result->mode = 'H';
        result->eps = (long double)is_inf_b * gq_hermite(1024, error);
        
        if(*error != SUCCESS)
            return;

        result->value = (long double)is_inf_b * gq_hermite(2048, error);
        result->eps = fabsl(result->value - result->eps);
            return;

    }
}

#endif