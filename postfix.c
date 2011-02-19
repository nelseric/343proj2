#include "postfix.h"
#include "stack.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char *infixToPostfix(char *infixStr){
    char inCopy[strlen(infixStr)];
    strcpy(inCopy,infixStr);

    char *postfixString = malloc(sizeof(char)*strlen(infixStr));
    postfixString[0] = '\0';

    char *token = strtok(inCopy," ");

    stack convoStack;
    stackInit(&convoStack);

    while(token != NULL){
        if(isOperand(token)){
            strcat(postfixString,token);
            strcat(postfixString," ");
        } else if(isLeftParen(token)){
            stackPush(&convoStack, token);
        } else if(isOperator(token)){
            if(!stackIsEmpty(&convoStack)){
                char *peek = stackPeek(&convoStack);
                while(isOperator(peek)){
                    int sp = stackPrecedence(peek);
                    int ip = inputPrecedence(token);
                    if(sp >= ip){
                        strcat(postfixString,stackPop(&convoStack));
                        strcat(postfixString," ");
                    } else
                        break;
                    if(!stackIsEmpty(&convoStack)){
                        peek = stackPeek(&convoStack);
                    } else {
                        peek = "\0";
                    }
                }
            }
            stackPush(&convoStack,token);
        } else if(isRightParen(token)){
            char *peek = stackPeek(&convoStack);
            while(isOperator(peek)){
                strcat(postfixString,stackPop(&convoStack));                
                strcat(postfixString," ");
                peek = stackPeek(&convoStack);
            }
            if(isLeftParen(stackPeek(&convoStack))){
                stackPop(&convoStack);
            }
        }
        token = strtok(NULL," ");
    }
    while(!stackIsEmpty(&convoStack)){
        char *tok = stackPop(&convoStack);
        if(isOperator(tok)){
            strcat(postfixString,tok);                
            strcat(postfixString," ");
        }
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
    char postfixCopy[strlen(postfixStr)];
    strcpy(postfixCopy,postfixStr);
    char *token = strtok(postfixCopy," ");
    int x, y;
    stack op;
    stackInit(&op);
    while (token != NULL){
        if(isOperand(token)){
            stackPush(&op, token);
        } else if(isOperator(token)) {
            y = atoi(stackPop(&op));
            x = atoi(stackPop(&op));
            char a[10];
            sprintf(a,"%d",applyOperator(x,y,token));
            stackPush(&op,a);
        }
        token = strtok(NULL," ");
    }
    return atoi(stackPop(&op));
}
int applyOperator(int num1, int num2, char *opr){
    int result;
    switch(opr[0]){
        case '+':
            result = num1 + num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '%':
            result = num1 % num2;
            break;
        case '^':
            result = ipow(num1, num2);
            break;
        default:
            result = 0;
    }
    return result;
}

int ipow(int a, int b){
    int res = 1;
    int i;
    for(i = 0; i < b; ++i){
        res *= a;
    }
    return res;
}


