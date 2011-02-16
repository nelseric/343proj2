/*
 * This is an interface for a stack of strings.
 *
 */
 
#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>

typedef char * stkElement;

struct stkNode {
  stkElement element;
  struct stkNode *next;
};

typedef struct stkNode stkNode;

typedef struct {
  stkNode *top;
} stack;

/* function to initialize a new stack variable */
void stackInit(stack *stkPtr);

/* function to free the memory associated with the stack */
void stackDestroy(stack *stkPtr);

/* function to add an element to the top of the stack */
void stackPush(stack *stkPtr, stkElement element);

/* function that removes the element from the top of the stack */
stkElement stackPop(stack *stkPtr);

/* function that returns a true value if the stack is empty */
bool stackIsEmpty(stack *stkPtr);

/* function that returns the number of elements in the stack */
int stackLength(stack *stkPtr);

/* function that returns the top element in the stack without removing it */
stkElement stackPeek(stack *stkPtr);

#endif  /* _STACK_H */
