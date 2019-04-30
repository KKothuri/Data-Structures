#include "String.h"

String::String(const char* inp)
{
	if (!inp)
		return;
	ull size = strlen(inp);
	elements_.resize(size + 1);
	for (ull i = 0; i < size; i++)
		elements_[i] = inp[i];
	elements_[size] = 0;
}

String::String(const String& str) { *this = str; }

String::String(const char& inp)
{
	elements_.resize(2);
	elements_[0] = inp;
	elements_[1] = 0;
}

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

const String& String::operator= (const char& inp)
{
	*this = String(inp);
	return *this;
}

const String String::operator+ (const char* rhs) const
{
	ull ssize = length();
	char* r = new char[ssize + strlen(rhs) + 1];
	for (ull i = 0; i < ssize; i++)
		r[i] = elements_[i];
	for (ull i = ssize; i < ssize + strlen(rhs); i++)
		r[i] = rhs[i - ssize];
	r[ssize + strlen(rhs)] = '\0';
	String ans(r);
	delete[] r;
	return ans;
}

const String String::operator+ (const String& rhs) const
{
	char* r = rhs;
	String ans = *this + r;
	delete[] r;
	return ans;
}

const String String::operator+ (const char& rhs) const
{
	char* r = new char[2];
	r[0] = rhs;
	r[1] = '\0';
	String ans = *this + r;
	delete[] r;
	return ans;
}

String& String::operator+=(const String& rhs)
{
	*this = *this + rhs;
	return* this;
}

String& String::operator+=(const char* rhs)
{
	*this = *this + rhs;
	return* this;
}

String& String::operator+=(const char& rhs)
{
	*this = *this + rhs;
	return* this;
}

String::operator char* () const
{
	char* ans = new char[length() + 1];
	for (ull i = 0; i < length(); i++)
		ans[i] = elements_[i];
	ans[length()] = '\0';
	return ans;
}

char& String::operator[] (ull index) { return elements_[index]; }

const char String::operator[] (ull index) const { return elements_[index]; }

const Vector<char>& String::getElem() const { return elements_; }

ull String::length() const { return elements_.Size() - 1; }

istream& operator>> (istream& is, String& str)
{
	str = "";
	char c;
	cin.get(c);
	while (!(c != ' ' && c != '\n' && c != '\t'))
		cin.get(c);
	while (c != ' ' && c != '\n' && c != '\t')
	{
		str += c;
		cin.get(c);
	}
	return is;
}