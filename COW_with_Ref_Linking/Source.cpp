// Main function for Copy on write implementation with reference counting

#include "StringBuffer.h"
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
	//create a smart string
	//create a smart string with const char*
	char* obj = "Hello";
	StringBuffer* object1 = new StringBuffer(obj, 5);
	StringBuffer* object2 = new StringBuffer();
	// Object referencing
	*object2 = *object1;

	int i = 0; 

	reflink* li = object1->get_link();
	// Checking reference of object 
	while (li) {

		if (li->_address == object2) {
			i = 1;
			break;
		}
		li = li->next;
	}
	cout << "Copy on Write Implementation wiht Reference Linking " << std::endl;
	// Checking Length Function
	cout << "Object 1 Length =" << object1->length() << std::endl;
	cout << "Object 2 Length =" << object2->length() << std::endl;
	// Checking if reference is found or not
	if (i ==1)
		cout << "Object 2 is in reference of Object 1"  << std::endl;
	// Checking Append Fucntion
	object1->append('a'); // 1st character append to obj 1
	object2->append('h'); // 1st character append to obj 2
	object2->append('w'); // 2nd character appedn to obj 2
	std::cout << "Object 1 charAt 3 = " << object1->charAt(3) << std::endl;
	std::cout << "Object 2 charAt 6 = " << object2->charAt(6) << std::endl;
	getchar();
	return 0;
}

