#include "DataContainer.h"

DataContainer::DataContainer(int _length, char _type){
    length = _length;
    type = _type;
    if (type=='O'){
        keys = new std::string[length];
    }else{
        keys = NULL;
    }    
    values = new Data[length];
}

Data DataContainer::getNullData(){
    Data result;
    result.data = NULL;
    result.type = "NULL";
    return result;
}

bool DataContainer::isObject(){
    return (type=='O'? true : false);
}

bool DataContainer::isArray(){
    return (type=='A'? true : false);
}

int DataContainer::getLength(){
    return length;
}

std::string* DataContainer::getPointerToKeys(){
    return keys;
}

Data* DataContainer::getPointerToValues(){
    return values;
}

void DataContainer::setLength(int _length){
    length = _length;
}

void DataContainer::setType(char _type){
    if (_type=='O'||_type=='A'){
        type = _type;
    }
}

Data DataContainer::getArrayByIndex(int i){
    //Index start from 0
    if (!isArray()){
        return getNullData();
    }else{
        if (i>=length){
            return getNullData();
        }else{
            return values[i];
        }
    }
}

Data DataContainer::getObjectByKey(std::string key){
    if (!isObject()){
        return getNullData();
    }else{
        for (int loop=0;loop<length;loop++){
            if (keys[loop]==key){
                return values[loop];
            }
        }
        return getNullData();
    }
}

std::string* DataContainer::getListOfKeys(){
    if (!isObject()){
        return NULL;
    }else{
        std::string* result = new std::string[length];
        for (int loop=0;loop<length;loop++){
            result[loop] = keys[loop];
        }
        return result;
    }
}