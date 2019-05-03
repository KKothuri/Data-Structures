#ifndef STACK_H
#define STACK_H

#include "XORList.h"

/*
	Stack class to mimic STL stack.
*/
template <class Object>

class Stack
{
    XORList<Object> elem_;
public:
    void push(const Object& x) { elem_.insertFront(x); }
    Object top() { if(size()) return elem_[0]; }
    void pop() { if(size()) elem_.removeFront(); }
    ull size() { return elem_.size(); }
    bool isEmpty() { return size() == 0; }
};

#endif
