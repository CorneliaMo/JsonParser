#include "Stack.h"

template<typename T>
Stack<T>::Stack(int _size){
	size = _size;
    length = 0;
    top = bottom = new T[size];
}

template<typename T>
int Stack<T>::pop(T* result){
    if (top==nullptr){
        //Memory error
        result == nullptr;
        return nullptr;
    }else if(top==bottom){
        //reach the bottom
        //clear the memory
        T tmp = *top;
        delete[] bottom;
        top = bottom =nullptr;
        size = length = 0;
        *result = tmp;
        return OK;
    }else{
        //default situation
        T tmp = *top;
        length--;
        top--;
        *result = tmp;
        return OK;
    }
}

template<typename T>
int Stack<T>::mem_increase(){
    try
    {
        //allocate new memory
        T* tmp_pointer = new T[size+size_increment];
        //move the data
        for (int loop=0;loop<size;loop++){
            tmp_pointer[loop] = bottom[loop];
        }
        //release memory
        delete[] bottom;
        //relocate the pointer
        bottom = tmp_pointer;
        top = tmp_pointer+length-1;
        size += size_increment;
        return OK;
    }
    catch(...)
    {
        return ERROR;
    }
}

template<typename T>
T* Stack<T>::push(T data){
    if (size==length){
        //memory is full
        mem_increase();        
    }
    top++;
    *top = data;
    length++;
    return top;
}

template<typename T>
int Stack<T>::getSize(){
    return size;
}

template<typename T>
int Stack<T>::getLength(){
    return length;
}

template<typename T>
int Stack<T>::setSizeincrement(int i){
    size_increment = i;
    return size_increment;
}

template<typename T>
Stack<T>::~Stack(){
    if (bottom!=nullptr){
        delete[] bottom;
    }
}

template<typename T>
int Stack<T>::emptyStack(){
    if (bottom!=nullptr){
        delete[] bottom;
    }
    bottom = top = new T[size_increment];
    size = size_increment;
    length = 0;
    return OK;
}