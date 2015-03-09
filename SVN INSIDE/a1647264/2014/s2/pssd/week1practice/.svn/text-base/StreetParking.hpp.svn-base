#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
 
/* 1.	It is not directly in front of a private driveway.
2.	It is not directly in front of a bus stop.
3.	It is not 5 meters before a bus stop.
4.	It is not 10 meters before a bus stop.
5.	It is not directly in front of a side-street.
6.	It is not 5 meters before a side-street.
7.	It is not 5 meters after a side-street. */

class StreetParking
{
  public:
  int freeParks(string street)
  {
	int amt = 0;
	char last = street[0];
	for(int i = 0; i < street.length(); i++)
	{
		if( street[i] == '-')
		{
			if(last!='S')
			{
				if( (i+2)<street.length() and street[i+2] == 'B' ) continue;
				if( (i+1)<street.length() and street[i+1] == 'B' ) continue;
				if( (i+1)<street.length() and street[i+1] == 'S' ) continue;
				amt++;
			}

			
		}
		last = street[i];
	}
	return amt;
  }
};

/*int main()
{
	StreetParking newStreet;
	cout << newStreet.freeParks("---B--S-D--S--") << endl;
	cout << newStreet.freeParks("DDBDDBDDBDD") << endl;
	cout << newStreet.freeParks("--S--S--S--S--") << endl;
	cout << newStreet.freeParks("SSD-B---BD-DDSB-----S-S--------S-B----BSB-S--B-S-D") << endl;
	cout << newStreet.freeParks("-SB---S----DD-D-DS---B--BD-S-SD---D----D-B---B-SDD") << endl;
	cout << newStreet.freeParks("------BB-----D--------S--D-BSSS-----B---S-S-SSS---") << endl;
	cout << newStreet.freeParks("-SDBS-DBB----SBSSDD--BB---B-DB-DS-DS--DD---DB--D-D") << endl;
	cout << newStreet.freeParks("B") << endl;
	cout << newStreet.freeParks("D") << endl;
	cout << newStreet.freeParks("S") << endl;

	
}*/

