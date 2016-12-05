/*

	COPIED POINTERS

*/
#include <iostream>

class String {

private:
	char* strbuf;                              //buffer to store the original string
	int size;                                //size of the string

public:
	String()                              //default constructor
	{
		strbuf = NULL;
		size = 0;
	}
	~String()                            //destructor; would delete the allocated buffer
	{
		delete[size] strbuf;
		size = 0;
	}
	String(const String& source)          //constructor for deep copying
	{
		strbuf = new char[source.size];
		for (int i = 0; i < source.size; i++)
		{
			strbuf[i] = source.strbuf[i];
		}
		size = source.size;
	}
	String(char* string, int len)                   //constructor to convert a char* to String
	{
		reserve(len);
		for (int i = 0; i < len; i++)
		{
			strbuf[i] = string[i];
		}
	}
	char charAt(int index) const                     //returns the character at the passed index
	{
		if (index < size)
			return strbuf[index];
	}
	int length() const                         //returns the size of the buffer
	{
		return size;
	}
	void reserve(int len)                          //allocates memory for the string, according to the passed character size
	{
		
		strbuf = new char[len];
		size = len;
		delete[] strbuf;
	}
	void append(char temp)                          //appends a single character at the end
	{
		char* newString = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			newString[i] = strbuf[i];
		}
		newString[size] = temp;
		delete[size] strbuf;
		strbuf = newString;
		size++;
	}
	void print()								// Only for testing
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << strbuf[i];
		}
	}
};

int main(void)
{
	String string2("Shehro", 6);
	String string(string2);
	string.print();
	string.append('z');
	std::cout << "\n";
	string.print();
	std::cout << "\n";
	string2.print();
	std::cout << "\n";

	return 0;
}