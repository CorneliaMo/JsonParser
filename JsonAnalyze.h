#ifndef JSONANALYZE_H
#define JSONANALYZE_H

//#include "Stack.cpp"
#include "Stack.h"
#include "DataContainer.h"
#include "SyntaxCheck.h"
#include <sstream>

class JsonAnalyze{
    private:
        Stack<DataContainer*> datacontainerStack;
        DataContainer* mainContainer;
        short success;
        std::string getKey(std::string json, int i);
        int convertToData(std::string sep_json, Data &data);
        std::string clearSpace(std::string string);
        bool isNumber(std::string string);
    public:
        JsonAnalyze();
        int Analyze(std::string json);
        DataContainer* successAnalyze();
};

#endif