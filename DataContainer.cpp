#include "DataContainer.h"

DataContainer::DataContainer(){

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

Data DataContainer::getElementByIndex(int i){
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

Data DataContainer::operator[](int i){
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

Data DataContainer::getElementByKey(std::string key){
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

Data DataContainer::operator[](std::string key){
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

std::string* DataContainer::getListOfKey(){
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