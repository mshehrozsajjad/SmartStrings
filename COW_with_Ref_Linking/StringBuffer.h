#pragma once
#include <iostream>
class reflink;
class stringB;
class StringBuffer;

class reflink
{
public:
	StringBuffer* _address;
	reflink* next;
};

class stringB
{
public:
	char* string_buf;    
	int strlen;      
	int _refcount;		
	reflink* _reflink;	
	stringB();	
};

class StringBuffer {

public:
	StringBuffer();  
	~StringBuffer();                
	StringBuffer(const StringBuffer&); 
	StringBuffer(char*, int);  
	char charAt(int) const;   
	int length() const;      
	void reserve(int);       
	void append(char);       
	reflink* get_link();	
	StringBuffer& operator = (const StringBuffer&);

private:
	stringB*  stringBuf;
};


