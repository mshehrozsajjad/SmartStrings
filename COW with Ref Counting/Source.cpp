#include <iostream>
#include <cstdlib>
#include <cstring>

#include "StringBuffer.h"

using namespace std;

int main(int argc, char** argv) {
	char* name = "Shehro";
	StringBuffer* object = new StringBuffer(name, 6);
	StringBuffer* object2 = new StringBuffer();

	*object2 = *object;
	
	object2->append('z'); 
	cout << "Ref counting write implementation "<< endl;
	cout << "object 1 length =" << object->length() << endl;
	cout << "object 2 length =" << object2->length() <<endl;
	std::cout << "New charAt 0 = " << object->charAt(0) << endl;
	return 0;
}

