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

#include <iostream>  // cout
#include <stack>     // stack from STL
using namespace std;

/**
 *  Prints the ENTIRE contents of a stack.
 *
 *  @param   st - COPY of the given stack (therefore emptied)
 */
void printStack(stack<int> st) {
    while (!st.empty()) {        // Still elements left:
        cout << ' ' << st.top(); // Print the current top.
        st.pop();                // Remove the top element.
    }
    cout << '\n';
}

/**
 *  Main program:
 */
int main() {
    stack<int> stackObj;   // Stack of integers.
    char ch;               // Character read from keyboard.
    int number;            // For building numbers and storing results.

    cout << "\n\nEnter a postfix expression:\n";

    // Read ALL characters, including ' ', until newline:
    while ((ch = cin.get()) != '\n') {
        number = 0;  // Reset accumulator.

        // Skip any extra spaces.
        while (ch == ' ') {
            ch = cin.get();
        }

        if (ch == '+') {                  // '+' found:
            number = stackObj.top();
            stackObj.pop();               // Pop first operand
            number += stackObj.top();
            stackObj.pop();               // Add to second operand
        }
        else if (ch == '*') {           // '*' found:
            number = stackObj.top();
            stackObj.pop();               // Pop first operand
            number *= stackObj.top();
            stackObj.pop();               // Multiply with second operand
        }

        // Build multi-digit number if digits are found:
        while (ch >= '0' && ch <= '9') {
            number = (10 * number) + (ch - '0'); // Shift left and add digit
            ch = cin.get();                      // Read next character
        }

        // Push either the computed or the built number.
        stackObj.push(number);

         printStack(stackObj);
    }

    // Only ONE number remains on the stack → the result!
    cout << "\n\nThe result is:  " << stackObj.top() << "\n\n";
    stackObj.pop();

    return 0;
}
