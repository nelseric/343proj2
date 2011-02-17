#include <stdio.h>
#include <string.h>
#include "postfix.h"

int main()
{
    char test[] = " ( 10 + 2 ) * 3 + 2 * ( 6 / 3 + 2 ^ 2 ) ";
    puts(test);
    puts(infixToPostfix(test));
    
    char postTest[] = "4 4 + 3 *";
    int i = evaluatePostfix(postTest);
    printf("%d\n", i);

    char *token = strtok(test, " ");
    int a, b, c, d, ip, sp;

    puts("token\t(\t)\topate\topand\tip\tsp");
    while(token != NULL) {
        a = isLeftParen(token);
        b = isRightParen(token);
        c = isOperator(token);
        d = isOperand(token);
        ip = inputPrecedence(token);
        sp = stackPrecedence(token);
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n",token, a, b, c, d, ip, sp);
        token = strtok(NULL," ");
    } 
    return 0;
}
