#pragma once
// StringBuffer.h for Owned Pointer
#include <iostream>
class StringBuffer {

public:
	//
	StringBuffer();			//Constructor
	~StringBuffer();        //Destructor
	char charAt(int) const;	//	Character Index
	int length() const;		// String length
	void reserve(int);     // Memory Allocation
	void append(char);      //Appending character to string
	StringBuffer(const StringBuffer&);  //Shallow Copying
	StringBuffer(char*&, int);			//Conversion 



private:
	char* stringBuf;       //String Buffer
	int stringLength;            //Length of string
};
