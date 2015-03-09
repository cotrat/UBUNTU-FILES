#include<iostream>
using namespace std;


void scale(int *values, unsigned int size, unsigned int scaleAmnt)
{
	int idx;

	for(idx =0; idx < size; idx++)
	{
		values[idx] = values[idx] * scaleAmnt;
	}

}

void print(int * array, unsigned int size)
{
	int idx;

	for(idx =0; idx < size; idx++)
	{
		cout << array[idx] << " ";
	}
}

int run(int *array, unsigned int size, unsigned int scales)
{
	if(size <=0)
	{
		cout << "NUMBER MUST BE ABOVE 0";
		return(0);
	}

	scale(array, size, scales);
	print(array,size);
	
	delete[] array;


}

void tests()
{
	int* test_a1;
	int* test_a2;
	int* test_a3;
	int* test_a4;

	unsigned int size1, size2, size3, size4, scale1,scale2,scale3,scale4;
	scale1 = 3;
	scale2 = 5;
	scale3 = 0;
	scale4 = 10;

	size1 = 10;
	size2 = 5;
	size3 = 0;
	size4 = 2;

	test_a1 = new int[size1];
	test_a2 = new int[size2];
	test_a3 = new int[size3];
	test_a4 = new int[size4];
/*
	test_a1 = {1,1,1,1,1,3,1,4,1,1};
	test_a2 = {2,3,1,4,1};
	test_a3 = {-100};
	test_a4 = {-100, 100};*/

	run(test_a1, size1, scale1);
	run(test_a2, size2, scale2);
	run(test_a3, size3, scale3);
	run(test_a4, size4, scale4);

}


int main()
{
	int idx;
	unsigned int size, scales;
	cout << "How many elements in the array? ";
	cin >> size;

	int* d_array;
	d_array = new int[size];
	cout << "Input your " << size << " Integers ";

	for(idx =0; idx < size; idx++)
	{
		cin >> d_array[idx];
	}

	cout << "how much do you want to scale by ";
	cin >> scales;

	run(d_array, size, scales);

	}


