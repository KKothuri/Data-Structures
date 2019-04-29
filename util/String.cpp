#include "String.h"

String::String() {}

String::String(const char* inp)
{
	if (!inp)
		return;
	ull size = strlen(inp);
	elements_.resize(size);
	for (ull i = 0; i < size; i++)
		elements_[i] = inp[i];
}

String::String(const String& str) { *this = str; }

const String& String::operator= (const String& str)
{
	elements_.resize(str.getElem().Size());
	for (ull i = 0; i < elements_.Size(); i++)
		elements_[i] = str.getElem()[i];
	return *this;
}

const String& String::operator= (const char* inp)
{
	*this = String(inp);
	return *this;
}

const String& String::operator+ (const char* rhs) const
{
	char* r = new char[elements_.Size() + strlen(rhs) + 1];
	for (ull i = 0; i < elements_.Size(); i++)
		r[i] = elements_[i];
	for (ull i = elements_.Size(); i < elements_.Size() + strlen(rhs); i++)
		r[i] = rhs[i - elements_.Size()];
	r[elements_.Size() + strlen(rhs)] = '\0';
	String ans(r);
	delete[] r;
	return ans;
}

const String& String::operator+ (const String& rhs) const
{
	char* r = rhs.toCString;
	String ans = *this + r;
	delete[] r;
	return ans;
}

String::operator char* () const { return toCString(); }

char* String::toCString() const
{
	char* ans = new char[elements_.Size() + 1];
	for (ull i = 0; i < elements_.Size(); i++)
		ans[i] = elements_[i];
	ans[elements_.Size()] = '\0';
	return ans;
}

const Vector<char>& String::getElem() const { return elements_; }