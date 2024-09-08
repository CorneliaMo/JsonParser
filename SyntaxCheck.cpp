#include "SyntaxCheck.h"

SyntaxCheck::SyntaxCheck(){
    charStack;
    symbolCountStack;
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
            char* prev_symbol;
            int re = charStack.pop(prev_symbol);
            if (re==ERROR||prev_symbol==nullptr){
                emptyStacks();
                return ERROR;
            }
            if (*prev_symbol!='['){
                emptyStacks();
                delete prev_symbol;
                return WRONG;
            }
            delete prev_symbol;
            if (symbolCountStack.getLength()==0){
                emptyStacks();
                return WRONG;
            }
            SymbolCount* prev_symbolCount;
            re = symbolCountStack.pop(prev_symbolCount);
            if (re==ERROR||prev_symbolCount==nullptr){
                emptyStacks();
                return ERROR;
            }
            if (!(prev_symbolCount->colon==0&&prev_symbolCount->comma==0)){
                if (prev_symbolCount->colon!=prev_symbolCount->comma+1){
                    emptyStacks();
                    delete prev_symbolCount;
                    return WRONG;
                }
            }
            delete prev_symbolCount;
        }else if (step=='}'){
            if (charStack.getLength()==0){
                emptyStacks();
                return ERROR;
            }
            char* prev_symbol;
            int re = charStack.pop(prev_symbol);
            if (re==ERROR||prev_symbol==nullptr){
                emptyStacks();
                return ERROR;
            }
            if (*prev_symbol!='{'){
                emptyStacks();
                delete prev_symbol;
                return WRONG;
            }
            delete prev_symbol;
            if (symbolCountStack.getLength()==0){
                emptyStacks();
                return WRONG;
            }
            SymbolCount* prev_symbolCount;
            re = symbolCountStack.pop(prev_symbolCount);
            if (re==ERROR||prev_symbolCount==nullptr){
                emptyStacks();
                return ERROR;
            }
            if (!(prev_symbolCount->colon==0&&prev_symbolCount->comma==0)){
                if (prev_symbolCount->colon!=prev_symbolCount->comma+1){
                    emptyStacks();
                    delete prev_symbolCount;
                    return WRONG;
                }
            }
            delete prev_symbolCount;
        }else if (step==','){
            if (symbolCountStack.getLength()==0){
                emptyStacks();
                return WRONG;
            }else{
                SymbolCount* prev_symbolCount;
                int re = symbolCountStack.pop(prev_symbolCount);
                if (re==ERROR||prev_symbolCount==nullptr){
                    emptyStacks();
                    return ERROR;
                }
                prev_symbolCount->comma++;
                symbolCountStack.push(*prev_symbolCount);
                delete prev_symbolCount;
            }
        }else if (step==':'){
            if (symbolCountStack.getLength()==0){
                emptyStacks();
                return WRONG;
            }else{
                SymbolCount* prev_symbolCount;
                int re = symbolCountStack.pop(prev_symbolCount);
                if (re==ERROR||prev_symbolCount==nullptr){
                    emptyStacks();
                    return ERROR;
                }
                prev_symbolCount->colon++;
                symbolCountStack.push(*prev_symbolCount);
                delete prev_symbolCount;
            }
        }else if (step=='"'){
            if (charStack.getLength()==0){
                emptyStacks();
                return WRONG;
            }
            char* prev_symbol;
            int re = charStack.pop(prev_symbol);
            if (re==ERROR||prev_symbol==nullptr){
                emptyStacks();
                return ERROR;
            }
            if (*prev_symbol!='"'){
                charStack.push(*prev_symbol);
                charStack.push('"');
            }
            delete prev_symbol;
        }
    }
    emptyStacks();
    return OK;
}