#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;




 int  prin(int arr[][4])
{
	
        int x,y;
      
	for (y = 0; y <=3; y++)
	{
		for (x = 0; x<=3; x++)
		{
			cout << arr[x][y] <<" ";
		}
		cout << endl;
	}
	return(0);
}

 int swapRow(int arr[][4],int row1, int row2)
{

        int x,temp;
	for (x = 0; x <=3; x++)
	{
	  temp = arr[x][row1];
	  arr[x][row1]=arr[x][row2];
	  arr[x][row2]=temp;
	}
	

	prin(arr);
	return(0);
}

int main()

{
        int row1,row2,x,y;
	string user;
	int arr[4][4];

	for (y = 0; y <=3; y++)
	{
		for (x = 0; x<=3; x++)
		{
			arr[y][x] = rand() % 100;
		}
	}
	
	while (user!="Q")
	{
	  cout << "P - Print S - Swap Q - Quit"<<endl;
	  cin >> user;
	  if (user=="P")
	    {
		prin(arr);
	    }
	
	  if (user=="S")
	    {
		cin >> row1;
		cin >> row2;
		swapRow(arr, row1,row2);
	    }	
	}
	return(0);
}

