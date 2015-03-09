#include <iostream>

using namespace std;

int main() {
    const int ARRAY_SIZE = 10;
    int a[ARRAY_SIZE];
    int* b; // A dynamic array 
    int* c; // another

    b = new int[ARRAY_SIZE];

	int d,e,f;
	d = sizeof(a);
	e = sizeof(b);
	f = sizeof(c);


    for(unsigned int idx = 0; idx < ARRAY_SIZE; idx++) {
        a[idx] = idx;
        b[idx] = idx;
    }

    delete []b;

    c = new int[ARRAY_SIZE];
    for(unsigned int idx = 0; idx < ARRAY_SIZE; idx++) {
        b[idx] = b[idx] + 1;
    }

    delete []c;

    return 0;
}
