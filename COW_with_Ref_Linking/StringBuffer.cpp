// Copy on write with implementation of reference linking
#include "StringBuffer.h"
#include <iostream>

StringBuffer::StringBuffer() 
{
	stringBuf = nullptr; 
}

StringBuffer::~StringBuffer() // 
{
	if (stringBuf->_refcount == 1)
	{
		delete[] stringBuf->string_buf;
		delete stringBuf->_reflink;
		delete stringBuf;
	}
	else
	{
		stringBuf->_refcount--;
		StringBuffer* add = this;
		if (stringBuf->_reflink->_address == this)
		{
			reflink* temp = stringBuf->_reflink;
			stringBuf->_reflink = stringBuf->_reflink->next;
			delete temp;
		}

		else {

			reflink* ptr = stringBuf->_reflink;
			reflink* prev = NULL;

			while (ptr)
			{
				if (ptr->_address == this)
				{
					prev->next = ptr->next;
					delete ptr;
					break;
				}
				prev = ptr;
				ptr = ptr->next;
			}

		}
	}

}
StringBuffer::StringBuffer(const StringBuffer& obj) {

	
	stringBuf->strlen = obj.length();
	stringBuf->string_buf = new char[stringBuf->strlen];
	for (int i = 0; i<stringBuf->strlen; i++)
	{
		stringBuf->string_buf[i] = obj.charAt(i);
	}
	reflink* rlinking = new reflink;
	rlinking->_address = this;
	rlinking->next = NULL;
	if (stringBuf->_reflink == NULL)
	{
		stringBuf->_reflink = rlinking;
	}
	else
	{
		reflink* ptr = stringBuf->_reflink;
		reflink*  prev = NULL;
		while (ptr)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = rlinking;
	}
}

StringBuffer::StringBuffer(char* ptr, int length)
{
	stringBuf = new stringB;
	stringBuf->string_buf = new char[length];
	stringBuf->strlen = length;
	for (int i = 0; i < length - 1; i++)
	{
		stringBuf->string_buf[i] = ptr[i];
	}
	reflink* rlinking = new reflink;
	rlinking->_address = this;
	rlinking->next = NULL;

	if (stringBuf->_reflink == NULL)
	{
		stringBuf->_reflink = rlinking;
	}
	else
	{
		reflink* ptr = stringBuf->_reflink;
		reflink*  prev = NULL;
		while (ptr)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = rlinking;
	}
}

char StringBuffer::charAt(int index) const
{
	if (index <stringBuf->strlen)
	{
		return *(stringBuf->string_buf + index);
	}
	else {

		throw"\n\n\tArray Index Out Of Bounds.\n\n";
	}
}


int StringBuffer::length() const {
	// -> returns the length of the buffer
	return stringBuf->strlen;
}

void StringBuffer::reserve(int length)
{
	// -> allocates memory of character length size
	stringBuf = new stringB;
	stringBuf->string_buf = new char[length];
	reflink* rlinking = new reflink;
	rlinking->_address = this;
	rlinking->next = NULL;
	if (stringBuf->_reflink == NULL)
	{
		stringBuf->_reflink = rlinking;
	}
	else
	{
		reflink* ptr = stringBuf->_reflink;
		reflink*  prev = NULL;
		while (ptr)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = rlinking;
	}
}

void StringBuffer::append(char c)
{
	// -> appendingcharacter at end of string

	if (stringBuf->_refcount>1)
	{
		stringB* str1 = new stringB;
		str1->strlen = stringBuf->strlen + 1;
		str1->string_buf = new char[str1->strlen];
		for (int i = 0; i < stringBuf->strlen; i++)
		{
			str1->string_buf[i] = stringBuf->string_buf[i];
		}
		str1->string_buf[stringBuf->strlen] = c;
		stringBuf->_refcount--;
		if (stringBuf->_reflink->_address == this)
		{
			reflink* str1 = stringBuf->_reflink;
			stringBuf->_reflink = stringBuf->_reflink->next;
			delete str1;
		}
		else {
			reflink* ptr = stringBuf->_reflink;
			reflink* prev = NULL;
			while (ptr)
			{
				if (ptr->_address == this)
				{
					prev->next = ptr->next;
					delete ptr;
					break;
				}
				prev = ptr;
				ptr = ptr->next;
			}

		}
		stringBuf = str1;
		reflink* rlinking = new reflink;
		rlinking->_address = this;
		rlinking->next = NULL;
		if (stringBuf->_reflink == NULL)
		{
			stringBuf->_reflink = rlinking;
		}
		else
		{
			reflink* ptr = stringBuf->_reflink;
			reflink*  prev = NULL;
			while (ptr)
			{
				prev = ptr;
				ptr = ptr->next;
			}
			prev->next = rlinking;
		}

	}
	else
	{

		char* str1 = stringBuf->string_buf;
		stringBuf->strlen++;
		stringBuf->string_buf = new char[stringBuf->strlen];
		for (int i = 0; i < stringBuf->strlen - 1; i++)
		{
			stringBuf->string_buf[i] = str1[i];
		}
		stringBuf->string_buf[stringBuf->strlen - 1] = c;
		delete[] str1;

	}


}
reflink* StringBuffer::get_link() {
	return stringBuf->_reflink;

}

StringBuffer& StringBuffer::operator = (const StringBuffer& obj)
{
	stringBuf = obj.stringBuf;
	stringBuf->_refcount++;
	reflink* rlinking = new reflink;
	rlinking->_address = this;
	rlinking->next = NULL;
	if (stringBuf->_reflink == NULL)
	{
		stringBuf->_reflink = rlinking;
	}
	else
	{
		reflink* ptr = stringBuf->_reflink;
		reflink*  prev = NULL;
		while (ptr)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = rlinking;
	}
	return *this;
}

stringB::stringB() 
{
	string_buf = nullptr;
	strlen = 0;
	_refcount = 1;
	_reflink = NULL;
}


