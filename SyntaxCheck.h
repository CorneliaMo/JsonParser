#ifndef SYSTAXCHECK_H
#define SYSTAXCHECK_H

#include "Stack.h"
#include "status_code.h"
#include <string>

typedef struct SymbolCount
{
    int colon;  //number of : in a structure
    int comma;  //number of , in a structure
}SymbolCount;

class SyntaxCheck {
    private:
        Stack<char> charStack;
        Stack<SymbolCount> symbolCountStack;
    public:
        SyntaxCheck();
        int checkSyntax(std::string json);
        int emptyStacks();
};

#endif //SYSTAXCHECK_H
