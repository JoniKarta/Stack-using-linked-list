
#ifndef UTILITY_H_
#define UTILITY_H_


#define TRUE 1
#define FALSE 0

struct Node {
	int data;
	struct Node *next;
};

struct Stack {
	struct Node *top;
};

/*
 ============================================================================
 Description : Stack operations
 ============================================================================
 */
int isEmpty(struct Stack *stack);
void push(struct Stack *stack, int data);
int pop(struct Stack *stack);
int peek(struct Stack *stack);
void display(struct Stack *stack) ;
void initStack(struct Stack *stack) ;


/*
 ============================================================================
 Problem 1: Check in a given string if the number of open parenthesis is
  	  	  	equal to the number of closing parenthesis
 ============================================================================
 */
int paranthesisMatching(char* str);


/*
 ============================================================================
 Description: Convert a statement from infix to postfix and helper methods.
 ============================================================================
 */
char* infixToPostfix(char* infix);
int isOperand(char ch);
int isOperator(char ch);
int precedence(char ch);

#endif /* UTILITY_H_ */
