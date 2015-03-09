#include <iostream>
using namespace std;

class A
{
public:
    int foo(int c) { c = c+1; return c; };
};

class B : public A
{
public:
    int foo(int c) { c = c-1; return c; };
};

int main()
{
  
   A item1;
   B item2;
   cout << item2.foo(10);
	cout<<item1.foo(10);
	A* newb = new B();
	cout << newb->foo(10);

    return 0;
}
