#include <iostream>
using namespace std;
void func(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	cout << &a << "  ADD OF A "<< endl;	
	cout << &b << "  ADD OF B "<< endl;
}

int main() {
	int x = 2;
	int y = 3;
	int *z1 = &y;
	int *z2;
	/* A */

	cout << &x << "  ADD OF X " << endl;
	cout << &y<< "  ADD OF Y " << endl;
	cout << &z1 << "  ADD OF Z1 "<< endl;
	cout << &z2<< "  ADD OF Z2 " << endl;

	func(&x, z1);
	/* B */

	
}

