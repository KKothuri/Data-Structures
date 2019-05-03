#ifndef QUEUE_H
#define QUEUE_H

#include "XORList.h"

/*
	Queue class to mimic STL queue.
*/
template <class Object>

class Queue
{
    XORList<Object> elem_;
public:
    void push(const Object& x) { elem_.insertEnd(x); }
    Object front() { if(size()) return elem_[0]; }
    void pop() { if(size()) elem_.removeFront(); }
    ull size() { return elem_.size(); }
    bool isEmpty() { return size() == 0; }
};

#endif
