#ifndef LIST_H
#define LIST_H

#include "Container.h"

#include <utility>

using ull = unsigned long long int;
using namespace std;

/*
	List(Doubly Linked) class
*/
template <class Object>

class List : public NodeBasedContainer<Object>
{
protected:
	class Node
	{
	public:
		Object data;
		Node* left;
		Node* right;
		Node(Object d) : data(d), left(NULL), right(NULL) {}
		Node(Object d, Node* l, Node *r) : data(d), left(l), right(r) {}
	};
	Node* start;
	Node* end;
public:
	List() : NodeBasedContainer<Object>(), start(NULL), end(NULL) {}
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

void List<Object>::insertFront(const Object& x)
{
	if (start)
	{
		start->left = new Node(x, NULL, start);
		start = start->left;
	}
	else start = end = new Node(x, NULL, NULL);
	this->size_++;
}

template <class Object>

void List<Object>::insertEnd(const Object& x)
{
	if (end)
	{
		end->right = new Node(x, end, NULL);
		end = end->right;
	}
	else start = end = new Node(x, NULL, NULL);
	this->size_++;
}

template <class Object>

void List<Object>::insertAt(const Object& x, ull ind)
{
	if (start)
	{
		if (!ind)
			insertFront(x);
		else
		{
			Node* t = start;
			while (--ind && t->right)
				t = t->right;
			t->right = new Node(x, t, t->right);
			this->size_++;
		}
	}
	else insert(x);
}

template <class Object>

pair<bool, ull> List<Object>::find (const Object& x) const
{
	if (start)
	{
		ull ind = 0;
		Node* t = start;
		while (t && t->data != x)
		{
			t = t->right;
			ind++;
		}
		return make_pair(t, ind);
	}
	else return make_pair(false, 0);
}

template <class Object>

void List<Object>::remove(const Object& x)
{
	pair<bool, ull> r = find(x);
	if(r.first)
        removeAt(r.second);
}

template <class Object>

void List<Object>::removeAt(ull ind)
{
	if(ind < this->size_)
    {
        if(!ind)
        {
            Node* t = start;
            start = start->right;
            if(t == end)
                end = end->right;
            delete t;
            if(start)
                start->left = NULL;
            this->size_--;
            return;
        }
        Node* t = start;
		while (ind--)
			t = t->right;
		if(t == end)
		{
		    end = t->left;
		    delete t;
		    end->right = NULL;
		    this->size_--;
		    return;
		}
		t->left->right = t->right;
		t->right->left = t->left;
		delete t;
		this->size_--;
    }
}

template <class Object>

void List<Object>::removeBack()
{
	if(end)
    {
        Node* t = end;
        end = end->left;
        delete t;
        if(end)
            end->right = NULL;
        this->size_--;
    }
}

#endif
