#include <stdio.h>
int main(int argc, char** argv)
{
	int x= 10;
	int y= 20;
	int* a= &x;
	int* b= &y;
	x= *b;
	y= y+(*a);
	printf("%d,%d\n",*a,y);
	return 0;
}
