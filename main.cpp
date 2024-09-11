#include <iostream>
#include "JsonAnalyze.h"

int main(){
    std::cout << "Tester for JsonParser by CorneliaMo\n";
    std::cout << "Input a json string :\n";
    std::string json;
    std::cin >> json;
    std::cout << std::endl;
    SyntaxCheck checker;
    if (checker.checkSyntax(json)!=OK){
        std::cout << "Syntax wrong!\n";
    }else{
        JsonAnalyze analyze;
        if (analyze.Analyze(json)!=OK){
            std::cout << "Analyze error!\n";
        }else{
            DataContainer* result = analyze.successAnalyze();
            if (result==NULL){
                std::cout << "Analyze error!\n";
            }else{
                std::cout << "Analyze success!\n";
            }
        }
    }
    return 0;
}