#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>

using namespace std;

using ull = unsigned long long int;

//Vector class to mimic the STL vector class
template <class Object>

class Vector
{
	static const ull maxsize = 4611686018427387903;
	ull size;
	Object* elements;
	ull capacity;
	void allocate(ull size);
public:
	Vector() : size(0), capacity(0), elements(NULL) {}
	Vector(ull size) { allocate(size); }
	Vector(ull size, const Object& init);
	Vector(const Vector& v);
	~Vector() { if (elements) delete[] elements; }
	Vector& operator= (const Vector& p);
	bool operator== (const Vector& p2) const;
	Object& operator[] (ull index);
	const Object operator[] (ull index) const;
	ull max_size() const { return maxsize; }
	ull Size() const { return size; }
	ull Capacity() const { return capacity; }
	void resize(ull size);
	void push_back(Object& x);
	void pop_back();
	void clear() { if (elements) delete[] elements; elements = NULL; capacity = size = 0; }
	void erase(ull i);
	void erase(ull i, ull j);
};

template <class Object>

void Vector<Object>::allocate(ull size)
{
	try
	{
		if (size < 0)
			throw size;
		this->size = size;
		capacity = size;
		elements = capacity ? new Object[capacity] : NULL;
	}
	catch (ull x)
	{
		cout << "Invalid initialisation size of " << x << " for a Vector.\nInitialising with default constructor.\n";
		elements = NULL;
		size = capacity = 0;
	}
}

template <class Object>

Vector<Object>::Vector(ull size, const Object& init)
{
	allocate(size);
	for (ull i = 0; i < capacity; i++)
		elements[i] = init;
}

template <class Object>

Vector<Object>::Vector(const Vector<Object>& v) { *this = v; }

template <class Object>

Vector<Object>& Vector<Object>::operator= (const Vector<Object> & p)
{
	resize(p.Size());
	for (int i = 0; i < p.Size(); i++)
		elements[i] = p[i];
	return *this;
}

template <class Object>

bool Vector<Object>::operator== (const Vector<Object> & p2) const
{
	bool ans = size == p2.Size();
	for (int i = 0; ans && i < size; i++)
		ans &= elements[i] == p2[i];
	return ans;
}

template <class Object>

Object& Vector<Object>::operator[] (ull index)
{
	if (index < size)
		return elements[index];
	else
	{
		cout << "Invalid index " << index << ".\n";
		exit(1);
	}
}

template <class Object>

const Object Vector<Object>::operator[] (ull index) const
{
	if (index < size)
		return elements[index];
	else
	{
		cout << "Invalid index " << index << ".\n";
		exit(1);
	}
}

template <class Object>

void Vector<Object>::resize(ull size)
{
	if (this->size == size)
		return;
	capacity = size;
	Object * temp = capacity ? new Object[capacity] : NULL;
	for (ull i = 0; i < min(size, this->size); i++)
		temp[i] = elements[i];
	if (elements)
		delete[] elements;
	elements = temp;
	this->size = size;
}

template <class Object>

void Vector<Object>::push_back(Object & x)
{
	if (capacity > size)
		elements[size++] = x;
	else
	{
		try
		{
			if (capacity * 2 > maxsize)
				throw 1;
			capacity *= 2;
			Object* temp = new Object[capacity];
			for (ull i = 0; i < size; i++)
				temp[i] = elements[i];
			temp[size++] = x;
			delete[] elements;
			elements = temp;
		}
		catch (int ec)
		{
			if (ec == 1)
				cout << "Max size reached\n";
		}
	}
}

template <class Object>

void Vector<Object>::pop_back()
{
	try
	{
		if (size = 0)
			throw 1;
		size--;
	}
	catch (int ec)
	{
		if (ec == 1)
			cout << "No elements in Vector\n";
	}
}

template <class Object>

void Vector<Object>::erase(ull i)
{
	try
	{
		if (i < 0 || i >= size)
			throw 1;
		for (int t = i; t < size - 1; t++)
			elements[t] = elements[t + 1];
		size--;
	}
	catch (int ec)
	{
		if (ec == 1)
			cout << "Index out of Bounds\n";
	}
}

template <class Object>

void Vector<Object>::erase(ull i, ull j)
{
	try
	{
		if (i < 0 || i > j || j >= size)
			throw 1;
		for (int t = i; t < size - j - 1; t++)
			elements[t] = elements[t + j - i + 1];
		size -= j - i + 1;
	}
	catch (int ec)
	{
		if (ec == 1)
			cout << "Indices out of Bounds\n";
	}
}

#endif
