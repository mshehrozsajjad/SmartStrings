#include <iostream>
#include "StringBuffer.h" 

StringBuffer::StringBuffer() 
{
	str = nullptr; 
}
StringBuffer::~StringBuffer() 
{
	if (str->refcount == 1)
	{
		delete[] str->stringBuf;
		delete str;
	}
	else
	{
		str->refcount--;
	}
}

strinB* StringBuffer::getstr() 
{
	return str;
}
StringBuffer::StringBuffer(const StringBuffer& obj) {

	
	str->len = obj.length();
	str->stringBuf = new char[str->len];
	for (int i = 0; i<str->len; i++)
	{
		str->stringBuf[i] = obj.charAt(i);
	}
}

StringBuffer::StringBuffer(char* ptr, int length)
{
	
	str = new strinB;
	str->stringBuf = new char[length];
	str->len = length;
	for (int i = 0; i < length - 1; i++)
	{
		str->stringBuf[i] = ptr[i];
	}
}

char StringBuffer::charAt(int index) const
{
	if (index < str->len) 
	{
		return *(str->stringBuf + index);
	}
	else {
		throw"Out of limit array index";
	}

}

int StringBuffer::length() const 
{
	return str->len;
}

void StringBuffer::reserve(int length)
{
	
	str = new strinB;
	str->stringBuf = new char[length];
}

void StringBuffer::append(char c)
{

	if (str->refcount>1)
	{
		strinB* str1 = new strinB;
		str1->len = str->len + 1;
		str1->stringBuf = new char[str1->len];
		for (int i = 0; i < str->len; i++)
		{
			str1->stringBuf[i] = str->stringBuf[i];
		}
		str1->stringBuf[str->len] = c;
		str->refcount--;
		str = str1;

	}
	else
	{

		char* str1 = str->stringBuf;
		str->len++;
		str->stringBuf = new char[str->len];
		for (int i = 0; i < str->len - 1; i++)
		{
			str->stringBuf[i] = str1[i];
		}
		str->stringBuf[str->len - 1] = c;
		delete[] str1;

	}


}
strinB::strinB()
{
	stringBuf = nullptr;
	len = 0;
	refcount = 1;
}
// Operator Overloading
StringBuffer& StringBuffer::operator = (const StringBuffer& obj)
{
	str = obj.str;
	str->refcount++;
	return *this;
}



