#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main()
{
      
	int arr[] = {5,2,3};			// Create an array
	int n = sizeof(arr)/sizeof(arr[0]); 	// Find size of the array
	sort(arr, arr+n);			// sort the array
	
	do 
	{
		for(int i = 0; i < n; i++)
		{
			cout << arr[i];
		}
			cout << endl;

	} while (next_permutation(arr, arr+n));
	
	
	    
}
