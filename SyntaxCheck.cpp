#include "SyntaxCheck.h"

SyntaxCheck::SyntaxCheck(){
    charStack = Stack<char>();
    symbolCountStack = Stack<SymbolCount>();
}

int SyntaxCheck::emptyStacks(){
    charStack.emptyStack();
    symbolCountStack.emptyStack();
    return OK;
}

int SyntaxCheck::checkSyntax(std::string json){
    if (json.length()<=1){
        return WRONG;
    }
    for (int loop=0;loop<json.length();loop++){
        char step = json[loop];
        if (step=='{'){
            charStack.push('{');
            SymbolCount tmp_symbolCount;
            tmp_symbolCount.comma = 0;
            tmp_symbolCount.colon = 0;
            symbolCountStack.push(tmp_symbolCount);
        }else if (step=='['){
            charStack.push('[');
            SymbolCount tmp_symbolCount;
            tmp_symbolCount.comma = 0;
            tmp_symbolCount.colon = 0;
            symbolCountStack.push(tmp_symbolCount);
        }else if (step==']'){
            if (charStack.getLength()==0){
                emptyStacks();
                return WRONG;
            }
            char prev_symbol = charStack.pop();
            if (prev_symbol!='['){
                emptyStacks();
                return WRONG;
            }
            if (symbolCountStack.getLength()==0){
                emptyStacks();
                return WRONG;
            }
            SymbolCount prev_symbolCount = symbolCountStack.pop();
            if (!(prev_symbolCount.colon==0&&prev_symbolCount.comma==0)){
                if (prev_symbolCount.colon!=prev_symbolCount.comma+1){
                    emptyStacks();
                    return WRONG;
                }
            }
        }else if (step=='}'){
            if (charStack.getLength()==0){
                emptyStacks();
                return ERROR;
            }
            char prev_symbol = charStack.pop();
            if (prev_symbol!='{'){
                emptyStacks();
                return WRONG;
            }
            if (symbolCountStack.getLength()==0){
                emptyStacks();
                return WRONG;
            }
            SymbolCount prev_symbolCount = symbolCountStack.pop();
            if (!(prev_symbolCount.colon==0&&prev_symbolCount.comma==0)){
                if (prev_symbolCount.colon!=prev_symbolCount.comma+1){
                    emptyStacks();
                    return WRONG;
                }
            }
        }else if (step==','){
            if (symbolCountStack.getLength()==0){
                emptyStacks();
                return WRONG;
            }else{
                SymbolCount prev_symbolCount = symbolCountStack.pop();
                prev_symbolCount.comma++;
                symbolCountStack.push(prev_symbolCount);
            }
        }else if (step==':'){
            if (symbolCountStack.getLength()==0){
                emptyStacks();
                return WRONG;
            }else{
                SymbolCount prev_symbolCount = symbolCountStack.pop();
                prev_symbolCount.colon++;
                symbolCountStack.push(prev_symbolCount);
            }
        }else if (step=='"'){
            if (charStack.getLength()==0){
                emptyStacks();
                return WRONG;
            }
            char prev_symbol = charStack.pop();
            if (prev_symbol!='"'){
                charStack.push(prev_symbol);
                charStack.push('"');
            }
        }
    }
    emptyStacks();
    return OK;
}