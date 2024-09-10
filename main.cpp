#include <iostream>
#include "JsonAnalyze.h"

int main(){
    std::cout << "Tester for JsonParser by CorneliaMo\n";
    std::cout << "Input a json string :\n";
    std::string json;
    std::cin >> json;
    std::cout << std::endl;
    JsonAnalyze analyze;
    if (analyze.Analyze(json)!=OK){
        std::cout << "Analyze error";
    }
    return 0;
}