#include <iostream>
#include "JsonAnalyze.h"
#include "status_code.h"
#include <fstream>

void outputData(Data &data){
    //Data can be int, double, true, false, string, null, object, array
    if (data.type=="string"){
        std::cout << *(std::string*)(data.data);
    }else if (data.type=="double"){
        std::cout << *(double*)(data.data);
    }else if (data.type=="int"){
        std::cout << *(int*)(data.data);
    }else if (data.type=="bool"){
        std::cout << *(bool*)(data.data);
    }else if (data.type=="null"){
        std::cout << "NULL";
    }else if (data.type=="object"){
        std::cout << "(object_ptr)";
    }else if (data.type=="array"){
        std::cout << "(array_ptr)";
    }
}

void outputDataContainer(DataContainer* container){
    if (container->isArray()){
        //is array
        int length = container->getLength();
        for (int loop=0;loop<length;loop++){
            Data result = container->getElementByIndex(loop);
            std::cout << "Index: " << loop << ", type: " << result.type << ", value: ";
            outputData(result);
            std::cout << std::endl;
        }
    }else if (container->isObject()){
        std::string* key_lists = container->getListOfKey();
        for (int loop=0;loop<container->getLength();loop++){
            Data result = container->getElementByKey(key_lists[loop]);
            std::cout << "Key: " << key_lists[loop] << ", type: " << result.type << ", value: ";
            outputData(result);
            std::cout << std::endl;
        }
    }
}

/*
int main(){
    std::cout << "Tester for JsonParser by CorneliaMo\n";
    std::cout << "Input a json string :\n";
    std::string json;
    std::cin >> json;
    std::cout << std::endl;
    JsonAnalyze analyze;
    int re = analyze.AnalyzeString(json);
    if (re == WRONG){
        std::cout << "Analyze error!\n\n";
    }else if (re == ERROR){
        std::cout << "Analyze error!\n\n";
    }else{
        DataContainer* result = analyze.successAnalyze();
        if (result!=NULL){
            std::cout << "Analyze success!\n\n";
            outputDataContainer(result);
        }else{
            std::cout << "Analyze error!\n\n";
        }
    }
    return 0;
}
*/

int main(){
    std::fstream fs("test.json");
    std::string json = "";
    std::string buffer = "";
    while(std::getline(fs, buffer)){
        json += buffer;
        buffer.clear();
    }
    std::cout << "Get json string: " << json << std::endl;

    JsonAnalyze analyzer;
    analyzer.AnalyzeString(json);
    DataContainer* json_data = analyzer.successAnalyze();
    outputDataContainer((DataContainer*)((*json_data).getElementByKey("preference").data));
}