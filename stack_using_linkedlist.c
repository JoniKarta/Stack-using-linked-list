/*
 ============================================================================
 Name        : LinkedLIstStack.c
 Author      : Jonathan karta
 Description : In this program I'm implementing stack using linked list
 	 	 	   and I'm solving common problems with it.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

int main(void) {
	char* validParenthesis = "((a+b)+(c+d))";
	printf("Is the parenthesis match? %s\n",paranthesisMatching(validParenthesis)?"True":"False");
	char* invalidParenthesis  = "((((a+b)+(c+d))";
	printf("Is the parenthesis match? %s\n",paranthesisMatching(invalidParenthesis  )?"True":"False");
	char* infix = "a+b*c-d";
	printf("Infix: %s --> Postfix: %s \n",infix, infixToPostfix(infix));
	char* invaildInfix = "a+&b*c-d";
	printf("Infix: %s --> Postfix: %s \n",infix, infixToPostfix(invaildInfix));

	return EXIT_SUCCESS;
}
