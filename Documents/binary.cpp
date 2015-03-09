#include <vector>
#include <iostream>
#include "math.h"
using namespace std;
void selection();
void insertion();
int main()
{
	vector<int> toFind;
	toFind.push_back(1);
	toFind.push_back(6);
	toFind.push_back(86);
	toFind.push_back(1110);
	toFind.push_back(5675);
	toFind.push_back(10000);
	toFind.push_back(100001);

	int mini;
	int maxi;
	int midi;
	mini = 0;
	maxi = 6;
	int val = 5675;
	while(maxi >= mini)
	{
		midi = floor((maxi+mini)/2);
		
		if(toFind.at(midi) < val)
		{
			mini = midi + 1;
		}
		else if(toFind.at(midi) > val)
		{
			maxi = midi - 1;
		}
		else
		{
			break;
		}
	}
	cout << midi <<endl;
	//selection();
	insertion();
}

void insertion()
{
	vector<int> toSort;
	toSort.push_back(123);
	toSort.push_back(1132);
	toSort.push_back(53);
	toSort.push_back(1);
	toSort.push_back(1124);
	toSort.push_back(12456);
	int holepos;
	int value;
	for(int i = 1; i < 5; i++)
	{
		holepos = i;
		value = toSort.at(i);
		while((holepos > 0) and (value < toSort.at(holepos - 1)))
		{
			toSort.at(holepos) = toSort.at(holepos - 1);
			holepos = holepos - 1;
		}
		toSort.at(holepos) = value;
	}
	for(int x=0;x<5;x++)
	{
		cout << toSort.at(x) << "  ";
	}
}

void insertion2()
{

	vector<int> toSort;
	toSort.push_back(123);
	toSort.push_back(1132);
	toSort.push_back(53);
	toSort.push_back(1);
	toSort.push_back(1124);
	toSort.push_back(12456);
	int holepos;
	int value;

	int x;
	for(x = 1; x < 5; x++)
	{
		holepos = x;
		value = toSort.at(x);
		while((holepos > 0) and (value < toSort.at(holepos - 1))
		{
			toSort.at(holepos) = toSort.at(holepos - 1);
			holepos = holepos - 1;
		}
		toSort.at(holepos) = value;
	}
}

void selection()
{
	vector<int> toSort;
	toSort.push_back(123);
	toSort.push_back(1132);
	toSort.push_back(53);
	toSort.push_back(1);
	toSort.push_back(1124);
	toSort.push_back(12456);

	int n = 5;
	int i;
	int j;
	int temp;

	for(j=0;j < n-1 ;j++)
	{
		int minimum = j;
		for(i = j+1;i<n;i++)
		{
			if(toSort.at(i) < toSort.at(minimum))
				{
					minimum = i;
				}
		}
		if(minimum!=j)
		{
			temp = toSort.at(j);
			toSort.at(j) = toSort.at(minimum);
			toSort.at(minimum) = temp;
		}
	}

	for(i=0;i<n;i++)
	{
		cout << toSort.at(i) << "  ";
	}


}








