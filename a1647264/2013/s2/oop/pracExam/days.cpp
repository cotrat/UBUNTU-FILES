#include<iostream>
#include<string>
using namespace std;



int main(int argc, char* argv[])
{
	int x;
	for(x=0; x<argc; x++)
	{
		string argstr = string(argv[x]);
		if(argstr == "-hello")
		{
			cout << " It was hello !!!!";
		}
	}
}
