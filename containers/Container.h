#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>

#define ull unsigned long long int

using namespace std;

/*
Container Abstract Class
All structures will be derived from this
*/
template <class Object>

class Container
{
protected:
	ull size_;
public:
	Container() : size(0) {}
	virtual void insert(Object& x) = 0;
	virtual void remove(Object& x) = 0;
	virtual bool isPresent const(Object& x) = 0;
	ull size() const { return size_; }
};

/*
	ArrayBasedContainer Abstract Class
	Superclass of structures which use arrays as an underlying data structure.
	Stacks, Queues, Heaps, Graphs etc.
*/
template <class Object>

class ArrayBasedContainer : public Container
{
protected:
	vector<Object> elements_;
public:
	ArrayBasedContainer() : Container(0) {};
	ArrayBasedContainer(ull size)
	{
		size_ = size;
		elements_.resize(size);
	}
	ull capacity() const { return elements_.capacity() };
};

/*
	NodeBasedContainer Abstract Class
	Superclass of structures which use nodes, pointers and references to store data.
	Lists, Trees, Graphs etc.
*/
template <class Object>

class NodeBasedContainer : public Container
{
protected:
	virtual class Node { Object data; };
public:
	NodeBasedContainer() : Container(0) {};
};

#undef ull

#endif