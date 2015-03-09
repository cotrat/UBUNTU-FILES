#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class ShipBoxes
{
  public:
	

	int cost(int a, int b, int c)
	{
		// Try each way of picking the "double thickness end"
		int x = (4 * a * b) + (2 * b * c) + (2 * a * c); 
		int y = (2 * a * b) + (4 * b * c) + (2 * a * c);
		int z = (2 * a * b) + (2 * b * c) + (4 * a * c);
		
		return min(z,min(x,y));
	}

	int calcMax(vector<int> box1, vector<int> box2)
	{
		sort(box1.begin(),box1.end()); 
    		sort(box2.begin(),box2.end()); 
		int cnt = 0;
    		int min = std::numeric_limits<int>::max();
    		do { 
      			do { 
				int a = box1[0]; 
				int b = box1[1]; 
				int c = box1[2]+box2[2];
				cout << a << "x" << b << "x" << c << endl;
				int cc = cost(a,b,c);
				if(cc < min)
				{
					cout << a << "x" << b << "x" << c << " winner "<< endl;
					min = cc;
				}
 
		      	} while(next_permutation(box2.begin(),box2.end())); 
		} while(next_permutation(box1.begin(),box1.end())); 
		cout << endl << min;
		
	}
	

	
	
		       
};
 
int main()
{
      	ShipBoxes a;
	long long l;
	int complearr[] = {1, 4, 9};
	vector<int> comple(complearr,complearr + sizeof(complearr) / sizeof(int) );

	int complearr2[] = {1, 4, 9};
	vector<int> comple2(complearr2,complearr2 + sizeof(complearr2) / sizeof(int) );
	
	l = a.calcMax(comple,comple2);
	//cout << l;
	//a.countMax(comple);

	
}
