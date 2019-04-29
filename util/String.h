#ifndef STRING_H
#define STRING_H

#include "Vector.h"
#include <cstring>

class String
{
	Vector<char> elements_;
public:
	String();
	String(const char* inp);
	String(const String& str);
	const String& operator= (const String& str);
	const String& operator= (const char* inp);
	const String& operator+ (const char* rhs) const;
	const String& operator+ (const String& rhs) const;
	operator char* () const;
	char* toCString() const;
	const Vector<char>& getElem() const;
};

#endif