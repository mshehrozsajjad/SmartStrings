// Owned Pointer implementation

#include "StringBuffer.h"
#include <iostream>

// Constructor
StringBuffer::StringBuffer() 
{
	stringBuf = nullptr;	
	stringLength = 0;		
}
// Destructor
StringBuffer::~StringBuffer() 
{
	delete[] stringBuf;  
}

// Appending Function
void StringBuffer::append(char c)
{

	char* temp = stringBuf;
	stringLength++;
	stringBuf = new char[stringLength];

	for (int i = 0; i < stringLength - 1; i++)
	{
		stringBuf[i] = temp[i];
	}
	stringBuf[stringLength - 1] = c;
	delete[] temp;
}
char StringBuffer::charAt(int index) const
{
	// Checking the length given is less then the string length
	if (index < stringLength)
	{
		return *(stringBuf + index);
	}
	else {
		throw"\n\n\t##Array Index Out Of Bounds.\n\n";
	}
}
// Length of the string
int StringBuffer::length() const 
{
	return stringLength;
}

// Shallow Copying

StringBuffer::StringBuffer(const StringBuffer& obj) {

	stringLength = obj.length();
	stringBuf = new char[stringLength];

	for (int i = 0; i<stringLength; i++)
	{
		stringBuf[i] = obj.charAt(i);
	}
}
// Conversion Function
StringBuffer::StringBuffer(char* &ptr, int length)
{
	
	stringBuf = ptr;
	ptr = NULL;		// Avoiding dangling pointer
	stringLength = length;

}

void StringBuffer::reserve(int length)
{
	// -> allocates memory of character length size
	stringBuf = new char[length];

}

