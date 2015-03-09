#include<iostream>
using namespace std;

int *copyarr(int *a, int size)
{
	int x;
	int* array_p_copy;
	array_p_copy = new int[size];
	
	for(x=0; x<size; x++) // Copying the array over
	{
		array_p_copy[x] = a[x];
	}
	return(array_p_copy);
}

int main() 
{ 	
	int x;
	int size = 3;
	int* array_p;
	array_p = new int[size];
	
	for(x=0; x<size; x++) // Putting something into the array
	{
		array_p[x] = x;
	}
	
	int* returnedArray;
	returnedArray = copyarr(array_p,size);
	
	
	for(x=0; x<size; x++)
	{
		cout << returnedArray[x];
	}
	
}
