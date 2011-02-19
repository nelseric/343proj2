/*
 * This is a linked list implementation of stack interface.
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

/* function to initialize a new stack variable */
void stackInit(stack *stkPtr)
{
	stkPtr->top = NULL;
}

/* function to free the memory associated with the stack */
void stackDestroy(stack *stkPtr)
{
	stkNode *temp, *temp2;
	
	temp = stkPtr->top;
	while (temp != NULL) {
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}	
	
	stkPtr->top = NULL;
}

/* function to add an element to the top of the stack */
void stackPush(stack *stkPtr, stkElement element)
{
	stkNode *newNode;

	/* allocate a new node to hold element pushed */
	newNode = malloc(sizeof(stkNode));

	if (newNode == NULL) {
		fprintf(stderr, "Insufficient memory to push element on stack.\n");
		exit(1); 
	}

	/* put information in node */


	newNode->element = malloc(sizeof(char) * strlen(element));
        strcpy(newNode->element,element);

        
	/* link new top node to old top node */
	newNode->next = stkPtr->top;

	/* make the new node the top node in stack */
	stkPtr->top = newNode;
}

/* function that removes the element from the top of the stack */
stkElement stackPop(stack *stkPtr)
{
	if (stackIsEmpty(stkPtr)) {
		fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
		exit(1); 
	}
	
	stkElement element = (stkPtr->top)->element;
	
	stkNode *temp = stkPtr->top;
	stkPtr->top = (stkPtr->top)->next;
	free(temp);
	
	return element;
}

/* function that returns a true value if the stack is empty */
bool stackIsEmpty(stack *stkPtr)
{
	return stkPtr->top == NULL;
}

/* function that returns the number of elements in the stack */
int stackLength(stack *stkPtr)
{
	int count = 0;
	
	stkNode *temp = stkPtr->top;
	
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	
	return count;
}

/* function that returns the top element in the stack without removing it */
stkElement stackPeek(stack *stkPtr)
{
	if (stackIsEmpty(stkPtr)) {
		fprintf(stderr, "Stack is empty - can't peek.\n");
		exit(1); 
	}
	
	return (stkPtr->top)->element;
}


