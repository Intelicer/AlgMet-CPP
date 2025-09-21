#include <iostream>  // cout
#include "../../include/PostfixToResualt.h"
using namespace std;

/**
 *  Main program:
 */
int main() {
    PostfixToResualt p1;

    p1.read_and_get_result();

    p1.printStack(p1.getStack());

    return 0;
}
