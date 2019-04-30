#ifndef STRING_H
#define STRING_H

#include "Vector.h"
#include <cstring>

class String
{
	Vector<char> elements_;
public:
	String() : elements_(1, 0) {};
	String(const char* inp);
	String(const String& str);
	String(const char& inp);
	const String& operator= (const String& str);
	const String& operator= (const char* inp);
	const String& operator= (const char& inp);
	const String operator+ (const char* rhs) const;
	const String operator+ (const String& rhs) const;
	const String operator+ (const char& rhs) const;
	String& operator+=(const String& rhs);
	String& operator+=(const char* rhs);
	String& operator+=(const char& rhs);
	operator char* () const;
	char& operator[] (ull index);
	const char operator[] (ull index) const;
	const Vector<char>& getElem() const;
	ull length() const;
	
	friend istream& operator>> (istream& is, String& str);
};

#endif