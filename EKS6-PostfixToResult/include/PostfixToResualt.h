#include <iostream>  // cout
#include <stack>     // stack from STL
using namespace std;



/**
 *   Program example no. 6 - Calculates/finds the result of a postfix expression.
 *
 *   Example showing the use of a stack in a concrete and practical case:
 *   A postfix expression is read, and its result is calculated.
 *   EKS_05_InfixToPostfix.cpp converts infix expressions to postfix expressions.
 *
 *   Example:  The result of   8 12 + 17 4 + *    is   420
 *
 *   Algorithm:
 *      - when encountering '+' or '*', pop two numbers/operands,
 *        calculate their sum/product, and push the result
 *      - when encountering digits, build them into a number
 *        and push that number once complete
 *
 *   NOTE: The postfix expression MUST:
 *      - have at least ONE space after each number and operator,
 *        except after the very last operator
 *      - be a valid postfix expression
 *
 *   @file     EKS_06_PostfixToResult.CPP
 *   @author   Frode Haug, NTNU
 */
class PostfixToResualt {

private:
    stack<int> stackObj;   // Stack of integers.
    char ch;               // Character read from keyboard.
    int number;            // For building numbers and storing results.

public:
    void read_and_get_result();

    /**
     *  Prints the ENTIRE contents of a stack.
     *
     *  @param   st - COPY of the given stack (therefore emptied)
     */
    void printStack(stack<int> st);

    stack<int> getStack() const;

};