#ifndef STACK_H
#define STACK_H
#include "status_code.h"

template<class T>
class Stack{
    private:
        T* top;
        T* bottom;
        int size;               //allocated memory size
        int length;             //used space
        short size_increment;
        int mem_increase();
    public:
        Stack(int _size=50);
        int push(T data); 
        int pop(T* result);         //result contain poped data
        int getSize();              //return size of stack
        int getLength();            //return length of stack
        int setSizeincrement(int i); //return current size_increment
        int emptyStack();
        ~Stack();
};

#endif
