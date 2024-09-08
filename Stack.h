#ifndef STACK_H
#define STACK_H
#include "status_code.h"

template<typename T>
class Stack{
    private:
        T* top;
        T* bottom;
        int size;               //allocated memory size
        int length;             //used space
        short size_increment = 20;
        int mem_increase();
    public:
        Stack(int _size=50);
        T* push(T data);        //return pointer of top
        T pop();                //return poped data
        int getSize();          //return size of stack
        int getLength();        //return length of stack
        int setSizeincrement(int i); //return current size_increment
        int emptyStack();
        ~Stack();
};

#endif
