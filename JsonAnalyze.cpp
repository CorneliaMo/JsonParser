#include "JsonAnalyze.h"
#include <iostream>

int JsonAnalyze::Analyze(std::string json){
    SyntaxCheck checker;
    if (checker.checkSyntax(json)!=OK){
        return WRONG;
    }
    for (int loop=0;loop<json.length();loop++){
        char step = json[loop];
        if (step=='{'||step=='['){
            //Data result;
            //result.type = 'O';
            char type = (step=='{'? 'O':'A');
            int left = 0;
            int length = 1;
            for (int loopB=loop+1;loopB<json.length();loopB++){
                //scan the number of object
                char stepB = json[loop];
                if (stepB=='{'||stepB=='['){
                    left++;
                }else if (stepB=='}'||stepB==']'){
                    left--;
                }else if (stepB==','&&left==0){
                    length++;
                }
                if (left<0){
                    break;
                }
            }
            std::cout << "Find " << (type=='O'? "object" : "array") << " which length is  " << length << std::endl; 
        }
    }
    return OK;
}