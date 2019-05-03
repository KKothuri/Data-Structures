#ifndef XORLIST_H
#define XORLIST_H

#include "Container.h"

#include <utility>

using ull = unsigned long long int;
using namespace std;

/*
	XORList(Memory Efficient Doubly Linked List) class
*/
template <class Object>

class XORList : public NodeBasedContainer<Object>
{
protected:
	class Node
	{
	public:
		Object data;
		Node* ptr;
		Node(Object d) : data(d), ptr(NULL) {}
		Node(Object d, Node* p) : data(d), ptr(p) {}
	};
	Node* start;
	Node* end;
public:
	XORList() : NodeBasedContainer<Object>(), start(NULL), end(NULL) {}
	Object& operator[] (ull index);
	const Object operator[] (ull index) const;
	void insert(const Object& x) { insertEnd(x); }
	void insertFront(const Object& x);
	void insertEnd(const Object& x);
	void insertAt(const Object& x, ull ind);
	pair<bool, ull> find (const Object& x) const;
	void remove(const Object& x);
	void removeAt(ull ind);
	void removeFront() { removeAt(0); }
	void removeBack();
	bool isPresent (const Object& x) const { return find(x).first; }
};

template <class Object>

Object& XORList<Object>::operator[] (ull ind)
{
	if (ind < this->size_)
	{
        Node* prev = NULL;
        Node* t = start;
        while (ind-- && (Node *)((uintptr_t)t->ptr ^ (uintptr_t)prev))
        {
            Node* p = t;
            t = (Node *)((uintptr_t)t->ptr ^ (uintptr_t)prev);
            prev = p;
        }
        return t->data;
	}
	else
	{
		cout << "Invalid index " << ind << ".\n";
		exit(1);
	}
}

template <class Object>

const Object XORList<Object>::operator[] (ull ind) const
{
	if (ind < this->size_)
	{
        Node* prev = NULL;
        Node* t = start;
        while (ind-- && (Node *)((uintptr_t)t->ptr ^ (uintptr_t)prev))
        {
            Node* p = t;
            t = (Node *)((uintptr_t)t->ptr ^ (uintptr_t)prev);
            prev = p;
        }
        return t->data;
	}
	else
	{
		cout << "Invalid index " << ind << ".\n";
		exit(1);
	}
}

template <class Object>

void XORList<Object>::insertFront(const Object& x)
{
	if (start)
	{
		Node* t = new Node(x, start);
		start->ptr = (Node *)((uintptr_t)t ^ (uintptr_t)start->ptr);
		start = t;
	}
	else start = end = new Node(x, NULL);
	this->size_++;
}

template <class Object>

void XORList<Object>::insertEnd(const Object& x)
{
	if (end)
	{
	    Node* t = new Node(x, end);
		end->ptr = (Node *)((uintptr_t)t ^ (uintptr_t)end->ptr);
		end = t;
	}
	else start = end = new Node(x, NULL);
	this->size_++;
}

template <class Object>

void XORList<Object>::insertAt(const Object& x, ull ind)
{
	if (start)
	{
		if (!ind)
			insertFront(x);
		else
		{
		    Node* prev = NULL;
			Node* t = start;
			while (--ind && (Node *)((uintptr_t)t->ptr ^ (uintptr_t)prev))
			{
			    Node* p = t;
			    t = (Node *)((uintptr_t)t->ptr ^ (uintptr_t)prev);
			    prev = p;
			}
			Node* next = (Node *)((uintptr_t)t->ptr ^ (uintptr_t)prev);
			next->ptr = (Node *)((uintptr_t)t ^ (uintptr_t)next->ptr);
			t->ptr = (Node *)((uintptr_t)t->ptr ^ (uintptr_t)next);
			Node* temp = new Node(x, t ^ next);
			t->ptr = (Node *)((uintptr_t)t->ptr ^ (uintptr_t)temp);
			next->ptr = (Node *)((uintptr_t)next->ptr ^ (uintptr_t)temp);
			this->size_++;
		}
	}
	else insert(x);
}

template <class Object>

pair<bool, ull> XORList<Object>::find (const Object& x) const
{
	if (start)
	{
		ull ind = 0;
		Node* prev = NULL;
		Node* t = start;
		while (t && t->data != x)
		{
			Node* p = t;
            t = (Node *)((uintptr_t)t->ptr ^ (uintptr_t)prev);
            prev = p;
			ind++;
		}
		return make_pair(t, ind);
	}
	else return make_pair(false, 0);
}

template <class Object>

void XORList<Object>::remove(const Object& x)
{
	pair<bool, ull> r = find(x);
	if(r.first)
        removeAt(r.second);
}

template <class Object>

void XORList<Object>::removeAt(ull ind)
{
	if(ind < this->size_)
    {
        if(!ind)
        {
            Node* t = start;
            start = start->ptr;
            if(start)
                start->ptr = (Node *)((uintptr_t)start->ptr ^ (uintptr_t)t);
            if(t == end)
                end = end->ptr;
            delete t;
            this->size_--;
            return;
        }
        Node* prev = NULL;
        Node* t = start;
		while (ind--)
		{
		    Node* p = t;
			t = (Node *)((uintptr_t)t->ptr ^ (uintptr_t)prev);
			prev = p;
		}
		if(t == end)
		{
		    end = t->ptr;
		    end->ptr = (Node *)((uintptr_t)t ^ (uintptr_t)end->ptr);
		    delete t;
		    this->size_--;
		    return;
		}
		Node* next = (Node *)((uintptr_t)t->ptr ^ (uintptr_t)prev);
		prev->ptr = (Node *)((uintptr_t)t ^ (uintptr_t)next ^ (uintptr_t)prev->ptr);
		next->ptr = (Node *)((uintptr_t)t ^ (uintptr_t)prev ^ (uintptr_t)next->ptr);
		delete t;
		this->size_--;
    }
}

template <class Object>

void XORList<Object>::removeBack()
{
	if(end)
    {
        Node* t = end;
        end = end->ptr;
        if(end)
            end->ptr = (Node *)((uintptr_t)t ^ (uintptr_t)end->ptr);
        delete t;
        this->size_--;
    }
}

#endif
