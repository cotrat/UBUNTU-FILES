#include <iostream>
#include <cstring>
using namespace std;

void stringPointerOperation(char* str, char* firstPtr, char* secondPtr)
{
cout << str << endl;
cout << "First character=" << *firstPtr << endl;
cout << "Second character =" << *secondPtr << endl;
}


int main()
{
	int ctr =0;
	char word[] = "hello";
	char* start = word;
	char* end = word+4;

	cout << word << "the add of word " << endl;
	cout << *start << "the add of start " << endl;
	cout << end << "the add of edn" << endl;
	cout << *start + (end -*start);
	
	

}


