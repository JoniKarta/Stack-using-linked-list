
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

/*
 ============================================================================
 Description : Check if the stack is empty
 ============================================================================
 */
int isEmpty(struct Stack *stack) {
	return stack->top == NULL ? TRUE : FALSE;
}

/*
 ============================================================================
 Description : Push value to the stack - creating new node
 ============================================================================
 */
void push(struct Stack *stack, int data) {
	struct Node *newNode = (struct Node*) calloc(1, sizeof(struct Node));
	if (!newNode) {
		printf("Cannot allocate more memory\n");
	}
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
}

/*
 ============================================================================
 Description : Remove item from the top of the stack
 ============================================================================
 */
int pop(struct Stack *stack) {
	struct Node *p;
	int data = -1;
	if (!isEmpty(stack)) {
		p = stack->top;
		stack->top = stack->top->next;
		data = p->data;
		free(p);
	}
	return data;
}

/*
 ============================================================================
 Description : Display the item that in the top of the stack
 ============================================================================
 */
int peek(struct Stack *stack) {
	return stack->top->data;
}

/*
 ============================================================================
 Description : Display all the elements in the stack
 ============================================================================
 */
void display(struct Stack *stack) {
	struct Node *p = stack->top;
	printf("Display Stack: \n");
	while (p != NULL) {
		printf("%d \n", p->data);
		p = p->next;
	}
	printf("--\n");
}

/*
 ============================================================================
 Description : Initialize the stack - which means the first node
  	  	  	   points to null
 ============================================================================
 */
void initStack(struct Stack *stack) {
	stack->top = NULL;
}


/*
 ============================================================================
 Problem 1: Check in a given string if the number of open parenthesis is
  	  	  	equal to the number of closing parenthesis
 ============================================================================
 */
int paranthesisMatching(char* str){
	struct Stack stack;
	initStack(&stack);
	char* s = str;
	while(*s != '\0'){
		if(*s == '('){
			push(&stack, *s);
		}else{
			if(*s == ')' && !isEmpty(&stack))
				pop(&stack);
			else if(*s == ')' && isEmpty(&stack))
				return FALSE;
		}
		s++;
	}
	return isEmpty(&stack)? TRUE:FALSE;
}

/*
 ============================================================================
 Problem 2: Convert a statement from infix to postfix .
 	 	 	In this implementation i used only the character from a - z as
 	 	 	valid operands, and the signs {+, -, *, /, ^} as operands.

 ============================================================================
 */
char* infixToPostfix(char* infix){
	int i = 0, j = 0;
	struct Stack st;
	initStack(&st);
	char* postfix = (char*)calloc(strlen(infix) + 1,sizeof(char));
	while(infix[i] != '\0'){
		if(isOperand(infix[i])){
			postfix[j++] = infix[i++];
		}
		else{
			if(isOperator(infix[i])){
				if(isEmpty(&st) || precedence(infix[i]) > precedence(st.top->data))
					push(&st,infix[i++]);
				else
					postfix[j++] = pop(&st);
			}else{
				printf("invalid expression\n");
				return NULL;
			}
		}
	}
	while(!isEmpty(&st)){
		postfix[j++] = pop(&st);
	}
	return postfix;
}

/*
 ============================================================================
 Description : Check if a given character is valid operand in the expression
 ============================================================================
 */
int isOperand(char ch){
	if (ch >= 'a' && ch <= 'z'){
		return TRUE;
	}
	return FALSE;
}

/*
 ============================================================================
 Description : Check if a given character is valid operator in the expression
 ============================================================================
 */
int isOperator(char ch){
	char validOperators[] = {'+', '-', '*', '/', '^'};
	for(int i = 0; i < strlen(validOperators); i++){
		if(validOperators[i] == ch)
			return TRUE;
	}
	return FALSE;
}

/*
 ============================================================================
 Description : Check the precedence of a given character and assign it
 	 	 	   a number that represent the precedence.
 	 	 	   The larger the number the higher the precedence
 ============================================================================
 */
int precedence(char ch){
	if(ch == '+' || ch == '-' )
		return 1;
	else if(ch == '*' || ch == '/'){
		return 2;
	}
	else if (ch == '^'){
		return 3;
	}
	return 0;
}
