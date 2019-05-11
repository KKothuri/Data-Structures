#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Container.h"
#include <functional>
#include <algorithm>

template <class Object>
using comparer = std::function<bool(const Object& a, const Object& b)>;

/*
	BST class
*/
template <class Object, comparer<Object> comp = [](const Object& a, const Object& b){ return a < b; }>

class BinarySearchTree : public NodeBasedContainer<Object>
{
protected:
	class Node
	{
	    Object data;
	    Node* left;
	    Node* right;
	    ull tsize;
	    ull height;
		Node(Object d, Node* l = NULL, Node* r = NULL) : data(d), left(l), right(r), tsize(1), height(0) {}
	};
	Node* root;
    virtual void insert(Node*& t, const Object& x);
    Node* find(Node*& t, const Object& x) const;
    virtual void remove(Node*& t, const Object& x);
    long long heightOf(Node* t) { return t ? t->height : -1; }
    ull sizeOf(Node* t) { return t ? t->tsize : 0; }
public:
	BinarySearchTree() : NodeBasedContainer<Object>(), root(NULL) {}
	void insert(const Object& x) { insert(root, x); this->size_--; }
	Node* find (const Object& x) const { return find(root, x); }
	void remove(const Object& x) {
	    if(isPresent(x))
        {
            remove(root, x);
            this->size_--;
        }
        else cout << "Element not found\n";
    }
	bool isPresent (const Object& x) const { return find(x); }
	ull countOf(const Object& x) {
	    Node* t = find(x);
	    return t ? t->tsize - sizeOf(t->left) - sizeOf(t->right) : 0;
	};
	const Object& findMin() const;
	const Object& findMax() const;
};

template <class Object, std::function<bool(const Object& a, const Object& b)> comp>

void BinarySearchTree<Object, comp>::insert(Node*& t, const Object& x)
{
    if(!t)
    {
        t = new Node(x);
        return;
    }
    if(t->data != x)
        comp(x, t->data) ? insert(t->left, x) : insert(t->right, x);
    t->tsize++;
    t->height = std::max(heightOf(t->left), heightOf(t->right)) + 1;
}

template <class Object, std::function<bool(const Object& a, const Object& b)> comp>

BinarySearchTree<Object, comp>::Node* BinarySearchTree<Object, comp>::find(Node*& t, const Object& x)
{
    if(!t || t->data == x)
        return t;
    return comp(x, t->data) ? find(t->left, x) : find(t->right, x);
}

template <class Object, std::function<bool(const Object& a, const Object& b)> comp>

const Object& BinarySearchTree<Object, comp>::findMin() const
{
    if(!root)
        cout << "Empty BST\n";
    else
    {
        Node* t = root;
        while(t->left)
            t = t->left;
        return t->data;
    }
}

template <class Object, std::function<bool(const Object& a, const Object& b)> comp>

const Object& BinarySearchTree<Object, comp>::findMax() const
{
    if(!root)
        cout << "Empty BST\n";
    else
    {
        Node* t = root;
        while(t->right)
            t = t->right;
        return t->data;
    }
}

template <class Object, std::function<bool(const Object& a, const Object& b)> comp>

void BinarySearchTree<Object, comp>::remove(Node*& t, const Object& x)
{
    if(t->data != x)
    {
        comp(x, t->data) ? find(t->left, x) : find(t->right, x);
        t->tsize--;
    }
    else
    {
        if(t->tsize - sizeOf(t->left) - sizeOf(t->right) > 1)
            t->tsize--;
        else
        {
            if(t->left && t->right)
            {
                Node* m = t->right;
                while(m->left)
                    m = m->left;
                t->data = m->data;
                t->tsize--;
                ull red = m->tsize;
                m = t->right;
                while(m->left->left)
                {
                    m->tsize -= red;
                    m = m->left;
                }
                delete m->left;
                m->left = NULL;
            }
        }
    }
}

#endif
