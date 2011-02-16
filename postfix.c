#include "postfix.h"
#include "stack.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char *infixToPostfix(char *infixStr){
    char inCopy[strlen(infixStr)];
    strcpy(inCopy,infixStr);

    char *postfixString = malloc(sizeof(char)*strlen(infixStr)*2);
    char *token = strtok(inCopy," ");
    
    while(token != NULL){   
        token = strtok(NULL," ");
    }
    return postfixString;
}

bool isOperator(char *str){
    char ops[] = "+-*/%^";
    int i;
    for(i = 0; i < strlen(ops); ++i){
        if(str[0] == ops[i])
            return true;
    }
    return false;
}

bool isOperand(char *str){
    int i;
    int good = true;
    for(i = 0; i < strlen(str); i++) {
        good = good && isdigit(str[i]);
    }
    return good;
}
bool isLeftParen(char *str){
    return str[0] == '(';
}

bool isRightParen(char *str){
    return str[0] == ')';
}

int stackPrecedence(char *str){
    if(str[0] == '+' || str[0] == '-'){
        return 1;
    } else if(str[0] == '*' || str[0] == '/' || str[0] == '%'){
        return 2;
    } else if(str[0] == '^'){
        return 3;
    } else if(isLeftParen(str)){
        return -1;
    }
    return 0;
}
int inputPrecedence(char *str){
    if(str[0] == '+' || str[0] == '-'){
        return 1;
    } else if(str[0] == '*' || str[0] == '/' || str[0] == '%'){
        return 2;
    } else if(str[0] == '^'){
        return 4;
    } else if(isLeftParen(str)){
        return 5;
    }
    return 0;
}
int evaluatePostfix(char *postfixStr){
    return 0;
}
int applyOperator(int num1, int num2, char *opr){
    return 0;
}
