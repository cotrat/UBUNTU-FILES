#include <iostream>
#include <cstdlib>
#include "math.h"
#include <vector>
#include <string>
using namespace std;
void binary();
void mem();
int main()
{
	vector<int> toSort;
	int x = 0;

	toSort.push_back(123);
	toSort.push_back(1132);
	toSort.push_back(53);
	toSort.push_back(1);
	toSort.push_back(1124);
	toSort.push_back(12456);

	cout << endl;
	int idx;
	int ydx;
	int temp;
	int minIdx;
	int n = 5;
	int ctr = 0;
	for(idx = 0; idx < n-1; idx++)
	{
		
		minIdx = idx;
		for(ydx = idx + 1; ydx < n; ydx++)
		{
			if(toSort.at(ydx) < toSort.at(minIdx))
			{
				minIdx = ydx;
			}
		}
		if(minIdx!=idx)
		{
			temp = toSort.at(idx);
			toSort.at(idx) = toSort.at(minIdx);
			toSort.at(minIdx) = temp;
		}
	}
	
	for(x = 0; x < n; x++)
	{
		cout << toSort.at(x) << " ";
	}
	
	int *b;
	b = new int(5);
	int *c;
	c = new int(6);
	cout << b <<"  "<< c;
	mem();
}

void mem()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d =0;
	cout << endl;
cout << endl;
cout << endl;
cout << endl;
cout << endl;
cout << endl;
cout << endl;
	cout << &a << endl << &b << endl << &c << endl << &d;



}

void binary()
{
	vector<int> toFind;
	toFind.push_back(1);
	toFind.push_back(6);
	toFind.push_back(86);
	toFind.push_back(1110);
	toFind.push_back(5675);
	toFind.push_back(10000);
	toFind.push_back(100001);

	int right;
	int left;
	int mid;
	int val = 1;
	left = 0;
	right = 5;
	
	while(right >= left)
	{
		mid = floor((left+right/2));
		if(val > toFind.at(mid))
		{
			left = mid + 1;
		}
		else if(val<toFind.at(mid))
		{
			right = mid - 1;
		}
		else
		{
			cout << "ITS AT INDEX " << mid;
			break;

		}
	}
	
	string t = "z";
	string s = "a";
	if(t>s)
	{
		cout << " iyca";
	}
}
	




















