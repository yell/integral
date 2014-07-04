#ifndef LDPARSER_C
#define LDPARSER_C 

#define __USE_MINGW_ANSI_STDIO 1 /* Provides correct work with long double in MinGW gcc */

#include <ctype.h>
#include <string.h>
#include <math.h> 
#include <stdlib.h>

/* Token-check macro */
#define is_variable(c)  (c == variable)
#define is_bracket(c)   (c == '(' || c == ')')
#define is_operator(c)  (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '$')
#define is_delimiter(c) (c == ',' || c == ';')

#define cmp(s, t) (!strcmp(s, t))

#define is_trigonometric(s)     ( cmp(s, "sin") || cmp(s, "cos") || cmp(s, "tg") || cmp(s, "tan") || cmp(s, "ctg") || cmp(s, "cot") || cmp(s, "sec") || cmp(s, "cosec") || cmp(s, "csc") )
#define is_inv_trigonometric(s) ( cmp(s, "arcsin") || cmp(s, "asin") || cmp(s, "arccos") || cmp(s, "acos") || cmp(s, "arctg") || cmp(s, "arctan") || cmp(s, "atan") || cmp(s, "arcctg") || cmp(s, "arccot") || cmp(s, "acot") )
#define is_hyperbolic(s)        ( cmp(s, "sh") || cmp(s, "sinh") || cmp(s, "ch") || cmp(s, "cosh") || cmp(s, "th") || cmp(s, "tanh") || cmp(s, "cth") || cmp(s, "coth") )
#define is_inv_hyperbolic(s)    ( cmp(s, "arsh") || cmp(s, "arsinh") || cmp(s, "arch") || cmp(s, "arcosh") || cmp(s, "arth") || cmp(s, "artanh") || cmp(s, "arcth") || cmp(s, "arcoth") )
#define is_special(s)           ( cmp(s, "gamma") || cmp(s, "lgamma") || cmp(s, "erf") || cmp(s, "j_o") || cmp(s, "jo") || cmp(s, "y_o") || cmp(s, "yo") )
#define is_other(s)             ( cmp(s, "exp") || cmp(s, "ln") || cmp(s, "log") || cmp(s, "sqrt") || cmp(s, "cbrt") || cmp(s, "abs") || cmp(s, "floor") || cmp(s, "sign") || cmp(s, "sgn") )
#define is_unary_function(s)    ( is_trigonometric(s) || is_inv_trigonometric(s) || is_hyperbolic(s) || is_inv_hyperbolic(s) || is_special(s) || is_other(s) )

#define is_binary_function(s)   ( cmp(s, "min") || cmp(s, "max") || cmp(s, "pow") || cmp(s, "bessel_j") || cmp(s, "bessel_y") )

#define is_math_constant(s)     ( cmp(s, "e") || cmp(s, "pi") )

#define is_right_assoc(s)       ( cmp(s, "^") || is_unary_function(s) || is_binary_function(s) )

/* Token types */
#define END_OF_EXPR      0
#define VAR              1
#define NUMBER           2
#define MATH_CONSTANT    3
#define BRACKET          4
#define OPERATOR         5
#define UNARY_FUNCTION   6
#define BINARY_FUNCTION  7
#define DELIMITER        8
#define UNKNOWN          9

/* Messages / Errors */
#define EXPR_IS_CONST           1
#define CORRECT_SYNTAX          0
#define STACK_OVERFLOW         -1
#define QUEUE_OVERFLOW         -2
#define DELIMITER_ERROR        -3
#define UNBALANCED_BRACKETS    -4
#define SYNTAX_ERROR           -5
#define OPERAND_ABSENCE        -6
#define NOT_ENOUGH_OPERANDS    -7
#define NOT_ENOUGH_OPERATIONS  -8
#define TOO_LONG_EXPR          -9
#define TOO_BIG_TOKEN         -10
#define INF                   -11
#define DOMAIN_ERROR          -12

#define EXPR_LNGTH_USER 128                /* expression length available to the user*/
#define EXPR_LNGTH (EXPR_LNGTH_USER * 3)   /* real available expression length -- it is because "|...|" will be transformed to " abs(...)" */
#define TOKEN_LNGTH_USER 45                /* token length available to the user (it can be only number) */
#define TOKEN_LNGTH (TOKEN_LNGTH_USER + 3) /* for "-" and label */
#define STACK_DPTH 64
#define QUEUE_DPTH 96

#define MACHINE_EPS  1.0e-12L
#define MACHINE_MAX  1.0e+45L
#define MACHINE_PI   3.141592653589793238462643383279502884L
#define MACHINE_PI_2 1.570796326794896619231321691639751442L
#define MACHINE_E    2.718281828459045235360287471352662497L

static char *expr; /* poiner to current position of parsing expression */
static char token[TOKEN_LNGTH]; /* current token, uses by get_token() and shunting_yard() */

static int variable; /* contains variable of expression (e.g. 'x' or 'z') */

static int abs_index[EXPR_LNGTH + 1]; /* auxiliary array for processing abs brackets "|" */

/* Stack and its pointer */
static char stack[STACK_DPTH][TOKEN_LNGTH];
static int sp = 0;

/* Queue and its pointers */
static char queue[QUEUE_DPTH][TOKEN_LNGTH];
static int rpos = 0;
static int spos = 0;

/* set_variable: changes variable of parsing expression to value */
void set_variable(int value){

    switch(tolower(value)){

        case 'p' : case 'q' : case 'r' : case 's' : case 't' : 
        case 'u' : case 'v' : case 'w' : case 'y' : case 'z' : variable = tolower(value); break;

        default : variable = 'x';
    }
}

/* parse_error_msg: returns parsing message/error by it's code */
char* parse_error_msg(int code){

    static char *temp;

    switch(code){

        case EXPR_IS_CONST         : temp = "expression is const";   break;
        case CORRECT_SYNTAX        : temp = "correct syntax";        break;
        case STACK_OVERFLOW        : temp = "stack overflow";        break;
        case QUEUE_OVERFLOW        : temp = "queue overflow";        break;
        case DELIMITER_ERROR       : temp = "delimiter error";       break;
        case UNBALANCED_BRACKETS   : temp = "unbalanced brackets";   break;
        case SYNTAX_ERROR          : temp = "syntax error";          break;
        case OPERAND_ABSENCE       : temp = "operand required";      break;
        case NOT_ENOUGH_OPERANDS   : temp = "not enough operands";   break;
        case NOT_ENOUGH_OPERATIONS : temp = "not enough operations"; break;
        case TOO_LONG_EXPR         : temp = "too long expr";         break;
        case TOO_BIG_TOKEN         : temp = "too long token";        break;
        case INF                   : temp = "infinity reached";      break;
        case DOMAIN_ERROR          : temp = "domain error";          break;

        default : temp = "";
    }

    return temp;
}

/* change_brackets: changes '[' to '(' and ']' to ')' */
void change_brackets(void){

    register int i = 0;
    static char modify[EXPR_LNGTH];

    strcpy(modify, expr);

    while(modify[i]){

        if(modify[i] == '[')
            modify[i] = '(';

        if(modify[i] == ']')
            modify[i] = ')';

        i++;
    }

    expr = modify;
}

/* implicit_arg: if unary function has operand of type "+value" or "-value" without brackets (e.g. "sin +  pi" or "exp-x" ),
                 that operand will be enclosed in brackets (e.g. "sin( +  pi)" or "exp(-x)" ) */
void implicit_arg(void){

    register int i = 0;
    register int j;
    int insert_start, insert_end;
    static char temp[TOKEN_LNGTH];
    static char modify[EXPR_LNGTH];

    strcpy(modify, expr);

    while(modify[i]){

        if(isalpha(modify[i])){
            
            insert_start = insert_end = 0;
            j = 0;

            while(isalpha(modify[i])){
                temp[j] = tolower(modify[i]);
                j++;
                i++;
            }

            temp[j] = '\0';

            if(is_unary_function(temp)){
                insert_start = i;

                while(isspace(modify[i]))
                    i++;

                if(modify[i] == '-' || modify[i] == '+'){
                    i++;

                    while(isspace(modify[i]))
                        i++;
                
                    if((tolower(modify[i]) == 'e' || is_variable(tolower(modify[i])) ) && !isalpha(modify[i + 1]))
                        insert_end = i + 2;        

                    if(tolower(modify[i]) == 'p' && tolower(modify[i + 1]) == 'i' && !isalpha(modify[i + 2]))
                        insert_end = i + 3;

                    if(isdigit(modify[i])){
                        while(isdigit(modify[i]) || modify[i] == '.')
                            i++;
                        insert_end = i + 1;
                    }
                }

                if(insert_end != 0){

                    for(j = insert_end; modify[j]; j++)
                        ;

                    while(j >= insert_start){
                        modify[j + 1] = modify[j];
                        j--;
                    }

                    modify[insert_start] = '(';

                    for(j = insert_end; modify[j]; j++)
                        ;

                    while(j >= insert_end){
                        modify[j + 1] = modify[j];
                        j--;
                    }

                    modify[insert_end] = ')';
                }

                i = insert_start;
            }
        }

        i++;
    }

    expr = modify;

    for(i = 0; temp[i]; i++)
        temp[i] = '\0';
}

/* implicit_multiplication: places '*' if it was omitted in follow situations ("*" marks the spot it will be placed in case of absence):

                            I:   "<number><space or not>*("
                                 "<number><space or not>*<alpha>"
                            II:  "<not an alpha or begin of expr><variable or math constant><space or not>*("
                                 "<not an alpha or begin of expr><variable or math constant><space>*<alpha>"
                            III: ")<space or not>*("
                                 ")<space or not>*<alpha>"

                            e.g. "6pi(2x^2-e x)x" will be transformed to "6*pi*(2*x^2-e *x)*x" (assuming x as variable) */
void implicit_multiplication(void){

    register int i = 0;
    register int j;
    int insert_pos;
    static char modify[EXPR_LNGTH];

    strcpy(modify, expr);

    while(modify[i]){

        insert_pos = 0;

        /* I: */
        if(isdigit(modify[i]) && !isdigit(modify[i + 1])){
            j = i + 1;

            while(isspace(modify[j]))
                j++;

            if(isalpha(modify[j]) || modify[j] == '(')
                insert_pos = j;
        }

        /* II for var, e: */
        if((is_variable(tolower(modify[i])) || tolower(modify[i]) == 'e') && (i == 0 || (i > 0 && !isalpha(modify[i - 1]))) && modify[i + 1] == '(')
            insert_pos = i + 1;

        if((is_variable(tolower(modify[i])) || tolower(modify[i]) == 'e') && (i == 0 || (i > 0 && !isalpha(modify[i - 1]))) && isspace(modify[i + 1])){
            j = i + 1;

            while(isspace(modify[j]))
                j++;

            if(isalpha(modify[j]) || modify[j] == '(')
                insert_pos = j;
        }

        /* II for pi: */
        if( tolower(modify[i]) == 'p' && tolower(modify[i + 1]) == 'i' && (i == 0 || (i > 0 && !isalpha(modify[i - 1]))) && modify[i + 2] == '(')
            insert_pos = i + 2;

        if( tolower(modify[i]) == 'p' && tolower(modify[i + 1]) == 'i' && (i == 0 || (i > 0 && !isalpha(modify[i - 1]))) && isspace(modify[i + 2])){
            j = i + 2;

            while(isspace(modify[j]))
                j++;

            if(isalpha(modify[j]) || modify[j] == '(')
                insert_pos = j;
        }

        /* III: */
        if(modify[i] == ')'){
            j = i + 1;

            while(isspace(modify[j]))
                j++;

            if(isalpha(modify[j]) || modify[j] == '(')
                insert_pos = j;   
        }

        /* Insert part: */
        if(insert_pos){

            for(j = insert_pos; modify[j]; j++)
                ;

            while(j >= insert_pos){
                modify[j + 1] = modify[j];
                j--;
            }

            modify[insert_pos] = '*';
        }

        i = (insert_pos) ? (insert_pos + 1) : (i + 1);
    }

    expr = modify;    
}

/* abs_correctness: checks correctness of "|" configuration in parsing expr */
int abs_correctness(void){

    register int i;
    int divisibility = 1; /* flag */
    int expr_length = strlen(expr);
    int sum, left_pos, right_pos;
    static char modify[EXPR_LNGTH];

    strcpy(modify, expr);

    for(i = 0, divisibility = 1; i <= EXPR_LNGTH; i++)
        abs_index[i] = 0;

    /* amount of "opening" "|" has to be equal to amount of "closing" "|" */
    for(i = 0; i < expr_length; i++){

        if(is_variable(tolower(modify[i])) && !isalpha(modify[i + 1]) && ( i == 0 || (i > 0 && !isalpha(modify[i - 1]))))
            divisibility = 0;

        else if(isdigit(modify[i]))
            divisibility = 0;

        else if(tolower(modify[i]) == 'e' && !isalpha(modify[i + 1]) && (i == 0 || (i > 0 && !isalpha(modify[i - 1]))))
            divisibility = 0;

        else if(tolower(modify[i]) == 'p' && tolower(modify[i + 1]) == 'i' && !isalpha(modify[i + 2]) && (i == 0 || (i > 0 && !isalpha(modify[i - 1]))))
            divisibility = 0;

        else if(is_operator(modify[i]) || is_delimiter(modify[i]))
            divisibility = 1;

        else if(modify[i] == '|'){

            if(divisibility)
                abs_index[i] = 1;
            else
                abs_index[i] = -1;
        }
    }

    for(i = sum = 0; i < expr_length; i++)
        if(abs_index[i])    
            sum += abs_index[i];

    if(sum)
        return UNBALANCED_BRACKETS;

    /* in every |...| has to be the same amount of '(' and ')' */
    do{

        for(i = 0, left_pos = right_pos = -1; i < expr_length && right_pos == -1; i++){

            if(abs_index[i] == 1)
                left_pos = i;

            else if(abs_index[i] == -1 && left_pos != -1)
                right_pos = i;
        }

        if(left_pos != -1)
            abs_index[left_pos] = 2;

        if(right_pos != -1)
            abs_index[right_pos] = -2;

        for(i = left_pos, sum = 0; i < right_pos; i++){

            if(modify[i] == '(')
                sum++;

            if(modify[i] == ')')
                sum--;
        }

        if(sum)
            return UNBALANCED_BRACKETS;

    }while(left_pos != -1);

    abs_index[expr_length] = 3;

    return CORRECT_SYNTAX;
}

/* abs_elimination: changes all "|...|" to " abs(...) */
void abs_elimination(void){

    register int i = 0;
    register int j = 0;
    int index = 0;
    static char modify[EXPR_LNGTH];

    strcpy(modify, expr);  

    while(abs_index[index] != 3){

        if(abs_index[index] == 2){

            while(modify[i] != '|')
                i++;

            for(j = 0; modify[j]; j++)
                ;

            while(i < j){
                modify[j + 4] = modify[j];
                j--;
            }

            modify[j++] = ' ';
            modify[j++] = 'a';
            modify[j++] = 'b';
            modify[j++] = 's';
            modify[j++] = '(';

            i = j;
        }

        if(abs_index[index] == -2){

            while(modify[i] != '|')
                i++;

            modify[i++] = ')';
        }

        index++;
    }

    expr = modify;
}

/* unary_plus_minus: changes unary '+' to ' ' and unary '-' to '$' */
void unary_plus_minus(void){ 
    
    register int i = 0;
    static char modify[EXPR_LNGTH];

    strcpy(modify, expr);

    for(i = 0; isspace(modify[i]); i++)
        ;

    if(modify[i] == '-')
        modify[i] = '$';

    if(modify[i] == '+')
        modify[i] = ' ';

    while(modify[i]){

        if(modify[i] == '(' || is_delimiter(modify[i])){    
        
            i++;
            
            while(isspace(modify[i]))
                i++;
            
            if(modify[i] == '+')
                modify[i] = ' ';
            
            if(modify[i] == '-')
                modify[i] = '$';
        }

        i++;
    }

    expr = modify;
}

/* get_token: gets current token from the expr and returns it's type */
unsigned int get_token(void){

    register char* temp;

    temp = token;

    while(isspace(*expr))
        ++expr; 

    if(!(*expr))
        return END_OF_EXPR;

    else if(is_variable(tolower(*expr)) && !isalpha(*(expr + 1))){
        *temp++ = tolower(*expr++);
        *temp = '\0';

        if(isalnum(*expr))
            return UNKNOWN; /* to avoid expressions e.g. "x2" */

        return VAR;
    }

    else if(is_bracket(*expr)){
        *temp++ = *expr++;
        *temp = '\0';
        return BRACKET;
    }

    else if(is_delimiter(*expr)){
        *temp++ = *expr++;
        *temp = '\0';
        return DELIMITER;
    }

    else if(is_operator(*expr)){
        *temp++ = *expr++;
        *temp = '\0';
        return OPERATOR;
    }

    else if(isalpha(*expr)){

        while(isalpha(*expr) || *expr == '_')
            *temp++ = tolower(*expr++);
        *temp = '\0';

        if(is_unary_function(token))
            return UNARY_FUNCTION;

        else if(is_binary_function(token))
            return BINARY_FUNCTION;

        else if(is_math_constant(token))
            return MATH_CONSTANT;
        
        else    
            return UNKNOWN;
    }

    else if(isdigit(*expr)){

        if(*expr == '0'){
            *temp++ = *expr++;

            if(isdigit(*expr)){
                *temp = '\0';
                return UNKNOWN;
            }

            if(*expr != '.'){
                *temp = '\0';
                return NUMBER;
            }
            else{  
                *temp++ = *expr++;

                if(!isdigit(*expr)){
                    *temp = '\0';
                    return UNKNOWN;
                }
                else{
                    while(isdigit(*expr))
                        *temp++ = *expr++;

                    *temp = '\0';
                    return NUMBER;
                }
            }
        }

        else{
            while(isdigit(*expr))
                *temp++ = *expr++;   

            if(*expr != '.'){
                *temp = '\0';
                return NUMBER;
            }
            else{
                *temp++ = *expr++;

                if(!isdigit(*expr)){
                    *temp = '\0';
                    return UNKNOWN;
                }
                else{
                    while(isdigit(*expr))
                        *temp++ = *expr++;

                    *temp = '\0';
                    return NUMBER;
                }
            }
        }
    }

    else{
        expr++;
        return UNKNOWN;
    }
}

/* op_priority: returns priority of operator or function s (>0) and 0 otherwise  */
unsigned int op_priority(char *s){

    if(is_unary_function(s) || is_binary_function(s))
        return 5;

    if(cmp(s, "^")) 
        return 4;

    if(cmp(s, "$"))
        return 3;

    if(cmp(s, "*") || cmp(s, "/"))
        return 2;

    if(cmp(s, "+") || cmp(s, "-"))
        return 1;

    return 0;
}

/* push: returns 1 in case of stack overflow */
unsigned int push(char *s){ 

    if(sp >= STACK_DPTH)
        return 1;

    strcpy(stack[sp++], s);    
        return 0;
}

/* pop: returns NULL if stack is empty */
char* pop(void){
    
    return (sp > 0) ? stack[--sp] : NULL;
}

void clean_stack(void){

    register int i, j;

    for(i = 0; i < STACK_DPTH; i++)
        if(stack[i][0])
            for(j = 0; j < TOKEN_LNGTH; j++)
                stack[i][j] = 0;

    sp = 0;
}

/* qstore: returns 1 in case of queue overflow */
unsigned int qstore(char* s){ 

    if(spos + 1 == rpos || ((spos + 1 == QUEUE_DPTH) && !rpos))
        return 1; 

    strcpy(queue[spos], s);
    spos++;

    if(spos == QUEUE_DPTH)
        spos = 0;

    return 0;
}

/* qretrieve: returns NULL if queue is empty */
char* qretrieve(void){ 

    if(rpos == QUEUE_DPTH)
        rpos = 0;

    if(rpos == spos)
        return NULL;

    rpos++;
    return queue[rpos - 1];
}
 
void clean_queue(void){

    register int i, j;

    for(i = 0; i < QUEUE_DPTH; i++)
        if(queue[i][0])
            for(j = 0; j < TOKEN_LNGTH; j++)
                queue[i][j] = 0;

    spos = rpos = 0;
}

/* shunting_yard: transforms parsing expression from infix notation into postfix notation; returns code of error */
int shunting_yard(void){ 
   
    int token_type;
    int operand_absence = 1;
    static char *temp;

    temp = token;

    while((token_type = get_token()) != END_OF_EXPR){

        if(strlen(token) > TOKEN_LNGTH_USER)
            return TOO_BIG_TOKEN;
        
        switch(token_type){

            case VAR : case NUMBER : case MATH_CONSTANT : {

                operand_absence = 0;
                if(qstore(token))
                    return QUEUE_OVERFLOW;
                
                break;
            }

            case DELIMITER : {

                temp = pop();

                while(temp != NULL && strcmp(temp, "(")){

                    if(qstore(temp))
                        return QUEUE_OVERFLOW;

                    temp = pop();
                }

                if(temp == NULL)
                    return DELIMITER_ERROR;
                else
                    push(temp);

                break;
            }

            case OPERATOR : case UNARY_FUNCTION : case BINARY_FUNCTION :{

                while( (temp = pop()) != NULL && op_priority(temp)){ 

                    if( (!is_right_assoc(token) && (op_priority(token) <= op_priority(temp))) || (is_right_assoc(token) && (op_priority(token) < op_priority(temp))) ){
                        if(qstore(temp))
                            return QUEUE_OVERFLOW;
                    }
                    else 
                        break;
                }

                if(temp != NULL)
                    push(temp);

                if(push(token))
                    return STACK_OVERFLOW;
                
                break;
            }

            case BRACKET : {

                if(cmp(token,"(")){
                    if(push(token))
                        return STACK_OVERFLOW;
                }
                
                else{

                    temp = pop();

                    while(temp != NULL && strcmp(temp,"(")){
                        if(qstore(temp))
                            return QUEUE_OVERFLOW;

                        temp = pop();
                    }

                    if(temp == NULL)
                        return UNBALANCED_BRACKETS;

                    temp = pop(); 

                    if(temp != NULL && (is_unary_function(temp) || is_binary_function(temp)) ){
                        if(qstore(temp))
                            return QUEUE_OVERFLOW;
                    }
                    else if(temp != NULL)
                            push(temp);
                }

                break;
            }

            case UNKNOWN : return SYNTAX_ERROR;
        }
    }

    while( (temp = pop()) != NULL){

        if(cmp(temp,"("))
            return UNBALANCED_BRACKETS;

        if(qstore(temp))
            return QUEUE_OVERFLOW;     
    }

    if(operand_absence)
        return OPERAND_ABSENCE;

    return CORRECT_SYNTAX;
}

/* calculate_unary: computes op(x) */
long double calculate_unary(char* op, long double x){

    if(cmp(op, "$"))
        return -x;

    if(cmp(op, "sin"))
        return sinl(x);

    if(cmp(op, "cos"))
        return cosl(x);

    if(cmp(op, "tg") || cmp(op, "tan"))
        return tanl(x);

    if(cmp(op, "ctg") || cmp(op, "cot"))
        return (1.0L / tanl(x));

    if(cmp(op, "sec"))
        return (1.0L / cosl(x));

    if(cmp(op, "cosec") || cmp(op, "csc"))
        return (1.0L / sinl(x));

    if(cmp(op, "arcsin") || cmp(op, "asin"))
        return asinl(x);

    if(cmp(op, "arccos") || cmp(op, "acos"))
        return acosl(x);

    if(cmp(op, "arctg") || cmp(op, "arctan") || cmp(op, "atan"))
        return atanl(x);

    if(cmp(op, "arcctg") || cmp(op, "arccot") || cmp(op, "acot"))
        return MACHINE_PI_2 - atanl(x);

    if(cmp(op, "sh") || cmp(op, "sinh"))
        return sinhl(x);

    if(cmp(op, "ch") || cmp(op, "cosh"))
        return coshl(x);

    if(cmp(op, "th") || cmp(op, "tanh"))
        return tanhl(x);

    if(cmp(op, "cth") || cmp(op, "coth"))
        return coshl(x) / sinhl(x);

    if(cmp(op, "arsh") || cmp(op, "arsinh"))
        return asinhl(x);

    if(cmp(op, "arch") || cmp(op, "arcosh"))
        return acoshl(x);

    if(cmp(op, "arth") || cmp(op, "artanh"))
        return atanhl(x);

    if(cmp(op, "arcth") || cmp(op, "arcoth"))
        return atanhl(1.0L / x);

    if(cmp(op, "gamma"))
        return tgammal(x);

    if(cmp(op, "lgamma"))
        return lgammal(x);

    if(cmp(op, "erf"))
        return erfl(x);

    if(cmp(op, "j_o") || cmp(op, "jo"))
        return j0((double)x);

    if(cmp(op, "y_o") || cmp(op, "yo"))
        return y0((double)x);

    if(cmp(op, "exp"))
        return expl(x);

    if(cmp(op, "ln") || cmp(op, "log"))
        return logl(x);

    if(cmp(op, "sqrt"))
        return sqrtl(x);    

    if(cmp(op, "cbrt"))
        return cbrtl(x);    
    
    if(cmp(op, "abs"))
        return fabsl(x);    

    if(cmp(op, "floor"))
        return floorl(x);    

    if(cmp(op, "sign") || cmp(op, "sgn")){

        if(isless(fabsl(x), MACHINE_EPS))
            return 0.0L;
        else
            return isgreater(x, 0.0L) ? 1.0L : -1.0L;
    }
}

/* calculate_binary: computes op(x, y) */
long double calculate_binary(char* op, long double x, long double y){

    if(cmp(op, "+"))
        return x + y;

    if(cmp(op, "-"))
        return x - y;

    if(cmp(op, "*"))
        return x * y;

    if(cmp(op, "/"))
        return x / y;

    if(cmp(op, "^") || cmp(op, "pow")){

        if(isless(fabsl(y - 0.5L), MACHINE_EPS))
            return sqrtl(x);

        else if(isless(fabsl(y - 1.0L / 3), MACHINE_EPS))
            return cbrtl(x);

        else if(isless(fabsl(x - 2.0L), MACHINE_EPS))
            return exp2l(y);

        else
            return powl(x, y);
    }

    if(cmp(op, "min"))
        return fminl(x, y);

    if(cmp(op, "max"))
        return fmaxl(x, y);

    if(cmp(op, "bessel_j")){

        if(isless(fabsl(x), MACHINE_EPS))
            return j0((double)y);

        else if(isless(fabsl(x - 1.0L), MACHINE_EPS))
            return j1((double)y);

        else
            return jn((double)x, (double)y);
    }

    if(cmp(op, "bessel_y")){

        if(isless(fabsl(x), MACHINE_EPS))
            return y0((double)y);

        else if(isless(fabsl(x - 1.0L), MACHINE_EPS))
            return y1((double)y);

        else
            return yn((double)x, (double)y);
    }
}

/* lddec: returns amount of digits before "." */
int lddec(long double a){
    
    int count = 1;

    while(isgreater(fabsl(a), 10.0L)){
        a /= 10.0L;
        count++;
    }

    return count;        
}

/* ldtoa: transforms long double to char* */
char* ldtoa(long double x){

    int dec = lddec(x);
    static char output[TOKEN_LNGTH - 1];
   
    sprintf(output, "%.*Lf", (TOKEN_LNGTH - 3 - dec), x);

    return output;
}

/* atold: transforms char* to long double */
long double atold(const char *s){

    static char **leftover;

    return strtold(s, leftover);
}

char* add_label(char *s){

    static const char* label = "#";

    return strcat(s, label);
}

int is_labeled(char *s){

    return (s[strlen(s) - 1] == '#') ? 1 : 0;
}

char* remove_label(char *s){    

    if(is_labeled(s))
        s[strlen(s) - 1] = '\0';

    return s;
}

/* precomputation: performs precomputation of constants in RPN */
int precomputation(void){

    int is_const = 1;
    long double temp1, temp2, result;
    static char *token, *operand1, *operand2;

    while( (token = qretrieve()) != NULL ){
        
        if(isdigit(*token) || ((*token == '-') && !cmp(token, "-")))
            push(token);

        else if(is_math_constant(token)){

            if(cmp(token, "e"))
                push(ldtoa(MACHINE_E));

            if(cmp(token, "pi"))
                push(ldtoa(MACHINE_PI));
        }

        else if(is_variable(*token) && strlen(token) == 1){
            push(add_label(token));
            is_const = 0;
        }

        else{

            if(is_unary_function(token) || cmp(token, "$")){
                
                if((operand1 = pop()) == NULL)
                    return NOT_ENOUGH_OPERANDS;

                if(is_labeled(operand1)){
                    push(operand1);
                    push(add_label(token));
                }

                else{

                    temp1 = ( (cmp(operand1,"inf")) ? INFINITY : atold(operand1) );

                    result = calculate_unary(token, temp1);
                    
                    if(isgreater(fabsl(result), MACHINE_MAX))
                        result = INFINITY;

                    if(isinf(result))
                        push("inf");

                    else if(isnan(result))
                        return DOMAIN_ERROR;

                    else
                        push(ldtoa(result));
                }
            }

            else if(is_binary_function(token) || (is_operator(*token) && !cmp(token,"$"))){
                
                if((operand2 = pop()) == NULL)
                    return NOT_ENOUGH_OPERANDS;

                else if((operand1 = pop()) == NULL)
                    return NOT_ENOUGH_OPERANDS;

                else if(is_labeled(operand1) || is_labeled(operand2)){
                    push(operand1);
                    push(operand2);
                    push(add_label(token));
                }

                else{

                    temp1 = ( (cmp(operand1,"inf")) ? INFINITY : atold(operand1) );
                    temp2 = ( (cmp(operand2,"inf")) ? INFINITY : atold(operand2) );

                    result = calculate_binary(token, temp1, temp2);
                    
                    if(isgreater(fabsl(result), MACHINE_MAX))
                        result = INFINITY;

                    if(isinf(result))
                        push("inf");

                    else if(isnan(result))
                        return DOMAIN_ERROR;

                    else
                        push(ldtoa(result));
                }
            }
        }
    }

    if(is_const){
        operand1 = pop();

        if((operand2 = pop()) != NULL)
            return NOT_ENOUGH_OPERATIONS;
        
        else if(cmp(operand1, "inf"))
            return INF;
        
        else{
            push(operand1);
            return EXPR_IS_CONST;
        }
    }

    while((operand1 = pop()) != NULL)
        qstore(remove_label(operand1));

    while((operand1 = qretrieve()) != NULL)
        push(operand1);
    
    while((operand1 = pop()) != NULL)
        qstore(operand1);

    return CORRECT_SYNTAX;
}

/* parse: parses *expression, assuming variable is var;
          if *expression does not contain variable, it's constant value will be stored in *const_value;
          *error stores parsing message/error */
void parse(char *expression, int var, long double *const_value, int *error){

    int abs_res, sh_yard_res, precomp_res;

    clean_stack();

    clean_queue();

    *const_value = 0.0L;

    expr = expression;

    set_variable(var);

    if(strlen(expr) > EXPR_LNGTH_USER){
        *error = TOO_LONG_EXPR;
        return;
    }

    change_brackets();

    implicit_arg();

    implicit_multiplication();
    
    if( (abs_res = abs_correctness()) == UNBALANCED_BRACKETS){
        *error = abs_res;
        return;
    }
    
    abs_elimination();

    unary_plus_minus();

    if( (sh_yard_res = shunting_yard()) != CORRECT_SYNTAX){
        *error = sh_yard_res;
        return;
    }  

    if( (*error = precomputation()) == EXPR_IS_CONST)
        *const_value = atold(pop());
}

/* computate: returns value of expression, that has already been parsed, where value of variable is x */
long double computate(long double x, int *error){

    static long double temp1, temp2, result;
    static char *token, *operand1, *operand2;
    int spos_old = spos;

    spos = (spos_old == QUEUE_DPTH - 1) ? 0 : (spos + 1);

    while( rpos != spos_old && (token = qretrieve()) != NULL ){
        
        if(isdigit(*token) || ((*token == '-') && !cmp(token, "-")))
            push(token);

        else if(is_math_constant(token)){
        
            if(cmp(token, "e"))
                push(ldtoa(MACHINE_E));

            if(cmp(token, "pi"))
                push(ldtoa(MACHINE_PI));
        }

        else if(is_variable(*token) && strlen(token) == 1)
            push(ldtoa(x));

        else if(cmp(token, "inf"))
            push(token);

        else{

            if(is_unary_function(token) || cmp(token, "$")){
                
                if((operand1 = pop()) == NULL){
                    *error = NOT_ENOUGH_OPERANDS;
                    return 0.0L;
                }

                else{
                    temp1 = ( (cmp(operand1,"inf")) ? INFINITY : atold(operand1) );
                    
                    result = calculate_unary(token, temp1);
                    
                    if(isgreater(fabsl(result), MACHINE_MAX))
                        result = INFINITY;

                    if(isinf(result))
                        push("inf");

                    else if(isnan(result)){
                        *error = DOMAIN_ERROR;
                        return 0.0L;
                    }

                    else
                        push(ldtoa(result));
                }
            }

            else if(is_binary_function(token) || (is_operator(*token) && !cmp(token,"$"))){
                
                if((operand2 = pop()) == NULL){
                    *error = NOT_ENOUGH_OPERANDS;
                    return 0.0L;
                }
                
                if((operand1 = pop()) == NULL){
                    *error = NOT_ENOUGH_OPERANDS;
                    return 0.0L;
                }

                    temp1 = ( (cmp(operand1,"inf")) ? INFINITY : atold(operand1) );
                    temp2 = ( (cmp(operand2,"inf")) ? INFINITY : atold(operand2) );

                    result = calculate_binary(token, temp1, temp2);
                    
                    if(isgreater(fabsl(result), MACHINE_MAX))
                        result = INFINITY;

                    if(isinf(result))
                        push("inf");

                    else if(isnan(result)){
                        *error = DOMAIN_ERROR;
                        return 0.0L;
                    }

                    else
                        push(ldtoa(result));
            }
        }

        if(rpos == QUEUE_DPTH)
            rpos = 0;

        qstore(token);
    }

    rpos = (rpos == QUEUE_DPTH - 1) ? 0 : (rpos + 1);
    
    operand1 = pop();
        
    if((operand2 = pop()) != NULL){
        *error = NOT_ENOUGH_OPERATIONS;
        return 0.0L;
    }

    else if(cmp(operand1, "inf")){
        *error = INF;
        return 0.0L;
    }

    else{
        *error = CORRECT_SYNTAX;
        return atold(operand1);
    }
}

#endif