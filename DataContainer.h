#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include <string>
#include <cstring>

// Define a common container for object, array
// Object is a list indexed by string keys
// Array is a list indexed by serial number 

typedef struct Data{
    void* data;
    std::string type;
}Data;

class DataContainer {
    private:
        std::string* keys;    //valid if is object
        Data* values;  //always valid
        int length;
        char type;      //'O' for object, 'A' for array
        friend class JsonAnalyze;
        Data getNullData();
        Data* getPointerToValues();
        std::string* getPointerToKeys();
        void setLength(int _length);
        void setType(char _type);
    public:
        DataContainer(int _length, char _type);
        bool isObject();
        bool isArray();
        int getLength();
        std::string* getListOfKeys();
        Data getObjectByKey(std::string key);
        Data getArrayByIndex(int i);

};

#endif //DATASTORAGE_H
