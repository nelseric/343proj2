/*
 * This is an interface for infix to postfix converter and
 * postfix evaluator.
 *
 */
 
#ifndef _POSTFIX_H
#define _POSTFIX_H

#include <stdbool.h>

/* function to convert an infix to postfix */
char *infixToPostfix(char *infixStr);

/* function that returns true if the string is an operator */
bool isOperator(char *str);

/* function that returns true if the string is an operand/integer */
bool isOperand(char *str);

/* function that returns true if the string is a left parenthesis */
bool isLeftParen(char *str);

/* function that returns true if the string is a right parenthesis */
bool isRightParen(char *str);

/* function that returns the stack precedence of given operator */
int stackPrecedence(char *str);

/* function that returns the input precedence of given operator */
int inputPrecedence(char *str);

/* function that evaluates a postfix expression and returns the result */
int evaluatePostfix(char *postfixStr);

/* function that performs num1 opr num2 and returns the result */
int applyOperator(int num1, int num2, char *opr);

#endif  /* _POSTFIX_H */
