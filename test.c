/*
 * test.c
 *
 *  Created on: Feb 19, 2011
 *      Author: Matthew LEvandowski
 *	 	Email: levandma@mail.gvsu.edu
 *      GVSU Computer Science
 */

#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#define OS_WIN
#endif

#include <stdio.h>
#include <stdlib.h>
#include "postfix.h"
#include "stack.h"

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
	printf("\n\n");
	return i;
}

void runInfixToPostfix() {
	char tempStr[80];
	fflush(stdout);
	printf("enter infix expr:\n");
	//fgets(tempStr, 80, stdin);
	scanf("%80s", tempStr);
	printf("Postfix output: %s", tempStr);
	end = 1;
}

void runEvaluatePostfix() {
	char *tempStr;
	int i;
	printf("enter postfix expr:\n");
	//set max string size to 82
	tempStr = malloc(82 * sizeof(char));
	scanf("%s", tempStr);
	for (i = 0; i < strlen(tempStr); i++) {
		printf("%s ", tempStr[i]);
	}
	printf("\n");
	end = 1;
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
