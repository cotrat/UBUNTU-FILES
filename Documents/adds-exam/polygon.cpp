// pointers to base class
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
	virtual int area() { cout << "PARENTS"; }
};

class Rectangle: public Polygon {
  public:
    virtual int area()
      { return width*height; }
};

class Triangle: public Polygon {
  public:
    //int area()
     // { return width*height/2; }
	void duh() { cout << "only triangles";}
};

int main () {

	Polygon* rectt = new Rectangle();
	rectt->set_values(10,20);
	cout << rectt->area();
	
  
  return 0;
}
