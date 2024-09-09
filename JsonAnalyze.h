#ifndef JSONANALYZE_H
#define JSONANALYZE_H

#include "Stack.cpp"
#include "DataContainer.h"
#include "SyntaxCheck.h"

class JsonAnalyze{
    private:
        Stack<Data> dataStack;
        Data mainTree;
        short success;
    public:
        JsonAnalyze();
        int Analyze(std::string json);
        int isSuccess();
};

#endif