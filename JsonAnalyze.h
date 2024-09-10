#ifndef JSONANALYZE_H
#define JSONANALYZE_H

//#include "Stack.cpp"
#include "Stack.h"
#include "DataContainer.h"
#include "SyntaxCheck.h"

class JsonAnalyze{
    private:
        Stack<Data> dataStack;
        Data mainTree;
        short success;
        int findEndSymbol(std::string json, int i);
    public:
        JsonAnalyze();
        int Analyze(std::string json);
        int isSuccess();
};

#endif