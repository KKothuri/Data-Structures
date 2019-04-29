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
	ull size;
public:
	Container() : size(0) {}
	virtual void insert(Object& x) = 0;
	virtual void remove(Object& x) = 0;
	virtual bool isPresent(Object& x) = 0;
	ull size() { return size; }
};

/*
	ArrayBasedContainer Abstract Class
	Superclass of structures which use arrays as an underlying data structure.
	Stacks, Queues, Heaps, Graphs etc.
*/
template <class Object>

class ArrayBasedContainer : Container
{
protected:
	vector<Object> elements;
public:
	ArrayBasedContainer() : size(0) {};
	ArrayBasedContainer(ull size)
	{
		try
		{
			if (size < 0)
				throw size;
			else
			{
				this.size = size;
				elements.resize(size);
			}
		}
		catch (ull x)
		{
			cout << "Invalid initialisation size of " << x << ".\nInitialising with default constructor.\n";
			ArrayBasedContainer();
		}
	}
};

/*
	NodeBasedContainer Abstract Class
	Superclass of structures which use nodes, pointers and references to store data.
	Lists, Trees, Graphs etc.
*/
template <class Object>

class NodeBasedContainer : Container
{
protected:
	virtual class Node {};
};

#undef ull

#endif