#include <iostream>
#include "SyntaxCheck.h"

int main(){
    std::cout << "Tester for JsonParser by CorneliaMo\n";
    std::cout << "Input a json string :\n";
    std::string json;
    std::cin >> json;
    std::cout << std::endl;
    SyntaxCheck syntaxChecker = SyntaxCheck();
    int re = syntaxChecker.checkSyntax(json);
    std::cout << (re==OK ? "Syntax is right." : "Syntax is wrong.") << std::endl;
    return 0;
}