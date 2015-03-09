#include<iostream>


using namespace std;

void conv_hr(char &ampm, int &hour);

int main()
{
	int main_hour, main_min;
	char ampm;
	cout << "Enter the hour " << endl;
	cin >> main_hour;
	if((main_hour < 0) or (main_hour > 24))
	{
		cout << "INVALID TIME";
		return 0;
	}
	cout << "Enter the Minute " << endl;
	cin >> main_min;
	if((main_min< 0) or (main_min > 59))
	{
		cout << "INVALID TIME";
		return 0;
	}
	
	
	cout << "The time you entered is " << main_hour << ":" << main_min << " " << endl;
	conv_hr(ampm, main_hour);
	cout << "The new time is " << main_hour << ":" << main_min << " " << ampm << "M";
}

void conv_hr(char &ampm, int &hour)
{
	if((hour<12) and (hour > 0))
	{
		hour = hour;
		ampm = 'A';
	}
	else if(hour == 0)
	{
		hour = 12;
		ampm = 'A';
	}
	else
	{
		hour = hour - 12;
		ampm = 'P';
		
	}
}
