/*
 * posftix.c
 *
 *  Created on: Feb 19, 2011
 *      Author: Matthew Levandowski
 *	 	Email: levandma@mail.gvsu.edu
 *      GVSU CS 343
 */

#define MAXBUFFERSIZE 80
#include <stdio.h>
#include <stdlib.h>
#include "postfix.h"
#include "stack.h"

stack pile;
int stackSize;

int Menu();
void runInfixToPostfix();
void runEvaluatePostfix();
void flushBuffer();

void flushBuffer() {
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

int Menu() {
	int exit_flag = 0, valid_choice;
	char menu_choice;

	while (exit_flag == 0) {
		valid_choice = 0;
		while (valid_choice == 0) {
			printf(
					"\n1 = Convert Infix to Postfix\n2 = Evaluate Postfix Expression\n3 = Exit\n");
			printf("Enter choice:\n");
			scanf("   %c", &menu_choice);
			if ((menu_choice == '1') || (menu_choice == '2') || (menu_choice
					== '3'))
				valid_choice = 1;
			else
				printf("\007Error. Invalid menu choice selected.\n");
		}
		switch (menu_choice) {
		case '1':
			flushBuffer();
			runInfixToPostfix();
			break;
		case '2':
			flushBuffer();
			runEvaluatePostfix();
			break;
		case '3':
			exit_flag = 1;
			break;
		default:
			printf("Error--- Should not occur.\n");
			break;
		}
	}
}

void runInfixToPostfix() {
	char ch; /* handles user input */
	char buffer[MAXBUFFERSIZE]; /* sufficient to handle one line */
	int char_count; /* number of characters read for this line */
	int exit_flag = 0;
	int valid_choice;
	char *result;

	while (exit_flag == 0) {
		printf("Enter an infix expression (<80 chars)\n");
		ch = getchar();
		char_count = 0;
		while ((ch != '\n') && (char_count < MAXBUFFERSIZE)) {
			buffer[char_count++] = ch;
			ch = getchar();
		}
		buffer[char_count] = 0x00; /* null terminate buffer */
		printf("\nThe line you entered was:\n");
		printf("%s\n", buffer);

		valid_choice = 0;
		while (valid_choice == 0) {
			printf("Is this Correct (Y/N)?\n");
			scanf(" %c", &ch);
			ch = toupper(ch);
			if ((ch == 'Y') || (ch == 'N')) {
				result = infixToPostfix(buffer);
				valid_choice = 1;
				printf("Postfix expression is: %s\n", result);
				exit_flag = 1;
			} else {
				printf("\007Error: Invalid choice\n");
			}
			flushBuffer();
		}
		if (ch == 'N')
			exit_flag = 1;
	}
}

void runEvaluatePostfix() {
	char ch; /* handles user input */
	char buffer[MAXBUFFERSIZE]; /* sufficient to handle one line */
	int char_count; /* number of characters read for this line */
	int exit_flag = 0;
	int valid_choice;
	int evalResult;

	while (exit_flag == 0) {
		printf("Enter a Postfix expression (<80 chars)\n");
		ch = getchar();
		char_count = 0;
		while ((ch != '\n') && (char_count < MAXBUFFERSIZE)) {
			buffer[char_count++] = ch;
			ch = getchar();
		}
		buffer[char_count] = 0x00; /* null terminate buffer */
		printf("\nThe line you entered was:\n");
		printf("%s\n", buffer);

		valid_choice = 0;
		while (valid_choice == 0) {
			printf("Is this Correct (Y/N)?\n");
			scanf(" %c", &ch);
			ch = toupper(ch);
			if ((ch == 'Y') || (ch == 'N')) {
				evalResult = evaluatePostfix(buffer);
				valid_choice = 1;
				printf("Postfix evaluation is: %d\n", evalResult);
				exit_flag = 1;
			} else {
				printf("\007Error: Invalid choice\n");
			}
			flushBuffer();
		}
		if (ch == 'N')
			exit_flag = 1;
	}
}

// main function
int main() {
	Menu();
	return 0;
}
