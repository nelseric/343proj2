/*
 * test.c
 *
 *  Created on: Feb 19, 2011
 *      Authors: Matthew LEvandowski Email: levandma@mail.gvsu.edu
 *	 	 Eric Nelson
 *      GVSU Computer Science
 */

#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#define OS_WIN
#endif

#include <stdio.h>
#include <stdlib.h>
#include "postfix.h"
#include "stack.h"
#include <string.h>
#include <readline/readline.h>


stack pile;
int stackSize;

int Menu();
void runInfixToPostfix();
void runEvaluatePostfix();

int end = 0;

int Menu() {
	int i;
	printf("\n");
	printf("MENU\n\n");
	printf("1 - Convert Infix to Postfix\n");
	printf("2 - Evaluate Postfix Expression\n");
	printf("3 - Exit\n\n");
	printf("Choose: ");
	scanf("%d", &i);
	if(ferror(stdin) == 0){
		clearerr(stdin);
		while(getchar() != '\n');
	}
	printf("\n\n");
	return i;
}

void runInfixToPostfix() {
	char *line = readline("Enter Infix Expression: ");
	char *postfix = infixToPostfix(line);
	printf("\tPostfix: %s\n", postfix);
	printf("\tValue: %d\n", evaluatePostfix(postfix));
}

void runEvaluatePostfix() {
	char *line = readline("Enter Postfix Expression: ");
	printf("\tValue: %d\n", evaluatePostfix(line));
}

void clearScreen() {
#ifdef OS_WIN
	system("CLS");
#else
	system("clear");
#endif

}

int main() {
	while (end != 1) {
		int op;
		//clearScreen();
		op = Menu();
		switch (op) {
			case 1:
				runInfixToPostfix();
				break;
			case 2:
				runEvaluatePostfix();
				break;
			case 3:// This is the option to quit the program
				end = 1;
				break;
			default:
				printf("ERROR: invalid selection.\n\n");
				break;
		}
	}
	return 0;
}
