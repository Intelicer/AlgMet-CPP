#pragma once

#include <iostream>  //  cout
#include <stack>     //  stack from STL

using namespace std;


/**
 *   Program example no. 5 - Infix to Postfix expression.
 *
 *   Example showing the use of a stack in a very concrete and practical case:
 *   An infix expression is read and converted (printed on the screen) to a
 *   postfix expression.
 *   EKS_06_PostfixToResult.cpp finds the result of such a postfix expression.
 *
 *   Example:  (( 8 + 12 ) * ( 17 + 4 ))  becomes:   8 12 + 17 4 + *
 *
 *   Algorithm: - push the operators '+' and '*'
 *              - immediately output digits/numbers
 *              - pop and output operator when encountering ')' (closing parenthesis)
 *              - ignore '(' (opening parenthesis)
 *
 *   NOTE: The infix expression MUST:
 *       - be a legal expression (with correct operator use/number of parentheses)
 *       - only contain the operators '+' and '*' (in addition to '(' and ')')
 *       - start with '(' and end with ')'
 *       - have at least ONE space AFTER every number (but not necessarily before)
 *       - inside a parenthesis only contain ONE operator and TWO operands,
 *         NOT e.g. ( 2 + 34 * 12 )
 *
 *   @file     EKS_05_InfixToPostfix.CPP
 *   @author   Frode Haug, NTNU
 */
class InfixTilPostfix {
private:
	stack<char> stackObj;  //  Stack with characters.
	char ch;               //  Character read from keyboard.

public:
    /**
	 *  Prints the ENTIRE contents of a stack.
	 *
	 *  @param   st - COPY of the provided stack container (therefore emptied)
	*/
	void printStack(stack<char> st);

	void read_from_user();

	stack<char> get_stack();
};